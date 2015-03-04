/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOLEAN = 258,
    FLOAT = 259,
    INT = 260,
    INT_CONST = 261,
    FLOAT_CONST = 262,
    STRING_CONST = 263,
    CHARACTER_CONST = 264,
    ID = 265,
    COMMENT = 266,
    SYN_ERR = 267,
    IF = 268,
    ELSE = 269,
    FOR = 270,
    RETURN = 271,
    BREAK = 272,
    CONTINUE = 273,
    NULL_TOKEN = 274,
    TRUE = 275,
    FALSE = 276,
    CLASS = 277,
    OPEN_BRACE = 278,
    CLOSE_BRACE = 279,
    SEMI_COLON = 280,
    BOOLEAN_CONST = 281,
    COMMA = 282,
    DOT = 283,
    OPEN_PARANTHESIS = 284,
    CLOSE_PARANTHESIS = 285,
    OPEN_SQR_BRACKET = 286,
    CLOSE_SQR_BRACKET = 287,
    VOID = 288,
    PLUS = 289,
    PLUS_PLUS = 290,
    MINUS = 291,
    MINUS_MINUS = 292,
    MULTIPLY = 293,
    DIVIDE = 294,
    MODULUS = 295,
    NOT_EQUAL = 296,
    NOT = 297,
    OR = 298,
    CALLOUT = 299,
    AND = 300,
    EQUAL_EQUAL = 301,
    EQUAL = 302,
    MIEQ = 303,
    PLEQ = 304,
    LESS_EQUAL = 305,
    LESS = 306,
    GREATER_EQUAL = 307,
    GREATER = 308,
    EOF_TOKEN = 309,
    UMINUS = 310,
    UPLUS = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 17 "parser.y" /* yacc.c:1909  */


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

#line 144 "parser.hpp" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
