%{
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "../ast/ast.h" // Include AST class blueprints to safely hook up tree generation

using namespace std;

/* 1. FLEX & BISON CONNECTION */

/* Calls the lexical analyzer to retrieve the next token. */
extern int yylex();

/* Current line number maintained by lexer.l for accurate syntax error reporting. */
extern int current_line;

/* Stores the current token text scanned by the lexer. */
extern char *yytext;

/* Input file pointer used by the lexer. */
extern FILE *yyin;

/* Syntax error handling function called automatically by Bison. */
void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error on Line %d: %s at token '%s'\n", current_line, s, yytext);
}

%}

/* Define the multi-type parsing stack to handle raw text strings and complex AST object allocations */
%union {
    char* string_val;
    class ASTNode* node;
}

/* 2. TOKEN DECLARATIONS */

/* Header File */
%token <string_val> HEADER_DIRECTIVE

/* Data Types */
%token <string_val> KEYWORD_INT
%token <string_val> KEYWORD_FLOAT
%token <string_val> KEYWORD_BOOL
%token KEYWORD_VOID

/* Control Statements */
%token KEYWORD_IF
%token KEYWORD_ELSE
%token KEYWORD_WHILE
%token KEYWORD_FOR

/* Function */
%token KEYWORD_RETURN

/* Output Statements */
%token KEYWORD_PRINT
%token KEYWORD_PRINTF
%token KEYWORD_COUT

/* Constants */
%token <string_val> CONST_INT
%token <string_val> CONST_FLOAT
%token <string_val> CONST_BOOL_TRUE
%token <string_val> CONST_BOOL_FALSE
%token <string_val> STRING_LITERAL

/* Identifier */
%token <string_val> IDENTIFIER

/* Operators */
%token ASSIGN
%token OP_EQ
%token OP_NEQ
%token OP_LEQ
%token OP_GEQ
%token OP_AND
%token OP_OR
%token STREAM_INSERTION

/* Delimiters */
%token SEMICOLON
%token COMMA
%token LBRACE
%token RBRACE
%token LPAREN
%token RPAREN

/* Assign precise AST class object types to all non-terminal grammar rules */
%type <node> program declaration_list declaration header_directive function
%type <node> variable_declaration variable_declaration_inline variable variable_list
%type <node> expression assignment_statement assignment_expression return_statement
%type <node> output_statement empty_statement block statement statement_list
%type <node> if_statement while_statement for_statement for_initialization
%type <node> parameter parameter_list
%type <string_val> type_specifier return_type

/* 3. START SYMBOL */

/* Parsing begins from the 'program' rule. */
%start program

%left OP_OR
%left OP_AND
%left OP_EQ OP_NEQ
%left OP_LEQ OP_GEQ '<' '>'
%left '+' '-'
%left '*' '/' '%'
%right '!'

%%
/* 4. PROGRAM STRUCTURE */

/* A program consists of one or more declarations. */
program
    : declaration_list { 
        $$ = $1; 
        global_ast_root = $$; // Catch the finished program compilation tree at the root element
    }
    ;

/* A declaration list can contain a single declaration
   or multiple declarations. */
declaration_list
    : declaration { 
        ProgramNode* prog = new ProgramNode(); 
        if ($1) prog->declarations.push_back($1); 
        $$ = prog; // Instantiate root tree vector storage for the first layout element
    }
    | declaration_list declaration { 
        ProgramNode* prog = (ProgramNode*)$1; 
        if ($2) prog->declarations.push_back($2); 
        $$ = prog; // Append sub-nodes sequentially into the root program vector list
    }
    ;

/* A declaration can be a header directive or variable declaration. */
declaration
    : header_directive          { $$ = $1; }
    | variable_declaration      { $$ = $1; }
    | function                  { $$ = $1; }
    ;

/* Header file declaration */
header_directive
    : HEADER_DIRECTIVE { 
        $$ = new HeaderNode($1); // Allocate a new HeaderNode object with its raw text content
    }
    ;

/* 5. DATA TYPES */

/* A type specifier defines the data type of a variable. */
type_specifier
    : KEYWORD_INT    { $$ = $1; }
    | KEYWORD_FLOAT  { $$ = $1; }
    | KEYWORD_BOOL   { $$ = $1; }
    ;

variable
    : IDENTIFIER { 
        $$ = new VariableNode($1); // Single unit structural variable instance allocation
    }
    | IDENTIFIER ASSIGN expression { 
        $$ = new AssignNode($1, $3); // Directly translate inline tracking initialization expressions
    }
    ;

