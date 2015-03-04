%{
    #include "node.h"
    #include<bits/stdc++.h>
    using namespace std;

// stuff from flex that bison needs to know about:
    extern "C" int yylex();
    extern "C" FILE *yyin;
    void yyerror(const char *s);
    #include "parser.hpp"

ASTProgram* init_start;

%}


%union {

struct {
    int ival;
    float fval;
    bool bval;
	char* pname;
//	string my;
//	string s;  string not supported
	char sval[100];
	ASTStart *astStart;
	ASTProgram *astProgram;
	vector <ASTDecl*> *astDecl;        
	vector<ASTVarDecl *> *astVarDecl;      
	ASTMethodDecl *astMethodDecl;
	ASTBlock *astBlock;
	vector<ASTStatement *> *astStatement;
	int datatype;      /////Either Char * or array of character or make an enum class   
	ASTString *astString;        
	ASTInt *astInt;
	char* name;
	ASTFloat *astFloat;
	ASTBool *astBool;
	vector< pair<Variable *, int> > *varDecl;
	ASTExpr *astExpr;
	ASTLocation *location;
	ASTCaller *astCaller;
	vector<ASTExpr *> *astexprMult;
    	ASTReturn *astReturn;
	Variable *reference;
    };
}



%type <astStart> program
%type <astDecl> declaration method_decl 
%type <astBlock> block else_part
%type <astStatement> stmt_mult
%type <datatype> type INT BOOLEAN FLOAT assign
%type <varDecl> variables variable
%type <astVarDecl> formals formal_param var var_decl 
%type <name> ID STRING_CONST
%type <ival> INT_CONST
%type <bval> BOOLEAN_CONST
%type <fval> FLOAT_CONST
%type <astInt> int_ast
%type <astExpr> expr ret_expr
%type <location> location
%type <astCaller> method_call 
%type <astexprMult> expr_mult callout_arg next_callout_arg

%token BOOLEAN
%token FLOAT
%token INT
%token  INT_CONST
%token  FLOAT_CONST
%token  STRING_CONST
%token  CHARACTER_CONST
%token  ID
%token  COMMENT
%token  SYN_ERR
%token IF
%token ELSE
%token FOR
%token RETURN
%token BREAK
%token CONTINUE
%token NULL_TOKEN
%token TRUE
%token FALSE

%token CLASS
%token OPEN_BRACE
%token CLOSE_BRACE
%token SEMI_COLON
%token BOOLEAN_CONST
%token COMMA
%token DOT
%token OPEN_PARANTHESIS
%token CLOSE_PARANTHESIS
%token OPEN_SQR_BRACKET
%token CLOSE_SQR_BRACKET
%token VOID

%token PLUS
%token PLUS_PLUS
%token MINUS
%token MINUS_MINUS
%token MULTIPLY
%token DIVIDE
%token MODULUS
%token NOT_EQUAL
%token NOT
%token OR
%token CALLOUT
%token AND
%token EQUAL_EQUAL
%token EQUAL
%token MIEQ 
%token PLEQ
%token LESS_EQUAL
%token LESS
%token GREATER_EQUAL
%token GREATER
%token EOF_TOKEN

%right EQUAL
%left OR
%left AND
%left EQUAL_EQUAL NOT_EQUAL
%nonassoc LESS GREATER LESS_EQUAL GREATER_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULUS
%right NOT UMINUS UPLUS


%%

program	   : CLASS ID OPEN_BRACE declaration CLOSE_BRACE { init_start = new ASTProgram($4);}
           ;

declaration   : {$$ = new vector<ASTDecl*>;}
              | type variables SEMI_COLON declaration 
                {
	                $$=$4;
               	 	for(int i=0;i<int($2->size()); i++)
  	                {
	                    $$->push_back(new ASTVarDecl($1, (*$2)[i].first, (*$2)[i].second));
	     		}
                }
              | type ID OPEN_PARANTHESIS formals CLOSE_PARANTHESIS block method_decl
	      	{
			$$=$7;
			$$->push_back(new ASTMethodDecl((ASTBlock *)$6,$4,new Variable($2),$1));
		}
              | VOID ID OPEN_PARANTHESIS formals CLOSE_PARANTHESIS block method_decl 
		{	
			$$=$7;
			$$->push_back(new ASTMethodDecl((ASTBlock *)$6,$4,new Variable($2),4));
		}
		;

type     : INT {$$ = 0;}
         | FLOAT {$$ = 1;}
         | BOOLEAN {$$ = 2;}
         ;

