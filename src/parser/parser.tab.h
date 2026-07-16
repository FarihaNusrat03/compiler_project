/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     HEADER_DIRECTIVE = 258,
     KEYWORD_INT = 259,
     KEYWORD_FLOAT = 260,
     KEYWORD_BOOL = 261,
     KEYWORD_VOID = 262,
     KEYWORD_IF = 263,
     KEYWORD_ELSE = 264,
     KEYWORD_WHILE = 265,
     KEYWORD_FOR = 266,
     KEYWORD_RETURN = 267,
     KEYWORD_PRINT = 268,
     KEYWORD_PRINTF = 269,
     KEYWORD_COUT = 270,
     KEYWORD_ENDL = 271,
     CONST_INT = 272,
     CONST_FLOAT = 273,
     CONST_BOOL_TRUE = 274,
     CONST_BOOL_FALSE = 275,
     STRING_LITERAL = 276,
     IDENTIFIER = 277,
     ASSIGN = 278,
     OP_EQ = 279,
     OP_NEQ = 280,
     OP_LEQ = 281,
     OP_GEQ = 282,
     OP_AND = 283,
     OP_OR = 284,
     STREAM_INSERTION = 285,
     SEMICOLON = 286,
     COMMA = 287,
     LBRACE = 288,
     RBRACE = 289,
     LPAREN = 290,
     RPAREN = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1685 of yacc.c  */
#line 33 "src/parser/parser.y"

    char* string_val;
    class ASTNode* node;



/* Line 1685 of yacc.c  */
#line 94 "src/parser/parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


