%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <float.h>
#include "y.tab.h"
int yylval;
float yylval_float;
int yystopparser=0;
FILE  *yyin;
char *yyltext;
char *yytext;

typedef struct
{
	char nombre[31];
	char  tipo[30];
	char valor[30];
	char longitud[10];
}t_tablaS;

t_tablaS tablaSim;

%}
%token ID

%token AND
%token OR

%token DOS_P
%token OP_ASIG
%token OP_SUM
%token OP_RES
%token OP_MULT
%token OP_DIV

%token OP_ACUMULADOR
%token COR_A COR_C
%token PAR_A PAR_C
%token LLA_A LLA_C
%token PUNTO_COMA

%token OP_COMPARACION
%token OP_LOG_AND OP_LOG_OR

%token I_WHILE I_ENDW
%token I_FOR I_ENDFOR
%token I_IF I_ENDIF I_ELSE

%token P_FLOTANTE P_STRING P_ENTERO

%token P_WRITE
%token P_READ

%token P_DECVAR
%token P_ENDDEC
%token P_DEFVAR
%token P_ENDDEF
%token P_INLIST
%token P_BETWEEN

%token T_ENTERO T_FLOTANTE

%%
programa : bloque											{ printf("Compilacion OK - Regla 1\n"); };

bloque: 
		sentencia											{ printf("Bloque - Regla 2 \n"); }
		|bloque sentencia									{ printf("Bloque - Regla 3 \n"); };

sentencia:
		declaracion	PUNTO_COMA								{ printf("Sentencia - Regla 4 \n"); }
		|asignacion PUNTO_COMA								{ printf("Sentencia - Regla 5 \n"); }
		|iterador											{ printf("Sentencia - Regla 6 \n"); }
		|condicional										{ printf("Sentencia - Regla 7 \n"); };

declaracion:
		tipo_dato ID 		 								{ printf("Declaracion - Regla 8 \n"); };

tipo_dato: 
		T_ENTERO											{ printf("Tipo dato - Regla 10 \n"); }
		| T_FLOTANTE										{ printf("Tipo dato - Regla 11 \n"); }; 

asignacion:	
		ID OP_ASIG 											{ printf("Asignacion - Regla 12 \n"); };
		|asignacion expresion 								{ printf("Asignacion - Regla 13 \n"); }
		
iterador:
		I_WHILE condicion LLA_A bloque LLA_C 				{ printf("Iterador While - Regla 14\n");}
		|I_FOR asignacion PUNTO_COMA condicion PUNTO_COMA ID OP_ACUMULADOR LLA_A bloque LLA_C	{printf("Iterador for - Regla 15\n");};

condicional:
		I_IF condicion LLA_A bloque LLA_C					{ printf("Condicional IF - Regla 17\n"); }
		|I_IF condicion LLA_A bloque LLA_C I_ELSE LLA_A bloque LLA_C	{ printf("Condicional IF - Regla 18\n"); }
		
/***************************				****************************/

comparador:
		expresion OP_COMPARACION expresion					{ printf("Comparador - Regla 19\n"); };
		
condicion:
		comparador 											{ printf("Condicion - Regla 20\n");}
		|comparador OP_LOG_AND comparador					{ printf("Condicion - Regla 21\n");}
		|comparador OP_LOG_OR comparador					{ printf("Condicion - Regla 22\n");};

/***************************				*******************************/
expresion:	
		termino												{ printf("Expresion - Regla 23\n");}
		|expresion OP_SUM termino 							{ printf("Resta - Regla 24\n");}
		|expresion OP_RES termino  							{ printf("Suma - Regla 25\n");};

termino: 
		factor												{ printf("Factor - Regla 26\n");}
		|termino OP_MULT factor  							{ printf("Multiplicacion - Regla 27\n");}
		|termino OP_DIV factor 								{printf("Division - Regla 28\n");};

factor: 
		ID 													{ printf("ID - Regla 29\n");}
		|P_ENTERO 											{$1 = yylval; printf("ENTERO es: %d - Regla 30\n", yylval);}
		|P_FLOTANTE											{$1 = yylval_float ; printf("FLOTANTE es %f - Regla 31\n", yylval_float); }
		|PAR_A expresion PAR_C 								{ printf("( Expresion ) - Regla 32\n");};

%%
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


