#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "ast/ast.h" // Lets us access the AST node blueprints and printing tools
#include "semantic/semantic.h" // <-- UPDATE 1: Added semantic header here!
using namespace std;

/* Link the Bison parser logic tool */
extern int yyparse();

/* Link the global file pointer stream used by the Flex lexer */
extern FILE* yyin;

/* Link the global AST root tracking pointer we created in ast.cpp */
extern ASTNode* global_ast_root;

/* Access the lexical error counter from lexer.l */
extern int lexical_error_count;
extern int syntax_error_count;

int main(int argc, char* argv[]) {

    if (argc > 1) {
        yyin = fopen(argv[1], "r");

        if (!yyin) {
            cerr << "Error: Could not open file!\n";
            return 1;
        }
    }

    cout << "=======================================\n";
    cout << "         Starting Compiler Parser      \n";
    cout << "=======================================\n";

    int parse_result = yyparse();

    if (yyin)
        fclose(yyin);

    // 5. Check for both syntax errors AND lexical errors
    if (parse_result == 0 && lexical_error_count == 0 && syntax_error_count == 0) {
        cout << "\nParsing completed successfully!\n\n";
        
        // Ensure our Abstract Syntax Tree root node exists before trying to print it
        if (global_ast_root) {
            cout << "=======================================\n";
            cout << "       Abstract Syntax Tree (AST)      \n";
            cout << "=======================================\n";
            
            // Print the completely stripped tree layout starting with 0 indent spaces
            global_ast_root->print(0);
            
            cout << "=======================================\n";
        
        cout << "\n=======================================\n";
            cout << "           Semantic Analysis           \n";
            cout << "=======================================\n";

            SemanticAnalyzer analyzer;
            bool success = analyzer.analyze(global_ast_root);

            if (success) {
                cout << "\nSemantic Analysis Passed with 0 Errors!\n";
            } else {
                cout << "\nSemantic Analysis Failed with " << analyzer.getErrorCount() << " error(s).\n";
            }
        
        
        } else {
            cout << "Warning: Parsing succeeded but no AST root was generated.\n";
        }
    } else {
        cerr << "\nParsing failed due to errors.\n";
        return 1;
    }

    return 0;
}