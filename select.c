#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 500000   // constante que define o tamanho do vetor

int main(){

	int *vetor, i, j, aux, min;		//aux é a variável auxiliar para a troca de valores no vetor, min é a variável que armazena o menor valor do vetor
	long long int trocas = 0, comp = 0;   //trocas e comp são as variáveis para calcular o números de instruções do algoritmo.
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
    
    srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		   vetor[i] = rand()%100;
		   
	//printf ("** Vetor original ***\n\n{ ");
	
	//for(i=0; i<n; i++)
       printf ("%d  ", vetor[i]);
    
   	//printf ("}\n\n");
   	
   	
    tinicio = time(NULL);  	
    
    //Algoritmo Selection Sort
	for (i = 0; i < n-1; i++) 
  {
     min = i;
     for (j = (i+1); j < n; j++) {
     	comp++;
       if(vetor[j] < vetor[min]) 
         min = j;
     }
     if (i != min) {
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
       trocas++;
     }
  }
																
	tfim = time(NULL);
    tempo = (tfim - tinicio);
            
	// Fim
	
	//printf ("\n\n** Vetor ordenado ***\n\n{ ");
	
//	for(i=0; i<n; i++)
       printf ("%d ", vetor[i]);
    
   //printf ("}\n\n");
	
	
	printf("Numero de trocas = %lld \nNumero de comparacoes = %lld \n",trocas,comp);    // cálculo do número de instruções
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);
}
