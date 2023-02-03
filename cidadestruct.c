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
	printf ("Informe uma cidade:");
	scanf("%s", &cidade[n].nome);

	printf ("Informe um estado:");
	scanf("%s", &cidade[n].estado);

	printf ("\nVoce deseja continuar adicionando cidades: \n0- Sair \n Ou qualquer numero para continuar");
	scanf ("%d", &continuar);
	}while(continuar != 0);
	
	if(cidade[n].estado == 'rs'){
		for(i = 1; i<=n ; i++){
			printf("%s", cidade[i].estado);
		}
	}
	

}
