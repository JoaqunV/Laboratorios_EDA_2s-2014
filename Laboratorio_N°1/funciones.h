#include <stdio.h>
#include <stdlib.h>
#define LARGO 1100

int *suma(int numero1[], int numero2[], int largo)
{
    int indice, acumulador=0;
    int *Array = (int*) calloc (largo, sizeof(int));
    for(indice=largo-1;indice>=0;indice--)
    {
        int s = numero1[indice] + numero2[indice];
        if(s/10>=1)
        {
            Array[indice]     = s % 10;
            acumulador        = s / 10;
            numero1[indice-1] = numero1[indice-1] + acumulador;
        }
        else
        {
            Array[indice] = s;
        }
    }
    return Array;
}


void fibonacci(int n)
{
    int Valor1[LARGO], Valor2[LARGO], indiceAuxiliar, indice, valor = 1;
    for(indice=0; indice < LARGO; indice++)
    {
        Valor1[indice]=0;
        Valor2[indice]=0;
	    if(indice==LARGO-1)
	    {
            Valor2[indice]=1;
        }   
    }
    for(indiceAuxiliar = 1; indiceAuxiliar < n; indiceAuxiliar++)
    {
        int *Puntero = suma(&Valor1, &Valor2, LARGO);
        for(indice=0;indice<LARGO;indice++)
        {
          Valor1[indice] = Valor2[indice];
          Valor2[indice] = Puntero[indice];
        }
    }
    for(indice=0;indice<LARGO;indice++)
    {    
        if(valor==1)
        {
            if (Valor2[indice+1]!=0)
            {
                 valor=0;
            }          
        }
        else
        {
            printf("%d", Valor2[indice]);
        }
    }    
}