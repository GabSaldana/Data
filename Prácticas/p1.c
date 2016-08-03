#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct racional{
	int num,den;
};
typedef struct racional Racional;

Racional *r;
Racional *sumaRacional(Racional *r1, Racional *r2);
Racional *restaRacional(Racional *r1, Racional *r2);
Racional *dividirRacional(Racional *r1, Racional *r2);
Racional *multiplicarRacional(Racional *r1, Racional *r2);
void imprimeRacional(Racional *r);
Racional *copiaRacional(Racional *r);
int esIgual(Racional *r1,Racional *r2);
void marco();
//void asigar(Racional *r, int num, int den);
//int numerador(Racional *r);
//int denominador(Racional *r);

Racional *creaRacional(int num, int den){
	Racional *p;
	p=(Racional *)malloc(sizeof(Racional));
	p->num=num;
	if(den==0)
		return p;
	p->den=den;
	return p;	
}

Racional *sumaRacional(Racional *r1, Racional *r2){
	return creaRacional(((r1->num*r2->den)+(r1->den*r2->num)),(r1->den*r2->den));
}

Racional *restaRacional(Racional *r1, Racional *r2){
	return creaRacional(((r1->num*r2->den)-(r1->den*r2->num)),(r1->den*r2->den));
}

Racional *dividirRacional(Racional *r1, Racional *r2){
	return creaRacional((r1->num*r2->den),(r1->den*r2->num));
}

Racional *multiplicarRacional(Racional *r1, Racional *r2){
	return creaRacional((r1->num*r2->num),(r1->den*r2->den));
}

void imprimeRacional(Racional *r){
	printf("\n %d\n---\n %d",r->num,r->den);
}

int esIgual(Racional *r1,Racional *r2){
	return (r1->num*r2->den)==(r1->den*r2->num);
}

Racional *copiaRacional(Racional *r){
	return creaRacional(r->num,r->den);
}

void main(){
	int n1,n2,d1,d2;
	Racional *r1,*r2,*r3,*r4;
	marco();
	printf("Este programa pedira 2 numeros Racionales y te mostrara diferentes operaciones que se pueden hacer con ellos\n");
	printf("Para empezar, Dame el numerador del primer numero: ");
	scanf("%d",&n1);
	printf("\nBien, ahora dame el denominador del primer numero: ");
	scanf("%d",&d1);
	printf("\nBuen trabajo, ahora dame el numerador del segundo numero: ");
	scanf("%d",&n2);
	printf("\nYa para terminar, ahora dame el denominador del segundo numero: ");
	scanf("%d",&d2);
	r1=creaRacional(n1,d1);
	r2=creaRacional(n2,d2);
	printf("\nAhora te mostrare lo que se puede hacer con esos numeros:\n");
	printf("Primero lo facil, una SUMA!!\n");
	r3=sumaRacional(r1,r2);
	imprimeRacional(r3);
//	system("PAUSE");
	printf("\nFacil verda?, bueno ahora una MULTIPLICACION!!\n");
	r3=multiplicarRacional(r1,r2);
	imprimeRacional(r3);
//	system("PAUSE");
	printf("\nSigue sindo facil no?, bueno que tal una DIVISION!!\n");
	r3=dividirRacional(r1,r2);
	imprimeRacional(r3);
//	system("PAUSE");
	printf("\nYa no fue tan facil, o si?, bueno que te parece si ahora comparamos si son iguales tus numeros!!\n");
	if(esIgual(r1,r2))
		printf("\n¿Que crees?, tus numeros SI son iguales\n");
	else
		printf("\n¿Que crees?, tus numeros NO son iguales\n");
//	system("PAUSE");
	printf("\nBueno eso fue todo, Nos vemos luego!!\n");
	system("PAUSE");
}

void marco(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::::::::::::::::::::::::::::::::::TAD-Racional:::::::::::::::::::::::::::::::\n");    
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::Saldaña Aguilar Gabriela::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LB::\n");
    //printf("                   Para continuar, siga las instrucciones:\n");
}