variables    : variable {$$ = $1;}
             | variable COMMA variables
             {$$ = $3; $$->push_back((*$1)[0]);}
             ;

variable    : ID 
	      {
	            $$ = new vector< pair<Variable*, int> >;
                    $$->push_back(make_pair(new Variable($1),0));
              }
            | ID OPEN_SQR_BRACKET INT_CONST CLOSE_SQR_BRACKET
              {
                $$ = new vector< pair<Variable*, int> >;
                $$->push_back( make_pair(new Variable($1), $3 ));
              }
            ;	
method_decl    : {$$ = new vector<ASTDecl*>;}
               | method_decl type ID OPEN_PARANTHESIS formals CLOSE_PARANTHESIS block
	        {
			 $$ = $1;
			 $$->push_back(new ASTMethodDecl((ASTBlock *)$7,$5,new Variable($3),$2));
		     }
               | method_decl VOID ID OPEN_PARANTHESIS formals CLOSE_PARANTHESIS block 
	         {
			 $$ = $1;
			 $$->push_back(new ASTMethodDecl((ASTBlock *)$7,$5,new Variable($3),4));
		     }
	       ;

formals	   : {$$ = NULL;}
           | formal_param 
	       {
		     $$ = $1;
	       }
	       ; 

formal_param 	: type ID 
		   {
			  $$ = new vector<ASTVarDecl *> ;
			  $$->push_back(new ASTVarDecl($1,new Variable($2),0));
	       }
           | type ID COMMA formal_param 
		   {
		      $$ = $4;
			  $$->push_back(new ASTVarDecl($1,new Variable($2),0));
	       }
           | type ID OPEN_SQR_BRACKET CLOSE_SQR_BRACKET COMMA formal_param
           {
              $$ = $6;
              $$->push_back(new ASTVarDecl($1,new Variable($2),-1));
           }
           | type ID OPEN_SQR_BRACKET CLOSE_SQR_BRACKET
           {
			  $$ = new vector<ASTVarDecl *> ;
              $$->push_back(new ASTVarDecl($1,new Variable($2),-1));
           }
		;

block	 : OPEN_BRACE var stmt_mult CLOSE_BRACE 
	   {
		  $$ = new ASTBlock($2,$3);
	   }
	 ;

var 	:{$$ = new vector<ASTVarDecl*>;}
        | var_decl var
    {
	 	 $$ = $2;
		 for(int i=0;i<int($1->size());i++)
		 {
			 $$->push_back((*$1)[i]);
		 }
         
	 }
	;

var_decl  : type variables SEMI_COLON 
  	    {
		    $$ = new vector<ASTVarDecl*>;
		    for(int i=0;i<int($2->size());i++)
		    {
			$$->push_back(new ASTVarDecl($1,(*$2)[i].first,(*$2)[i].second));
		    }
	    }
	  ;

stmt_mult   	: {$$ = new vector<ASTStatement *>;}
	    	    
                | location assign expr SEMI_COLON stmt_mult 
        	    {
			        $$ = $5;
	                $$->push_back( new ASTAssignment($1, $3 ,$2));
          	    }
        	    
                | method_call SEMI_COLON stmt_mult
                {
			        $$ = $3;
			        $$->push_back((ASTStatement *) $1);
		        }
                
                | FOR ID EQUAL expr COMMA expr block stmt_mult 
		        {
			        $$ = $8;
			        $$->push_back(new ASTFor(new Variable($2),$4,$6,$7));
		        }
                
                | IF OPEN_PARANTHESIS expr CLOSE_PARANTHESIS block else_part stmt_mult
		        {
			        $$=$7;
			        $$->push_back(new ASTIf($3,$5,$6));
		        }
                
                | BREAK SEMI_COLON stmt_mult
                {
                    $$ = $3;
                    $$->push_back(new ASTKeyword("break"));
                    
                }
                
                | CONTINUE SEMI_COLON stmt_mult
                {
                    $$ = $3;
                    $$->push_back(new ASTKeyword("continue"));
                }
                
                | RETURN ret_expr SEMI_COLON stmt_mult
                {
                    $$ = $4;
                    $$->push_back(new ASTReturn((ASTExpr*)$2));
                }
                
                | block stmt_mult
                {
                    $$ = $2;
                    $$->push_back((ASTStatement*)$1);
                }
		;

ret_expr        : {$$ = NULL;}
        
                | expr 
                {$$ = $1;}
        ;

else_part       : {$$ = NULL;}
                
                | ELSE block 
	            {$$ = $2;}
	    ;

