#include "node.h"
#include "codegen.h"
#include <bits/stdc++.h>
#include <string.h> // strdup
#include <stdio.h> // printf
#include <stdarg.h>
#include <string.h>
#include <vector>
#include<iostream>

using namespace std;


/* Compile the AST into a module */
void CodeGenContext::generateCode(ASTProgram& root)
{
	std::cout << "llvm Code Generation !!!\n";

	/* Create the top level interpreter function to call as entry */
	vector<Type*> argTypes;
	FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), makeArrayRef(argTypes), false);
	mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);

	/* Push a new variable/block context */
	pushBlock(bblock);
	root.codeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(getGlobalContext(), bblock);
	popBlock();

	/* Print the bytecode in a human-readable format 
	   to see if our program compiled properly
	 */
	std::cout << "Code is generated.\n";
	PassManager pm;
	pm.add(createPrintModulePass(&outs()));
	pm.run(*module);
}

/* Executes the AST by running the main function */
GenericValue CodeGenContext::runCode() {
	ExecutionEngine *ee = EngineBuilder(module).create();
	vector<GenericValue> noargs;
	GenericValue v = ee->runFunction(mainFunction, noargs);
	return v;
}


///////////////// Helper Functions for printing the AST  ////////////////////////////////
static int indent=-1;

void whites()
{
	for(int i=0;i<indent;i++)
		cout<<"\t";
}
///////////////////////////////////////////////////////////////////////////////////////

ASTExpr *Error(const char *Str) { fprintf(stderr, "Error: %s\n", Str);    return 0;}
Value *ErrorV(const char *Str) { Error(Str); return 0; }

static Module *TheModule;
static IRBuilder<> Builder(getGlobalContext());
static std::map<std::string, Value*> NamedValues;

//////////////////////////////////////// Code Gen //////////////////////////////////////

Value* ASTFloat::codeGen(CodeGenContext& context) 
{
	return ConstantFP::get(Type::getDoubleTy(getGlobalContext()), floatConst);
}

Value* ASTInt::codeGen(CodeGenContext& context) 
{
	return ConstantInt::get(Type::getInt64Ty(getGlobalContext()), intConst, true);
}

Value* ASTString::codeGen(CodeGenContext& context) 
{
	return ConstantDataArray::getString(getGlobalContext(), stringConst, true);
}

Value* ASTMethodCall::codeGen(CodeGenContext& context) 
{
	Function *function = context.module->getFunction(id->Id);
	if(function == NULL)
	{
		cout << "no such function " << id->Id << endl;
	}
	std::vector<Value*> args;
	if(expr)
	{
		for(int i=0;i<expr->size();i++)
		{
			args.push_back((*expr)[i]->codeGen(context));
		}
	}
        CallInst *call = CallInst::Create(function, makeArrayRef(args), "", context.currentBlock());
	return call;
}

Value* ASTOp::codeGen(CodeGenContext& context) 
{
	if(leftExpr)
	{
		leftExpr->codeGen(context);
	}
	if(rightExpr)
	{
		rightExpr->codeGen(context);
	}

	//return NULL;
	Instruction::BinaryOps instr;
	string a="+";
	string b="-";
	string c="*";
	string d="/";
	string e="%";
	cout << binOp  << endl;

	if(binOp== a)
		instr = Instruction::Add;
	else if(binOp == b)
		instr = Instruction::Sub; 
	else if(binOp == c)
		instr = Instruction::Mul; 
	else if(binOp== d)
		instr = Instruction::SDiv;
	else if(binOp== e)
		instr = Instruction::SRem;
	else if(binOp == "==")
	{
		return Builder.CreateICmpEQ(leftExpr->codeGen(context), rightExpr->codeGen(context),"tmp");
	}
	else
		return NULL;
	return BinaryOperator::Create(instr, leftExpr->codeGen(context), rightExpr->codeGen(context), "tmp", context.currentBlock());	
}


Value* ASTLocation::codeGen(CodeGenContext &context)
{
	Value *f = NULL;
	if(expr)
		f = expr->codeGen(context);
	if(varId)
		f = varId->codeGen(context);
	return f;
}

