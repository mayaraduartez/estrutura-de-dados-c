#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
   int valor;
   struct fila *prox;
}Fila;

Fila *inicio = NULL, *fim = NULL;
      
void insere_fila (int elemento)
{
	Fila *novo;

	novo = (Fila*) malloc (sizeof (Fila));//to transofrmando uma estrutura na memoria
	novo->valor = elemento;
	novo->prox = NULL;

    if (inicio == NULL){
		inicio = novo;//isso é para o primeiro elemento da fila
	}
	else{
		fim->prox = novo;//aponta para novo que criei, na linha 15,16,17
	}
	
	fim = novo;//aponta para o novo elemento no final da minha lista
}

void retira_fila (){
	Fila *aux = NULL;//criei o auxiliar para remover depois
	
    if (inicio == NULL)
 		   printf ("Fila esta vazia...");//quer dizer que nao tenho nada na fila

    else{
		aux = inicio;
	
		inicio = inicio->prox;//inicio aponta para o proxima estrutura
		if (inicio == NULL)
		    fim = NULL;//caso estiver apenas um elemento na lista
	    
    	free(aux);//liberando a memória q ele ta apontando
    }
}

void mostra_fila (){
	Fila *aux = inicio;//auxiliar para percorrer a fila
     
	while (aux != NULL){
		printf ("%d --> ", aux->valor);
		aux = aux->prox;
	}
}

int main(void) {
   int elemento;
   int opcao=-1;
   
   do{
		printf ("\n\n1 - Insere elemento na fila");
		printf ("\n2 - Retira elemento da fila");
		printf ("\n3 - Mostra fila");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao ?");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
				printf ("\nInforme valor: ");
				scanf ("%d", &elemento);
				insere_fila(elemento);
				mostra_fila();
				printf ("\n");
				break;
			case 2:
				retira_fila();
				mostra_fila();
				printf ("\n");
				break;
			case 3:
				mostra_fila();
				printf ("\n");
				break;
			}
	}while(opcao != 0);
	
}
