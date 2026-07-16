#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ast/ast.h" // Lets us access the AST node blueprints and printing tools

using namespace std;

/* Link the Bison parser logic tool */
extern int yyparse();

/* Link the global file pointer stream used by the Flex lexer */
extern FILE* yyin;

/* Link the global AST root tracking pointer we created in ast.cpp */
extern ASTNode* global_ast_root;

int main(int argc, char* argv[]) {
    // 1. Open your code test file (input.txt) in read-only mode
    FILE* infile = fopen("input.txt", "r");
    if (!infile) {
        cerr << "Error: Could not open input.txt file!\n";
        return 1;
    }

    // 2. Tell the lexer to read text from input.txt instead of the console terminal
    yyin = infile;

    cout << "=======================================\n";
    cout << "         Starting Compiler Parser      \n";
    cout << "=======================================\n";

    // 3. Trigger the parser to analyze the tokens and build the AST structures
    int parse_result = yyparse();

    // 4. Close the file stream since we are done reading
    fclose(infile);

    // 5. Check if the parser encountered any syntax rule breakages
    if (parse_result == 0) {
        cout << "\nParsing completed successfully!\n\n";
        
        // Ensure our Abstract Syntax Tree root node exists before trying to print it
        if (global_ast_root) {
            cout << "=======================================\n";
            cout << "       Abstract Syntax Tree (AST)      \n";
            cout << "=======================================\n";
            
            // Print the completely stripped tree layout starting with 0 indent spaces
            global_ast_root->print(0);
            
            cout << "=======================================\n";
        } else {
            cout << "Warning: Parsing succeeded but no AST root was generated.\n";
        }
    } else {
        cerr << "\nParsing failed due to syntax errors.\n";
        return 1;
    }

    return 0;
}