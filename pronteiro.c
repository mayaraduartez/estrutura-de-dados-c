#include <stdio.h>
#include <stdlib.h>

int main (){
	int num1;
	int num2;
	int *p1;
	int *p2;
	
	p1 = &num1;//quando o ponteiro aponta e aparece o & é pq tá pegando a posição
	p2 = &num2;//quando aparece *p= 35 ( valor qualquer) ta incrementando o 35 no lugar da posição que ele aponta 
	
	//**p = ponteiro para ponteiro 
	
	
	
	printf("Digite o valor do numero 1: ");
	scanf("%d", &num1);
	printf("Digite o valor do numero 2: ");
	scanf("%d", &num2);
	
	printf("%d\n", num1 + num2);
	printf("%d\n", *p1 * *p2);
}
