#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Estructura

struct pila{
	int tope;
	void **eltos;
};

typedef struct pila Pila;

//Prototipos
char* creaChar(char);
Pila* creaPila(int);
void push(Pila*,void*);
void* pop(Pila*);
void* top(Pila*);
int isEmpty(Pila*);
void marco();
//main

void main (){
	FILE *Fichero;
	char nArchivo[100],c,*m;
	Pila *p=creaPila(100);
	marco();
	printf("Dame el nombre del archivo que deseas verificar si tiene sus llavas, corchetes y parentesis balanceadas dentro de el, Recuerda que el archivo tiene que estar en la misma direccion que este programa y no olvodes poner su extensión\n");
	gets(nArchivo);
	Fichero=fopen(nArchivo,"r");
	if(Fichero==NULL){
		printf("NO exixte tu archivo");
		exit(0);
	}
	do{
		c=fgetc(Fichero);
		if(c=='{' || c=='[' || c=='(')
			push(p,(void*)creaChar(c));	
		 if(c=='}' || c==']' || c==')')				
		 	m=pop(p);
	}while(!feof(Fichero));
	fclose(Fichero);
	if(isEmpty(p))
        	printf("\nEsta balanceado\n");
    	else
        	printf("\nNo esta balanceado\n");
	
	
}

//Definiciones de Funciones

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
void marco(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::::::::::::::::::::::::::::::Balanceo-De-Progrmas:::::::::::::::::::::::::::::\n");    
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                   Para continuar, siga las instrucciones:\n");
}
