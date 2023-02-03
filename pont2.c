#include <stdio.h>
#include <stdlib.h>

int main (){
	int num1;
	int *p1;
	int **p2;
	
	p2 = &p1;
	p1= &num1;
	
	printf("%d\n", num1);
	printf("%d\n", *p1);
	printf("%d\n", **p2);
	
	num1 = 20;
	*p1 = 30;
	**p2 = 40;//implementando o valor 40 na posição que está indicando a posição p2
	
	printf("%d\n", num1 );
	printf("%d\n", *p1);
	printf("%d\n", **p2);
	
	printf("%d\n", &p1);
	printf("%d\n", &p2);
	printf("%d\n", &num1);//& mostra o local da memoria que está 
	
}


