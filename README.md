Shikher Somal - 201201091
Ashish Kumar - 201202100

Files included:

1. tokens.l
2. parser.y
3. makefile
4. readme.txt

lex.l
This is the flex responsible for performing the lexical analysis. It uses regular expressions specified and corresponding token is generated. This token is then used by the parser and used to check for the grammar.


lex.y
The bison file which has the CFG. It uses grammar from the productions specified in the assignment.

Makefile
This file contains the code to run the flex and bison files together. It then generates the parser executable.


To compile and run the code:
1. Navigate to the directory containing the above 3 files
2. Run the command: make
3. Give the following command: ./lex input.decaf


Grammar not supported:
	-> Comments
	-> Dynamic declaration 
