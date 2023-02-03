#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char nome[20];
	int id;
}Curso;

typedef struct{
	int semestre;
	int ano;
	Curso curso;
}Disciplinas;

typedef struct{
	char nome[20];
	int matricula[10];
	Disciplinas disciplinas;
}Alunos;

int main (){
	int menu;
	Alunos alunos[10];
	Disciplinas disciplinas;
	Curso curso;
	int i=0;
	int j;
	int ver;
	
	do {
		
	
	printf("Digite 1 se deseja cadastrar um aluno. Ou 2 se deseja ver a lista de alunos. 3 para sair: ");
	scanf("%d", &menu );
	
	if( menu == 1){
		printf("Digite o nome do aluno: ");
		scanf("%s", &alunos[i].nome);
		printf("Qual o numero de matricula? ");
		scanf("%d", &alunos[i].matricula);
		printf("Sobre as disciplinas. Qual semeste você está? ");
		scanf("%d" , &alunos[i].disciplinas.semestre);
		printf("Qual ano está cursando? ");
		scanf("%d", &alunos[i].disciplinas.ano);
		printf("Qual curso você está? ");
		scanf("%s" , &alunos[i].disciplinas.curso.nome);
		printf("Qual o id do seu curso? ");
		scanf("%d", &alunos[i].disciplinas.curso.id);
		i++;
		
	}else{
		printf("1- Ver todos os alunos \n2-Ver por curso \n3-Ver por Semestre");
		scanf("%d", &ver);
		
		switch :
			case 1:
			for( j = 0; j<=i ; j++){
			printf("Aluno: %s" , alunos[j].nome );
			printf("\nNumero da matricula: %d", alunos[j].matricula);
			printf("\nSemestre: %d" , alunos[j].disciplinas.semestre);
			printf("\nAno cursando: %d", alunos[j].disciplinas.ano);
			printf("\nCurso: %s", alunos[j].disciplinas.curso.nome);
			printf("\nId do curso: %d", alunos[j].disciplinas.curso.id);
		}
		break;
		
		case 2: 
		for( j = 0; j<=i ; j++){
			printf("Aluno: %s", alunos[i].curso);
		}
		
		case 3: 
		for(j = 0; j<=1 ; j++){
			printf("Aluno: %s", alunos[i].semestre);
		}
	}
	
}while ( menu != 3);


	
}
