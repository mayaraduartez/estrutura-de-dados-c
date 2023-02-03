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
	Nodo *novo, *aux1;
	
	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	aux1=inicio;

    if (inicio == NULL){
		inicio = novo;
		fim = novo;
	}else
	{
		while(aux1 != NULL && aux1->valor < novo->valor)
		{
			aux1 = aux1->prox;
		}
		if(aux1==NULL)
		  {
	  		fim->prox = novo;
	  		novo->ant = fim;
	  		fim = novo;
	 	  }
	 	 else if(aux1==inicio)
		  {
	  		aux1->ant = novo;
	  		novo->prox = aux1;
	  		inicio = novo;
	  	   }
	  	else
		  {
	  		aux1->ant->prox = novo;
	  		novo->ant = aux1->ant;
	  		aux1->ant = novo;
	  		novo->prox = aux1;
	  	  }
	}
}

void procurar (int elemento)
{
	Nodo *novo;
	Nodo *aux1;
	int posicao;
	
	aux1 = inicio;
	posicao = 1;
	
	while(aux1 != NULL && aux1->valor != elemento)
		{
			aux1 = aux1->prox;
			posicao++;
		}
			
		if(aux1 != NULL){
			printf("Seu elemento esta na posição %d", posicao);
		}else {
			printf("Esse elemento não esta na lista!");
  		   	}
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

void removern_maior (int elemento){
		Nodo *aux1;
	aux1 = fim;
	int i;
	
	for( i = 1; i<elemento; i++)
		aux1 = aux1->ant;
		
		remover(aux1->valor);
		
}

void removern_menor (int elemento){
	Nodo *aux1;
	int i;
	
	aux1 = inicio;
	
	for(i = 1; i<elemento; i++)
	{
		aux1= aux1->prox;	
	}
	
	remover(aux1->valor);
}

void trocar (int posicao1, int posicao2){
	Nodo *aux1,*aux2;
	int i, a, b;
	
	aux1=inicio;
	aux2=inicio;

	for( i = 1 ; i<posicao1 ;i++){
		aux1 = aux1->prox;
	}a = aux1->valor;
	
	for (i = 1; i<posicao2; i++){
		aux2= aux2->prox;
	}b= aux2->valor;
	
	aux2->valor=a;
	aux1->valor=b;
	
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
   int elemento;
   int opcao;
   
   int posicao1=0, posicao2=0;
   
   do{
		printf("\n1- Insere elemento na lista");
		printf("\n2- Procurar um elemento na lista");
		printf("\n3- Remover um elemento da lista");
		printf("\n4- Remover o n-esimo maior elemento da lista");
		printf("\n5- Remover o n-esimo menor elemento da lista");
		printf("\n6- Trocar elementos de posicao");
		printf("\n7- Mostrar lista do inicio");
		printf("\n8- Mostrar lista do fim");
		printf("\n0- Encerra programa");
		printf("\nEscolha uma opcao:");
	    scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nInforme um valor para a lista");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
			case 2:
				 printf("Qual valor deseja procurar?");
				 scanf("%d", &elemento);
				 procurar(elemento);
				 mostra_inicio();
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
					printf ("\nInforme qual n-esimo maior deseja remover: ");
					scanf ("%d", &elemento);
					removern_maior(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 5:
				if (inicio != NULL){
					printf ("\nInforme qual n-esimo menor deseja remover: ");
					scanf ("%d", &elemento);
					removern_menor(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 6:
				  printf("Qual a posicao deseja trocar?");
				  scanf("%d", &posicao1);
				  printf("Qual a segunda deseja trocar?");
				  scanf("%d", &posicao2);
				  trocar(posicao1,posicao2);
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
