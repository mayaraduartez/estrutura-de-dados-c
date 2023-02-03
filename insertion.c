#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 500000    // constante que define o tamanho do vetor

int main(){

	int *vetor, i, j, aux;				//aux � a vari�vel auxiliar para a troca de valores no vetor
	long long int trocas = 0, comp = 0;   	//trocas e comp s�o as vari�veis para calcular o n�meros de instru��es do algoritmo.
	time_t tinicio, tfim;   
	double tempo;
	
	vetor = (int *) malloc (n * sizeof(int));
    
    srand(time(NULL));  //fun��o para gerar sempre n�meros aleat�rios diferentes.
	for (i = 0; i < n; i++)		//preenche o vetor com valores aleat�rios
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
	
	
	printf("Numero de trocas = %lld \nNumero de comparacoes = %lld \n",trocas,comp);    // c�lculo do n�mero de instru��es
	printf("O tempo de execucao foi: %.3f segundos.",tempo);
	
	free(vetor);
}
