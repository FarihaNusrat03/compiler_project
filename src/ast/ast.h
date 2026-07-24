#ifndef AST_H
#define AST_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* ==========================================================================
   1. BASE AST NODE
   ========================================================================== */

/* The fundamental base class that all other AST nodes inherit from. */
class ASTNode {
public:
    virtual ~ASTNode() = default;
    
    /* Prints the tree structure with nice text-based indentation. */
    virtual void print(int indent) = 0;
    
    /* Helper function to print spaces for the tree indentation depth. */
    void printIndent(int indent) {
        for (int i = 0; i < indent; ++i) {
            cout << "  ";
        }
    }
};

/* ==========================================================================
   2. HIGH LEVEL STRUCTURES (PROGRAM & HEADERS)
   ========================================================================== */

/* Represents the absolute root of your program, holding all top-level declarations. */
class ProgramNode : public ASTNode {
public:
    /* Holds the list of header directives, variable declarations, and functions. */
    vector<ASTNode*> declarations;

    ProgramNode() = default;
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[ProgramNode]\n";
        for (auto* decl : declarations) {
            if (decl) decl->print(indent + 1);
        }
    }
};

/* Header file declaration (e.g., #include <iostream>). */
class HeaderNode : public ASTNode {
public:
    /* Stores the raw text string of the header directive. */
    string header_text;

    HeaderNode(const string& text) : header_text(text) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[HeaderNode]: " << header_text << "\n";
    }
};

/* ==========================================================================
   3. DATA TYPES & VARIABLES
   ========================================================================== */

/* A variable declaration statement (e.g., int x, y = 10;). */
class VariableDeclNode : public ASTNode {
public:
    /* Stores the data type string: "int", "float", or "bool". */
    string type;
    
    /* Holds the individual variables or assignments being declared. */
    vector<ASTNode*> variables;

    VariableDeclNode(const string& t) : type(t) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[VariableDeclNode] Type: " << type << "\n";
        for (auto* var : variables) {
            if (var) var->print(indent + 1);
        }
    }
};

/* Represents a single variable identity reference by its name. */
class VariableNode : public ASTNode {
public:
    /* Stores the identifier name string (e.g., "x", "sum"). */
    string name;

    VariableNode(const string& n) : name(n) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[VariableNode]: " << name << "\n";
    }
};

/* ==========================================================================
   4. EXPRESSIONS (VALUES & OPERATORS)
   ========================================================================== */

/* Represents raw constant values (e.g., 5, 3.14, true, "hello"). */
class ConstantNode : public ASTNode {
public:
    /* The actual string representation of the value. */
    string value;
    
    /* The type category: "INT", "FLOAT", "BOOL", or "STRING". */
    string type;

    ConstantNode(const string& val, const string& t) : value(val), type(t) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[ConstantNode] (" << type << "): " << value << "\n";
    }
};

/* An arithmetic, relational, or logical calculation operation (e.g., x + 5, a == b). */
class BinaryOpNode : public ASTNode {
public:
    /* Stores the operation symbol string (e.g., "+", "-", "==", "<"). */
    string op;
    
    /* Pointer to the left-hand side expression node. */
    ASTNode* left;
    
    /* Pointer to the right-hand side expression node. */
    ASTNode* right;

    BinaryOpNode(const string& operation, ASTNode* l, ASTNode* r) 
        : op(operation), left(l), right(r) {}
        
    void print(int indent) override {
        printIndent(indent);
        cout << "[BinaryOpNode]: " << op << "\n";
        if (left) left->print(indent + 1);
        if (right) right->print(indent + 1);
    }
};

/* ==========================================================================
   5. STATEMENTS
   ========================================================================== */

/* An assignment statement that updates a variable's value (e.g., x = y + 5;). */
class AssignNode : public ASTNode {
public:
    /* Stores the target variable name string. */
    string var_name;
    
    /* Pointer to the expression node evaluating to the new value. */
    ASTNode* expression;

    AssignNode(const string& name, ASTNode* expr) : var_name(name), expression(expr) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[AssignNode]: " << var_name << " =\n";
        if (expression) expression->print(indent + 1);
    }
};

/* Output statements (handles print y;, printf("...", x); and cout << x;). */
class PrintNode : public ASTNode {
public:
    string print_type;
    string format_string; // Declared first
    ASTNode* target;      // Declared second

    // Initialized in exact order: print_type, format_string, target
    PrintNode(const string& type, ASTNode* tgt, const string& fmt = "") 
        : print_type(type), format_string(fmt), target(tgt) {} 
        
    void print(int indent) override {
        printIndent(indent);
        cout << "[PrintNode] (" << print_type << ")";
        if (!format_string.empty()) cout << " Format: " << format_string;
        cout << "\n";
        if (target) target->print(indent + 1);
    }
};

/* A compound block of codes wrapped securely inside braces { ... }. */
class BlockNode : public ASTNode {
public:
    /* A collection vector storing all statements parsed within the block scope. */
    vector<ASTNode*> statements;