return_type
    : type_specifier { $$ = $1; }
    | KEYWORD_VOID   { $$ = (char*)"void"; }
    ;

/* A list of variables separated by commas. */
variable_list
    : variable { 
        vector<ASTNode*>* list = new vector<ASTNode*>();
        if ($1) list->push_back($1);
        $$ = (ASTNode*)list; // Bundle standard vector configuration as a stack pass payload
    }
    | variable_list COMMA variable { 
        vector<ASTNode*>* list = (vector<ASTNode*>*)$1;
        if ($3) list->push_back($3);
        $$ = (ASTNode*)list; // Append additional inline variables to the existing allocation list
    }
    ;
    
variable_declaration
    : type_specifier variable_list SEMICOLON { 
        VariableDeclNode* decl = new VariableDeclNode($1);
        vector<ASTNode*>* list = (vector<ASTNode*>*)$2;
        if (list) {
            decl->variables = *list;
            delete list;
        }
        $$ = decl; // Flatten out the accumulated declaration items into a unified node object
    }
    ;

variable_declaration_inline
    : type_specifier variable_list { 
        VariableDeclNode* decl = new VariableDeclNode($1);
        vector<ASTNode*>* list = (vector<ASTNode*>*)$2;
        if (list) {
            decl->variables = *list;
            delete list;
        }
        $$ = decl; // Process inline declarations identically without trailing semicolons
    }
    ;

/* 6. EXPRESSIONS */

/* An expression can be a constant, identifier,
   or an arithmetic operation. */
expression
    : CONST_INT         { $$ = new ConstantNode($1, "INT"); }
    | CONST_FLOAT       { $$ = new ConstantNode($1, "FLOAT"); }
    | IDENTIFIER        { $$ = new VariableNode($1); }
    | CONST_BOOL_TRUE   { $$ = new ConstantNode($1, "BOOL"); }
    | CONST_BOOL_FALSE  { $$ = new ConstantNode($1, "BOOL"); }
    | LPAREN expression RPAREN { $$ = $2; } // Semicolons and parentheses are cleanly stripped out
    | expression '+' expression      { $$ = new BinaryOpNode("+", $1, $3); }
    | expression '-' expression      { $$ = new BinaryOpNode("-", $1, $3); }
    | expression '*' expression      { $$ = new BinaryOpNode("*", $1, $3); }
    | expression '/' expression      { $$ = new BinaryOpNode("/", $1, $3); }
    | expression '%' expression      { $$ = new BinaryOpNode("%", $1, $3); }
    | expression OP_EQ expression    { $$ = new BinaryOpNode("==", $1, $3); }
    | expression OP_NEQ expression   { $$ = new BinaryOpNode("!=", $1, $3); }
    | expression OP_LEQ expression   { $$ = new BinaryOpNode("<=", $1, $3); }
    | expression OP_GEQ expression   { $$ = new BinaryOpNode(">=", $1, $3); }
    | expression '<' expression      { $$ = new BinaryOpNode("<", $1, $3); }
    | expression '>' expression      { $$ = new BinaryOpNode(">", $1, $3); }
    | expression OP_AND expression   { $$ = new BinaryOpNode("&&", $1, $3); }
    | expression OP_OR expression    { $$ = new BinaryOpNode("||", $1, $3); }
    | '!' expression                 { $$ = new BinaryOpNode("!", $2, nullptr); } // Handled unary inversion through a binary variant layout
    | STRING_LITERAL    { $$ = new ConstantNode($1, "STRING"); }
    ;

/* An assignment assigns a value to a variable. */
assignment_statement
    : IDENTIFIER ASSIGN expression SEMICOLON { 
        $$ = new AssignNode($1, $3); // Allocate dynamic AssignNode values safely
    }
    ;

/* Assignment without semicolon used in loop control. */
assignment_expression
    : IDENTIFIER ASSIGN expression { 
        $$ = new AssignNode($1, $3); // Instantiate explicit standard control flow updates without semicolon checks
    }
    ;

/* A return statement sends a value back from a function. */
return_statement
    : KEYWORD_RETURN expression SEMICOLON  { $$ = new ReturnNode($2); }
    | KEYWORD_RETURN SEMICOLON             { $$ = new ReturnNode(nullptr); }
    ;