Value* Variable::codeGen(CodeGenContext& context){
	if(context.locals().find(Id)== context.locals().end()){
		cout << "undeclared variable" <<   Id << endl;
		return NULL;
	}
	return new LoadInst(context.locals()[Id], "", false, context.currentBlock());

}

Value* ASTProgram::codeGen(CodeGenContext& context){

	Value* f = NULL;
	for(auto i = (*decl).rbegin();i!=(*decl).rend();i++)
	{
		f=(*i)->codeGen(context);
	}
}

Value* ASTVarDecl::codeGen(CodeGenContext& context) 
{ 

	AllocaInst *alloc = NULL;
	if(dataType==0)
	{
		alloc = new AllocaInst(Type::getInt64Ty(getGlobalContext()), Id->Id, context.currentBlock());
	}
	else if(dataType==1)
	{
		alloc = new AllocaInst(Type::getDoubleTy(getGlobalContext()), Id->Id, context.currentBlock());
	}
	else
	{
		//TODO
		//bool a;
		//alloc = new AllocaInst(Type::getPrimitiveType(getGlobalContext(), a), Id, context.currentBlock());
	}
	context.locals()[Id->Id] = alloc;
	return alloc;
}


Value* ASTMethodDecl::codeGen(CodeGenContext& context){

	vector<Type*> argTypes;
	//cout<<retType<<endl;
	for(int i=0;args!=NULL && i<args->size();i++)
	{
		if((*args)[i]->dataType==0)
		{
			argTypes.push_back(Type::getInt64Ty(getGlobalContext()));
		}
		else if((*args)[i]->dataType==1)
		{
			argTypes.push_back(Type::getDoubleTy(getGlobalContext()));
		}
	}
	FunctionType* fType = NULL;
	if(retType==0)
	{
		fType = FunctionType::get(Type::getInt64Ty(getGlobalContext()), makeArrayRef(argTypes), context.currentBlock());
	}
	else if(retType==1)
	{
		fType = FunctionType::get(Type::getDoubleTy(getGlobalContext()), makeArrayRef(argTypes), context.currentBlock());
	}
	else
	{
		//TODO
		//bool a;
		//fType = FunctionType::get(retType, makeArrayRef(argTypes), false);
	}

	Function *function = Function::Create(fType, GlobalValue::InternalLinkage, Id->Id, context.module);
	BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", function, 0);


	context.pushBlock(bblock);

	Function::arg_iterator argsValues = function->arg_begin();
	Value* argumentValue;

	for(int i=0;args!=NULL && i<args->size();i++){
		(*args)[i]->codeGen(context);
		argumentValue = argsValues++;
		argumentValue->setName((*args)[i]->Id->Id);
		StoreInst *inst = new StoreInst(argumentValue, context.locals()[(*args)[i]->Id->Id], false, bblock);
	}

	block->codeGen(context);
	ReturnInst::Create(getGlobalContext(), context.getCurrentReturnValue(), bblock);

	context.popBlock();
	return function;
}


Value* ASTBlock::codeGen(CodeGenContext& context){

	Value* f = NULL;
	for(auto i = (*VarDecl).rbegin();i!=(*VarDecl).rend();i++)
	{
		f=(*i)->codeGen(context);
	}
	for(auto i = (*statement).rbegin();i!=(*statement).rend();i++)
	{
		f=(*i)->codeGen(context);
	}
	return f;
}

Value* ASTAssignment::codeGen(CodeGenContext& context){

	if (context.locals().find(location->varId->Id) == context.locals().end()) {
		cout << "undeclared variable" << location->varId->Id << endl;
		return NULL;
	}

	StoreInst *inst = new StoreInst((expr)->codeGen(context), context.locals()[location->varId->Id], false, context.currentBlock());
	return inst;
}


///////////////////////////////////////End Code Gen ////////////////////////////////////


/////////////////////////////////////////Constructors /////////////////////////////////
ASTProgram::ASTProgram(vector <ASTDecl*> *declarations)
{
	decl=declarations;
}

Variable::Variable(string s)
{
	Id=s;
}

