%{
#include <iostream>
#include <cstdio>
#include <cstdlib>

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
void yyerror(const char *s);

%}

/* 2. TOKEN DECLARATIONS */

/* Header File */
%token HEADER_DIRECTIVE

/* Data Types */
%token KEYWORD_INT
%token KEYWORD_FLOAT
%token KEYWORD_BOOL
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
%token CONST_INT
%token CONST_FLOAT
%token CONST_BOOL_TRUE
%token CONST_BOOL_FALSE
%token STRING_LITERAL

/* Identifier */
%token IDENTIFIER

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
    : declaration_list
    ;

/* A declaration list can contain a single declaration
   or multiple declarations. */
declaration_list
    : declaration
    | declaration_list declaration
    ;

/* A declaration can be a header directive or variable declaration. */
declaration
    : header_directive
    | variable_declaration
    | function
    ;
/* Header file declaration */
header_directive
    : HEADER_DIRECTIVE
    ;
/* 5. DATA TYPES */

/* A type specifier defines the data type of a variable. */
type_specifier
    : KEYWORD_INT
    | KEYWORD_FLOAT
    | KEYWORD_BOOL
    ;




variable
    : IDENTIFIER
    | IDENTIFIER ASSIGN expression
    ;

return_type
    : type_specifier
    | KEYWORD_VOID
    ;

/* A list of variables separated by commas. */
variable_list
    : variable
    | variable_list COMMA variable
    ;
    
variable_declaration
    : type_specifier variable_list SEMICOLON
    ;



/* 6. EXPRESSIONS */

/* An expression can be a constant, identifier,
   or an arithmetic operation. */
expression
    : CONST_INT
    | CONST_FLOAT
    | IDENTIFIER
    | CONST_BOOL_TRUE
    | CONST_BOOL_FALSE
    | LPAREN expression RPAREN
    | expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | expression '%' expression
    | expression OP_EQ expression
    | expression OP_NEQ expression
    | expression OP_LEQ expression
    | expression OP_GEQ expression
    | expression '<' expression
    | expression '>' expression
    | expression OP_AND expression
    | expression OP_OR expression
    | '!' expression
    | STRING_LITERAL
    ;
/* An assignment assigns a value to a variable. */
assignment_statement
    : IDENTIFIER ASSIGN expression SEMICOLON
    ;

/* Assignment without semicolon used in loop control. */
assignment_expression
    : IDENTIFIER ASSIGN expression
    ;


/* A return statement sends a value back from a function. */
return_statement
    : KEYWORD_RETURN expression SEMICOLON
    | KEYWORD_RETURN SEMICOLON
    ;

/* Output statements */
output_statement
    : KEYWORD_PRINTF LPAREN expression RPAREN SEMICOLON
    | KEYWORD_PRINT LPAREN expression RPAREN SEMICOLON
    | KEYWORD_COUT STREAM_INSERTION expression SEMICOLON
    ;
    
empty_statement
    : SEMICOLON
    ;

block
    : LBRACE statement_list RBRACE
    | LBRACE RBRACE
    ;

/* 7. STATEMENTS */

statement
    : variable_declaration
    | assignment_statement
    | return_statement
    | if_statement
    | while_statement
    | for_statement
    | output_statement
    | empty_statement
    ;
statement_list
    : statement
    | statement_list statement
    ;

/* 8. CONTROL STATEMENTS */

/* If statement can have only if part or if-else part. */
if_statement
    : KEYWORD_IF LPAREN expression RPAREN block
    | KEYWORD_IF LPAREN expression RPAREN block KEYWORD_ELSE block
    ;
/* While loop repeats statements while condition is true. */
while_statement
    : KEYWORD_WHILE LPAREN expression RPAREN block
    ;
/* For loop contains initialization, condition,
   update expression, and body. */
for_initialization
    : variable_declaration
    | assignment_expression
    ;
for_statement
    : KEYWORD_FOR LPAREN for_initialization SEMICOLON expression SEMICOLON assignment_expression RPAREN block
    ;

/* 9. FUNCTION PARAMETERS */

/* Function parameters contain a data type and identifier. */
parameter
    : type_specifier IDENTIFIER
    ;

/* Multiple parameters separated by commas. */
parameter_list
    : parameter
    | parameter_list COMMA parameter
    ;
function
    : return_type IDENTIFIER LPAREN parameter_list RPAREN block
    | return_type IDENTIFIER LPAREN RPAREN block
    ;