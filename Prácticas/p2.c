#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pila{
	int tope;
	void **eltos;
};
typedef struct pila Pila;

//Declaracion de prototipos de funciones.
char* creaChar(char);
Pila* creaPila(int);
void push(Pila*,void*);
void* pop(Pila*);
void* top(Pila*);
int isEmpty(Pila*);


void main(){
	int i,ig;
	Pila *p;
	char *m;
	char text[100];
	marco();
	printf("Dame el texto\n");
	gets(text);
	p=creaPila(strlen(text));
	for(i=0;i<strlen(text);i++)
		if(text[i]!=' ')
			push(p,(void*)creaChar(text[i]));
	for(i=0;i<strlen(text);i++){
		if(text[i]!=' ')
			if(text[i]==*(m=top(p)))
				m=pop(p);
			else
				break;
	}
	if(isEmpty(p))
		printf("\nTu texto SI es Palindroma!!!\n");
	else
		printf("\nTu texto NO es Palindroma!!!\n");
	system("PAUSE");
}

char* creaChar(char c){
	char *nvo;
	nvo=(char*)malloc(sizeof(char));
	*nvo=c;
	return nvo;
}

Pila* creaPila(int n){
	Pila* nvo;
	nvo=(Pila*)malloc(sizeof(Pila));
	nvo->tope=0;
	nvo->eltos=(void**)malloc(n*sizeof(void*));
	return nvo;
}

void push(Pila* p, void* dato){
	p->eltos[p->tope]=dato;
	p->tope+=1;
}

void* pop(Pila* p){
	p->tope=p->tope-1;
	return p->eltos[p->tope];
}

void* top(Pila * p){
	return p->eltos[p->tope-1];
}

int isEmpty(Pila* p){
	return p->tope==0;
}


