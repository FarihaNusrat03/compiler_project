#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// Category of the declared symbol
enum SymbolKind {
    KIND_VARIABLE,
    KIND_FUNCTION
};

// Information stored for each symbol entry
struct SymbolInfo {
    string name;          // e.g., "x", "calculateSum"
    string type;          // e.g., "int", "float", "bool", "void"
    SymbolKind kind;      // KIND_VARIABLE or KIND_FUNCTION
    int line_declared;    // Line number in source code
    int scope_level;      // Scope depth (0 = global)
    vector<string> param_types; // For functions: parameter list types (e.g., {"int", "float"})
};

// Represents a single scope level
class ScopeTable {
public:
    int level;
    unordered_map<string, SymbolInfo*> symbols; // Storing pointers to prevent map rehash invalidation
    ScopeTable* parent;

    ScopeTable(int level, ScopeTable* parent = nullptr) 
        : level(level), parent(parent) {}

    ~ScopeTable() {
        // Free dynamically allocated SymbolInfo objects on scope destruction
        for (auto& pair : symbols) {
            delete pair.second;
        }
    }
};

// Main Symbol Table class supporting nested scopes
class SymbolTable {
private:
    ScopeTable* current_scope;
    int current_level;

public:
    SymbolTable();
    ~SymbolTable();

    // Scope navigation
    void enterScope();
    void exitScope();

    // Insertion & Lookup
    bool insert(const string& name, const string& type, SymbolKind kind, int line_no, vector<string> param_types = {});
    SymbolInfo* lookup(const string& name);
    SymbolInfo* lookupLocal(const string& name);

    // Debugging utility
    void printTable();
};

#endif // SYMBOL_TABLE_H