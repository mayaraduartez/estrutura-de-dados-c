#include <stdio.h>
#include <stdlib.h>

typedef struct{
   int *valor;
   int inicio;
   int fim;
   int tam;
}Fila;
      
Fila insere_fila (Fila fila, int elemento){
	fila.fim++;
	fila.valor[fila.fim] = elemento;	
	
	return fila;
}

Fila retira_fila (Fila fila){
	int i;
	
    if (fila.fim == -1)
 		   printf ("Fila esta vazia...");
    else{
		for ( i = fila.inicio; i <= fila.fim; i++){
			fila.valor[i] = fila.valor[i+1];
		}
		fila.fim--;
    }
    return fila;
}

void mostra_fila (Fila fila){
	int i;
     
	for(i = fila.inicio; i <= fila.fim; i++){
		printf ("%d --> ", fila.valor[i]);
	}
	
}

int main(void) {	
	Fila fila;
	fila.inicio = 0;
	fila.fim = -1;
	
   int elemento;
   int opcao=-1;
   int tam;
   
   printf("Qual o tamanho maximo da fila? ");
   scanf("%d",&fila.tam);
   
   fila.valor = (int*) malloc (fila.tam * sizeof(int));
   
   do{
		printf ("\n\n1 - Insere elemento na fila");
		printf ("\n2 - Retira elemento da fila");
		printf ("\n3 - Mostra fila");
		printf ("\n0 - Encerra programa");
		printf ("\nOpcao ?");
		scanf ("%d", &opcao);
		
		switch (opcao){
			case 1:
				if (fila.fim == fila.tam-1){
					printf("\nFila Cheia!\n");
					break;
				}
				printf ("\nInforme valor: ");
				scanf ("%d", &elemento);
				fila = insere_fila(fila, elemento);
				mostra_fila(fila);
				printf ("\n\n");
				break;
			case 2:
				fila = retira_fila(fila);
				mostra_fila(fila);
				printf ("\n\n");
				break;
			case 3:
				mostra_fila(fila);
				printf ("\n\n");
				break;
			}
	}while(opcao != 0);
	
}
