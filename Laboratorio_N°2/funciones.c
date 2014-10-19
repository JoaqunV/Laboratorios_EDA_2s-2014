#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* DEFINICIÓN DE MACROS, VARIABLES GLOBALES Y CONSTANTES*/
#define CANTIDADCARTAS 108
char colores[4] = "RBGY";

/*===================================DEFINICIÓN DE ESTRUCTURAS ===========================================*/

/** 
	Estructura de dato abstracto Carta
	Se compone de:
		- Variable entera tipo. (0 = normal, 1=especial)
		- Cadena de caracteres 'Valor'.
		- Char color, indica el color de cada carta.
*/
typedef struct cartas{
	int  tipo;
	char valor[8];
	char color;
}Carta;

/** 
	Estructura de dato abstracto cartasJugadas
	Se compone de:
		- Variable entera tope, indica la cantidad de cartas que se han jugado.
		- Lista de cartas jugadas. 
*/
/*typedef struct jugadas{
	int tope;
	Carta *carta;
}cartasJugadas;*/

/** 
	Estructura de dato abstracto Juego
	Lista circular doblemente enlazada que servirá para emular el comportamiento del juego desarrollado.
	Se compone de:
		- Variable de tipo puntero-entero denominado anterior, indica la posición en la lista del jugador anterior.
		- Variable de tipo puntero-entero denominado siguiente, indica la posición en la lista del jugador siguiente.
		- Pila de cartas que han sido jugadas.
*/
typedef struct listaCircular
{
	Carta *Mano;
	int topeMano;
	//int *anterior;
	//int *siguiente;
}Jugador;
	
/** 
	Estructura de dato abstracto Mazo
	Se compone de:
		- Variable entera tope, indica la cantidad de cartas disponibles en el mazo.
		- Lista de cartas presentes en el mazo.
*/
typedef struct pila{
	//definición estructura pila que será ocupada como el mazo.
	int tope;
	Carta *carta;
}Mazo;

/*===================================DEFINICIÓN DE FUNCIONES ===========================================*/

/** @function CrearMazo
	@brief Crea un mazo vacio
	@param None
*/
Mazo crearMazo()
{
    Mazo  mazo;
    mazo.carta = malloc(sizeof(Carta)*CANTIDADCARTAS);
    mazo.tope  = -1;
    return(mazo);
}

/** @function esVacio
	@brief Verifica si la pila (Mazo) ingresada es vacia.
	@param None
	@return 1 si la lista es vacia y 0 si la lista tiene al menos un elemento.
*/
int esVacio(Mazo m)
{
    if(m.tope == -1)
        return 1;
    else
        return 0;
}

