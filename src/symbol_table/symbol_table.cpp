#include "symbol_table.h"

// Constructor: Initializes the symbol table with a global scope (Level 0)
SymbolTable::SymbolTable() {
    current_level = 0;
    current_scope = new ScopeTable(current_level, nullptr);
}

// Destructor: Cleans up dynamically allocated scope tables
SymbolTable::~SymbolTable() {
    while (current_scope != nullptr) {
        ScopeTable* temp = current_scope;
        current_scope = current_scope->parent;
        delete temp;
    }
}

// Enter a new nested scope (e.g., entering a function body, if block, or loop)
void SymbolTable::enterScope() {
    current_level++;
    ScopeTable* new_scope = new ScopeTable(current_level, current_scope);
    current_scope = new_scope;
}

// Exit current scope and revert to parent scope
void SymbolTable::exitScope() {
    if (current_scope->parent != nullptr) {
        ScopeTable* temp = current_scope;
        current_scope = current_scope->parent;
        current_level--;
        delete temp;
    }
}

// Insert a symbol into the CURRENT local scope only
bool SymbolTable::insert(const string& name, const string& type, SymbolKind kind, int line_no, vector<string> param_types) {
    // Check if identifier is already declared in the current scope
    if (current_scope->symbols.find(name) != current_scope->symbols.end()) {
        return false; // Error: Redeclaration in same scope
    }

    SymbolInfo* info = new SymbolInfo{name, type, kind, line_no, current_level, param_types};
    current_scope->symbols[name] = info;
    return true;
}

// Lookup symbol starting from current scope and walking up to parent scopes
SymbolInfo* SymbolTable::lookup(const string& name) {
    ScopeTable* scope = current_scope;
    while (scope != nullptr) {
        auto it = scope->symbols.find(name);
        if (it != scope->symbols.end()) {
            return it->second;
        }
        scope = scope->parent; // Walk up to enclosing scope
    }
    return nullptr; // Not found in any accessible scope
}

// Lookup symbol in ONLY the current local scope
SymbolInfo* SymbolTable::lookupLocal(const string& name) {
    auto it = current_scope->symbols.find(name);
    if (it != current_scope->symbols.end()) {
        return it->second;
    }
    return nullptr;
}

// Debug utility: Print all symbols across current scope chain
void SymbolTable::printTable() {
    cout << "\n=================== SYMBOL TABLE ===================\n";
    ScopeTable* scope = current_scope;
    while (scope != nullptr) {
        cout << "--- Scope Level " << scope->level << " ---\n";
        if (scope->symbols.empty()) {
            cout << "  (Empty scope)\n";
        } else {
            for (const auto& pair : scope->symbols) {
                const SymbolInfo* sym = pair.second;
                cout << "  Name: " << sym->name 
                     << " | Type: " << sym->type 
                     << " | Kind: " << (sym->kind == KIND_VARIABLE ? "VARIABLE" : "FUNCTION")
                     << " | Line: " << sym->line_declared;
                
                if (sym->kind == KIND_FUNCTION && !sym->param_types.empty()) {
                    cout << " | Params: (";
                    for (size_t i = 0; i < sym->param_types.size(); ++i) {
                        cout << sym->param_types[i] << (i + 1 < sym->param_types.size() ? ", " : "");
                    }
                    cout << ")";
                }
                cout << "\n";
            }
        }
        scope = scope->parent;
    }
    cout << "====================================================\n\n";
}