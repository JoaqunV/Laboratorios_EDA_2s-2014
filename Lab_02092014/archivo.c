#include "split.h"
#include "estructuras.h"

int main()
{

	//Definición de variables
	char nombre[50];
	char cod_carrera[4];
	int edad;
	int a_ingreso;
	//Crear arreglo donde se guardaran los strings entrantes
	char lectura[100];
	char** array_lectura;
	//Crear puntero donde se guardará la dirección del archivo
	FILE * archivo;
	//Abrir el archvio nombre.txt en modo de lectura read
	archivo = fopen("ListaAlumnos.txt", 'r');
	//si el archivo existe será distinto de null
	if(archivo!=null)
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
				int cantidad_alumnos = atoi(lectura);
				//Se crea arreglo de alumnos del largo total existente.
				Alumno *alumnos = (Alumno *)malloc(sizeof(Alumno)*cantidad_alumnos);
			}
			else 
			{
				contador++;
				fgets(lectura,100,archivo);
				array_lectura = str_split(lectura, ',');
				*(alumnos[indice]->nombre)      = array_lectura[1];
				*(alumnos[indice]->edad)        = atoi(array_lectura[2]);
				*(alumnos[indice]->cod_carrera) = array_lectura[3];
				*(alumnos[indice]->a_ingreso)   = atoi(array_lectura[4]);
			}
		} 
		//Finaliza While y se completa el arreglo con "cantidad_alumnos" elementos.
	}

	
	getche();
	return 0;
}