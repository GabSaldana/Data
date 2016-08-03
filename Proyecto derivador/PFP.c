#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
    
//Declaracion de estructuras  
 struct pila   
 {   
    int tope;   
    void **eltos;   
 };  
    
 typedef struct pila Pila;   
         
 struct NodoArb  
 {   
    void *dato;   
    struct NodoArb *der;   
    struct  NodoArb *izq;   
 };  
    
 typedef struct NodoArb NodoArb;    
    
//Declaracion de funciones  
 NodoArb *creaNodoArb(void *dato,NodoArb *der,NodoArb *izq);   
 Pila *creaPila(int n);   
 void *push(void *dato,Pila *p);   
 void *pop(Pila *p);   
 NodoArb *evalDerivada(NodoArb *r);     
 char *creaChar(char c);  
 NodoArb *dupv(NodoArb *u,NodoArb *v);  
 NodoArb *dumasv(NodoArb *u,NodoArb *v,char s);  
 NodoArb *duev(NodoArb *u,NodoArb *v);  
 NodoArb *dsenu(NodoArb *v);   
 NodoArb *dcosu(NodoArb *v); 
 NodoArb *dtanu(NodoArb *v); 
 NodoArb *dcotu(NodoArb *v); 
 NodoArb *dsecu(NodoArb *v); 
 NodoArb *dcscu(NodoArb *v); 
 NodoArb *dexpu(NodoArb *v);   
 NodoArb *dlnu(NodoArb *v);   
 void Imprimepost(NodoArb *r,void(*f)(void*));  
 void print(void *s);  
 void marco(); 
//Funciones que derivan  
    
//ÁRBOL DE LA DERIVADA DE UNA SUMA O RESTA(U'+-V')  
 NodoArb *dumasmenosv(NodoArb *u,NodoArb *v,char signo){  
   return creaNodoArb((void*)creaChar(signo),evalDerivada(u),evalDerivada(v));//U'+-V'  
 }  
     
//ÁRBOL DE UN PRODUCTO(U'*V')  
NodoArb *dupv(NodoArb *u,NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e,*f;  
    b=evalDerivada(u);//U'  
    a=u;  
    c=v;  
    d=evalDerivada(v);//V'  
    e=creaNodoArb((void*)creaChar('*'),b,c);//U'*V  
    f=creaNodoArb((void*)creaChar('*'),a,d);//U*V'  
    return creaNodoArb((void*)creaChar('+'),e,f);//U'*V+U*V'  
}  
    
//DERIVADA DE UNA DIVISIÓN((U'*V-U*V')/V^2)  
NodoArb *duev(NodoArb *u,NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e,*f,*g,*h,*i;  
    b=evalDerivada(u);//U'  
    a=u;  
    c=v;  
    d=evalDerivada(v);//V'  
    e=creaNodoArb((void*)creaChar('*'),b,c);//U'*V  
    f=creaNodoArb((void*)creaChar('*'),a,d);//U*V'  
    g=creaNodoArb((void*)creaChar('-'),e,f);//U'*V-V'*U  
    h=creaNodoArb((void*)creaChar('2'),NULL,NULL);//2  
    i=creaNodoArb((void*)creaChar('^'),h,c);//V^2  
    return creaNodoArb((void*)creaChar('/'),i,g);//(U'*V-V'*U)/V^2  
}  
    
//DERIVADA DE UN SENO(COSV*V')  
NodoArb *dsenu(NodoArb *v){  
    NodoArb *a,*b,*c,*d;  
    a=v;  
    c=evalDerivada(v);//V'  
    b=creaNodoArb((void*)creaChar('c'),a,NULL);//COSV  
    return creaNodoArb((void*)creaChar('*'),c,b);//COSV*V'  
}  
    
//DERIVADA DE UN COSENO(-SENV*V')  
NodoArb *dcosu(NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e;  
    a=v;  
    c=evalDerivada(v);//V'  
    b=creaNodoArb((void*)creaChar('s'),a,NULL);//SENV  
    d=creaNodoArb((void*)creaChar('-'),b,NULL);//-SENV  
    return creaNodoArb((void*)creaChar('*'),c,d);//-SENV*V'  
} 
  
//DERIVADA DE UNA TANGENTE 
  
NodoArb *dtanu(NodoArb *v){  
    NodoArb *a,*b,*c,*d;  
    a=v;  
    c=evalDerivada(v);//V'  
    b=creaNodoArb((void*)creaChar('S'),a,NULL);//SECV  
    d=creaNodoArb((void*)creaChar('^'),creaNodoArb((void*)creaChar('2'),NULL,NULL),b); 
    return creaNodoArb((void*)creaChar('*'),c,d);//SECV^2*V'  
} 
  
//DERIVADA DE LA COTANGENTE 
  
