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
#include "tabla_simbolos.h"

int yystopparser=0;
FILE  *yyin;
char *yyltext;
char *yytext;
extern linea;
extern errMsg;

char tipoDato[31];
char valorDato[31];
char nombreDato[31];
char tipoDatoCons[31];

typedef struct Dec {
	char nombreDato[31];
} Dec;
Dec pilaDec[200];

int ult, i;

%}
%union{
	int length;
	char texto[257];
	char *txtPtr;
}

%token ID

%token OP_SUM OP_RES OP_MULT OP_DIV AND OR

%token COR_A COR_C PAR_A PAR_C LLA_A LLA_C
%token PUNTO_COMA COMA DOS_P OP_ASIG OP_ACUMULADOR

%token OP_LOG_AND OP_LOG_OR

%token I_WHILE I_END
%token I_IF I_ELSE

%token C_FLOTANTE C_CADENA C_ENTERO

%token P_WRITE P_READ

%token P_DECVAR P_ENDDEC
%token P_DEFVAR P_ENDDEF
%token P_INLIST P_BETWEEN

%token OP_CMP_mI OP_CMP_MI OP_CMP_m OP_CMP_M OP_CMP_IGUAL

%token T_ENTERO T_FLOTANTE T_STRING

%%
programa : sentencia										{ printf("Regla 1 - Compilacion OK\n"); }
		|programa sentencia									{ printf("Regla 2 - programa\n"); };

sentencia:
		P_DECVAR dec_declaracion P_ENDDEC					{ printf("Regla 3 - Sentencia\n"); }
		|P_DEFVAR def_declaracion P_ENDDEF					{ printf("Regla 4 - Sentencia\n"); }
		|asignacion 										{ printf("Regla 5 - Sentencia\n"); }
		|iterador											{ printf("Regla 6 - Sentencia\n"); }
		|condicional										{ printf("Regla 7 - Sentencia\n"); }
		|b_between											{ printf("Regla 8 - Sentencia\n"); }
		|b_inList											{ printf("Regla 9 - Sentencia\n"); }
		|b_write											{ printf("Regla 10 - Sentencia\n"); }
		|b_read												{ printf("Regla 11 - Sentencia\n"); };
		
dec_declaracion:
		declaracion	DOS_P tipo_dato							{ 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 12 - Declaracion DEC\n"); 
															}

def_declaracion:
		declaracion	DOS_P tipo_dato							{ 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 13 - Declaracion DEF %s\n"); 
															}
		|def_declaracion declaracion DOS_P tipo_dato	 	{ 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 14 - Declaracion DEF %s\n"); 
															};
		
declaracion:
		ID						 							{ 
																//verificar si la variable ya existen en tabla
																ult = 0;
																strncpy(pilaDec[ult++].nombreDato, yylval.txtPtr, 31);
																printf("Regla 15 - Declaracion %s\n", yylval.txtPtr); 
															}
		|declaracion COMA ID								{ 
																strncpy(pilaDec[ult++].nombreDato, yylval.txtPtr, 31);
																printf("Regla 16 - Declaracion multiple %s\n", yylval.txtPtr); 
															};
															
tipo_dato: 
		T_ENTERO											{
																printf("Regla 17 - Tipo dato entero\n"); 
																strncpy(tipoDato, "INT", 31);
															}
		|T_STRING											{
																printf("Regla 18 - Tipo dato cadena\n"); 
																strncpy(tipoDato, "STRING", 31);
															}
		|T_FLOTANTE											{
																printf("Regla 19 - Tipo dato flotante\n"); 
																strncpy(tipoDato, "FLOAT", 31);
															}; 

asignacion:	
		ID OP_ASIG expresion								{ 
																//verificar tipado e insertar valor
																printf("Regla 20 - Asignacion\n"); 
															};
															
iterador:
		I_WHILE condicion LLA_A programa LLA_C 				{ printf("Regla 21 - Iterador While\n");};

condicional:
		I_IF condicion LLA_A programa LLA_C					{ printf("Regla 22 - Condicional IF\n"); }
		|I_IF condicion LLA_A programa LLA_C I_ELSE LLA_A programa LLA_C	{ printf("Regla 23 - Condicional IF ELSE\n"); };
		
