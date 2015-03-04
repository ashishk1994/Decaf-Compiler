%{
	#include "node.h"
	#include	<iostream>
	#include	<sstream>
	#include 	<string>
	using namespace std;

	#include "parser.hpp"
	#define YY_DECL extern "C" int yylex()
//	#define TRACE_PROG
	#define TRACE(x) cout<<x<<endl ;
%}

%option noyywrap

DIGIT				[0-9]
ALPHA				[a-zA-Z_]
HEX_DIGIT		[0-9a-fA-F]
CHAR				([\40-\176]{-}['"\\])|\\n|\\t|\\\\|\\\"|\\\'
%%

null 			{return NULL_TOKEN;}
\,			{return COMMA;}

\+\+			{return PLUS_PLUS;}
\+			{return PLUS;}
\-			{return MINUS;}
\*			{return MULTIPLY;}
\=			{return EQUAL;}
\/			{return DIVIDE;}
\!			{return NOT;}
\<			{return LESS;}
\>			{return GREATER;}
\%			{return MODULUS;}
\;			{return SEMI_COLON;}
float			{return FLOAT;}
\(			{return OPEN_PARANTHESIS;}
\)			{return CLOSE_PARANTHESIS;}
\[			{return OPEN_SQR_BRACKET;}
\]			{return CLOSE_SQR_BRACKET;}


\{	{
		return OPEN_BRACE;
	}
\}	{
	return CLOSE_BRACE;
	}
boolean	{
	return BOOLEAN;
}
break	{
	return BREAK;
}
callout	{
	return CALLOUT;
}
class	{
	return CLASS;
}
continue	{
	return CONTINUE;
}
else	{
	return ELSE;
}
false	{
	return BOOLEAN;
}
for	{
	return FOR;
}
if	{
	return IF;
}
int	{
	return INT;
}
return	{
	return RETURN;
}
true	{
	return BOOLEAN_CONST;
}
void	{
	return VOID;
}
{ALPHA}({ALPHA}|{DIGIT})*	{
    yylval.name = yytext;
	return ID;	
}	
[0-9]+	{
    yylval.ival = atoi(yytext);
	return INT_CONST;
}
0x{DIGIT}+	{
	return INT_CONST;
}
\"{CHAR}*\"	{
	string a(yytext);
	strcpy(yylval.sval,a.substr(1,a.length()-2).c_str());
	return STRING_CONST;
}

\'{CHAR}\'	{
		yylval.ival=yytext[1];
		return CHARACTER_CONST;
}


\-\=	{
	return MIEQ;
}
\+\=	{
	return PLEQ;
}
\|\|	{
	return OR;
}
\&\&	{
	return AND;
}
\!\=	{
	return NOT_EQUAL;
}
\=\=	{
	return EQUAL_EQUAL;
}
\>\=	{
	return GREATER_EQUAL;
}
\<\=	{
	return LESS_EQUAL;
}
\/\/(.*?)\n	{
}
[\t\n\ ]	{
}
.	{
	TRACE(("ERROR: %s",yytext));
}



%%
