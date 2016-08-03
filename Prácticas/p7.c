#include<stdio.h>
#include<stdlib.h>

//Estructuras

struct nodo{
    int numero,x,y,z,band;
    struct nodo *sig;
};

typedef struct nodo Nodo;

//Declaracion de prototipos

Nodo *creaNodo(int,int,int,int, Nodo *);
void imprime(Nodo *);
Nodo* suma(Nodo *,Nodo *);
void insertaIni(int,int,int,int, Nodo **);
void marco();

//Definicion de funciones

main()
{
    marco();
    Nodo *cab = NULL;
    Nodo *cab2 = NULL;

                                                            /*Polinomio 1*/
    insertaIni(4,0,0,0, &cab);
    insertaIni(1,1,1,1, &cab);
    insertaIni(8,1,0,0, &cab);

                                                            //Polinomio 2*/
    insertaIni(5,0,0,0, &cab2);
    insertaIni(1,1,1,1, &cab2);
    insertaIni(1,0,1,0, &cab2);
    insertaIni(5,1,0,0, &cab2);
    
    Nodo *s=suma(cab,cab2);                                           
    puts("POLINOMIO 1");
    imprime(cab);
                                        
    puts("POLINOMIO 2");
    imprime(cab2);
    puts("\nSUMA DE POLINOMIO");
    imprime(s);
    getch();
}

Nodo *creaNodo(int numero,int x,int y,int z, Nodo *p)
{
    Nodo *nvo;
    nvo =(Nodo *)malloc(sizeof(Nodo));

    nvo->numero=numero;
    nvo->x=x;
    nvo->y=y;
    nvo->z=z;
    nvo->band=0;
    nvo->sig=p;

    return nvo;
}

Nodo* suma(Nodo *p,Nodo*q)
{
    Nodo *r=NULL;
    Nodo *aux; 
    Nodo *aux2;
    for(aux=p;aux;aux=aux->sig)
    {
        for(aux2=q;aux2;aux2=aux2->sig)
        {
            if((aux->x == aux2->x) && (aux->y == aux2->y) && (aux->z == aux2->z))
                {
                    insertaIni(aux->numero+aux2->numero,aux->x,aux->y,aux->z,&r);
                    aux->band=1;
                    aux2->band=1;
                }   
        }
        if(aux->band==0)
            insertaIni(aux->numero,aux->x,aux->y,aux->z,&r); 
    }
    
    for(aux2=q;aux2;aux2=aux2->sig)
    {
        if(aux2->band==0)
            insertaIni(aux2->numero,aux2->x,aux2->y,aux2->z,&r);
    }
    return r;
    
}

void imprime(Nodo *cab)
{
    Nodo *p;
    for(p=cab;p;p=p->sig)
    {
        printf("%d<%d,%d,%d>  ",p->numero,p->x,p->y,p->z);
    }
    printf("\n\n");
}

void insertaIni(int numero,int x,int y,int z, Nodo **cab)
{
    *cab = creaNodo(numero,x,y,z,*cab);
}

void marco(){
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("::::::::::::::::::::::::::::::Suma-De-Polinomios:::::::::::::::::::::::::::::::\n");    
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n");
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    //printf("                   Para continuar, siga las instrucciones:\n");
}
