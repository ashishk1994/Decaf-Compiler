#include <bits/stdc++.h>
#include <llvm/IR/Value.h>
using namespace std;
class CodeGenContext;


class ASTDecl;
class ASTStart;
class ASTProgram;
class ASTExpr;
class Variable;
class ASTLocation;
class ASTAssignment;
class ASTVarDecl;
class ASTDecl;
class ASTInt;
class ASTBlock;

class ASTStart{
	private:
		string nodeType;
	public:
		virtual void print()=0;
		virtual llvm::Value* codeGen(CodeGenContext& context){
		return NULL;
		 }
};

class ASTProgram: public ASTStart{
	private:
		vector<ASTDecl*> *decl;
	public:
		ASTProgram(vector<ASTDecl*> *);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTProgram();
		void print();
};

class ASTExpr: public ASTStart{
	private:
		string exprString;
	public:
		 virtual void print()=0;
};

class ASTStatement: public ASTStart{
	private:
		string statementType;
	public:
		virtual void print()=0;
};


class ASTDecl: public ASTStart{
	public:
		Variable* Id;
		virtual void print()=0;
};

//##################################Classes for Declaration Type ##########################
class ASTBlock;
class ASTVarDecl;
class ASTMethodDecl: public ASTDecl{ //retType name(args){block;}
	private:
		ASTBlock* block;	
		vector<ASTVarDecl *> *args;
		int retType;
	public:
		ASTMethodDecl(ASTBlock*,vector<ASTVarDecl*> *,Variable*,int);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTMethodDecl();
		void print();
};

class ASTVarDecl:public ASTDecl{ // dataType name || dataType name[1000];
	public:
		int dataType;
		int arr_count;
		ASTVarDecl(int, Variable*, int);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTVarDecl();
		void print();
};

//###################################Classes for Statement Type ################################
class ASTLocation;

class ASTAssignment:public ASTStatement{ // RHS = Expr; //RHS may be of type ID , ID [1000] 
	private:
		ASTLocation *location;
		int assignType;
		ASTExpr *expr;
	public:
		ASTAssignment(ASTLocation *,ASTExpr *,int);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTAssignment();
		void print();
};

class ASTIf:public ASTStatement{
	private:
		ASTExpr *expr;
		ASTBlock *ifBlock;
		ASTBlock *elseBlock;
	public:
		ASTIf(ASTExpr *,ASTBlock *,ASTBlock *);
		~ASTIf();
		void print();
};

class ASTFor:public ASTStatement{
	private:
	Variable* idName;
		ASTExpr *initExpr;
		ASTExpr *condExpr;
		ASTBlock *forBlock;
	public:
		ASTFor(Variable*,ASTExpr *,ASTExpr *,ASTBlock *);
		~ASTFor();
		void print();
};
/*
class ASTJump:public ASTStatement{
	private:
		ASTExpr *expr;
		string type;
	public:
		ASTJump(ASTExpr *,string);
		~ASTJump();
		void print();
};
*/
class ASTReturn:public ASTStatement{
	private:
		ASTExpr *expr;
	public:
		ASTReturn(ASTExpr *);
		~ASTReturn();
		void print();
};

class ASTKeyword:public ASTStatement{
	private:
		string keywordType;
	public:
		ASTKeyword(string);
		~ASTKeyword();
		void print();
};

class ASTBlock:public ASTStatement{
	private:
		vector<ASTVarDecl *> *VarDecl;
		vector<ASTStatement *> *statement;
	public:
		ASTBlock(vector<ASTVarDecl*> *,vector<ASTStatement *> *);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTBlock();
		void print();
};
//###################################Classes for Expression Type ################################

class ASTCaller:public ASTExpr,public ASTStatement{
	public:
		void print() = 0;
};

class ASTMethodCall:public ASTCaller{
	private:
		Variable* id;
		vector<ASTExpr *> *expr;
	public:
		ASTMethodCall(Variable* ,vector<ASTExpr *> *);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTMethodCall();
		void print();
};

class ASTCallout:public ASTCaller{
	private:
		string stringConst;
		vector<ASTExpr *> *expr;
	public:
		ASTCallout(string,vector<ASTExpr *> *);
		~ASTCallout();
		void print();
};

class ASTLocation: public ASTExpr
{       
    public:
      Variable* varId;
      ASTExpr* expr;
     virtual llvm::Value* codeGen(CodeGenContext& context);
      ASTLocation(Variable*, ASTExpr*);
      ~ASTLocation();
      void print();
};

class Variable:public ASTStart{
	public:
		string Id;
		Variable(string);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~Variable();
		void print();
};

class ASTInt: public ASTExpr {
	public:
		int intConst;
		ASTInt(int);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTInt();
		void print();
};

class ASTBool: public ASTExpr {
	public:
		bool booleanConst;
		ASTBool(bool);
		~ASTBool();
		void print();
};

class ASTChar: public ASTExpr {
	public:
		char charConst;
		ASTChar(char);
		~ASTChar();
		void print();
};


class ASTFloat: public ASTExpr {
	public:
		float floatConst;
		ASTFloat(float);
		~ASTFloat();
		virtual llvm::Value* codeGen(CodeGenContext& context);
		void print();
};

class ASTString: public ASTExpr {
	public:
		string stringConst;
		ASTString(string);
		virtual llvm::Value* codeGen(CodeGenContext& context);
		~ASTString();
		void print();
};

class ASTOp: public ASTExpr{
	private:
		ASTExpr *leftExpr;
		ASTExpr *rightExpr;
		string binOp;
	public:
		virtual llvm::Value* codeGen(CodeGenContext& context);
		ASTOp(string,ASTExpr *,ASTExpr *);
		~ASTOp();
		void print();
};




