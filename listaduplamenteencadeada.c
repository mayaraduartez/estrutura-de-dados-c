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
	
	novo = (Nodo*) malloc (sizeof (Nodo));
	novo->valor = elemento;
	novo->prox = NULL;
	novo->ant = NULL;
	aux=inicio;

    if (inicio == NULL){
		inicio = novo;
		fim = novo;
	}else
	{
		while(aux != NULL && aux->valor < novo->valor)
		{
			aux = aux->prox;
		}
		if(aux==NULL)
		  {
	  		fim->prox = novo;
	  		novo->ant = fim;
	  		fim = novo;
	 	  }
	 	 else if(aux==inicio)
		  {
	  		aux->ant = novo;
	  		novo->prox = aux;
	  		inicio = novo;
	  	   }
	  	else
		  {
	  		aux->ant->prox = novo;
	  		novo->ant = aux->ant;
	  		aux->ant = novo;
	  		novo->prox = aux;
	  	  }
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
		}else {
			printf("Seu elemento esta na posição %d", c);
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

void removemaior (int elemento){
	Nodo *aux;
	aux = fim;
	int i;
	
	for( i = 1; i<elemento; i++)
		aux = aux->ant;
		
		remover(aux->valor);
	
}

void removemenor (int elemento){
	Nodo *aux;
	aux = inicio;
	int i;
	
	for(i = 1; i<elemento; i++){
		aux = aux->prox;
		
		
	}remover(aux->valor);
}

void troca (int p1, int p2){
	Nodo *aux1 = inicio, *aux2= inicio;
	int i, x, y;
	
	for( i = 1 ; i<p1 ;i++){
		aux1 = aux1->prox;
	}
	for (i = 1; i<p2; i++){
		aux2= aux2->prox;
	}
	
	
	
	x=aux1->valor;
	y=aux2->valor;
	aux1->valor=y;
	aux2->valor=x;
	
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
   int p1, p2;
   
   do{
		printf("\n1- Insere elemento na lista");
		printf("\n2- Procurar um elemento na lista");
		printf("\n3- Remover um elemento da lista");
		printf("\n4- Remover o n-ésimo maior elemento da lista");
		printf("\n5- Remover o n-ésimo menor elemento da lista");
		printf("\n6- Trocar elementos de posição");
		printf("\n7- Mostrar lista do inicio");
		printf("\n8- Mostrar lista do fim");
		printf("\n0- Encerra programa");
		printf("\nEscolha uma opcao:");
	    scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nInforme valor a ser inserido: ");
				scanf ("%d", &elemento);
				insere(elemento);
				mostra_inicio();
				break;
			case 2:
				 printf("Informe o valor que quer procurar: ");
				 scanf("%d", &elemento);
				 procura(elemento);
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
					printf ("\nInforme qual n-ésimo maior quer remover: ");
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
					printf ("\nInforme qual n-ésimo menor quer remover: ");
					scanf ("%d", &elemento);
					removemenor(elemento);
					if (inicio != NULL)
						mostra_inicio();
				}
				else
					printf("Lista vazia...\n");
				break;
			case 6:
				  printf("Qual a primeira deseja trocar?");
				  scanf("%d", &p1);
				  printf("Qual a segunda posição deseja trocar?");
				  scanf("%d", &p2);
				  troca(p1,p2);
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
