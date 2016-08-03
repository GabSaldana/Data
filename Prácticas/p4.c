#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//Estructuras
 
struct perro{
    char nombre[100];
    char raza[60];
    int edad;
    char genero;
};
 
typedef struct perro Perro;
 
struct nodo{
    void* dato;
    struct nodo* sig;
};
 
typedef struct nodo NodoL;
 
//Declaracion de Prototipos
 
Perro *creaPerro(char[],char[],int,char);
NodoL *creaNodoL(void*, NodoL*);
void insertaIniL(NodoL**, void*);
void imprimeL(NodoL*,void (*f)(void*));
void *copiaPerro(void*);
NodoL *copiaSL(NodoL*);
NodoL *copiaPL(NodoL*, void* (*f)(void*));
void imprimePerro(void*);
NodoL *find(NodoL*,void*, int(*cmp)(void*,void*));
int comPerroGenero(void*,void*);
int comPerroRaza(void*,void*);
int comPerroEdad(void*,void*);
int comPerroNom(void*,void*); 
void marco();
//Main
 
void main(){
    int op,edad,p;
    char nombre[100], raza[60],genero;
    NodoL *cab,*cabCS,*cabCP,*F;
    Perro *pp;
    insertaIniL((void*)creaPerro("Dogo","Doberman",1,'M'),cab);
    insertaIniL((void*)creaPerro("Bola","Chihuahua",2,'F'),cab);
    insertaIniL((void*)creaPerro("Artur","San Bernardo",3,'M'),cab);
    insertaIniL((void*)creaPerro("Figo","Doberman",4,'M'),cab);
    insertaIniL((void*)creaPerro("Melenas","Chihuahua",3,'M'),cab);
    insertaIniL((void*)creaPerro("Pelusa","San Bernardo",2,'F'),cab);
    insertaIniL((void*)creaPerro("Dino","Chihuahua",4,'M'),cab);
    insertaIniL((void*)creaPerro("Manchas","Doberman",5,'M'),cab);
    insertaIniL((void*)creaPerro("Kelly","San Bernardo",6,'F'),cab);
    insertaIniL((void*)creaPerro("Mimi","Chihuahua",4,'F'),cab);
    imprimeL(cab,imprimePerro);
    cabCS=copiaSL(cab);
    cabCP=copiaPL(cab,copiaPerro);
    do{ 
        marco();
        printf("Como quieres buscar al Perro para borrarlo?\n1.Nombre\n2.Raza\n3.Edad\n4.Sexo\n5.Salir\n");
        scanf("%d",&op);
        switch (op){
            case 1:
                printf("Dame el nombre del Perro\n");
                scanf("%s",&nombre);
                pp=creaPerro(nombre,"",0,'M');
                if(find(cab,(void*)pp,comPerroNom))	
                	printf("Lo encontro");          
                else
                	printf("NO Lo encontro");          
            break;
            case 2:
                printf("Dame la raza del Perro\n");
                scanf("%s",&raza);
                F=find(cab,(void*)raza,comPerroRaza);
                printf("Llego");
            break;
            case 4:
                printf("Dame el genero del Perro\n");
                scanf("%c",&genero);
                F=find(cab,(void*)genero,comPerroGenero);
                printf("Llego");
            break;
            case 3:
                printf("Dame la edad del Perro\n");
                scanf("%d",&edad);
                F=find(cab,(void*)edad,comPerroEdad);
                printf("Llego");
            break;
        }
    }while(op!=5);
}
 
//Definicion de las funciones
 
Perro* creaPerro(char nombre[],char raza[],int edad,char genero){
    Perro* nvo;
    nvo=(Perro*)malloc(sizeof(Perro));
    strcpy(nvo->nombre,nombre);
    strcpy(nvo->raza,raza);
    nvo->edad=edad;
    nvo->genero=genero;
    return nvo;
}
 
NodoL* creaNodoL(void* dato, NodoL* sig){
    NodoL* nvo;
    nvo=(NodoL*)malloc(sizeof(NodoL));
    nvo->dato=dato;
    nvo->sig=sig;
    return nvo;
}
 
void insertaIniL(NodoL** cab, void* dato){
    *cab=creaNodoL(dato,*cab);
}
 
 
void imprimeL(NodoL* cab,void (*f)(void*)){
    if(!cab) return;
    f(cab->dato);
    imprimeL(cab->sig,f);
}
 
NodoL* copiaSL(NodoL* cab){
    NodoL *p,*cab2;
    for(p=cab;p;p=p->sig)
        cab2=creaNodoL(p->dato,cab2);
    return cab2;    
}
 
NodoL* copiaPL(NodoL* cab, void* (*f)(void*)){
    NodoL *p,*cab2;
    for(p=cab;p;p->sig)
        cab2=creaNodoL(f(p->dato),cab2);
    return cab2;
}
 
void* copiaPerro(void* p){
    Perro *pe=(Perro*)p;
    return (void*)creaPerro(pe->nombre,pe->raza,pe->edad,pe->genero);
}
 
void imprimePerro(void* p){
    Perro *pe=(Perro*)p;
    puts(pe->nombre);
    puts(pe->raza);
    printf("%d\n",pe->edad);
    printf("%c\n",pe->genero);
}
 
NodoL* find(NodoL* cab,void *key, int(*cmp)(void*,void*)){
    NodoL* p;
    for(p=cab;p;p=p->sig)
        if(!cmp(p->dato,key))
            return p;
    return (NodoL*)NULL;
}
 
int comPerroNom(void* p1,void *p2){
    Perro *pe1=(Perro*)p1;
    Perro *pe2=(Perro*)p2;
    return strcmp(pe1->nombre,pe2->nombre);
}
 
int comPerroRaza(void* p1,void *p2){
    Perro *pe1=(Perro*)p1;
    Perro *pe2=(Perro*)p2;
    return strcmp(pe1->raza,pe2->raza);
}
 
int comPerroEdad(void* p1,void *p2){
    Perro *pe1=(Perro*)p1;
    Perro *pe2=(Perro*)p2;
    return pe1->edad==pe2->edad;
}
 
int comPerroGenero(void* p1,void *p2){
    Perro *pe1=(Perro*)p1;
    Perro *pe2=(Perro*)p2;
    return pe1->genero==pe2->genero;
}

void marco(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::Listas-De-Perros::::::::::::::::::::::::::::::::\n");    
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("                   Para continuar, siga las instrucciones:\n");
}