/** @function asignarCartasAMazo
	@brief Al mazo creado, le asigna la totalidad de cartas que este puede soportar.
	@param Mazo vacio.
	@return Mazo con cartas.
*/
Mazo asignarCartasAMazo(Mazo m)
{
	int i, j=0;
	for(i=0;i<8;i++)
	{   
		m.carta[i].tipo  = 1;
		strcpy(m.carta[i].valor, "Invertir");
		m.carta[i].color = colores[j];	
		j++;
		if(j>3)
		{
			j = 0;
		}	
	}

	/** Asigno Saltar */
	j = 0;
	for(i=8;i<16;i++)
	{   
		m.carta[i].tipo  = 1;
		strcpy(m.carta[i].valor, "Saltar");
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j = 0;
		}	
	}

	/** Asigno +2 */
	j = 0;
	for(i=16;i<24;i++)
	{   
		m.carta[i].tipo  = 1;
		strcpy(m.carta[i].valor, "+2");
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j = 0;
		}	
	}

	/** Asigno +4 */
	j = 0;
	for(i=24;i<28;i++)
	{   
		m.carta[i].tipo  = 1;
		strcpy(m.carta[i].valor,"+4"); 
		m.carta[i].color, "T";	
	}

	/** Asigno cambioColor */
	j = 0;
	for(i=28;i<32;i++)
	{   
		m.carta[i].tipo  = 1;
		strcpy(m.carta[i].valor, "Cambio"); 
		m.carta[i].color, "T";	
	}
	
	/** Asigno cartas 0 */
	j = 0;
	for(i=32;i<36;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "0"); 
		m.carta[i].color = colores[j];		
		j++;
	}

	/** Asigno cartas 1 */
	j = 0;
	for(i=36;i<44;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "1"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}	
	/** Asigno cartas 2 */
	j = 0;
	for(i=44;i<52;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "2"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 3 */
	j = 0;
	for(i=52;i<60;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "3"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 4 */
	j = 0;
	for(i=60;i<68;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "4"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 5 */
	j = 0;
	for(i=68;i<76;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "5"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 6 */
	j = 0;
	for(i=76;i<84;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "6"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 7 */
	j = 0;
	for(i=84;i<92;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "7"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 8 */
	j = 0;
	for(i=92;i<100;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "8"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}

	/** Asigno cartas 8 */
	j = 0;
	for(i=100;i<108;i++)
	{   
		m.carta[i].tipo  = 0;
		strcpy(m.carta[i].valor, "9"); 
		m.carta[i].color = colores[j];		
		j++;
		if(j>3)
		{
			j=0;
		}
	}
	m.tope = 107;
	return(m);
}			

/** @function revolverMazo
	@brief    Baraja el mazo 
	@param    Mazo M con cartas asignadas.
	@return   Mazo con cartas.
*/
Mazo revolverMazo(Mazo m)
{
	int i, j;
	Carta auxiliar;
	srand(time(0)); 
	int maximo = m.tope;
	for (i = 1; i <=maximo; i++)
	{
		j = rand()%(maximo)+1;
		auxiliar = m.carta[i];
		m.carta[i] = m.carta[j];
		m.carta[j] = auxiliar; 
	}
	return m;
}

/** @function entregarCarta
	@brief    Entrega la primera carta de la pila Mazo.
	@param    Paso por referencia del Mazo implementado.
	@return   Carta solicitada.
*/
Carta entregarCarta(Mazo *m)
{
	int indice = m->tope;
	m->tope--;
	return m->carta[indice];
}

/** @function insertarCartaAMazo
	@brief    Inserta carta al final del mazo.
	@param    Paso por referencia del Mazo implementado y la carta a ingresar.
	@return   None
*/
void insertarCartaAMazo(Mazo *m, Carta car)
{
	int i, indice;
	indice = m->tope;
	if(indice>=108)
	{
		printf("ERROR: El mazo tiene el total de cartas asignadas\n");

	}
	for (i = indice; i >= 0; i--)
	{
		m->carta[i+1] = m->carta[i];
	}
	m->carta[0] = car;
}

/** @function crearJugador
	@brief    Crea un jugador con sus atributos nulos.
	@param    None
	@return   Jugador creado.
*/
Jugador crearJugador()
{
	Jugador  jugs;
    jugs.Mano = (Carta*)malloc(sizeof(Carta)*CANTIDADCARTAS);
    jugs.topeMano = 0;
    //jugs.anterior  = NULL;
    //jugs.siguiente = NULL;
    return(jugs);
}

/** @function crearJugadores
	@brief    Crea una cantidad indicada de jugadores, cotejandolos en un arreglo dinamico de jugadores.
	@param    cantidad de jugadores.
	@return   Arreglo de Jugadores creado.
*/
Jugador *crearJugadores(int cantidadJugadores)
{
	int i;
	Jugador *jugadores = (Jugador*)malloc(sizeof(Jugador)*cantidadJugadores);
	for ( i= 0; i < cantidadJugadores; i++)
	{
		jugadores[i] = crearJugador();
	}
	return jugadores;
}

Mazo repartirCartas(Jugador *jugadores, int cantidadJugadores, Mazo mazo)
{
	int i, j;
	for(i = 0; i < cantidadJugadores; i++)
	{
		for(j = 0; j < 7; j++)
		{
			jugadores[i].Mano[j] = entregarCarta(&mazo);	
			jugadores[i].topeMano++;
		}

	}
	return mazo;
}

Carta obtenerUltimaCartaJugada(Mazo m){
	return m.carta[0];
}

Carta jugarCarta(Jugador jugador, Mazo mazo, Carta ultimaCartaJugada)
{
	char color;
	color = ultimaCartaJugada.color;
}	

void mostrarManoJugador(Jugador jugador)
{
	int i;
	for (i = 0; i < jugador.topeMano; i++)
	{
		if(jugador.Mano->tipo==0)
		{

		}
		else
		{
			
		}	
	}
}


int main(){

	Mazo M;
	Jugador *j;
	int opcion, numJugadores = 2;
	printf("=====================================================================\n");
	printf("=======    BIENVENIDO A UNO, EL JUEGO LIDER DEL MERCADO    ==========\n");
	printf("=====================================================================\n");
	do
	{
		printf("\n*****Menú******\n");
		printf("===> 1) Jugar una partida individual contra el sistema.\n");
		printf("===> 2) Jugar contra varios oponentes del sistema.\n");
		printf("===> 3) Salir\n");
		printf("Ingrese opción: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
					M = crearMazo();
					M = asignarCartasAMazo(M);
					j = crearJugadores(numJugadores);
					M = repartirCartas(j, numJugadores, M);
					printf("===========    ¡COMIENZA EL JUEGO!    ===========\n");
					printf("|       Tipo       |   Valor   |     Color   \n");


			break;
			case 2:
					/*
					printf("\nIngrese numero de jugadores(Minimo 2, maximo 4): \n");
					scanf("%d", &numJugadores);
					if (numJugadores>4 || numJugadores<2)
					{
						printf("El numero de jugadores no es acorde a las especificaciones del juego\n");
					}
					else*/
						//Hago el multijugador
				
			break;
			case 3:
			break;
			default:
			break;
		}
	}while(opcion!=3);
	return 0;
}

