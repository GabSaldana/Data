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

//Declaracion de prototiposter
  
NodoArb *creaNodoArb(NodoArb *izq,NodoArb *der,void* dato);
NodoArb *copiaNodoArb(NodoArb* old);
void marco();

//Main

int main(){
    char Pregunta[1024],Animal[512],res[1],rp[1],ra[1],rn[1];
    NodoArb *cab=creaNodoArb(creaNodoArb(NULL,NULL,(void*)"Leon"),creaNodoArb(NULL,NULL,(void*)"Delfin"),(void*)"Vive en la tierra?");
    NodoArb *old=(NodoArb*)NULL;
    NodoArb *nvo=(NodoArb*)NULL;
    NodoArb *p=(NodoArb*)NULL;
    do{
        system("CLS");
        marco();
        p=cab;
        while(p){
           if(p->izq!=NULL && p->der!=NULL){
                printf("%s\n",(char*)p->dato);
                scanf("%s",&rp);
                if(rp[0]=='s' || rp[0]=='S'){
                   p=p->izq;
                   //printf("%s\n",(char*)p->dato);
                }
                if(rp[0]=='n' || rp[0]=='N'){
                   p=p->der;
                   //printf("%s\n",(char*)p->dato);
                }
           }
           if(p->izq==NULL && p->der==NULL){
                printf("El animal en el que estabas pensando es un(a) %s?\n",(char*)p->dato);
                scanf("%s",&ra);
                if(ra[0]=='s' || ra[0]=='S'){
                     printf("YEAH! GANE :D\n");
                     break;
                }
                if(ra[0]=='n' || ra[0]=='N'){
                     old=copiaNodoArb(p);
                     printf("En que animal estabas pensando?\n");
                     gets(Animal);
                     gets(Animal);
                     nvo=creaNodoArb(NULL,NULL,NULL);
                     nvo->dato=(void*)malloc(sizeof(char)*512);
                     strcpy((char*)nvo->dato,Animal);
                     //printf("%s\n",(char*)nvo->dato);
                     //printf("%s\n",(char*)old->dato);
                     printf("Dame una pregunta para diferenciar a este nuevo animal...\n");
                     gets(Pregunta);
                     //p->dato=NULL;
                     p->dato=(void*)malloc(sizeof(char)*1024);
                     strcpy((char*)p->dato,Pregunta);
                     printf("Para tu pregunta cual seria la respuesta para %s\n",(char*)nvo->dato);
                     scanf("%s",&rn);
                     if(rn[0]=='s' || rn[0]=='S'){
                        p->izq=copiaNodoArb(nvo);
                        p->der=copiaNodoArb(old);
                        break;
                     }
                     if(rn[0]=='n' || rn[0]=='N'){
                        p->izq=copiaNodoArb(old);
                        p->der=copiaNodoArb(nvo);
                        break;              
                     }
                }
           }
        }
        printf("Desea seguir en el juego?\n");
        scanf("%s",&res);
    }while(res[0]=='s' || res[0]=='S');
    return 0;
}

//Definicion de funciones
   
NodoArb *creaNodoArb(NodoArb *izq,NodoArb *der,void* dato){
    NodoArb *nvo; 
    nvo=(NodoArb*)malloc(sizeof(NodoArb));
    nvo->dato = dato;
    nvo->izq = izq;
    nvo->der = der;
    return nvo;
}

NodoArb *copiaNodoArb(NodoArb* old) {
	NodoArb *nvo=creaNodoArb(NULL,NULL,NULL);
	nvo->dato=(void*)malloc(sizeof(char)*1024);
	strcpy((char*)nvo->dato,(char*)old->dato);
	return nvo;
}

void marco(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::::::::::::::::::::::::::::Adivinador-De-Animales:::::::::::::::::::::::::::::\n");    
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                   Para continuar, contesta las preguntas:\n");
}
