%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include "y.tab.h"
FILE *yyin;
FILE *yyout;

int linea = 1;
char errMsg[51];

#ifndef MAX_ID
#define MAX_ID 20
#endif

#ifndef MAX_STR
#define MAX_STR 31
#endif

%}
%option noyywrap  
%option yylineno 

DIGITO			[0-9]
LETRA			[a-zA-Z]
ID				{LETRA}({LETRA}|{DIGITO}|_)*
ESPACIO			[" "]
VAR_FLOAT		{LETRA}{DIGITO}({LETRA}|{DIGITO}|_)*
CONST_ENTERO	{DIGITO}+
CONST_FLOAT		{DIGITO}+"."{DIGITO}*|"."{DIGITO}+
CONST_STR	 	\"(\.|[^"])*\"
COMENTARIO1		--\/([^\/]|\/+[^-])*
COMENTARIO2 	-\/([^\/]|\/+[^-])*\/-

%%
"++"		{ return OP_ACUMULADOR;}
"["			{ return COR_A;}
"]"			{ return COR_C;}
"("			{ return PAR_A;}
")"			{ return PAR_C;}
"{"			{ return LLA_A;}
"}"			{ return LLA_C;}
";"			{ return PUNTO_COMA;}
","			{ return COMA;}
":"			{ return DOS_P;} 
"="			{ return OP_ASIG;}

"+"			{ return OP_SUM;}
"-"			{ return OP_RES;}
"*"			{ return OP_MULT;}
"/"			{ return OP_DIV;}

"AND"		{ return OP_LOG_OR;}
"OR"		{ return OP_LOG_AND;}

"<="		{ return OP_CMP_mI;}
">="		{ return OP_CMP_MI;}
"<"			{ return OP_CMP_m;}
">"			{ return OP_CMP_M;}
"=="		{ return OP_CMP_IGUAL;}
"=="		{ return OP_CMP_IGUAL;}

"WHILE"		{ return I_WHILE;}
"IF"		{ return I_IF;}
"ELSE"		{ return I_ELSE;}

"STRING"	{ return T_STRING;}
"FLOAT"		{ return T_FLOTANTE;}
"INT"		{ return T_ENTERO;}

"WRITE"		{ return P_WRITE;}
"READ"		{ return P_READ;}

"DECVAR"	{ return P_DECVAR;}
"ENDDEC"	{ return P_ENDDEC;}
"DEFVAR"	{ return P_DEFVAR;}
"ENDDEF"	{ return P_ENDDEF;}

"INLIST"	{ return P_INLIST;}
"BETWEEN"	{ return P_BETWEEN;}

{CONST_ENTERO}		{
						if( validarEntero(yytext) == 1 ) {
							sprintf(errMsg, "El entero \"%s\" se excede del limite (MIN: %d MAX: %d).\n", yytext, SHRT_MIN + 1, SHRT_MAX - 1);
							errorLexico(errMsg);
						} else {
							char aux_nombre[31];
							char aux_valor[30];
							sprintf(aux_nombre, "_%d", atoi(yytext));
							sprintf(aux_valor, "%d", atoi(yytext));
							
							if(buscarEnTS(aux_nombre) == -1) insertarEnTS(aux_nombre, "INT", aux_valor, "");
						}
						
						yylval.txtPtr = yytext;
						return C_ENTERO;
					}
{CONST_FLOAT}		{
						if( validarFlotante(yytext) == 1) {
							sprintf(errMsg, "El flotante \"%s\" se excede del limite (MIN: %E MAX: %E).\n", yytext, FLT_MIN, FLT_MAX);
							errorLexico(errMsg);
						} else {
							char aux_nombre[31];
							char aux_valor[30];
							sprintf(aux_nombre, "_%f", atof(yytext));
							sprintf(aux_valor, "%f", atof(yytext));
							
							if(buscarEnTS(aux_nombre) == -1) insertarEnTS(aux_nombre, "FLOAT", aux_valor, "");
						}
						yylval.txtPtr = yytext;
						return C_FLOTANTE;
					}
{CONST_STR}			{
						char aux_nombre[101];
						char aux_longitud[31];
						sprintf(aux_longitud, "%d\0", yyleng);
						sprintf(aux_nombre, "_%s\0", yytext);
						
						if(buscarEnTS(aux_nombre) == -1) insertarEnTS(aux_nombre, "STRING", yytext, aux_longitud);
						yylval.txtPtr = yytext;
						return C_CADENA;
					}
{ID}				{ 
						yylval.txtPtr = yytext;
						return ID;
					}
{COMENTARIO1}		{}
{COMENTARIO2}		{}

"\n"      		
"\t"		




