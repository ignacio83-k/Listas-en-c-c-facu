#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Tipos de dato
typedef struct NODO
{
    char Dato;
    struct NODO *Siguiente, *Anterior;
} TIPO_NODO;
typedef TIPO_NODO *PUNTERO_LISTA;

//Procedimientos y funciones
void Lista_Crear(PUNTERO_LISTA *Lista1, char Caracter_A_Ingresar);
void Lista_Avanzar(PUNTERO_LISTA *Lista1);
void Lista_Retroceder(PUNTERO_LISTA *Lista1);
void Lista_Visualizar(PUNTERO_LISTA Lista1);
void Lista_ReemplazoCaracter(PUNTERO_LISTA *Lista1, char Caracter_A_Remplazar, char Caracter_Reemplazador);
void Lista_VuelvoAlInicio(PUNTERO_LISTA *Lista1);

int main()
{
    PUNTERO_LISTA Lista1=NULL;
    char Caracter_A_Remplazar;
    char Caracter_Reemplazador;
    char CadenaDeCaracteres[100];
    printf("Ingrese una palabra para pasarla a lista : ");
    scanf("%s", CadenaDeCaracteres);
    for (int i=0; CadenaDeCaracteres[i]!='\0'; i++)
    {
        Lista_Crear(&Lista1, CadenaDeCaracteres[i]);
    }
    printf("Ingrese el caracter que sera reemplazado en la lista : ");
    scanf(" %c", &Caracter_A_Remplazar);
    printf("Ingrese el caracter sustituto : ");
    scanf(" %c", &Caracter_Reemplazador);
    Lista_ReemplazoCaracter(&Lista1, Caracter_A_Remplazar, Caracter_Reemplazador);
    Lista_Visualizar(Lista1);
}

void Lista_Crear(PUNTERO_LISTA *Lista1, char Caracter_A_Ingresar)
{
    PUNTERO_LISTA Asignador;
    Asignador               = new TIPO_NODO;
    Asignador->Dato         = Caracter_A_Ingresar;
    Asignador->Siguiente    = *Lista1;
    Asignador->Anterior     = NULL;
    *Lista1                 = Asignador;
}

void Lista_Avanzar(PUNTERO_LISTA *Lista1)
{
    PUNTERO_LISTA Lista_Auxiliar    = *Lista1;
    Lista_Auxiliar                  = Lista_Auxiliar->Siguiente;
    Lista_Auxiliar->Anterior        = *Lista1;
    *Lista1                         = Lista_Auxiliar;
}

void Lista_Retroceder(PUNTERO_LISTA *Lista1)
{
    PUNTERO_LISTA Lista_Auxiliar    = *Lista1;
    Lista_Auxiliar                  = Lista_Auxiliar->Anterior;
    Lista_Auxiliar->Siguiente       = *Lista1;
    *Lista1                         = Lista_Auxiliar;
}

void Lista_Visualizar(PUNTERO_LISTA Lista1)
{
    Lista_VuelvoAlInicio(&Lista1);
    PUNTERO_LISTA Lista_Auxiliar = Lista1;

    //Visualizo lista : recorrido normal
    printf("Lista (Recorrido normal)  : ");
    while (Lista_Auxiliar->Siguiente!=NULL)
    {
        printf("%c", Lista_Auxiliar->Dato);
        Lista_Avanzar(&Lista_Auxiliar);
    }
    printf("%c", Lista_Auxiliar->Dato);
    printf("\n");

    //Visualizo lista : recorrido inverso
    printf("Lista (Recorrido inverso) : ");
    while (Lista_Auxiliar->Anterior!=NULL)
    {
        printf("%c", Lista_Auxiliar->Dato);
        Lista_Retroceder(&Lista_Auxiliar);
    }
    printf("%c", Lista_Auxiliar->Dato);
    printf("\n");
}

void Lista_ReemplazoCaracter(PUNTERO_LISTA *Lista1, char Caracter_A_Remplazar, char Caracter_Reemplazador)
{
    PUNTERO_LISTA Lista_Auxiliar = *Lista1;
    Lista_VuelvoAlInicio(&Lista_Auxiliar);
    while (Lista_Auxiliar->Siguiente!=NULL)
    {
        if (Lista_Auxiliar->Dato==Caracter_A_Remplazar)
        {
            Lista_Auxiliar->Dato=Caracter_Reemplazador;
        }
        Lista_Avanzar(&Lista_Auxiliar);
    }
    if (Lista_Auxiliar->Dato==Caracter_A_Remplazar)
    {
        Lista_Auxiliar->Dato=Caracter_Reemplazador;
    }
    Lista_VuelvoAlInicio(&Lista_Auxiliar);
    *Lista1 = Lista_Auxiliar;
}

void Lista_VuelvoAlInicio(PUNTERO_LISTA *Lista1)
{
    PUNTERO_LISTA Lista_Auxiliar = *Lista1;
    while (Lista_Auxiliar->Anterior!=NULL)
    {
        Lista_Retroceder(&Lista_Auxiliar);
    }
    *Lista1 = Lista_Auxiliar;

}
