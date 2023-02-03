#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
	float media;
	
}Aluno;

int main (void){
	
	Aluno alunos[10];
	int i;
	
	
	for(i = 0; i < 10; i++){
		
		printf("Digite seu nome %d: ", i+1);
		scanf("%s", &alunos[i].nome);
		
		printf("Digite a nota 1 do aluno %d: ", i+1);
		scanf("%f", &alunos[i].nota1);
		
		printf("Digite a nota 2 do aluno %d: ", i+1);
		scanf("%f", &alunos[i].nota2);
		
		printf("Digite a nota 3 do aluno %d: ", i+1);
		scanf("%f", &alunos[i].nota3);
		
		alunos[i].media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3)/3;
		
	}
	
	for( i = 0; i< 10; i++){
		printf("Média do aluno %s: %2.f\n", alunos[i].nome, alunos[i].media);
	}
	
}
