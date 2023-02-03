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
	Nodo *novo, *aux=inicio;
	

	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;


    if (inicio == NULL){
		inicio = novo;
		fim = novo;
	}else if(novo->valor < inicio->valor){
		aux->ant = novo;
		novo->prox = inicio;
		inicio = novo;		
	}
	else {
		
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

void remover (int elemento){
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

void removemaior( int elemento){
	
	Nodo *aux;
	int i;
	aux = inicio;
	
	if(inicio==NULL){
		printf("lista esta vazia");
	}else{
	for(i = 1; i<elemento; i++){
		aux = aux->prox;
		}
		remover(aux->valor);
 } 
}
	


void removemenor(int elemento){
	Nodo *aux;
	int i;
	aux = inicio;
	
		while(aux != NULL && aux->valor != elemento){
		aux = aux->prox;	
		}
	remover(aux->valor);
}

void trocar (int elemento, int elemento2){
	Nodo *aux1, *aux2;
	
	aux1=inicio;
	aux2=inicio;
	int i, d=0, m=0;
	
	for( i = 1 ; i<elemento ;i++){
		aux1 = aux1->prox;
	}
	for (i = 1; i<elemento2; i++){
		aux2= aux2->prox;
	}
	
	
	
	m=aux1->valor;
	d=aux2->valor;
	aux1->valor=d;
	aux2->valor=m;
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
	printf("NULL <-- ", fim); 
	while (aux != NULL){
		if ((aux->prox== NULL && aux->ant == NULL) || aux == inicio)
			printf ("%d --> ", aux->valor);
		else
			printf ("%d <--> ", aux->valor);	
		aux = aux->ant;
	}
	printf("NULL "); 
	printf("\n");
}

int main(void) {
   int elemento, elemento2;
   int opcao;
   
   
   do{
		printf("\n1- Insere elemento na lista");
		printf("\n2- Buscar um elemento na lista");
		printf("\n3- Remover um elemento da lista");
		printf("\n4- Remover o º maior elemento da lista");
		printf("\n5- Remover o º menor elemento da lista");
		printf("\n6- Trocar elementos de posição");
		printf("\n7- Mostrar lista do inicio");
		printf("\n8- Mostrar lista do fim");
		printf("\n0- Encerra programa");
		printf("\nEscolha uma opcao:");
	    scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nQual valor: ");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
			case 2:
				 printf("Qual valor procurar: ");
				 scanf("%d", &elemento);
				 buscar(elemento);
				 break;
			case 3:
				if (inicio != NULL){
					printf ("\nInforme valor a ser removido: ");
					scanf ("%d", &elemento);
					remover(elemento);
					mostra_inicio();
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 4:
				if (inicio != NULL){
					printf ("\nqual º maior valor a ser removido: ");
					scanf ("%d", &elemento);
					removemaior(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 5:
				if (inicio != NULL){
					printf ("\nqual º menor valor a ser removido: ");
					scanf ("%d", &elemento);
					removemenor(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 6:
				  printf("Qual a posicao?");
				  scanf("%d", &elemento);
				  printf("Qual a segunda ?");
				  scanf("%d", &elemento2);
				  trocar(elemento,elemento2);
				  mostra_inicio();
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
