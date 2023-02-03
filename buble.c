#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10     // constante que define o tamanho do vetor

int main(){

	int *vetor, i, j, aux, k = n;  	//aux é a variável auxiliar para a troca de valores no vetor 
	long long int trocas = 0, comp = 0;	//trocas e comp são as variáveis para calcular o números de instruções do algoritmo.  
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
																		
	srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		   vetor[i] = rand()%100;
		   
	printf ("** Vetor original ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d  ", vetor[i]);
    
   	printf ("}\n\n");
   	
   	
     tinicio = time(NULL);  	
    
	// Algoritmo Bubble Sort
	for (i=0;i<n;i++){
	   for (j=0;j<k-1;j++){
	   	    comp++;							//incrementa a variável de contagem de comparações
	        if (vetor[j] > vetor[j+1]){		// compara se um elemento é maior do que o subsequente, se for, realiza a troca
			 aux = vetor[j];
			 vetor[j]= vetor[j+1];
			 vetor[j+1] = aux;
			 trocas++;						// incrementa a variável de contagem de trocas
		   }	
		}
		k--; 					// otimização do bubble sorte para a cada iteração reduzir em 1 o tamanho do vetor a ser ordenado. 
	}
	
	tfim = time(NULL);
    tempo = (tfim - tinicio);
             
	// Fim
	
	printf ("\n\n** Vetor ordenado ***\n\n{ ");
	
	for(i=0; i<n; i++)
       printf ("%d ", vetor[i]);
    
   	printf ("}\n\n");
	
	printf("Numero de trocas = %lld \nNumero de comparacoes = %lld \n",trocas,comp);    // cálculo do número de instruções
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	free(vetor);
	printf("Número de operacoes= %lld", comp + trocas*3);
}

