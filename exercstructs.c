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
	
	printf("Qual o nome da sua empresa? ");
	scanf("%s", &empresa.nome_emp);
	
	for(i=0 ; i<=5; i++){
		printf("Qual o setor da sua empresa? ");
		scanf ("%d", &empresa.setor[i].nome_set);
		
	}
	
}
