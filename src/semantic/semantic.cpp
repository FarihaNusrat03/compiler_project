#include "semantic.h"

SemanticAnalyzer::SemanticAnalyzer() {
    error_count = 0;
}

void SemanticAnalyzer::reportError(const string& message) {
    cerr << "[Semantic Error] " << message << "\n";
    error_count++;
}

// Evaluates an expression node and returns its inferred data type
string SemanticAnalyzer::getType(ASTNode* node) {
    if (!node) return "unknown";

    if (ConstantNode* cn = dynamic_cast<ConstantNode*>(node)) {
        // Convert AST constant types (INT, BOOL, FLOAT) to match standard declaration types
        if (cn->type == "INT") return "int";
        if (cn->type == "BOOL") return "bool";
        if (cn->type == "FLOAT") return "float";
        if (cn->type == "STRING") return "string";
        return cn->type; 
    } 
    else if (VariableNode* vn = dynamic_cast<VariableNode*>(node)) {
      auto* sym = symTable.lookup(vn->name);
        return sym ? sym->type : "unknown";
    } 
    else if (BinaryOpNode* bn = dynamic_cast<BinaryOpNode*>(node)) {
        string leftType = getType(bn->left);
        string rightType = getType(bn->right);

        // Arithmetic operators return numeric types
        if (bn->op == "+" || bn->op == "-" || bn->op == "*" || bn->op == "/") {
            if (leftType == "float" || rightType == "float") return "float";
            return "int";
        }
        // Relational / Logical operators return boolean types
        if (bn->op == "==" || bn->op == "!=" || bn->op == "<" || 
            bn->op == ">" || bn->op == "<=" || bn->op == ">=" || 
            bn->op == "&&" || bn->op == "||") {
            return "bool";
        }
    }
    return "unknown";
}

bool SemanticAnalyzer::analyze(ASTNode* root) {
    if (!root) return false;

    ProgramNode* prog = dynamic_cast<ProgramNode*>(root);
    if (prog) {
        visitProgram(prog);
    } else {
        visitStatement(root);
    }

    // Print final Symbol Table state after analysis
    symTable.printTable();

    return (error_count == 0);
}

void SemanticAnalyzer::visitProgram(ProgramNode* node) {
    if (!node) return;

    for (ASTNode* decl : node->declarations) {
        visitStatement(decl);
    }
}

void SemanticAnalyzer::visitVariableDecl(VariableDeclNode* node) {
    if (!node) return;

    for (ASTNode* var_node : node->variables) {
        string var_name = "";
        ASTNode* initializer = nullptr;

        if (VariableNode* vn = dynamic_cast<VariableNode*>(var_node)) {
            var_name = vn->name;
        } else if (AssignNode* an = dynamic_cast<AssignNode*>(var_node)) {
            var_name = an->var_name;
            initializer = an->expression; // Uses 'expression' from ast.h
        }

        if (var_name.empty()) continue;

        // Check for redeclaration in current scope
        if (symTable.lookupLocal(var_name) != nullptr) {
            reportError("Redeclaration of variable '" + var_name + "' in the same scope.");
        } else {
            symTable.insert(var_name, node->type, KIND_VARIABLE, 0);
            cout << "[Semantic Check] Registered variable '" << var_name 
                 << "' (" << node->type << ")\n";
        }

        // Validate initializer expression if present
        if (initializer) {
            visitStatement(initializer);
            string exprType = getType(initializer);
            if (exprType != "unknown" && exprType != node->type) {
                reportError("Type Mismatch: Cannot assign '" + exprType + "' to '" + 
                            node->type + "' variable '" + var_name + "'.");
            }
        }
    }
}

