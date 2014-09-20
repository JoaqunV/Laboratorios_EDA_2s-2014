









			#include "funciones.c"

			int main(int argc, char **argv)
			{
				if(argc==2)
				{
				    int n = atoi(argv[1]);
				    fibonacci(n);
				    printf("\n");
				}	
			    else
			    {
			    	printf("Debe ingresar el numero N a evaluar como parametro,");
				printf("separado por un espacio del nombre del archivo ejecutable.\n");
			    }	
			    return 0;
			}
