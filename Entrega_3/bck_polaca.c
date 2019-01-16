
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TAM_TS
#define TAM_TS 100
#endif

struct _nodo_polaca {
	int ind_TS;  /*solo para id y cte*/
	char token[50]; /*guarda el token si es un operador o una etiqueta*/
	int tipo;		/* 1 para operador, -1 para operados y 0 para etiquetas*/
	struct _nodo_polaca* sig;
};
typedef struct _nodo_polaca nodo_polaca;

typedef struct {
	int compuesta;
	int aux1;
	char comp1[3];
	int aux2;
	char comp2[3];
	char op_log[3];
} condicion_filter;


nodo_polaca* enlaza_nodo(nodo_polaca* tope, int, char*, int);
nodo_polaca* codigo_intermedio(void);
void genera_polaca(int, char*, int);
void verificaTipoDato();
int verificaOperacionDato(char*,char*,char*);

int pila[20];
int cola_id[50];
int cant_nodos_polaca = 0, tope_pila = 0, tope_cola = 0, fin_cola = 0, tope_pila_filter = 0;
condicion_filter pila_filter[20];
nodo_polaca* tope = NULL;

nodo_polaca* enlaza_nodo(nodo_polaca* tope,int _ind_TS, char* token, int tipo) {
	nodo_polaca* q = (nodo_polaca*)malloc(sizeof(nodo_polaca));
	nodo_polaca* act = tope;

	q->ind_TS = _ind_TS;
	strcpy(q->token, token);
	q->tipo = tipo;

	if(q == NULL) {
		printf("\n Error al crear un nodo para la polaca por falta de memoria\n");
		system("PAUSE");
		exit(1);
	}

	if(tope == NULL) {
		q->sig = NULL;
		return q;
	} else {
		while(act->sig != NULL) act = act->sig;

		q->sig = NULL;
		act->sig = q;
	}

	return tope;
}

