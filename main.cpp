#include <iostream>
#include "codegen.h"
#include "node.h"
#include <cstdio>
#include <stdarg.h>

using namespace std;

extern int yyparse();
extern "C" FILE *yyin;
extern ASTProgram* init_start;

void createCoreFunctions(CodeGenContext& context);

int main(int argc, char *argv[]) {
        // open a file handle to a particular file:
        cout << argv[1] << endl;
        if(argc<2)
        {
                cout<<"Correct usage : ./project <input-file-name>\n";
                return -1;
        }


        char *filename;

        FILE *myfile = fopen(argv[1], "r");
        filename = argv[1];
        // make sure it is valid:
        if (!myfile) {
                cout << "Could not open .decaf file!" << endl;
                return -1;
        }
        // set flex to read from it instead of defaulting to STDIN:
        yyin = myfile;

        // parse through the input until there is no more:
        do {
                yyparse();
        } while (!feof(yyin));
	//cout << program << endl;
    // see http://comments.gmane.org/gmane.comp.compilers.llvm.devel/33877
	init_start->print();
	InitializeNativeTarget();
	CodeGenContext context;
	createCoreFunctions(context);
	context.generateCode(*init_start);
	context.runCode();
	
	return 0;

}
