#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
   int valor;
   struct no *prox;
   struct no *ant;   
}Nodo;

Nodo *inicio = NULL, *fim = NULL;

void inserenoinicio (int elemento){
	Nodo *novo, *aux; 
	
	novo = (Nodo*) malloc (sizeof (Nodo));
	
	if(novo){
		novo->valor = elemento;
		
		if(inicio == NULL){
		  inicio = novo;
		}
	    else{
	    	fim->ant = novo;
	    	novo->prox = fim;
		}
		fim = novo;
	}
	else {
		printf("Erro");
	}
}
      
void inserenofim (int elemento)
{
	Nodo *novo;

	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;

    if (inicio == NULL){
		inicio = novo;
	}
	else{
		fim->prox = novo;
		novo->ant = fim;
	}
	
	fim = novo;
}

void remover(int elemento){
	Nodo *aux;
	
	aux = inicio;
	
	while(aux != NULL && aux->valor != elemento){
		aux = aux->prox;	
	}
	
	if (aux == NULL)
		printf("Elemento nao esta na lista...\n");
	
	else{
		if (aux == inicio && aux == fim){
				inicio = fim = NULL;
		}
		
		else if (aux == inicio){
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		
		else if (aux == fim){
			fim = fim->ant;
			fim->prox = NULL;
		}
		
		else{
		aux->ant->prox = aux->prox;
		aux->prox->ant = aux->ant;
		}
		
		printf("Elemento %d removido!", aux->valor);
		free(aux);	
	}
	
}

void mostra_inicio (){
	Nodo *aux = inicio;
	
    printf("\n");
	printf("NULL <-- "); 
	while (aux != NULL){
		if ((aux == inicio && aux->prox == NULL) || aux == fim)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->prox;
	}
	printf("NULL "); 
	printf("\n");
}

void mostra_fim (){
	Nodo *aux = fim;
	
    printf("\n"); 
	printf("NULL <-- "); 
	while (aux != NULL){
		if ((aux == fim && aux->ant == NULL) || aux == inicio)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->ant;
	}
	printf("NULL "); 
	printf("\n");
}

int main(void) {
   int elemento;
   int opcao;
   
   
   do{
		printf ("\n1 - Insere elemento na lista");
		printf ("\n2 - Retira elemento da lista");
		printf ("\n3 - Mostrar lista do inicio");
		printf ("\n4 - Mostrar lista do fim");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nInforme valor a ser inserido: ");
				scanf ("%d", &elemento);
				inserenoinicio(elemento);
				mostra_inicio();
				break;
			case 2:
				if (inicio != NULL){
					printf ("\nInforme valor a ser removido: ");
					scanf ("%d", &elemento);
					remover(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 3:
				if (inicio != NULL)
					mostra_inicio();
				else
					printf("Lista vazia...\n");	
				break;
			case 4:
				if (inicio != NULL)
					mostra_fim();
				else
					printf("Lista vazia...\n");
				break;
			}
	}while(opcao != 0);
	
}
