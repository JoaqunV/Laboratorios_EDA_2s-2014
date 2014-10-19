// Implementacion de las funciones
void insertar(int elem, int pos) 
{
	int i;
	if(pos > fin || pos < 0) 
	{
		printf("ERROR: posicion no existe.\n");
		return;
	}
	if(fin == 0) 
	{
		lista = (int *) malloc(sizeof(int));
		if(!lista) {
		printf("ERROR: No se pudo asignar memoria.\n");
		return;
		}
		lista[0] = elem;
	}
	else 
	{
		lista = (int *) realloc(lista, (fin + 1) * sizeof(*lista));
		if(!lista) 
		{
			printf("ERROR: No se pudo asignar memoria.\n");
			return;
		}
		for(i = fin; i > pos; i--) 
		{
			lista[i] = lista[i - 1];
		}
		lista[pos] = elem;
	}
	fin++;
}

void borrar(int pos) 
{
	int i;
	if(pos >= fin || pos < 0) 
	{
		printf("ERROR: posicion no existe.\n");
		return;
	}
	for(i = pos; i < fin - 1; i++) 
	{
		lista[i] = lista[i + 1];
	}
	fin--;
	lista = (int *) realloc(lista, (fin) * sizeof(*lista));
	if(!lista) 
	{
		printf("ERROR: No se pudo reasignar memoria.\n");
		return;
	}
}

void anular() 
{
	lista = NULL;
	fin = 0;
	free(lista);
}