assign	        : EQUAL 
                {$$ = 0;} 
                
                | PLEQ
                {$$ = 1;}
                
                | MIEQ
                {$$ = 2;}
        ;

method_call 	: ID OPEN_PARANTHESIS CLOSE_PARANTHESIS
		 {$$ = new ASTMethodCall(new Variable($1),NULL);}
               | ID OPEN_PARANTHESIS expr_mult CLOSE_PARANTHESIS 
	          {$$ = new ASTMethodCall(new Variable($1),$3);}
                | CALLOUT OPEN_PARANTHESIS STRING_CONST callout_arg CLOSE_PARANTHESIS 
		  {$$= new ASTCallout($3,$4);}
		;

callout_arg   : {$$ = new vector<ASTExpr *>;}
              | COMMA next_callout_arg 
	        {$$ = $2;}
	      ;

next_callout_arg  : expr {$$ = new vector<ASTExpr *>;
		    	$$->push_back((ASTExpr *)$1);
		    }
                  | expr COMMA next_callout_arg
		    {
			    $$ = $3;
			    $$->push_back((ASTExpr *)$1);
		    }
		  ;


location	: ID {$$ = new ASTLocation(new Variable($1), NULL);}
           	| ID OPEN_SQR_BRACKET expr CLOSE_SQR_BRACKET 
		   {$$ = new ASTLocation(new Variable($1),$3);}
		;

expr	    	: location {$$ = $1;}
                
                | method_call {$$ =(ASTExpr *) $1;}
                
                | int_ast  { $$ =  $1; }
                
                | STRING_CONST { $$ = new ASTString($1);}
                
                | FLOAT_CONST { $$ = new ASTFloat($1);}
                
                | BOOLEAN_CONST { $$ =  new ASTBool($1);}
                
                | expr PLUS expr
                {$$ = new ASTOp("+",(ASTExpr*)$1 ,(ASTExpr*) $3 );}	/* arith_op */
                
                | expr MINUS expr		
                 {$$ = new ASTOp("-",(ASTExpr*)$1 ,(ASTExpr*) $3 );} /* arith_op */
                
                | expr MULTIPLY expr		
                 {$$ = new ASTOp("*",(ASTExpr*)$1 ,(ASTExpr*) $3 );} /* arith_op */
                
                | expr DIVIDE expr		
                 {$$ = new ASTOp("/",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* arith_op */
                
                | expr MODULUS expr		
                  {$$ = new ASTOp("%",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* arith_op */
                
                | expr AND expr				
                 {$$ = new ASTOp("&",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* bool_op */
                
                | expr OR expr				
                 {$$ = new ASTOp("|",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* bool_op */
                
                | expr EQUAL_EQUAL expr			
                {$$ = new ASTOp("==",(ASTExpr*)$1 ,(ASTExpr*) $3 );}   /* bool_op */                
                | expr NOT_EQUAL expr			
                 {$$ = new ASTOp("!=",(ASTExpr*)$1 ,(ASTExpr*) $3 );}   /* bool_op */
                
                | expr LESS expr			
                 {$$ = new ASTOp("<",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* bool_op */
                
                | expr GREATER expr			
                 {$$ = new ASTOp(">",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* bool_op */
                
                | expr LESS_EQUAL expr			
                 {$$ = new ASTOp("<=",(ASTExpr*)$1 ,(ASTExpr*) $3 );}  /* bool_op */

                | expr GREATER_EQUAL expr		
                {$$ = new ASTOp(">=",(ASTExpr*)$1 ,(ASTExpr*) $3 );}   /* bool_op */
                
                | NOT expr			
                 {$$ = new ASTOp("!",NULL,(ASTExpr*) $2);}   /* unary_op */
                
                | MINUS expr		%prec UMINUS			
                {$$ = new ASTOp("--",NULL,(ASTExpr*) $2);}   /* unary_op */
                
                | OPEN_PARANTHESIS expr CLOSE_PARANTHESIS 
		 {$$ = $2;}
		;

int_ast : INT_CONST { $$ = new ASTInt($1);};

expr_mult   : expr {
		      $$= new vector<ASTExpr *>;
	              $$->push_back((ASTExpr *)$1);
	      	   }
            | expr COMMA expr_mult
	      {
		      $$ = $3;
		      $$->push_back((ASTExpr *)$1);
	      }
	    ;


%%

void yyerror(const char *s) 
{
        cout<<"ERROR: "<<s<<endl;
            exit(-1);
}