ASTVarDecl::ASTVarDecl(int type, Variable* v, int c)
{
	dataType = type;
	arr_count = c;
	string s = v->Id;
	string tmp ="";
	for(int i=0;i< s.size() && s[i]!=',' && s[i]!='[';i++)
	{	
		if(s[i]!=' ' && s[i]!=';')
			tmp+=s[i];
	}
	Id=new Variable(tmp);
}

ASTMethodDecl::ASTMethodDecl(ASTBlock* blk,vector<ASTVarDecl*> *arguments,Variable* id,int ret)
{
	retType = ret;
	block = blk;

	string s = id->Id;
	string tmp="";
	for(int i=0;i<s.size() && s[i]!='(';i++)
	{
		if(s[i]!=' ')
			tmp+=s[i];
	}
	Id = new Variable(tmp);
	args = arguments;
}

ASTBlock::ASTBlock(vector<ASTVarDecl*> *vars,vector<ASTStatement *> *statements)
{
	VarDecl = vars;
	statement = statements;
}

ASTLocation::ASTLocation(Variable* v,ASTExpr* expression)
{
	string s= v->Id;
	string tmp ="";
	for(int i=0;i< s.size() && s[i]!='='&&s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='%'&&s[i]!=';'&&s[i]!='<'&&s[i]!='>'&&s[i]!=')'&&s[i]!=','&&s[i]!='\n';i++)
	{	
		if(s[i]!=' ')
			tmp+=s[i];
	}
	varId = new Variable(tmp);

	expr=expression;
}


///////////////////////STATEMENTS/???????//////////////////////////////////////
ASTAssignment::ASTAssignment(ASTLocation *loc,ASTExpr * expression,int type)
{
	location = loc;
	expr = expression;
	assignType = type;
}

ASTOp::ASTOp(string op,ASTExpr *lexpr,ASTExpr *rexpr)
{
	binOp = op;
	leftExpr = lexpr;
	rightExpr = rexpr;
}

ASTFor::ASTFor(Variable* v,ASTExpr *expr1,ASTExpr *expr2,ASTBlock *expr3)
{
	string s= v->Id;
	string tmp ="";
	for(int i=0;i< s.size() && s[i]!='=';i++)
	{	
		if(s[i]!=' ')
			tmp+=s[i];
	}
	idName = new Variable(tmp);
	initExpr = expr1;
	condExpr = expr2;
	forBlock = expr3;
}

ASTReturn::ASTReturn(ASTExpr* expression)
{
	expr = expression;
}

ASTKeyword::ASTKeyword(string keyword)
{
	keywordType = keyword;
}

ASTIf::ASTIf(ASTExpr *expr1,ASTBlock *block1,ASTBlock *block2)
{
	expr = expr1;
	ifBlock = block1;
	elseBlock = block2;
}

/////////////////////////////////////////////Method Call ////////////////////////////////
ASTMethodCall::ASTMethodCall(Variable* mname,vector<ASTExpr *> * exprs)
{
	string s = mname->Id;
	string tmp="";
	
	for(int i=0;i<s.size() && s[i]!='(';i++)
	{
		if(s[i]!=' ')
			tmp+=s[i];
	}
	id = new Variable(tmp);
	expr = exprs;
}

ASTCallout::ASTCallout(string stConst,vector<ASTExpr *> * exprs)
{
	stringConst = stConst;
	expr = exprs;
}

//////////////////////////////////////////////Constants /////////////////////////////////////////////////
ASTInt::ASTInt(int i)
{
	intConst=i;
}
/*
   Value *ASTInt::Codegen() {
   return ConstantFP::get(getGlobalContext(), APFloat(intConst));
   }
 */
ASTChar::ASTChar(char c)
{
	charConst=c;
}

ASTBool::ASTBool(bool b)
{
	booleanConst=b;
}


ASTString::ASTString(string s)
{
	string tmp="";
	int i=0;
	while(i<s.size() && s[i]!='"')
		i++;
	for(;i<s.size()&&s[i+1]!='"';i++)
	{
		if(s[i]!='"')
			tmp+=s[i];
	}
	if(s[i]!='"')
		tmp+=s[i];
	stringConst=tmp;
}

ASTFloat::ASTFloat(float s)
{
	floatConst=s;
}