b_between:
		P_BETWEEN PAR_A ID COMA COR_A expresion COMA expresion COR_C PAR_C	{ printf("Regla 24 - Between\n"); };
		
b_inList:
		P_INLIST PAR_A ID COMA COR_A lista COR_C PAR_C		{ printf("Regla 25 - InList\n"); };
		
b_write:
		P_WRITE C_CADENA									{ printf("Regla 26 - Write con constante\n");}
		|P_WRITE ID											{ printf("Regla 27 - Write\n");};

b_read:
		P_READ ID											{ printf("Regla 28 - Read\n");};
		
/***************************				****************************/

lista:
		expresion											{ printf("Regla 29 - Lista\n"); }
		|lista PUNTO_COMA expresion							{ printf("Regla 30 - Lista larga\n"); };

comparador:
		expresion cmp expresion								{ printf("Regla 31 - Comparador\n"); };
		
condicion:
		comparador											{ printf("Regla 32 - Condicion\n");}
		|comparador operador comparador						{ printf("Regla 33 - Condicion doble\n");};

/***************************				*******************************/

operador:
		OP_LOG_AND | OP_LOG_OR								{ printf("Regla 34 - Operador logico");}

cmp:
		OP_CMP_mI | OP_CMP_MI | OP_CMP_m | OP_CMP_M | OP_CMP_IGUAL 	{ printf("Regla 35 - Operador comparacion\n");};

expresion:	
		termino												{ printf("Regla 36 - Expresion\n");}
		|expresion OP_SUM termino 							{ printf("Regla 37 - Resta\n");}
		|expresion OP_RES termino  							{ printf("Regla 38 - Suma\n");};

termino: 
		factor												{ printf("Regla 39 - Factor\n");}
		|termino OP_MULT factor  							{ printf("Regla 40 - Multiplicacion\n");}
		|termino OP_DIV factor 								{ printf("Regla 41 - Division\n");};

factor: 
		ID 													{ printf("Regla 42 - ID: %s\n", yylval.txtPtr);}
		|C_ENTERO 											{
																strncpy(valorDato, yylval.txtPtr, 31);
																printf("Regla 43 - ENTERO es: %s\n", yylval.txtPtr);}
		|C_FLOTANTE											{
																strncpy(valorDato, yylval.txtPtr, 31);
																printf("Regla 44 - FLOTANTE es %s\n", yylval.txtPtr); }
		|C_CADENA											{
																strncpy(valorDato, yylval.txtPtr, 31);
																printf("Regla 45 - CADENA es %s\n", yylval.txtPtr); 
															}
		|PAR_A expresion PAR_C 								{ printf("Regla 46 - ( Expresion )\n");};

%%

/***********************************	FUNCIONES	**********************************/
int insertarListaVariables(Dec *pilaDec, char *tipo, int cantidad) {
	int i = 0;
	
	strncpy(tipoDato, tipo, 31);
	
	for(i = 0; i < cantidad; i++) {
		printf("%s ", pilaDec[i].nombreDato);
		insertarEnTS(pilaDec[i].nombreDato, tipoDato, "", "");
	}
	printf("de tipo %s\n", tipoDato);
	return i;
}

int errorLexico(char * msgErr) {
	printf("Lexical Error en linea %d: %s\n", linea, msgErr);
	system("Pause");
	exit(1);
}

int validarEntero(char *txt) {
	long int numero = strtol(txt, NULL, 10);
	//COTA MAXIMA: 32767 || COTA MINIMA: -32767  NOTA: Tmb habia que averiguarlo?
	if( numero >= SHRT_MAX -1 || numero <= SHRT_MIN +1 ) {
		return 1;
	}
	return 0;
}

int validarFlotante(char *txt) {
	float numero = strtof(txt, NULL);
	//COTA MINIMA: 1.175494E-038; COTA MAXIMA: 3.402823E+038
	if( numero < FLT_MIN || numero > FLT_MAX) {
		return 1;
	}
	return 0;
}

/***********************************	FIN FUNCIONES	**********************************/

int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
  }
  fclose(yyin);
  return 0;
}
int yyerror(voID)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}


