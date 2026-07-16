%{
#include <iostream>
#include <cstdio>
#include <cstring>

#include "parser.tab.h" 

using namespace std;

int current_line = 1; 

//Simple safe custom duplicate function to completely bypass the Windows MinGW scope issue
char* custom_strdup(const char* src) {
    if (!src) return nullptr;
    char* dst = new char[strlen(src) + 1];
    strcpy(dst, src);
    return dst;
}
#define strdup custom_strdup
%}

%option noyywrap
%option never-interactive
%option nounput

%%

[ \t\r]+        { /* Discard spaces */ }
\n              { current_line++; }

"//".* { /* Discard comment */ }
"/*"([^*]|\n|\*+[^*/])*(\*+)?("*/") {
    for (int i = 0; yytext[i] != '\0'; i++) {
        if (yytext[i] == '\n') current_line++;
    }
}

"#include"[ \t]*"<"[a-zA-Z0-9_\.]+">" { yylval.string_val = strdup(yytext); return HEADER_DIRECTIVE; }

"int"           { yylval.string_val = strdup(yytext); return KEYWORD_INT; }
"float"         { yylval.string_val = strdup(yytext); return KEYWORD_FLOAT; }
"bool"          { yylval.string_val = strdup(yytext); return KEYWORD_BOOL; }
"void"          { return KEYWORD_VOID; }
"if"            { return KEYWORD_IF; }
"else"          { return KEYWORD_ELSE; }
"while"         { return KEYWORD_WHILE; }
"for"           { return KEYWORD_FOR; }
"return"        { return KEYWORD_RETURN; }

"print"         { return KEYWORD_PRINT; }
"printf"        { return KEYWORD_PRINTF; }
"cout"          { return KEYWORD_COUT; }
"endl"          { return KEYWORD_ENDL; }

"true"          { yylval.string_val = strdup(yytext); return CONST_BOOL_TRUE; }
"false"         { yylval.string_val = strdup(yytext); return CONST_BOOL_FALSE; }

[a-zA-Z_][a-zA-Z0-9_]* { yylval.string_val = strdup(yytext); return IDENTIFIER; }

[0-9]+\.[0-9]+      { yylval.string_val = strdup(yytext); return CONST_FLOAT; }
[0-9]+              { yylval.string_val = strdup(yytext); return CONST_INT; }
"\""[^\"]*"\""      { yylval.string_val = strdup(yytext); return STRING_LITERAL; }

"+"             { return '+'; }                
"-"             { return '-'; }               
"*"             { return '*'; }                
"/"             { return '/'; }                
"%"             { return '%'; }                

"=="            { return OP_EQ; }             
"!="            { return OP_NEQ; }            
"<="            { return OP_LEQ; }            
">="            { return OP_GEQ; }            
"<"             { return '<'; }                
">"             { return '>'; }                

"&&"            { return OP_AND; }            
"||"            { return OP_OR; }             
"!"             { return '!'; }                

"="             { return ASSIGN; }          
"<<"            { return STREAM_INSERTION; }

";"             { return SEMICOLON; }          
","             { return COMMA; }              
"{"             { return LBRACE; }             
"}"             { return RBRACE; }             
"("             { return LPAREN; }            
")"             { return RPAREN; }             

.               { printf("Lexical Error on Line %d: Unrecognized character token '%s'\n", current_line, yytext); }

%%