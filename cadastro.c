#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <boolean.h>

typedef struct{
	char nome_do_produto[5];
	int codigo_de_barra~[5];
	float preco[5];
	char setor[5];
	bool promocao[5];
}Cadastro;

int main(){
	Cadastro cadastro[5];
	int i;
	int nota;

	if(i=0; i<=5; i++){
		printf("Digite produto do supermercado: ");
		scanf("%s", &cadastro[i].nome_do_produto);
		printf("Digite o codigo de barra: ");
		scanf("%d", &cadastro[i].codigo_de_barra);
		printf("Digite o preco: ");
		scanf("%f", cadastro[i].preco);
		printf("Digite o setor: ");
		scanf("%s" , cadastro[i].setor)
		prinft("Esse produto esta em promocao: Digite 1-Sim ou 2-Não ");
		scanf("%d", &nota);
		
		if(nota ==1){
			cadastro[i].promocao = true; 
		}else{
			cadastro[i].promocao = false;
		}
	}
	
	
	
	
	
	
	
	
	
}
