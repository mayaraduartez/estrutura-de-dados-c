#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
   int valor;
   struct no *prox;
   struct no *ant;   
}Nodo;

typedef struct{
    Nodo *inicio;
    int tam;
}Lista;

Nodo *inicio = NULL, *fim = NULL;

void buscar(int elemento){
    Nodo *aux, *novo;
    int p=1;

    aux = inicio;
    while(aux != NULL && aux->valor != elemento){
        aux = aux->prox;
        p++;
    }
    printf("Ele tá na posicao: %d", p);
}


void insere (int elemento)
{
	Nodo *novo, *aux=inicio;
	

	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;


    if (inicio == NULL){
		inicio = novo;
		fim = novo;
	}else if(novo->valor < inicio->valor){//inserir se for menor q o inicio 
		aux->ant = novo;
		novo->prox = inicio;
		inicio = novo;		
	}
	else {//inserir no meio ou no final
		
		while(aux->prox && novo->valor > aux->prox->valor) 
			aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
			novo->ant = aux;
			aux= fim;
			fim = novo;
			
		}	
	fim = novo;
}




void procurar(int elemento){
	
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

void removemaior( int elemento){
	
	Nodo *aux;
	int i;
	aux = inicio;
	
		
	for(i =1; 1<elemento; i++){
		while(aux != NULL)
		aux = aux->prox;
	}
	
	remover(aux->valor);

	
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
		printf("\n2- Procurar elemento na lista");
		printf ("\n3 - Retira elemento da lista");
		printf("\n4- Remove nmaior");
		printf ("\n5 - Mostrar lista do inicio");
		printf ("\n6 - Mostrar lista do fim");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao? ");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nInforme valor a ser inserido: ");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
				
			case 2:
				printf("\nQual elemento deseja procurar?");
				scanf("%d", &elemento);
				buscar(elemento);
				break;
			case 3:
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
			case 4:
				print("qual nmaior deseja remover?");
				scanf("%d", &elemento);
				removemaior(elemento);
				break;
			case 5:
				if (inicio != NULL)
					mostra_inicio();
				else
					printf("Lista vazia...\n");	
				break;
			case 6:
				if (inicio != NULL)
					mostra_fim();
				else
					printf("Lista vazia...\n");
				break;
			
			}
	}while(opcao != 0);
	
}
