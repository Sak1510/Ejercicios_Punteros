/*
EJERCICIO: INVERTIR PALABRAS

1. Pide al usuario una frase por teclado (maximo no sabes cual es,
   asi que tendras que pedir memoria dinamica).

2. Crea una funcion con esta firma:
   char** split_and_reverse(char *frase, int *num_palabras); 

   Lo que tiene que hacer:
   - Recibe "frase" original.
   - Cuenta cuantas palabras hay.
   - Hace malloc para un array de punteros char** (una casilla por palabra).
   - Para cada palabra, hace malloc para copiar esa palabra PERO invertida.
     Ej: "hola" -> "aloh"
   - Guarda en *num_palabras cuantas palabras encontro.
   - Devuelve el array.

3. En el main, imprime las palabras invertidas en orden inverso a la frase
   original. Ej:
   Entrada: hola mundo cruel
   Salida:
   leurc
   odnum
   aloh

4. Libera TODA la memoria que pediste antes de terminar.
   Ni un malloc sin su free.

REGLAS:
- No puedes usar [] para acceder al array, solo aritmetica de punteros *(arr + i)
- No puedes usar strtok, strrev ni nada parecido. Hazlo a mano con punteros.
- Si malloc falla, libera todo lo que ya pediste y sal.
*/

#include <stdio.h>
#include <stdlib.h>

char **split_and_reverse(char *frase, int *num_palabras); 

int main(void) {
	int buffer_size = 100;
	char *str_buffer = (char *)malloc(sizeof(char) * buffer_size);

	printf("Frase: ");
	str_buffer = fgets(str_buffer, buffer_size, stdin);

	if(str_buffer == NULL) {
		printf("[!] Fallo fgets().");
		exit(1);
	}

	printf("[+] str_buffer = %s", str_buffer);

	// Funcion que voltea las palabras
	int num_palabras = 0;
	char **split_buffer = split_and_reverse(str_buffer, &num_palabras);

	printf("num_palabras = %d\n", num_palabras);

	free(split_buffer);
	free(str_buffer);
	return 0;
}


char **split_and_reverse(char *frase, int *num_palabras) {
	// Si uno de los dos punteros esta vacio, se termina el programa
	if(frase == NULL || num_palabras == NULL)
		return NULL;
		
	int np = 0;		// Numero de Palabras
	int nl = 0;		// Numero de Letras
	char *frase_copy = frase;
	
	while(*(frase_copy + 1) != '\0') {
		

	
		if(*frase_copy == ' ') 
			np++;
	}
	
	return NULL;
}  
