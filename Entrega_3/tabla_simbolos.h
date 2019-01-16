#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef TAM_TS
#define TAM_TS 1000
#endif
#ifndef TAM_LEXEMA
#define TAM_LEXEMA 100
#endif

typedef struct simbolo {
	char nombre[TAM_LEXEMA + 1];
 	char tipo[31];
 	char valor[40];
 	char longitud[31];
} simbolo;


	FILE * tabla;

simbolo ts[TAM_TS];
extern int ultimo=0;

int insertarEnTS(char *nombre, char *tipo, char *valor, char *longitud){
	if(ultimo == TAM_TS)
		return -1;
	strncpy(ts[ultimo].nombre, nombre, TAM_LEXEMA + 1);
	strncpy(ts[ultimo].tipo, tipo, 31);
	strncpy(ts[ultimo].valor, valor, 40);
    strncpy(ts[ultimo].longitud, longitud, 31);

	return ultimo++;
};

int buscarEnTS(char *nombre){
	int pos = 0;
	while(pos != ultimo){
		if(strcmp(nombre, ts[pos].nombre) == 0)
			return pos;
		pos++;
	}
	return -1;
};

int buscarEnTSTipo(char *nombre){
 int pos = 0;
 while(pos != ultimo){
	 if(strcmp(nombre, ts[pos].valor) ==0)
	 {
		 if(strcmp(ts[pos].tipo,"CONST_INT") == 0)
			   {
				   //printf("ENCONTRE CONST, CON VALOR %s \n", ts[pos].nombre);
				return 1;
			   }
		else
		{
			return 0;
		}
		
	 }
	 //printf("MI POS ES: %d \n", pos);
  pos++;

}
return 0;
};

void grabarTS(){
	int pos = 0;
	if( !(tabla = fopen("ts.txt","w"))){
		printf("Error de creacion del archivo ts.txt ...");
    	exit(0);
	}
	fprintf(tabla,"NOMBRE                  TIPO                                       VALOR	    LONGITUD      ZONA   \n");

	while(pos != ultimo){
	   	fprintf(tabla, " |%s                        ", ts[pos].nombre);
	   	fprintf(tabla, " |%s                      ", ts[pos].tipo);
	   	fprintf(tabla, " |%s                 ", ts[pos].valor);
		fprintf(tabla, " |%s               ", ts[pos].longitud);
		pos++;
		fprintf(tabla, "\n");
	}
	fclose(tabla);
};

void mostrarTS(){
	int pos = 0;
  	printf("NOMBRE\t\t\t\tTIPO\t\t\t\tVALOR\t\t\t\tLONGITUD\t\t\t\tZONA\n");
  	while(pos != ultimo){
	   	printf("%40s", ts[pos].nombre);
	   	printf("\t\t\t%40s", ts[pos].tipo);
	   	printf("\t\t\t%40s", ts[pos].valor);
		printf("\t\t\t%40s\n", ts[pos].longitud);
		pos++;
	}
};

char* getNombre(int pos){
	return (ts[pos].nombre);
};

char* getTipo(int pos){
	return (ts[pos].tipo);
};

char* getValor(int pos){
	return (ts[pos].valor);
};

char* getLongitud(int pos){
	return (ts[pos].longitud);
};

void borrarTiposDato(){
	ultimo = ultimo - 5;
};

int getCountTS(){
	return ultimo;
};