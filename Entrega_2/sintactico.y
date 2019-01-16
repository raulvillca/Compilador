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
#include "polaca.h"
#include "tabla_simbolos.h"

extern YYSTYPE yylval;

int yystopparser=0;
FILE *yyin;
FILE *yyout;
char *yyltext;
char *yytext;
extern linea;
extern errMsg;

char tipoDato[31];
char valorDato[31];
char nombreDato[31];
char tipoDatoCons[31];
char opComparador[31];
char opCondicional[31];

typedef struct Dec {
	char nombreDato[31];
} Dec;
Dec pilaDec[200];

int ult, i, encontrado, contadorBetween = 0;

typedef struct Between {
	char result[31];
	char id[31];
	char min[31];
	char max[31];
} Between;

Between bt;

char p_result[31] = "aux", p_id[31] = "aux_id", p_inf[31] = "", p_sup[31] = "", aux[31] = "";

%}
%union{
	int intVal;
	float floatVal;
	char *txtPtr;
}

%token <txtPtr> ID
%token <txtPtr> OP_SUM OP_RES OP_MULT OP_DIV AND OR
%token COR_A COR_C PAR_A PAR_C LLA_A LLA_C
%token <txtPtr> PUNTO_COMA COMA DOS_P OP_ASIG OP_ACUMULADOR
%token <txtPtr> OP_LOG_AND OP_LOG_OR
%token I_WHILE I_END
%token I_IF I_ELSE
%token <txtPtr> C_FLOTANTE C_CADENA C_ENTERO
%token P_WRITE P_READ
%token P_DECVAR P_ENDDEC
%token P_DEFVAR P_ENDDEF
%token P_INLIST P_BETWEEN
%token <txtPtr> OP_CMP_mI OP_CMP_MI OP_CMP_m OP_CMP_M OP_CMP_IGUAL
%token <txtPtr> T_ENTERO T_FLOTANTE T_STRING

%type <txtPtr> expresion op_sum_res op_mult_div cmp id op_log
%type <txtPtr> P_WRITE P_READ 
%type <txtPtr> tipo_dato comparador termino factor

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
		id OP_ASIG expresion								{ 
																//verificar tipado e insertar valor
																printf("Regla 20 - Asignacion\n"); 
																insertarEnPolaca($2);
															};
id:
		ID													{ insertarEnPolaca($1);};
iterador:
		I_WHILE condicion LLA_A programa LLA_C 				{ 
																desapilarSalto(3);
																resetearSalto(3, -1);
																printf("Regla 21 - Iterador While\n");
															};

condicional:
		I_IF condicion LLA_A programa LLA_C					{ 
																desapilarSalto(3);
																desapilarSalto(4);
																
																resetearSalto(3, -1);
																resetearSalto(4, -1);
																printf("Regla 22 - Condicional IF\n"); 
															}
		|I_IF condicion LLA_A programa LLA_C else LLA_A programa LLA_C	{
																desapilarSalto(5);
																
																resetearSalto(5, -1);
																printf("Regla 23 - Condicional IF ELSE\n"); 
															};
else:
		I_ELSE 												{
																insertarEnPolaca("BI");
																guardarPosicion(5);
																insertarEnPolaca("_");
																
																desapilarSalto(3);
																desapilarSalto(4);
																
																resetearSalto(4, -1);
																resetearSalto(3, -1);
															};
		
b_between:
		P_BETWEEN PAR_A param_between COMA COR_A inferior COMA superior COR_C PAR_C	{ 
																				printf("Regla 24 - Between\n"); 
																				strncpy(p_inf, "", 31);
																				strncpy(p_sup, "", 31);
																				desapilarSalto(0);
																				desapilarSalto(1);
																			};
		
b_inList:
		P_INLIST PAR_A param_inList COMA COR_A lista COR_C PAR_C		{ printf("Regla 25 - InList\n"); };
		
b_write:
		P_WRITE C_CADENA									{ 
																insertarEnPolaca("WRITE");
																insertarEnPolaca($2);
																printf("Regla 26 - Write con constante\n");
															}
		|P_WRITE ID											{ 
																insertarEnPolaca("WRITE");
																insertarEnPolaca($2);
																printf("Regla 27 - Write\n");
															};

b_read:
		P_READ ID											{
																insertarEnPolaca("READ");
																insertarEnPolaca($2);
																printf("Regla 28 - Read\n");
															};
		
/***************************				****************************/

inferior:
		expresion											{
																insertarEnPolaca(p_id);
																insertarEnPolaca(p_inf);
																insertarEnPolaca("CMP");
																insertarEnPolaca("BGT");
																guardarPosicion(0);
																insertarEnPolaca("_");
															}
superior:
		expresion											{
																insertarEnPolaca(p_id);
																insertarEnPolaca(p_sup);
																insertarEnPolaca("CMP");
																insertarEnPolaca("BLT");
																guardarPosicion(1);
																insertarEnPolaca("_");
																insertarEnPolaca(p_result);
																insertarEnPolaca("true");
																insertarEnPolaca("=");
															}
