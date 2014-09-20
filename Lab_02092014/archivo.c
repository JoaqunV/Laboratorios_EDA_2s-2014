#include "split.h"
#include "estructuras.h"
#include <stdlib.h>

int main()
{
	int mayor, menor, i, a, b, c, cantidad_alumnos;
	//Definición de variables
	Alumno *alumnos;
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen("ListaAlumnos.txt", "r");
	//si el archivo existe será distinto de null
	if(archivo==NULL)
	{
		printf("El archivo ListaAlumnos.txt no existe, tiene un nombre diferente o no se tiene permiso de lectura.\n");
	}
	else
	{
		int contador=0;
		int indice = 0;
		while(feof(archivo)==0)
		{
			if(contador==0)
			{
				contador++;
				fgets(lectura,100,archivo);
				//Definición de Variables
				cantidad_alumnos = atoi(lectura);
				//Se crea arreglo de alumnos del largo total existente.
				alumnos = (Alumno *)malloc(sizeof(Alumno)*cantidad_alumnos);
			}
			else 
			{
				
				fgets(lectura, 100, archivo);
				//printf("lectura: %s", lectura);
				array_lectura = str_split(lectura, ',');
				strcpy(alumnos[indice].nombre, array_lectura[0]);
				alumnos[indice].edad = atoi(array_lectura[1]);
				strcpy(alumnos[indice].cod_carrera, array_lectura[2]);
				alumnos[indice].a_ingreso = atoi(array_lectura[3]);
				contador++;
				indice++;
			}
		} 
		printf("**********Se ha leido la Base de datos de los alumnos ****\n");
		//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
		menor = 2014; 
		for(i=0;i<=cantidad_alumnos;i++)
		{
			if(menor<alumnos[i].a_ingreso)
			{
				mayor = alumnos[i].a_ingreso;
				a = i;
			}
		}
		printf("Uno de los alumnos mas antiguo de la carrera es: %s\n", alumnos[a].nombre);	
		for(i=0;i<=cantidad_alumnos;i++)
		{
			if(menor>=alumnos[i].edad)
			{
				menor = alumnos[i].edad;
				a = i;
			}
			if(mayor<=alumnos[i].edad)
			{
				mayor = alumnos[i].edad;
				b = i;
			}	
		}
		printf("El alumno menor es de la carrera #%s y su nombre es: %s \n", alumnos[a].cod_carrera, alumnos[a].nombre);
		printf("El alumno mayor es de la carrera #%s y su nombre es: %s \n", alumnos[b].cod_carrera, alumnos[b].nombre);
		a=0; b=0; c = 0;
		for(i=0;i<=cantidad_alumnos;i++)
		{
			if(strcmp(alumnos[i].cod_carrera, "C1000")==0)
				c++;
			else 
				if(strcmp(alumnos[i].cod_carrera, "C1001")==0)
					a++;
				else
					b++;
		}
		printf("Existen %d alumnos que estan en la carrera C1000 \n", c);
		printf("Existen %d alumnos que estan en la carrera C1001 \n", a);
		printf("Existen %d alumnos que estan en la carrera C1002 \n", b);
	}
	return 0;
}