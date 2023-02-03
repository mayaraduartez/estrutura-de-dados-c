#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 500000    // constante que define o tamanho do vetor

int main(){

	int *vetor, i, j, aux;				//aux é a variável auxiliar para a troca de valores no vetor
	long long int trocas = 0, comp = 0;   	//trocas e comp são as variáveis para calcular o números de instruções do algoritmo.
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
    
    srand(time(NULL));  //função para gerar sempre números aleatórios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleatórios
		   vetor[i] = rand()%100;
		   
//	printf ("** Vetor original ***\n\n{ ");
	
//	for(i=0; i<n; i++)
       printf ("%d  ", vetor[i]);
    
 //  	printf ("}\n\n");
   	
   	
    tinicio = time(NULL);  	
     
    //Algoritmo Insertion Sort
	for (i = 1; i < n; i++) {
        aux = vetor[i];
        j = i - 1;
        comp++;
        while (j >= 0 && vetor[j] > aux) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            trocas++;
        }
        vetor[j + 1] = aux;
    }
																
	tfim = time(NULL);
    tempo = (tfim - tinicio);
             
	// Fim
	
	//printf ("\n\n** Vetor ordenado ***\n\n{ ");
	
	//for(i=0; i<n; i++)
       printf ("%d ", vetor[i]);
    
   //	printf ("}\n\n");
	
	
	printf("Numero de trocas = %lld \nNumero de comparacoes = %lld \n",trocas,comp);    // cálculo do número de instruções
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	
	free(vetor);
}