//////////////////////////////////////////Print /////////////////////////////////////////////////////////////////
void ASTProgram::print()
{
	indent++;
	whites();
	cout<<"Program Node begins ------------------------------------------------------------------ "<<endl;
	for(auto i = (*decl).rbegin();i!=(*decl).rend();i++)
	{
		(*i)->print();
	}
	whites();
	cout<<"Program Node ends -------------------------------------------------------------------"<<endl<<endl;
	indent--;
}

string getType(int val)
{
	if(val == 0)
		return "INT";
	else if(val == 1)
		return "FLOAT";
	else if(val == 2)
		return "BOOLEAN";
	else if(val == 3)
		return "VOID";
	return "INVALID DATATYPE";
}

void ASTVarDecl::print()
{
	indent++;
	whites();
	cout<<" Entering Variable Declaration Node"<<endl;
	whites();
	cout<<" Variable Name = " <<endl;
	Id->print();
	whites();
	cout<<" Variable Type = "<<getType(dataType)<<endl;
	whites();
	cout<<" Count = "<<arr_count<<endl;
	whites();
	cout<<" Exiting Variable Declaration Node"<<endl<<endl;
	indent--;
}

void ASTMethodDecl::print()
{
	indent++;
	whites();
	cout<<"Entering Method Declaration Node"<<endl;
	whites();
	cout<< "Method Name "<<endl;
	Id->print();
	whites();
	cout<<"Return Type = "<<getType(retType)<<endl;
	whites();
	cout<<"Argument List: ";
	if(args)
	{
		for(auto i=(*args).rbegin();i!=(*args).rend();i++)
		{
			(*i)->print();
		}
	}
	else
	{
		cout << " None" <<endl;
	}
	block->print();
	whites();
	cout<<"Exiting Method Declaration Node"<<endl<<endl;
	indent--;
}


void ASTBlock::print()
{
	indent++;
	whites();
	cout<<"Entering Block Node"<<endl;
	whites();
	cout<<"Variable Declarations"<<endl;
	for(auto i=(*VarDecl).begin();i!=(*VarDecl).end();i++)
	{
		(*i)->print();
	}
	whites();
	cout<<"Statements"<<endl;
	for(auto i=(*statement).rbegin();i!=(*statement).rend();i++)
	{
		(*i)->print();
	}
	whites();
	cout<<"Exiting Block Node"<<endl<<endl;
	indent--;
}

void ASTInt::print()
{
	indent++;
	whites();
	cout<<" Entering Constant Char Node "<<endl;
	whites();
	cout<<intConst<<endl;
	whites();
	//cout<< Codegen() <<endl;
	cout<<" Exiting Constant Char Node "<<endl<<endl;
	indent--;
}

void ASTChar::print()
{
	indent++;
	whites();
	cout<<" Entering Constant Char Node "<<endl;
	cout<<charConst<<endl;
	whites();
	cout<<" Exiting Constant Char Node "<<endl<<endl;
	indent--;
}

void ASTBool::print()
{
	indent++;
	whites();
	cout<<" Entering Constant Bool Node "<<endl;
	cout<<booleanConst<<endl;
	whites();
	cout<<" Exiting Constant Bool Node "<<endl<<endl;
	indent--;
}

void ASTFloat::print()
{
	indent++;
	whites();
	cout<<" Entering Constant Float Node "<<endl;
	cout<< floatConst<<endl;
	whites();
	cout<<" Exiting Constant Float Node "<<endl<<endl;
	indent--;
}

void ASTString::print()
{
	indent++;
	whites();
	cout<<" Entering Constant String Node "<<endl;
	whites();
	cout<< stringConst <<endl;
	whites();
	cout<<" Exiting Constant String Node "<<endl<<endl;
	indent--;
}

string getAssignType(int assignType)
{
	switch(assignType)
	{
		case 0: return "=";
		case 1: return "+=";
		case 2: return "-=";
	}
	return "Unsupported assign type";
}
void ASTAssignment::print()
{
	indent++;
	whites();
	cout<<" Entering Assignment Node "<<endl;
	location->print();
	whites();
	cout << "Type of assignment: " << getAssignType(assignType) << endl;
	whites();
	cout << "Expression: " <<endl;
	expr->print();
	whites();
	cout<<" Exiting Assignment Node "<<endl;
	indent--;
}

