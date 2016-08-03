#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
//Estructuras
 
struct nodoArb{
    void* dato;
    struct nodoArb *izq;
    struct nodoArb *der;
};
 
typedef struct nodoArb NodoArb;
 
struct pila
{
int tope;
void **eltos;
};
   
typedef struct pila Pila;
   
//Prototipos
 
Pila *creaPila(int);
void push(Pila *p,void *dato);
void *top(Pila *p);
void *pop(Pila *p);
int empty(Pila *p);
char *crearChar(char c);
NodoArb *creaNodoArb(NodoArb *izq,NodoArb *der,void* dato);
int evalArb(NodoArb *p);
void marco();
 
//main
 
void main(){
    char linea[100];
    int i;
    Pila *p=creaPila(100);
    marco();
    puts("Dame la cadena en sufijo:\n");
    gets(linea);
    //puts("dfgdfg");
    for(i=0;linea[i];i++)
    {
        if(linea[i]>='0' && linea[i]<='9')
        {  
	    //printf("%d",i);
            push(p,creaNodoArb(NULL,NULL,(void*)crearChar(linea[i])));
            continue;
        }
        push(p,creaNodoArb((NodoArb*)pop(p),(NodoArb*)pop(p),&linea[i]));
    }
    printf("\nEl resulatado es: %d\n", evalArb((NodoArb*)pop(p)));
         
}
 
//Defincion de Funciones
 
Pila *creaPila(int n)
{
Pila *nvo;
nvo=(Pila*)malloc(sizeof(Pila));
nvo->tope=0;
nvo->eltos = (void **)malloc(n*sizeof(void *));
return nvo;
}
   
   
void push(Pila *p,void *dato)//función para ingresar un dato.
{
p->eltos[p->tope]=dato;
p->tope++;
}
   
void *top(Pila *p)//función para imprimir el último valor;
{
return p->eltos[p->tope-1];
}
   
   
 
void *pop(Pila *p)//función para sacar valores
{
p->tope=p->tope-1;
return p->eltos[p->tope];
}
   
int empty(Pila *p)//función para sacar valores
{
return p->tope==0;
}
   
char *crearChar(char c)//Crear caracter.
{
char *nvo;
nvo=(char*)malloc(sizeof(char));
*nvo=c;
return nvo;
}
 
NodoArb *creaNodoArb(NodoArb *izq,NodoArb *der,void* dato){
    NodoArb *nvo;  
    nvo=(NodoArb*)malloc(sizeof(NodoArb));
    nvo->dato = dato;
    nvo->izq = izq;
    nvo->der = der;
    return nvo;
}
 
int evalArb(NodoArb *p)
{
    char c = *(char*)(p->dato);
    if(p->der==NULL&&p->izq==NULL)return c-'0';
    if(c=='+')return evalArb(p->izq)+evalArb(p->der);
    if(c=='*')return evalArb(p->izq)*evalArb(p->der);
    if(c=='/')return evalArb(p->izq)/evalArb(p->der);
    if(c=='-')return evalArb(p->izq)-evalArb(p->der);
} 

void marco(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::::::::::::::::::::::::::::Evaluar-Un-Arbol-Binario:::::::::::::::::::::::::::\n");    
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                   Para continuar, siga las instrucciones:\n");
}