NodoArb *dcotu(NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e;  
    a=v;  
    c=evalDerivada(v);//V'  
    b=creaNodoArb((void*)creaChar('C'),a,NULL);//CSCV  
    d=creaNodoArb((void*)creaChar('^'),creaNodoArb((void*)creaChar('2'),NULL,NULL),b); 
    e=creaNodoArb((void*)creaChar('-'),d,NULL);//-CSCV^2  
    return creaNodoArb((void*)creaChar('*'),c,e);//-CSCV^2*V'  
} 
  
//DERIVADA DE LA SECANTE 
  
NodoArb *dsecu(NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e;  
    a=v;  
    c=evalDerivada(v);//V'  
    b=creaNodoArb((void*)creaChar('S'),a,NULL);//SECV  
    d=creaNodoArb((void*)creaChar('t'),a,NULL);//TANV 
    e=creaNodoArb((void*)creaChar('*'),d,b);//SECV*TANV  
    return creaNodoArb((void*)creaChar('*'),c,e);//SECV*TANV*V'  
} 
  
//DERIVADA DE LA COSECANTE 
  
NodoArb *dcscu(NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e,*f;  
    a=v;  
    c=evalDerivada(v);//V'  
    b=creaNodoArb((void*)creaChar('C'),a,NULL);//CSCV  
    d=creaNodoArb((void*)creaChar('T'),a,NULL);//COTV 
    e=creaNodoArb((void*)creaChar('*'),d,b);//CSCV*COTV 
    f=creaNodoArb((void*)creaChar('-'),e,NULL);//-CSCV*COTV  
    return creaNodoArb((void*)creaChar('*'),c,f);//-CSCV*COTV*V'  
     
}  
    
//DERIVADA DE UN EXPONENTE(e^V*V')  
NodoArb *dexpu(NodoArb *v){  
    NodoArb *a,*b,*c,*d;  
    a=v;  
    b=evalDerivada(v);  
    c=creaNodoArb((void*)creaChar('e'),a,NULL);//e^V  
    return creaNodoArb((void*)creaChar('*'),b,c);//e^V*V'  
}  
    
//DERIVADA DE UN LOGARITMO(1/V*V')  
NodoArb *dlnu(NodoArb *v){  
    NodoArb *a,*b,*c,*d,*e;  
    a=v;  
    b=evalDerivada(v);  
    c=creaNodoArb((void*)creaChar('1'),NULL,NULL);//1  
    d=creaNodoArb((void*)creaChar('/'),a,c);//1/V  
    return creaNodoArb((void*)creaChar('*'),b,d);//1/V*V'  
}   
    
//DERIVADA DE U ^ n((n*U^n-1)*U')  
NodoArb *dualan(NodoArb *n,NodoArb *u){  
    NodoArb *a,*b,*c,*d,*e,*f,*g;  
    a=u;  
    b=n;  
    g=evalDerivada(u);  
    c=creaNodoArb((void*)creaChar('1'),NULL,NULL);//1 
    d=creaNodoArb((void*)creaChar('-'),c,b);//n-1  
    e=creaNodoArb((void*)creaChar('^'),d,a);//U^n-1 
    f=creaNodoArb((void*)creaChar('*'),e,b);//U^n-1*n  
    return creaNodoArb((void*)creaChar('*'),f,g);//(U^n-1*n)*U'  
}  
    
//Funciones del Árbol  
    
NodoArb *creaNodoArb(void *dato,NodoArb *der,NodoArb *izq)   
 {   
    NodoArb *nvo;   
    nvo=(NodoArb*)malloc(sizeof(NodoArb));   
    nvo->der=der;   
    nvo->izq=izq;   
    nvo->dato=dato;   
    return nvo;   
 }   
     
 void Imprimepost(NodoArb *r,void(*f)(void*))  
 {   
    if(r)  
        {    
           Imprimepost(r->izq,f);  
           f(r->dato);  
           Imprimepost(r->der,f); 
        }     
 }  
     
 void print(void *s)  
 {   
    char c[5];  
    strcpy(c,(char*)s);   
    if(c[0]=='x' || c[0]<='9' && c[0]>='0' || c[0]=='+' || c[0]=='-' || c[0]=='*' || c[0]=='/' || c[0]=='^') //si es un nodo hoja  
        {  
          printf("%c ",c[0]);   
        }  
        //si no es nodo hoja   
    if(c[0]=='s')   
        {   
            printf("sen ");   
        }  
    if(c[0]=='c')   
        {   
            printf("cos ");   
        } 
    if(c[0]=='t')   
        {   
            printf("tan ");   
        }  
    if(c[0]=='T')//COTANGENTE   
        {   
            printf("cot ");   
        } 
    if(c[0]=='S')//SECANTE   
        {   
            printf("sec ");   
        }  
    if(c[0]=='C')//COSECANTE   
        {   
            printf("csc ");   
        }   
    if(c[0]=='e')   
        {   
            printf("exp ");   
        }  
    if(c[0]=='l')   
        {   
            printf("ln ");   
        } 
 }  