void SemanticAnalyzer::visitAssign(AssignNode* node) {
    if (!node) return;

    if (node->expression) {
        visitStatement(node->expression);
    }

    // Use auto* to let C++ automatically detect the return type of lookup
    auto* sym = symTable.lookup(node->var_name);
    if (!sym) {
        reportError("Variable '" + node->var_name + "' used before declaration or out of scope.");
        return;
    }

    if (node->expression) {
        string rhsType = getType(node->expression);
        if (rhsType != "unknown" && sym->type != rhsType) {
            reportError("Type Mismatch: Cannot assign '" + rhsType + "' to '" + 
                        sym->type + "' variable '" + node->var_name + "'.");
        }
    }
}
void SemanticAnalyzer::visitFunction(FunctionNode* node) {
    if (!node) return;

    vector<string> param_types;
    for (ASTNode* p : node->parameters) {
        if (ParameterNode* param = dynamic_cast<ParameterNode*>(p)) {
            param_types.push_back(param->type);
        }
    }

    if (symTable.lookupLocal(node->name) != nullptr) {
        reportError("Redeclaration of function '" + node->name + "'.");
    } else {
        symTable.insert(node->name, node->return_type, KIND_FUNCTION, 0, param_types);
        cout << "[Semantic Check] Registered function '" << node->name << "()'\n";
    }

    // Open function body scope
    symTable.enterScope();

    for (ASTNode* p : node->parameters) {
        if (ParameterNode* param = dynamic_cast<ParameterNode*>(p)) {
            if (!symTable.insert(param->name, param->type, KIND_VARIABLE, 0)) {
                reportError("Duplicate parameter name '" + param->name + "' in function '" + node->name + "'.");
            }
        }
    }

    if (node->body) {
        if (BlockNode* block = dynamic_cast<BlockNode*>(node->body)) {
            visitBlock(block);
        } else {
            visitStatement(node->body);
        }
    }
    symTable.exitScope();
}

void SemanticAnalyzer::visitBlock(BlockNode* node) {
    if (!node) return;

    for (ASTNode* stmt : node->statements) {
        visitStatement(stmt);
    }
}

void SemanticAnalyzer::visitStatement(ASTNode* node) {
    if (!node) return;

    if (VariableDeclNode* varDecl = dynamic_cast<VariableDeclNode*>(node)) {
        visitVariableDecl(varDecl);
    } 
    else if (AssignNode* assignStmt = dynamic_cast<AssignNode*>(node)) {
        visitAssign(assignStmt);
    }
    else if (VariableNode* varNode = dynamic_cast<VariableNode*>(node)) {
        if (symTable.lookup(varNode->name) == nullptr) {
            reportError("Variable '" + varNode->name + "' used before declaration or out of scope.");
        }
    }
    else if (FunctionNode* funcDecl = dynamic_cast<FunctionNode*>(node)) {
        visitFunction(funcDecl);
    } 
    else if (BlockNode* blockDecl = dynamic_cast<BlockNode*>(node)) {
    symTable.enterScope();
    visitBlock(blockDecl);
    symTable.exitScope();
}
    else if (IfNode* ifStmt = dynamic_cast<IfNode*>(node)) {
        if (ifStmt->condition) visitStatement(ifStmt->condition);
        if (ifStmt->then_block) visitStatement(ifStmt->then_block);
        if (ifStmt->else_block) visitStatement(ifStmt->else_block);
    }
    else if (WhileNode* whileStmt = dynamic_cast<WhileNode*>(node)) {
        if (whileStmt->condition) visitStatement(whileStmt->condition);
        if (whileStmt->body) visitStatement(whileStmt->body);
    }
    else if (ForNode* forStmt = dynamic_cast<ForNode*>(node)) {
        symTable.enterScope();
        if (forStmt->initialization) visitStatement(forStmt->initialization);
        if (forStmt->condition) visitStatement(forStmt->condition);
        if (forStmt->update) visitStatement(forStmt->update);
        if (forStmt->body) visitStatement(forStmt->body);
        symTable.exitScope();
    }
    else if (BinaryOpNode* binOp = dynamic_cast<BinaryOpNode*>(node)) {
        visitStatement(binOp->left);
        visitStatement(binOp->right);
    }
}