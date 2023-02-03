#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
   int valor;
   struct no *prox;
   struct no *ant;   
}Nodo;

Nodo *inicio = NULL, *fim = NULL;
      
void insere (int elemento)
{
	Nodo *novo, *aux;
	int num;

	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	
	
		if(incio == NULL){
			inicio = novo;
			fim = novo;
		}
		else if(novo->valor <= ->valor){
			novo->prox = elemento;
			
		}
		else{
			aux = *lista;
			while(aux->prox && novo->valor > aux->prox->valor)
				aux = aux->prox;
				novo->prox = aux->prox;
				aux->prox = novo;
		}
		
}


void procura (int elemento)
{
	Nodo *novo, *aux;
	int c = 1;
	
	aux = inicio;
	
	while(aux->valor != elemento && aux!= NULL){
			aux = aux->prox;
			c++;
		}
			
		if(aux == NULL){
			printf("Esse elemento não esta na lista...");
		}else if{
			printf("Seu elemento esta na posição %d", c);
 	}
}

void remove (int elemento){
	Nodo *aux;
	
	aux = inicio;
	
	while(aux != NULL && aux->valor != elemento){
		aux = aux->prox;	
	}
	
	if (aux == NULL){
		printf("Elemento nao esta na lista...\n");
	}
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

void removemaior (int elemento){
	Nodo *aux;
	aux = fim;
	int i;
	
	for( i = 1; i<elemento; i++){
		aux = aux->ant;
		
		remove(aux->valor);
	
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
	    printf("Escolha uma opção:");
	    scanf("%d", &opcao);
		printf("\n1- Insere elemento na lista");
		printf("\n2- Procurar um elemento na lista");
		printf("\n3- Remover um elemento da lista");
		printf("\n4- Remover o n-ésimo maior elemento da lista");
		printf("\n5- Remover o n-ésimo menor elemento da lista");
		printf("\n6- Trocar elementos de posição");
		printf("\n7- Mostrar lista do inicio");
		printf("\n8- Mostrar lista do fim");
		printf("\n0- Encerra programa");
		printf("\nOpcao? ");
		
		switch (opcao){
			case 1:
				printf("\nInforme valor a ser inserido: ");
				scanf("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
				
			case 2:
				 printf("Informe o valor que quer procurar: ");
				 scanf("%d", &elemento);
				 procura(elemento);
				 mostra inicio();
				 break;
				
			case 3:
				if (inicio != NULL){
					printf ("\nInforme valor a ser removido: ");
					scanf ("%d", &elemento);
					remove(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 7:
				if (inicio != NULL)
					mostra_inicio();
				else
					printf("Lista vazia...\n");	
				break;
			case 8:
				if (inicio != NULL)
					mostra_fim();
				else
					printf("Lista vazia...\n");
				break;
			}
	}while(opcao != 0);
	
}
