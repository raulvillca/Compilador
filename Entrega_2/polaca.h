
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char instrucciones[5000][30];
int posiciones[6] = {-1,-1,-1,-1,-1, -1};
int i = 0;
void insertarEnPolaca(char *token) {
	strncpy(instrucciones[i++], token, 30);
}

void guardarPosicion(int pos) {
	posiciones[pos] = i;
}

void desapilarSalto(int pos) {
	if (posiciones[pos] != -1) {
		sprintf(instrucciones[posiciones[pos]], "%d", i + 1);
	}
}

void resetearSalto(int pos, int valor) {
	posiciones[pos] = valor;
}

void grabarPolaca() {
	int pos = 0;
	int ultimo = i;
	FILE * polaca;
	if( !(polaca = fopen("polaca.txt","w"))){
		printf("Error de creacion del archivo polaca.txt ...");
    	exit(0);
	}
	
	while(pos != ultimo){
	   	fprintf(polaca, "%s ", instrucciones[pos]);
		pos++;
	}
	fclose(polaca);
}

