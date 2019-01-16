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

void generar_asm_archivo();
void apilar_pila_asm(char *);
void desapilar_pila_asm();
void format_ent_asm(char *,char *);
void ent_to_str(int , char* , int ) ;

int yystopparser=0;
FILE *yyin;
FILE *yyout;
FILE *asm_archivo;
FILE *asm_archivo_dos;
FILE *asm_final;
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
int ind_pil_asm=0;

typedef struct Dec {
	char nombreDato[31];
} Dec;
Dec pilaDec[200];

typedef struct{
char nodo[1000];
} nodo_pol;

nodo_pol pila_a_asm[1000];

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
programa: bloque											{ printf("Regla 0 - Compilacion OK\n");};

bloque : sentencia											{ printf("Regla 1 - bloque\n"); }
		|bloque sentencia									{ printf("Regla 2 - bloque\n"); };

sentencia:
		P_DECVAR dec_declaracion P_ENDDEC					{ printf("Regla 3 - Sentencia\n"); }
//		|P_DEFVAR def_declaracion P_ENDDEF					{ printf("Regla 4 - Sentencia\n"); }
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
																printf("Regla 12 - Declaracion DEC %s\n"); 
															}
		|dec_declaracion declaracion DOS_P tipo_dato	 	{ 
																insertarListaVariables(pilaDec, tipoDato, ult);
																printf("Regla 14 - Declaracion DEC %s\n"); 
															};


//def_declaracion:
//		declaracion	DOS_P tipo_dato							{ 
//																insertarListaVariables(pilaDec, tipoDato, ult);
//																printf("Regla 13 - Declaracion DEF %s\n"); 
//															}
//		|def_declaracion declaracion DOS_P tipo_dato	 	{ 
//																insertarListaVariables(pilaDec, tipoDato, ult);
//																printf("Regla 14 - Declaracion DEF %s\n"); 
//															};
		
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
int yyerror(voID)
{
	printf("Syntax Error\n");
	system ("Pause");
	exit (1);
}

void apilar_pila_asm(char *cad)
	{
		strcpy(pila_a_asm[ind_pil_asm].nodo,cad);
		ind_pil_asm++;
	}

void desapilar_pila_asm(char *tmp)
	{
		//char tmp[200];
		strcpy(tmp,pila_a_asm[ind_pil_asm-1].nodo);
		ind_pil_asm--;
	}

void ent_to_str(int num, char* str, int base) 
	{ 
		int i = 0; 
		int isNegative = 0; 
	  
		/* Handle 0 explicitely, otherwise empty string is printed for 0 */
		if (num == 0) 
		{ 
			str[i++] = '0'; 
			str[i] = '\0'; 
			return ; 
		} 
	  
		// In standard itoa(), negative numbers are handled only with  
		// base 10. Otherwise numbers are considered unsigned. 
		if (num < 0 && base == 10) 
		{ 
			isNegative = 1; 
			num = -num; 
		} 
	  
		// Process individual digits 
		while (num != 0) 
		{ 
			int rem = num % base; 
			str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
			num = num/base; 
		} 
	  
		// If number is negative, append '-' 
		if (isNegative == 1) 
			str[i++] = '-'; 
	  
		str[i] = '\0'; // Append string terminator 
	  
		// Reverse the string 
		strrev(str); 
		
	} 

void format_ent_asm(char *cad, char *var)
	{
		strcpy(cad,"_");
		strcat(cad,var);
	}