param_inList:
		ID													{
																encontrado=0;
																strncpy(p_id, yylval.txtPtr, 31);
																insertarEnPolaca("aux_pos");
																insertarEnPolaca("false");
																insertarEnPolaca("=");
																insertarEnPolaca("aux");
																insertarEnPolaca($1);
																insertarEnPolaca("=");
															}
															
param_between:
		ID													{ 
																printf("Regla 29 - Parametro ID");
																contadorBetween = 0;
																insertarEnPolaca(p_result);
																insertarEnPolaca("false");
																insertarEnPolaca("=");
																insertarEnPolaca(p_id);
																insertarEnPolaca($1);
																insertarEnPolaca("=");
															}
lista:
		expresion											{ 
																insertarEnPolaca("e");
																insertarEnPolaca("=");
																insertarEnPolaca("aux");
																insertarEnPolaca("e");
																insertarEnPolaca("CMP");
																insertarEnPolaca("BNE");
																guardarPosicion(2);
																insertarEnPolaca("_l");
																insertarEnPolaca("aux_pos");
																insertarEnPolaca("true");
																insertarEnPolaca("=");
																desapilarSalto(2);
																
																printf("Regla 29 - Lista\n"); 
															}
		|lista PUNTO_COMA expresion							{ 
																printf("Regla 30 - Lista larga\n"); 
																insertarEnPolaca("e");
																insertarEnPolaca("=");
																insertarEnPolaca("aux");
																insertarEnPolaca("e");
																insertarEnPolaca("CMP");
																insertarEnPolaca("BNE");
																guardarPosicion(2);
																insertarEnPolaca("_l");
																insertarEnPolaca("aux_pos");
																insertarEnPolaca("true");
																insertarEnPolaca("=");
																desapilarSalto(2);
																
																printf("Regla 29 - Lista\n"); 
															};

comparador:
		expresion cmp expresion								{ 
																printf("Regla 31 - Comparador\n");
																
																insertarEnPolaca("CMP");
																insertarEnPolaca(opComparador);
																
															};

condicion:
		comparador											{ 
																guardarPosicion(3);
																insertarEnPolaca("_");
																printf("Regla 32 - Condicion\n");
															}
		|comparador op_log comparador						{ 
																guardarPosicion(4);
																insertarEnPolaca("_");
																if(strcmp(opCondicional, "OR") == 0) {
																	desapilarSalto(3);
																	resetearSalto(3, -1);
																}
																printf("Regla 33 - Condicion doble\n");
															};

op_log:
		OP_LOG_AND											{ 
																strncpy(opCondicional, "AND", 31);
																guardarPosicion(3);
																insertarEnPolaca("_");
																printf("Regla 34 - Operador Condicional\n");
															}
		| OP_LOG_OR											{ 
																strncpy(opCondicional, "OR", 31);
																guardarPosicion(3);
																insertarEnPolaca("_");
																printf("Regla 35 - Operador Condicional\n");
															};
/***************************				*******************************/

cmp:
		OP_CMP_mI 											{ strncpy(opComparador, "BGT", 31);}
		| OP_CMP_MI 										{ strncpy(opComparador, "BLT", 31);}
		| OP_CMP_m 											{ strncpy(opComparador, "BGE", 31);}
		| OP_CMP_M 											{ strncpy(opComparador, "BLE", 31);}
		| OP_CMP_IGUAL 										{ 
																strncpy(opComparador, "BNE", 31);
																printf("Regla 35 - Operador comparacion\n");
															};

expresion:	
		termino												{ 
																printf("Regla 36 - Expresion\n");
															}
		|expresion op_sum_res termino  						{ 
																printf("Regla 38 - expresion %s \n", $2);
																insertarEnPolaca($2);
															};
op_sum_res:
		OP_SUM
		| OP_RES
termino: 
		factor												{ printf("Regla 39 - Factor\n");}
		|termino op_mult_div factor  						{ 
																printf("Regla 40 - Multiplicacion\n");
																insertarEnPolaca($2);
															};
op_mult_div:
		OP_MULT
		| OP_DIV

factor: 
		ID 													{
																printf("Regla 42 - ID: %s\n", $1);
																insertarEnPolaca($1);
															}
		|C_ENTERO 											{
																printf("Regla 43 - ENTERO es: %s\n", yylval.txtPtr);
																insertarEnPolaca($1);
															}
		|C_FLOTANTE											{
																printf("Regla 44 - FLOTANTE es %s\n", yylval.txtPtr); 
																insertarEnPolaca($1);
															}
		|C_CADENA											{
																printf("Regla 45 - CADENA es %s\n", yylval.txtPtr);
																insertarEnPolaca($1);
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
	
	/*yyout = fopen("tokens_reconocidos.txt", "wt");

	if(yyout == NULL) {
		perror("Error al abrir el archivo de salida\n");
		return 1;
	}*/
	
	if ((yyin = fopen(argv[1], "rt")) == NULL) {
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
		return 2;
	} else {
		yyparse();
	}
	
	grabarPolaca();
	grabarTS();
	
	fclose(yyin);
	//fclose(yyout);
	return 0;
}

int yyerror(voID)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}


