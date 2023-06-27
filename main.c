#include <stdio.h>

#define MAXLINE 80

int main(int argc, char **argv)
{
	char *nombre_archivo;
	FILE *fptr;
	char linea[MAXLINE];

	/* Verifica que se ha enviado exactamente un argumento */
	if (argc != 2){
		fprintf(stderr, "Error, uso incorrecto de argumentos.\n");
		fprintf(stderr, "Uso: %s <nombre archivo>\n", argv[0]);
		return 1;
	}

	/* obtiene nombre de archivo del argumento */
	nombre_archivo = argv[1];

	/* Abriendo el archivo */
	printf("Abriendo %s...\n", nombre_archivo);
	fptr = fopen(nombre_archivo, "r");

	/* Verifica que el archivo ha sido abierto correctamente */
	if(fptr != NULL){
		int n = 0;
		/* Lee primera linea del archivo */
		n = fscanf(fptr, "%s", linea);
		/* Lee el resto de lineas...*/
		for(int i=1; n == 1; i++){
			printf("Linea %d: %s\n", i, linea);
			n = fscanf(fptr, "%s", linea);
		}
	}else{
		fprintf(stderr, "Error al abrir %s\n", nombre_archivo);
		return 1;
	}

	/* Cierra el archivo */
	fclose(fptr);

	return 0;
}
