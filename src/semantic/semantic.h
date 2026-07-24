#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <iostream>
#include <string>
#include <vector>
#include "../ast/ast.h"
#include "../symbol_table/symbol_table.h"

using namespace std;

class SemanticAnalyzer {
private:
    SymbolTable symTable;
    int error_count;

    void reportError(const string& message);
    string getType(ASTNode* node);

    void visitProgram(ProgramNode* node);
    void visitVariableDecl(VariableDeclNode* node);
    void visitAssign(AssignNode* node);
    void visitFunction(FunctionNode* node);
    void visitBlock(BlockNode* node);
    void visitStatement(ASTNode* node);

public:
    SemanticAnalyzer();
    bool analyze(ASTNode* root);
    int getErrorCount() const { return error_count; }
};

#endif // SEMANTIC_H