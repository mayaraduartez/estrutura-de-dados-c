#include <stdio.h>
#include <stdlin.h>

typedef struct fila{
	int valor;
	struct fila *prox;
}Fila;

Fila *inicio = NULL, *fim = NULL;

void insere_fila (int elemento){
	Fila *novo;
	
	novo = (Fila*) malloc (sizeof (Fila));]
	novo->valor = elemento;
	novo->prox = NULL;
	
	if(inicio = NULL){
		inicio = novo;
	}else{
		fim->prox = novo;
	}
	
	fim = novo;
}

void retira_fila(){
	Fila *aux = NULL;
	
	if(inicio = NULL){
		printf("A fila esta vazia")
	}else{
		aux = inicio;
		
		inicio = inicio->prox;
		if(inicio = NULL){
			fim = NULL;
		}
		
		free(aux);
	}
}

void mostra_fila(){
	Fila *aux = inicio;
	
	while(aux != NULL){
		printf("%d", aux->valor);
		aux = aux->prox;
	}
}