    BlockNode() = default;
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[BlockNode]\n";
        for (auto* stmt : statements) {
            if (stmt) stmt->print(indent + 1);
        }
    }
};

/* ==========================================================================
   6. CONTROL STATEMENTS
   ========================================================================== */

/* If statement can have only if part or an optional if-else part. */
class IfNode : public ASTNode {
public:
    /* Pointer to the conditional evaluation rule expression branch. */
    ASTNode* condition;
    
    /* Pointer to the statement block executed if the evaluation is true. */
    ASTNode* then_block;
    
    /* Pointer to the statement block executed if alternative path is taken (nullable). */
    ASTNode* else_block;

    IfNode(ASTNode* cond, ASTNode* then_b, ASTNode* else_b = nullptr) 
        : condition(cond), then_block(then_b), else_block(else_b) {}
        
    void print(int indent) override {
        printIndent(indent);
        cout << "[IfNode]\n";
        printIndent(indent + 1); cout << "(Condition):\n";
        if (condition) condition->print(indent + 2);
        printIndent(indent + 1); cout << "(Then):\n";
        if (then_block) then_block->print(indent + 2);
        if (else_block) {
            printIndent(indent + 1); cout << "(Else):\n";
            else_block->print(indent + 2);
        }
    }
};

/* While loop repeats statements while a condition checks true. */
class WhileNode : public ASTNode {
public:
    /* Pointer to the conditional evaluation loop check loop. */
    ASTNode* condition;
    
    /* Pointer to the loop code execution body block. */
    ASTNode* body;

    WhileNode(ASTNode* cond, ASTNode* b) : condition(cond), body(b) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[WhileNode]\n";
        printIndent(indent + 1); cout << "(Condition):\n";
        if (condition) condition->print(indent + 2);
        printIndent(indent + 1); cout << "(Body):\n";
        if (body) body->print(indent + 2);
    }
};

/* For loop contains initialization, condition, update expression, and body. */
class ForNode : public ASTNode {
public:
    /* Pointer to loop variable declaration or initial assignment (nullable). */
    ASTNode* initialization;
    
    /* Pointer to loop boundary checker expression rule. */
    ASTNode* condition;
    
    /* Pointer to loop iterator update assignment modifier. */
    ASTNode* update;
    
    /* Pointer to the loop code execution body block. */
    ASTNode* body;

    ForNode(ASTNode* init, ASTNode* cond, ASTNode* upd, ASTNode* b) 
        : initialization(init), condition(cond), update(upd), body(b) {}
        
    void print(int indent) override {
        printIndent(indent);
        cout << "[ForNode]\n";
        if (initialization) {
            printIndent(indent + 1); cout << "(Init):\n";
            initialization->print(indent + 2);
        }
        if (condition) {
            printIndent(indent + 1); cout << "(Condition):\n";
            condition->print(indent + 2);
        }
        if (update) {
            printIndent(indent + 1); cout << "(Update):\n";
            update->print(indent + 2);
        }
        if (body) {
            printIndent(indent + 1); cout << "(Body):\n";
            body->print(indent + 2);
        }
    }
};

/* ==========================================================================
   7. FUNCTION PARAMETERS & SCHEMATICS
   ========================================================================== */

/* Function parameters contain a data type and an identifier name. */
class ParameterNode : public ASTNode {
public:
    /* Parameter type string label (e.g., "int", "float"). */
    string type;
    
    /* Parameter local lookup identifier variable name string. */
    string name;

    ParameterNode(const string& t, const string& n) : type(t), name(n) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[ParameterNode] Type: " << type << ", Name: " << name << "\n";
    }
};

/* Function blueprint definitions (contains return types, names, bounds, and blocks). */
class FunctionNode : public ASTNode {
public:
    /* Function global scope type configuration label ("int", "void"). */
    string return_type;
    
    /* Function entry execution label mapping name. */
    string name;
    
    /* Holds the ordered collection vector of input parameters rules. */
    vector<ASTNode*> parameters;
    
    /* Pointer to the function code execution body block. */
    ASTNode* body;

    FunctionNode(const string& r_type, const string& n, ASTNode* b) 
        : return_type(r_type), name(n), body(b) {}
        
    void print(int indent) override {
        printIndent(indent);
        cout << "[FunctionNode] Return: " << return_type << ", Name: " << name << "\n";
        if (!parameters.empty()) {
            printIndent(indent + 1); cout << "(Parameters):\n";
            for (auto* param : parameters) {
                if (param) param->print(indent + 2);
            }
        }
        printIndent(indent + 1); cout << "(Body):\n";
        if (body) body->print(indent + 2);
    }
};

/* A return statement sends an evaluated expression value back from a function. */
class ReturnNode : public ASTNode {
public:
    /* Pointer to evaluation payload expression (nullable if target is void function). */
    ASTNode* expression;

    ReturnNode(ASTNode* expr = nullptr) : expression(expr) {}
    
    void print(int indent) override {
        printIndent(indent);
        cout << "[ReturnNode]\n";
        if (expression) expression->print(indent + 1);
    }
};

#endif