//FUNCION QUE RECORRE EL ÁRBOL DE EXPRESIÓN Y VA EVALUANDO SU DERIVADA  
NodoArb *evalDerivada(NodoArb *r)   
 {   
    char c =*(char*)(r->dato);     
    if(r->izq==NULL&&r->der==NULL) //si es un nodo hoja  
        {  
            if (c=='x'){//detenemos la recursividad con la DERIVADA DE X(1)  
         
                return creaNodoArb((void*)creaChar( '1'),NULL,NULL);  
             }  
            if (c<='9' && c>='0'){//detenemos la recursividad con la DERIVADA DE cnte(0)  
        
                return creaNodoArb((void*)creaChar('0'),NULL,NULL);  
             }  
        }  
        //si no es nodo hoja  
    if(c=='+' || c=='-')                 
        {   
     
            return dumasmenosv(r->der,r->izq,c);//pasamos U,V  
        }   
    if(c=='*')   
        {   
            return dupv(r->der,r->izq); //pasamos U,V  
        }   
    if(c=='/')   
        {   
            return duev(r->der,r->izq); //pasamos U,V  
        }  
    if(c=='^')   
        {   
            return dualan(r->der,r->izq); //pasamos U,V  
        }  
    if(c=='s')   
        {   
            return dsenu(r->der); //pasamos V  
        }  
    if(c=='c')   
        {   
            return dcosu(r->der);//pasamos V   
        } 
    if(c=='t')   
        {   
            return dtanu(r->der); //pasamos V  
        }  
    if(c=='T')//COTANGENTE   
        {   
            return dcotu(r->der);//pasamos V   
        } 
        if(c=='S')//SECANTE   
        {   
            return dsecu(r->der); //pasamos V  
        }  
    if(c=='C')//COSECANTE   
        {   
            return dcscu(r->der);//pasamos V   
        }   
    if(c=='e')   
        {   
            return dexpu(r->der); //pasamos V  
        }  
    if(c=='l')   
        {   
            return dlnu(r->der); //pasamos V  
        }   
               
 }  
    
 char *creaChar(char c)   
    {   
    char *nvo;   
    nvo=(char*)malloc(sizeof(char));   
    *nvo=c;   
    return nvo;   
    }      
    
//Funciones de la Pila  
    
 Pila *creaPila(int n)   
 {   
    Pila *p;   
    p=(Pila*)malloc(sizeof(Pila));   
    p->eltos=(void**)malloc(n*sizeof(void*));   
    p->tope=0;   
    return p;   
 }   
    
 void *push(void *dato,Pila *p)   
 {   
    p->eltos[p->tope]=dato;   
    p->tope=p->tope+1;   
 }  
    
 void *pop(Pila *p)   
 {   
    p->tope=p->tope-1;   
    return p->eltos[p->tope];   
 }      
       
 //MAIN   
 void main ()   
 {   
             
     int i;  
     NodoArb *d=NULL;  
     NodoArb *a=NULL,*izq=NULL,*der=NULL;   
     char cad[256],op[1];   
     Pila *p=creaPila(20); 
     do{  
     system("cls"); 
     marco(); 
    printf("Dame la expresion, de la cual deseas saber su derivada, en posfijo\n");   
    scanf("%s",&cad);        
    for(i=0;cad[i]!='\0';i++) //CREANDO ÁRBOL DE EXPRESIÓN  
    {   
          
        if(cad[i]>='0' && cad[i]<='9' || cad[i]=='x')   
         {   
            push((void*)creaNodoArb((void*)creaChar(cad[i]),NULL,NULL),p);   
         }   
        if(cad[i]=='+'||cad[i]=='-'||cad[i]=='*'||cad[i]=='/'||cad[i]=='^')  
        {  
            izq=pop(p); 
            der=pop(p); 
            push((void*)creaNodoArb(creaChar(cad[i]),izq,der),p);   
        }   
        if(cad[i]=='s'||cad[i]=='c'||cad[i]=='l'||cad[i]=='e' || cad[i]=='S'||cad[i]=='C'||cad[i]=='t'||cad[i]=='T')  
        {   
                 
            push((void*)creaNodoArb(creaChar(cad[i]),pop(p),NULL),p);   
        }   
     }        
    a=(NodoArb*)pop(p);   
    d=evalDerivada(a); //EVALUANDO ÁRBOL DE EXPRESIÓN    
    printf("Tu expresion original es: \n"); 
    Imprimepost(a,print); 
    printf("\nLa derivada es:\n"); 
    Imprimepost(d,print);     
    printf("\n"); 
    printf("Desea calcular otra expresion(s/n)?\n"); 
    scanf("%s",&op); 
   }while(op[0]=='s' || op[0]=='S') ; 
 }  
  
void marco(){ 
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"); 
    printf(":::::::::::::::::::::::::::::Derivador-De-Funciones::::::::::::::::::::::::::::\n");     
    printf(":::::::::::::::::::::::::::::::::Realizado-Por:::::::::::::::::::::::::::::::::\n"); 
    printf("::::::::::::::::::::::::::::Saldana-Aguilar-Gabriela:::::::::::::::::::::::::::\n"); 
    printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n"); 
    printf("                   Para continuar, siga las instrucciones:\n"); 
} 
