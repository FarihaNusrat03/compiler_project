#include "ast.h"

/* ==========================================================================
   GLOBAL AST MANAGEMENT
   ========================================================================== */

/* This global pointer holds the single root node of the parsed program.
   Once parser.y finishes successfully, it assigns the final ProgramNode here. */
ASTNode* global_ast_root = nullptr;