/* Output statements */
output_statement
    : KEYWORD_PRINT IDENTIFIER SEMICOLON { 
        $$ = new PrintNode("PRINT", new VariableNode($2)); // Handle raw standalone identifiers
    }
    | KEYWORD_PRINT LPAREN expression RPAREN SEMICOLON { 
        $$ = new PrintNode("PRINT", $3); // Route complete structured expressions
    }
    | KEYWORD_PRINTF LPAREN STRING_LITERAL COMMA expression RPAREN SEMICOLON { 
        $$ = new PrintNode("PRINTF", $5, $3); // Map the required string literal format tracking data explicitly
    }
    | KEYWORD_COUT STREAM_INSERTION expression SEMICOLON { 
        $$ = new PrintNode("COUT", $3); // Map standard C++ formatting channels directly
    }
    ;
    
empty_statement
    : SEMICOLON { $$ = nullptr; }
    ;

block
    : LBRACE statement_list RBRACE  { $$ = $2; }
    | LBRACE RBRACE                 { $$ = new BlockNode(); } // Handle blank braces gracefully by allocating an empty BlockNode
    ;

/* 7. STATEMENTS */

statement
    : variable_declaration  { $$ = $1; }
    | assignment_statement  { $$ = $1; }
    | return_statement      { $$ = $1; }
    | if_statement          { $$ = $1; }
    | while_statement       { $$ = $1; }
    | for_statement         { $$ = $1; }
    | output_statement      { $$ = $1; }
    | empty_statement       { $$ = $1; }
    | error SEMICOLON { yyerrok; $$ = nullptr; } /* Standard Bison syntax error recovery rule */
    ;

statement_list
    : statement { 
        BlockNode* blk = new BlockNode();
        if ($1) blk->statements.push_back($1);
        $$ = blk; // Initialize a scoped block node array layout to hold runtime rules
    }
    | statement_list statement { 
        BlockNode* blk = (BlockNode*)$1;
        if ($2) blk->statements.push_back($2);
        $$ = blk; // Accumulate execution sequences into the active block sequence list
    }
    ;

/* 8. CONTROL STATEMENTS */

/* If statement can have only if part or if-else part. */
if_statement
    : KEYWORD_IF LPAREN expression RPAREN block { 
        $$ = new IfNode($3, $5, nullptr); // Singular condition verification without alternative path execution
    }
    : KEYWORD_IF LPAREN expression RPAREN block KEYWORD_ELSE block { 
        $$ = new IfNode($3, $5, $7); // Complete binary branch target construction
    }
    ;

/* While loop repeats statements while condition is true. */
while_statement
    : KEYWORD_WHILE LPAREN expression RPAREN block { 
        $$ = new WhileNode($3, $5); 
    }
    ;

/* For loop contains initialization, condition,
   update expression, and body. */
for_initialization
    : variable_declaration_inline   { $$ = $1; }
    | assignment_expression         { $$ = $1; }
    | /* empty initialization */    { $$ = nullptr; }
    | %empty                        { $$ = nullptr; }
    ;

for_statement
    : KEYWORD_FOR LPAREN for_initialization SEMICOLON expression SEMICOLON assignment_expression RPAREN block { 
        $$ = new ForNode($3, $5, $7, $9); // Assemble all four components into a standard structured loop node
    }
    ;

/* 9. FUNCTION PARAMETERS */

/* Function parameters contain a data type and identifier. */
parameter
    : type_specifier IDENTIFIER { 
        $$ = new ParameterNode($1, $2); 
    }
    ;

/* Multiple parameters separated by commas. */
parameter_list
    : parameter { 
        vector<ASTNode*>* list = new vector<ASTNode*>();
        if ($1) list->push_back($1);
        $$ = (ASTNode*)list; // Handle list compilation payloads seamlessly
    }
    | parameter_list COMMA parameter { 
        vector<ASTNode*>* list = (vector<ASTNode*>*)$1;
        if ($3) list->push_back($3);
        $$ = (ASTNode*)list; // Append consecutive function variables safely
    }
    ;

function
    : return_type IDENTIFIER LPAREN parameter_list RPAREN block { 
        FunctionNode* func = new FunctionNode($1, $2, $6);
        vector<ASTNode*>* list = (vector<ASTNode*>*)$4;
        if (list) {
            func->parameters = *list;
            delete list;
        }
        $$ = func; // Instantiate complete signature blueprints for structured functional tracking objects
    }
    : return_type IDENTIFIER LPAREN RPAREN block { 
        $$ = new FunctionNode($1, $2, $5); // Simplify instantiation routines for parameterless scopes
    }
    ;