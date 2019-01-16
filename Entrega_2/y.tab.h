
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     ID = 258,
     OP_SUM = 259,
     OP_RES = 260,
     OP_MULT = 261,
     OP_DIV = 262,
     AND = 263,
     OR = 264,
     COR_A = 265,
     COR_C = 266,
     PAR_A = 267,
     PAR_C = 268,
     LLA_A = 269,
     LLA_C = 270,
     PUNTO_COMA = 271,
     COMA = 272,
     DOS_P = 273,
     OP_ASIG = 274,
     OP_ACUMULADOR = 275,
     OP_LOG_AND = 276,
     OP_LOG_OR = 277,
     I_WHILE = 278,
     I_END = 279,
     I_IF = 280,
     I_ELSE = 281,
     C_FLOTANTE = 282,
     C_CADENA = 283,
     C_ENTERO = 284,
     P_WRITE = 285,
     P_READ = 286,
     P_DECVAR = 287,
     P_ENDDEC = 288,
     P_DEFVAR = 289,
     P_ENDDEF = 290,
     P_INLIST = 291,
     P_BETWEEN = 292,
     OP_CMP_mI = 293,
     OP_CMP_MI = 294,
     OP_CMP_m = 295,
     OP_CMP_M = 296,
     OP_CMP_IGUAL = 297,
     T_ENTERO = 298,
     T_FLOTANTE = 299,
     T_STRING = 300
   };
#endif
/* Tokens.  */
#define ID 258
#define OP_SUM 259
#define OP_RES 260
#define OP_MULT 261
#define OP_DIV 262
#define AND 263
#define OR 264
#define COR_A 265
#define COR_C 266
#define PAR_A 267
#define PAR_C 268
#define LLA_A 269
#define LLA_C 270
#define PUNTO_COMA 271
#define COMA 272
#define DOS_P 273
#define OP_ASIG 274
#define OP_ACUMULADOR 275
#define OP_LOG_AND 276
#define OP_LOG_OR 277
#define I_WHILE 278
#define I_END 279
#define I_IF 280
#define I_ELSE 281
#define C_FLOTANTE 282
#define C_CADENA 283
#define C_ENTERO 284
#define P_WRITE 285
#define P_READ 286
#define P_DECVAR 287
#define P_ENDDEC 288
#define P_DEFVAR 289
#define P_ENDDEF 290
#define P_INLIST 291
#define P_BETWEEN 292
#define OP_CMP_mI 293
#define OP_CMP_MI 294
#define OP_CMP_m 295
#define OP_CMP_M 296
#define OP_CMP_IGUAL 297
#define T_ENTERO 298
#define T_FLOTANTE 299
#define T_STRING 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 51 "sintactico.y"

	int intVal;
	float floatVal;
	char *txtPtr;



/* Line 1676 of yacc.c  */
#line 150 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


