#include <stdio.h>
#include <stdlib.h>

int main (){
	int *vet;
	int n;
	int i;
	
	
	//maloc adiciona o vetor
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	vet = (int*) malloc (n * sizeof(int));
	

	printf("\n\nSeu vetor possui: \n\n");
	for ( i = 0; i < n; i++){
		printf("posicao: %d\nValor: %d\n\n", i , vet[i]);
		vet[i] = 1;
		printf("Posicao: %d\n Valor: %d\n\n", i , vet[i]);
	} 
	
	//realoc adiciona por cima o vetor ou diminui eles, mas não apaga 
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	vet = (int*) realloc (vet, n * sizeof(int));
	
	
	printf("\n\nSeu vetor possui: \n\n");
	for ( i = 0; i < n; i++){
		printf("posicao: %d\nValor: %d\n\n", i , vet[i]);
		vet[i] = 1;
		printf("Posicao: %d\n Valor: %d\n\n", i , vet[i]);
	} 
	
	free(vet);
}
