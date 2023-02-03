#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome [50];
	char estado [2];
} Cidade;

int main () {
	Cidade *cidade;
	int n;
	int continuar;
	int i;
	
	printf("Digite o tamanho do vetor de cidades: ");
	scanf("%d", &n);
	
	cidade = (Cidade*) malloc (n * sizeof(Cidade));
	
	do{
	for( i = 1; i <=n ; i++){
		printf("Digite o nome da cidade: ");
		scanf("%s", &cidade[i].nome);
		printf("Digite o estado da cidade: ");
		scanf("%s", &cidade[i].estado);
		printf("0- para sair \n Qualquer outro numero para continuar ");
		scanf("%d", &continuar);
	}
	}while(continuar != 0);

}