void ASTLocation::print()
{
	indent++;
	whites();
	cout<<" Entering Location Node "<<endl;
	varId->print();
	whites();
	//cout << "Expression: " << expr->print() << endl;
	cout<<" Exiting Assignment Node "<<endl;
	indent--;
}

void Variable::print()
{
	indent++;
	whites();
	cout << "Entering Reference node "<<endl;
	whites();
	cout << Id <<endl;
	whites();
	cout << "Exiting Reference node "<<endl;
	indent--;
}

void ASTOp::print()
{
	indent++;
	whites();
	cout<<" Entering Operation Node "<<endl;
	whites();
	if(leftExpr == NULL)
	{
		cout<<"Operation Type: Unary"<<endl;
		whites();
		cout<<"Operator:"<<binOp<<endl;
		whites();
		cout<<"Expression:"<<endl;
		rightExpr->print();
	}
	else
	{
		cout<<"Operation Type: Binary"<<endl;
		whites();
		cout<<"Operator:"<<binOp<<endl;
		whites();
		cout<<"Left Expression:"<<endl;
		leftExpr->print();
		whites();
		cout<<"Right Expression"<<endl;
		rightExpr->print();
	}
	whites();
	cout<<" Exiting Operation Node "<<endl;
	indent--;
}
void ASTMethodCall::print()
{
	indent++;
	whites();
	cout<<" Entering Method Call Node "<<endl;
	whites();
	cout<<" Name : "<<endl;
	id->print();
	if(expr!=NULL)
	{
		for(auto i=(*expr).rbegin();i!=(*expr).rend();i++)
		{
			(*i)->print();
		}
	}
	whites();
	cout<<"Exiting Method Call Node "<<endl;
	indent--;
}
void ASTCallout::print()
{
	indent++;
	whites();
	cout<<" Entering Callout Method Node: "<<endl;
	whites();
	cout <<" String Name: "<<stringConst<<endl;
	if(expr!=NULL)
	{
		for(auto i=(*expr).rbegin();i!=(*expr).rend();i++)
		{
			(*i)->print();
		}
	}
	whites();
	cout<<"Exiting Callout Method Node "<<endl;
	indent--;
}


void ASTFor::print()
{
	indent++;
	whites();
	cout<<"Entering For Node : "<<endl;
	whites();
	cout<<" ID->Name : "<<endl;
	idName->print();
	whites();
	cout<<"Init expr:"<<endl;
	initExpr->print();
	whites();
	cout<<"conditional expr:"<<endl;
	condExpr->print();
	whites();
	cout<<"For block:"<<endl;
	forBlock->print();
	whites();
	cout<<"Exiting For Node"<<endl<<endl;
	indent--;
}

void ASTIf::print()
{
	indent++;
	whites();
	cout<<"Entering If Node : "<<endl;
	whites();
	cout<<"IF expression:"<<endl;
	expr->print();
	whites();
	cout<<"If Block:"<<endl;
	ifBlock->print();
	whites();
	cout<<"else block:"<<endl;
	if(elseBlock == NULL)
	{
		whites();
		cout<<"NULL"<<endl;
	}
	else
		elseBlock->print();
	whites();
	cout<<"Exiting If Node"<<endl<<endl;
	indent--;
}

void ASTReturn::print()
{
	indent++;
	whites();
	cout<<"Entering Return Node : "<<endl;
	whites();
	cout<<"Return expression:"<<endl;
	if(expr !=NULL)
	{
		expr->print();
	}
	else
	{
		whites();
		cout << "NULL" <<endl;
	}
	whites();
	cout<<"Exiting Return Node"<<endl<<endl;
	indent--;
}

void ASTKeyword::print()
{
	indent++;
	whites();
	cout<<"Entering Keyword Node : "<<endl;
	whites();
	cout << "Keyword : " << keywordType << endl;
	whites();
	cout<<"Exiting Keyword Node"<<endl<<endl;
	indent--;
}