void generar_asm_archivo()
{
	if( !(tabla = fopen("ts.txt","r")))
		{
			printf("Error de creacion del archivo ts.txt ...");
			exit(0);
		}
int cont_cad_cte=0;
int cont_de_aux=0;

// Usamos asm_archivo para escribir el header de .data

fprintf(asm_archivo,"include macros2.asm \n");
fprintf(asm_archivo,"include number.asm \n");
fprintf(asm_archivo,"\n");
fprintf(asm_archivo,".model LARGE \n");
fprintf(asm_archivo,".386\n");
fprintf(asm_archivo,".stack 200h\n");
fprintf(asm_archivo,"\n");
fprintf(asm_archivo,".data\n");

rewind(tabla);
char linea[2000];
char straux[2000];
char *var;
char *tipo;
char *nombre;
char *len;
int longi;
char nomb[101];
char tip[31];

fprintf(asm_archivo,"salto_linea DB 13,10,\"$\" \n");
fprintf(asm_archivo,"aux_decla_var dd ?\n");
fprintf(asm_archivo,"_0in dd 0.0\n");
fprintf(asm_archivo,"_1in dd 1.0\n");
fprintf(asm_archivo,"aux_pos dd ?\n");
fprintf(asm_archivo,"e dd ?\n");
fprintf(asm_archivo,"true dd ?\n");
fprintf(asm_archivo,"false dd ?\n");
fprintf(asm_archivo,"aux dd ?\n");
int contador;

for(contador=0; contador < ultimo; contador++)
	{//fscanf(tabla,"%s",linea);
		//printf("%s \n", ts[contador].nombre);
		if(strcmp(ts[contador].tipo,"INT")==0)
			{
				//fprintf(asm_archivo,"%s dd ?\n",var);
				fprintf(asm_archivo,"%s dd ?\n",ts[contador].nombre);
			}

		if(strcmp(ts[contador].tipo,"FLOAT")==0)
			{
				fprintf(asm_archivo,"%s dd ?\n",ts[contador].nombre);
			}
		if(strcmp(ts[contador].tipo,"STRING")==0)
			{
				fprintf(asm_archivo,"%s dw ?\n",ts[contador].nombre);
			}
						
		if(strcmp(ts[contador].tipo,"CONST_INT")==0)
			{
				//format_ent_asm(straux,ts[contador].nombre);
				//strcat(ts[contador].nombre,".0");
				fprintf(asm_archivo,"%s dd %s\n",ts[contador].nombre, ts[contador].valor);
			}
		if(strcmp(ts[contador].tipo,"CONST_FLOAT")==0)
			{
				//format_ent_asm(straux,ts[contador].nombre);
				strcat(ts[contador].nombre,".0");
				fprintf(asm_archivo,"%s dd %s\n",straux,ts[contador].nombre);
			}
		if(strcmp(ts[contador].tipo,"CONST_STRING")==0)
			{
				char auxiliar[50];
				strcpy(auxiliar, ts[contador].nombre);
				//len=strtok(NULL,"|");
				//nombre=strtok(NULL,"|");
				char cadaux[50]="$";
				char c;
				//strcpy(cadaux,var);
				strrev(ts[contador].nombre);
				strcat(cadaux,ts[contador].nombre);
				c=cadaux[0];
				cadaux[0]=cadaux[1];
				cadaux[1]=c;
				strrev(cadaux);
				fprintf(asm_archivo,"%s db %s \n",auxiliar,cadaux);
				cont_cad_cte++;
			}

	}
fclose(tabla);
// Terminamos de escribir el header de .data

// Usamos asm_archivo_dos para escribir el .code

fprintf(asm_archivo_dos,"\n");
fprintf(asm_archivo_dos,".code\n");
fprintf(asm_archivo_dos,"start:\n");
fprintf(asm_archivo_dos,"\n");
fprintf(asm_archivo_dos,"\n");

// Levantamos las variables

fprintf(asm_archivo_dos,"\n");
fprintf(asm_archivo_dos,"mov ax,@data\n");
fprintf(asm_archivo_dos,"mov ds,ax\n");
fprintf(asm_archivo_dos,"mov es,ax\n");
fprintf(asm_archivo_dos,"\n");

// Inicio el coprocresar

fprintf(asm_archivo_dos,"FINIT\n");
fprintf(asm_archivo_dos,"FFREE\n");

// clear screen

fprintf(asm_archivo_dos,"\n");
fprintf(asm_archivo_dos,"mov ax,0003h \n");
fprintf(asm_archivo_dos,"int 10h\n");
fprintf(asm_archivo_dos,"\n");

// Empezamos a recorrer polaca

char oper1[200];
char oper2[200];
char nombre_aux[50];
char nombre_aux_cont[50];
int ind_aux=0;

	while(ind_aux < pos)
		{
			if(strcmp(instrucciones[ind_aux],"WRITE")==0)
				{
					desapilar_pila_asm(oper1);
					fprintf(asm_archivo_dos,"\n");
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
					//fprintf(asm_archivo_dos,"writeeee\n");
					fprintf(asm_archivo_dos,"DisplayFloat %s, 2\n",oper1);
					fprintf(asm_archivo_dos,"\n");
				}
				
			else	if(strcmp(instrucciones[ind_aux],"READ")==0)
				{
					desapilar_pila_asm(oper1);
					fprintf(asm_archivo_dos,"\n");
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
					//fprintf(asm_archivo_dos,"read\n");
					//printf("OPERADOR: %S", oper1);
					fprintf(asm_archivo_dos,"GetFloat %s, 2\n",oper1);
					fprintf(asm_archivo_dos,"\n");
						
				}
			else 	if(strcmp(instrucciones[ind_aux],"+")==0)
				{

					desapilar_pila_asm(oper2);
					desapilar_pila_asm(oper1);

					fprintf(asm_archivo_dos,"\n");
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux-2));
					//fprintf(asm_archivo_dos,"FFREE\n");
					if (buscarEnTSTipo(oper1) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper1);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper1);
					}
					
					if (buscarEnTSTipo(oper2) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper2);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper2);
					}
					fprintf(asm_archivo_dos,"FADD\n");
					fprintf(asm_archivo_dos,"FSTP @aux%d\n",cont_de_aux);
					fprintf(asm_archivo,"@aux%d dd ?\n",cont_de_aux);
					strcpy(nombre_aux,"@aux");
					ent_to_str(cont_de_aux,nombre_aux_cont,10);
					strcat(nombre_aux,nombre_aux_cont);
					apilar_pila_asm(nombre_aux);
					fprintf(asm_archivo_dos,"\n");
					cont_de_aux++;
					
					
				} 
			else 	if(strcmp(instrucciones[ind_aux],"-")==0)
				{
					desapilar_pila_asm(oper2);
					desapilar_pila_asm(oper1);
					fprintf(asm_archivo_dos,"\n");
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux-2));
					if (buscarEnTSTipo(oper1) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper1);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper1);
					}
					
					if (buscarEnTSTipo(oper2) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper2);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper2);
					}
					fprintf(asm_archivo_dos,"FSUB\n");
					fprintf(asm_archivo_dos,"FSTP @aux%d\n",cont_de_aux);
					fprintf(asm_archivo,"@aux%d dd ?\n",cont_de_aux);
					strcpy(nombre_aux,"@aux");
					ent_to_str(cont_de_aux,nombre_aux_cont,10);
					strcat(nombre_aux,nombre_aux_cont);
					apilar_pila_asm(nombre_aux);
					fprintf(asm_archivo_dos,"\n");
					cont_de_aux++;
				}
			else	if(strcmp(instrucciones[ind_aux],"*")==0)
				{
					desapilar_pila_asm(oper2);
					desapilar_pila_asm(oper1);
					fprintf(asm_archivo_dos,"\n");
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux-2));
					if (buscarEnTSTipo(oper1) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper1);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper1);
					}
					
					if (buscarEnTSTipo(oper2) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper2);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper2);
					}
					fprintf(asm_archivo_dos,"FMUL\n");
					fprintf(asm_archivo_dos,"FSTP @aux%d\n",cont_de_aux);
					fprintf(asm_archivo,"@aux%d dd ?\n",cont_de_aux);
					strcpy(nombre_aux,"@aux");
					ent_to_str(cont_de_aux,nombre_aux_cont,10);
					strcat(nombre_aux,nombre_aux_cont);
					apilar_pila_asm(nombre_aux);
					fprintf(asm_archivo_dos,"\n");
					cont_de_aux++;
				}
			else	if(strcmp(instrucciones[ind_aux],"/")==0)
				{
					desapilar_pila_asm(oper2);
					desapilar_pila_asm(oper1);
					
					fprintf(asm_archivo_dos,"\n");
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux-2));
					if (buscarEnTSTipo(oper1) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper1);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper1);
					}
					
					if (buscarEnTSTipo(oper2) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper2);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper2);
					}
					fprintf(asm_archivo_dos,"FDIV\n");
					fprintf(asm_archivo_dos,"FSTP @aux%d\n",cont_de_aux);
					fprintf(asm_archivo,"@aux%d dd ?\n",cont_de_aux);
					strcpy(nombre_aux,"@aux");
					ent_to_str(cont_de_aux,nombre_aux_cont,10);
					strcat(nombre_aux,nombre_aux_cont);
					apilar_pila_asm(nombre_aux);
					fprintf(asm_archivo_dos,"\n");
					cont_de_aux++;
				}
			else	if(strcmp(instrucciones[ind_aux],"=")==0)
				{
					desapilar_pila_asm(oper2);
					desapilar_pila_asm(oper1);
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux-2));
					//fprintf(asm_archivo_dos,"asignacion\n");
					if (buscarEnTSTipo(oper1) ==1)
					{
						
						fprintf(asm_archivo_dos,"FLD _%s\n",oper1);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper1);
					}

					if (buscarEnTSTipo(oper2) ==1)
					{
						
						fprintf(asm_archivo_dos, "FSTP _%s\n", oper2);
					}
					else
					{
						fprintf(asm_archivo_dos,"FSTP %s\n",oper2);
					}
					/*
					fprintf(asm_archivo_dos,"mov ax, %s\n",oper1);
					fprintf(asm_archivo_dos,"mov %s, ax\n",oper2);
					fprintf(asm_archivo_dos,"\n");*/
					
				}
			else	if(strcmp(instrucciones[ind_aux],"CMP")==0)
				{
					desapilar_pila_asm(oper2);
					desapilar_pila_asm(oper1);
					fprintf(asm_archivo_dos,"label%d:\n",(ind_aux-2));
					if (buscarEnTSTipo(oper1) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper1);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper1);
					}
					
					if (buscarEnTSTipo(oper2) ==1)
					{
						
						fprintf(asm_archivo_dos, "FLD _%s\n", oper2);
					}
					else
					{
						fprintf(asm_archivo_dos,"FLD %s\n",oper2);
					}
					fprintf(asm_archivo_dos,"FCOMP \n");
					fprintf(asm_archivo_dos,"FSTSW ax\n");
					fprintf(asm_archivo_dos,"FFREE st(0)\n");
					fprintf(asm_archivo_dos,"sahf\n"); 
					 
					fprintf(asm_archivo_dos,"\n");
				}
			else	if(strcmp(instrucciones[ind_aux],"BI")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"jmp label%s\n",instrucciones[ind_aux]-1);
				}
			else	if(strcmp(instrucciones[ind_aux],"BGT")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"jnbe label%s\n",instrucciones[ind_aux]);
				}
			else	if(strcmp(instrucciones[ind_aux],"BGE")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"jnb label%s\n",instrucciones[ind_aux]);
				}
			else	if(strcmp(instrucciones[ind_aux],"BLE")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"jna label%s\n",instrucciones[ind_aux]);
				}
			else	if(strcmp(instrucciones[ind_aux],"BLT")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"jnae label%s\n",instrucciones[ind_aux]);
				}
			else	if(strcmp(instrucciones[ind_aux],"BNE")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"jne label%s\n",instrucciones[ind_aux]);
				}
			else	if(strcmp(instrucciones[ind_aux],"BE")==0)
				{
						fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
						ind_aux++;
						fprintf(asm_archivo_dos,"je label%s\n",instrucciones[ind_aux]);
				}
			else	
				{
					apilar_pila_asm(instrucciones[ind_aux]);
				}
				
			ind_aux++;
		}

		// Terminamos el main
	fprintf(asm_archivo_dos,"\n");
	fprintf(asm_archivo_dos,"label%d:\n",(ind_aux));
	fprintf(asm_archivo_dos,"mov ax,4c00h\n");
	fprintf(asm_archivo_dos,"int 21h\n");
	fprintf(asm_archivo_dos,"jmp final_programa \n");
	fprintf(asm_archivo_dos,"\n");


	// Aca insertamos funciones
	fprintf(asm_archivo_dos,"\n");
	fprintf(asm_archivo_dos,"insertar_salto_linea:\n");
	fprintf(asm_archivo_dos,"mov ax,seg salto_linea\n");
	fprintf(asm_archivo_dos,"mov ds,ax \n");
	fprintf(asm_archivo_dos,"mov dx,offset salto_linea \n");
	fprintf(asm_archivo_dos,"mov ah,09 \n");
	fprintf(asm_archivo_dos,"int 21h \n");
	fprintf(asm_archivo_dos,"ret \n");
	fprintf(asm_archivo_dos,"\n");



	// Aca termina el programa
	fprintf(asm_archivo_dos,"\n");
	fprintf(asm_archivo_dos,"final_programa:\n");
	fprintf(asm_archivo_dos,"end start\n");
	fprintf(asm_archivo_dos,"\n");


	//Merge de archivos

	char a;
	rewind(asm_archivo);
	rewind(asm_archivo_dos);
	 // Copy contents of first file to file3.txt 
	   while ((a = fgetc(asm_archivo)) != EOF) 
		  fputc(a, asm_final); 
	  
	   // Copy contents of second file to file3.txt 
	   while ((a = fgetc(asm_archivo_dos)) != EOF) 
		  fputc(a, asm_final); 	  
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

	if ((asm_archivo=fopen("Final_1.asm","w+t")) == NULL) {
		printf("\nNo se puede abrir el archivo: Final_1.asm");
		return 2;
	} else {
		//printf("creo file1\n");
		//yyparse();
	}

	if ((asm_archivo_dos=fopen("Final_2.asm","w+t")) == NULL) {
		printf("\nNo se puede abrir el archivo: Final_2.asm");
		return 2;
	} else {
		//printf("creo file 2\n");
		//yyparse();
	}

	if ((asm_final=fopen("Final.asm","w+t")) == NULL) {
		printf("\nNo se puede abrir el archivo: Final.asm");
		return 2;
	} else {
		//printf("creo file final\n");
		//yyparse();
	}

	
	grabarPolaca();
	grabarTS();
	generar_asm_archivo();

	fclose(yyin);
	fclose(asm_archivo);
    fclose(asm_archivo_dos);
    fclose(asm_final);
	//fclose(yyout);
	return 0;
}


