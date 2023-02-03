#include <stdio.h>
#include <stdlib.h>

//Nomedastruct *p (declarando o ponteiro da struct
//p = &pessoa
//printf = p->nome

typedef struct{
	char nome[10];
	int matricula;
	float nota1;
	float nota2;
	float nota3;
	float media;
}Aluno;

int main(){
	Aluno aluno;
	Aluno *p;
	p = &aluno;
	
	
	printf("Digite seu nome: ");
	scanf("%s", &aluno.nome);
	printf("Digite o seu numero de matricula: ");
	scanf("%d", &aluno.matricula);
	printf("Digite a sua nota 1: ");
	scanf("%f", &aluno.nota1);
	printf("Digite a sua nota 2: ");
	scanf("%f", &aluno.nota2);
	printf("Digite a sua nota 3: ");
	scanf("%f", &aluno.nota3);
	
		p->media = (p->nota1 + p->nota2 + p->nota3)/ 3;
		
		
	printf("Auno: %s", p->nome);
	printf("\nMatricula: %d", p->matricula);
	printf("\nNota 1: %f", p->nota1);
	printf("\nNota 2: %f", p->nota2);
	printf("\nNota 3: %f", p->nota2);
	printf("\nSua media eh: %f", p->media);
	
}
