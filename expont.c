#include <stdio.h>
#include <stdlib.h>

int main (){
	float nota1;
	float nota2;
	float media;
	float *p1;
	float *p2;
	float *p3;
	
	
	printf("Qual a nota1: ");
	scanf("%f", &nota1);
	printf("Qual a nota2: ");
	scanf("%f", &nota2);
	
	p1 = &nota1;
	p2 = &nota2;
	p3= &media;
	
	*p3 = (*p1 + *p2)/ 2;
	
	printf("A media eh: %f", *p3);
	
	
}
