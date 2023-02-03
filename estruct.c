#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome_func;
	int cpf;
	float salario;
}Funcionario;

typedef struct {
	char nome_set;
	int ramal;
	Funcionario funcionario[15];
}Setor;

typedef struct {
	char nome_emp;
	char ramo;
	int sede;
	int telefone;
	Setor setor[5];
}Empresa;

int main (){
	Funcionario funcionario[15];
	Setor setor[5];
	Empresa empresa;
	int i;
	int j;
	
	printf("Qual o nome da sua empresa? ");
	scanf("%s", &empresa.nome_emp);
	printf("Qual o ramo da sua empresa? ");
	scanf("%s", &empresa.ramo);
	printf("Qual a sede da sua empresa? ");
	scanf("%d", &empresa.sede);
	printf("Qual o telefone de contato para sua empresa? ");
	scanf("%d", &empresa.telefone);
	
	
	for(i=0 ; i<5; i++){
		printf("Qual o setor da sua empresa? ");
		scanf ("%d", &empresa.setor[i].nome_set);
		printf("Qual o ramal do teu setor? ");
		scanf("%d", &empresa.setor[i].ramal);
		
			for(j=0; j<3; j++){
				printf("Qual o funcionario desse setor? ");
				scanf("%s", &empresa.setor[i].funcionario[j].nome_func);
				printf("Qual o cpf desse funcionario? ");
				scanf("%d", &empresa.setor[i].funcionario[j].cpf);
				printf("Qual o salario desse funcionario? ");
				scanf("%f", &empresa.setor[i].funcionario[j].salario);
			}
	}
	
}