void genera_polaca(int _ind_TS, char* token, int tipo)
{
	/*tipo es 1 para operadores, -1 para operandos y 0 para etiquetas que se deben pegar en el código*/
	int desapilado, num_nodo_act = 1, ind_etiq;
	nodo_polaca* act = tope;
	char etiqueta[10];

	if(!strcmp(token, "IF"))/*comienza if*/
	{
		pila[tope_pila++] = cant_nodos_polaca + 1;
		genera_polaca(0, " ", -1);
		genera_polaca(0, "BF", 1);

	} else if(!strcmp(token, "ELSE")) {
		desapilado = pila[--tope_pila];
		/*busco el nodo en la lista*/
		while(act && num_nodo_act != desapilado) {
			act = act->sig;
			num_nodo_act++;
		}

		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", cant_nodos_polaca + 3);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1) {
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta,"");;
		}
		act->ind_TS = ind_etiq;

		pila[tope_pila++] = cant_nodos_polaca + 1;

		genera_polaca(0, "", -1);
		genera_polaca(0, "JMP", 1);


		/*escribo etiqueta*/
		genera_polaca(0, etiqueta, 0);
	} else if(!strcmp(token, "ENDIF")) {
		desapilado = pila[--tope_pila];
		/*busco el nodo en la lista*/
		while(act && num_nodo_act != desapilado) {
			act = act->sig;
			num_nodo_act++;
		}

		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", cant_nodos_polaca + 1);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1) {
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta,"");;
		}
		act->ind_TS = ind_etiq;

		/*escribo etiqueta*/
		genera_polaca(0, etiqueta, 0);
	} else if(!strcmp(token, "WHILE")) {
		pila[tope_pila++] = cant_nodos_polaca + 1;
		/*dejo espacio para etiqueta*/
		genera_polaca(0, "", 0);
	} else if(!strcmp(token, "CONDICION")) {
		pila[tope_pila++] = cant_nodos_polaca + 1;
		genera_polaca(0, " ", -1);
		genera_polaca(0, "BF", 1);
	} else if(!strcmp(token, "ENDWHILE")) {
		int indexJump = pila[--tope_pila];
		desapilado = pila[--tope_pila];
		while(act && num_nodo_act != desapilado) {
			act = act->sig;
			num_nodo_act++;
		}
		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", desapilado);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1) {
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta, "");
		}
		strcpy(act->token, etiqueta);

		genera_polaca(ind_etiq, "", -1);
		genera_polaca(0, "JMP", 1);
		
		//etiqueta del final
		act = tope;
		num_nodo_act = 1;

		while(act && num_nodo_act != indexJump) {
			act = act->sig;
			num_nodo_act++;
		}
		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", indexJump);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1) {
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta, "");;
		}
		act->ind_TS=ind_etiq;

		genera_polaca(0, etiqueta, 0);
	} else if(!strcmp(token, "FIB")) {
	
	/***
	e1 := FIB(e3 * e1);
	 e1, _f_fib, e3, e1, *, :=, _a_fib, _0, :=, _c_fib, _a_fib, :=, _1, _f_fib, ==, _ETIQ60, BF, _b_fib, _1, :=, _c_fib, _b_fib, :=, _2, _f_fib, ==, _ETIQ59, BF, _i_fib, _2, :=, _ETIQ35, _c_fib, _a_fib, _b_fib, +, :=, _a_fib,_b_fib, :=, _b_fib,_c_fib, :=, _i_fib, _i_fib, _1, +, :=, _i_fib, _f_fib, ==, _ETIQ61, BF, _ETIQ35, JMP, _ETIQ59, _ETIQ60, _ETIQ61, _c_fib, :=, 
	***/
		int fib2;
		genera_polaca(0, ":=", 1); 
		fib2 = insertarEnTS("_a_fib", "INT", "", "");	
		genera_polaca(fib2, "", -1);
		fib2 = insertarEnTS("_0","ENTERO","0","");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, ":=", 1);
		fib2 = insertarEnTS("_c_fib", "INT", "", "");	
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_a_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, ":=", 1);
		fib2 = insertarEnTS("_1","ENTERO","1","");
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_f_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0,"!=", 1);
		//etiqueta
		pila[tope_pila++] = cant_nodos_polaca + 1;
		genera_polaca(0, " ", -1); //etiqueta al final
		genera_polaca(0, "BF", 1);
		
		fib2 = insertarEnTS("_b_fib", "INT", "", "");	
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_1");
		genera_polaca(fib2, "", -1);												
		genera_polaca(0, ":=", 1);
		fib2 = buscarEnTS("_c_fib");	
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_b_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, ":=", 1);
		fib2 = insertarEnTS("_2","ENTERO","2","");
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_f_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0,"!=", 1);
		
		//etiqueta
		pila[tope_pila++] = cant_nodos_polaca + 1;
		genera_polaca(0, " ", -1); //etiqueta al final
		genera_polaca(0, "BF", 1);
				
		fib2 = insertarEnTS("_i_fib", "INT", "", "");	
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_2");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, ":=", 1);
		
		//etiqueta
		pila[tope_pila++] = cant_nodos_polaca + 1;
		/*dejo espacio para etiqueta*/
		genera_polaca(0, "", 0);
		
					
		fib2 = insertarEnTS("_c_fib", "INT", "", "");	
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_a_fib");
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_b_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, "+", 1);
		genera_polaca(0, ":=", 1); 
		fib2 = buscarEnTS("_a_fib");
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_b_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, ":=", 1); 
		fib2 = buscarEnTS("_b_fib");
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_c_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, ":=", 1); 
		fib2 = buscarEnTS("_i_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_1");
		genera_polaca(fib2, "", -1);
		genera_polaca(0, "+", 1); 
		genera_polaca(0, ":=", 1); 
		fib2 = buscarEnTS("_i_fib");
		genera_polaca(fib2, "", -1);
		fib2 = buscarEnTS("_f_fib");
		genera_polaca(fib2, "", -1);
		genera_polaca(0,"!=", 1);
		//etiqueta
		pila[tope_pila++] = cant_nodos_polaca + 1;
		genera_polaca(0, " ", -1); //etiqueta al final
		genera_polaca(0, "BF", 1);
		
		int indexJump = pila[--tope_pila];
		desapilado = pila[--tope_pila];
		while(act && num_nodo_act != desapilado) {
			act = act->sig;
			num_nodo_act++;
		}
		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", desapilado);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1)
		{
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta, "");
		}
		strcpy(act->token, etiqueta);

		genera_polaca(ind_etiq, "", -1);
		genera_polaca(0, "JMP", 1);
		
		//1. etiqueta del final 
		act = tope;
		num_nodo_act = 1;
		desapilado = pila[--tope_pila];
		//busco el nodo en la lista
		while(act && num_nodo_act != desapilado)
		{
			act = act->sig;
			num_nodo_act++;
		}
		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", cant_nodos_polaca + 1);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1)
		{
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta,"");;
		}
		act->ind_TS = ind_etiq;
		//escribo etiqueta
		genera_polaca(0, etiqueta, 0);	
		
		//2. etiqueta del final
		act = tope;
		num_nodo_act = 1;
		desapilado = pila[--tope_pila];
		//busco el nodo en la lista
		while(act && num_nodo_act != desapilado)
		{
			act = act->sig;
			num_nodo_act++;
		}
		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", cant_nodos_polaca + 1);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1)
		{
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta,"");;
		}
		act->ind_TS = ind_etiq;
		//escribo etiqueta
		genera_polaca(0, etiqueta, 0);	
			
		//3. etiqueta del final 
		act = tope;
		num_nodo_act = 1;
		tope_pila=3;
		desapilado = pila[tope_pila++];
		//busco el nodo en la lista
		while(act && num_nodo_act != desapilado)
		{
			act = act->sig;
			num_nodo_act++;
		}
		memset(etiqueta, '\0', sizeof(etiqueta));
		sprintf(etiqueta, "_ETIQ%d", cant_nodos_polaca + 1);
		if((ind_etiq = buscarEnTS(etiqueta)) == -1)
		{
			ind_etiq = insertarEnTS(etiqueta, "ETIQUETA", etiqueta,"");;
		}
		act->ind_TS = ind_etiq;
		//escribo etiqueta
		genera_polaca(0, etiqueta, 0);	
		
		//me queda el resultado en _c_fib
		fib2 = buscarEnTS("_c_fib");
		genera_polaca(fib2, "", -1);
	
	}
	else if(!strcmp(token, "TAKE"))
	{
	}
	else
	{
		cant_nodos_polaca++;
		tope = enlaza_nodo(tope, _ind_TS, token, tipo);
	}
}


nodo_polaca* codigo_intermedio(void)
{
	FILE *pf;
	char* file_polaca = "Intermedia.txt";
	nodo_polaca* aux;

	if((pf = fopen(file_polaca, "w")) == NULL) { 
		printf("Error al grabar la polaca \n");
		exit(1);
	}
	
	while(tope) {
		if(tope->tipo == -1 && esCteSinNombre(tope->ind_TS)==1) {
			fprintf(pf, "%s, ", getValor(tope->ind_TS));
		} else if(tope->tipo == -1) {
			fprintf(pf, "%s, ", getNombre(tope->ind_TS));
		} else {
			printf(pf, "%s, ", tope->token);
		}
		aux = tope;
		tope = tope->sig;
		free(aux);
	}

	fclose(pf);
	return tope;
}
