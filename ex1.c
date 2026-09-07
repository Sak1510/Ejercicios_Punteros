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
- No puedes usar [] para acceder al array, solo aritmetica de punteros *(arr + index)
- No puedes usar strtok, strrev ni nada parecido. Hazlo a mano con punteros.
- Si malloc falla, libera todo lo que ya pediste y sal.
*/

#include <stdio.h>
#include <stdlib.h>

void *freep_error(char *str, void *p);
size_t _strlen(char *str);
char **strsplit(char *str);
char *_strrev(char *str);


char **split_and_reverse(char *frase, int *num_palabras); 
int main(void) {
	int buffer_size = 100;
	char *str_buffer = (char *)malloc(sizeof(char) * buffer_size);
	if(str_buffer == NULL) {
		printf("[!] ERROR. malloc fallo.\n");
		free(str_buffer);
		exit(1);
	}

	printf("Frase: ");
	fgets(str_buffer, buffer_size, stdin);

	if(str_buffer == NULL) {
		printf("[!] Fallo fgets().");
		exit(1);
	}


	// Funcion que voltea las palabras
	int num_palabras = 0;
	char **split_buffer = split_and_reverse(str_buffer, &num_palabras);


	// 	========	PRUEBAS		========
	printf("[+] str_buffer = %s\n", str_buffer);
	printf("num_palabras = %d\n", num_palabras);

	char *strrev_p = _strrev(str_buffer);
	printf("\nstrrev(%s) = %s\n", str_buffer, strrev_p);

	free(strrev_p);	
	free(split_buffer);
	free(str_buffer);
	return 0;
}


/**
 * Llamar en caso de fallar malloc() dentro de una función. Libera la memoria del puntero
 * el cual se procesa.
 * \param str String a imprimir por el error.
 * \param p Puntero para liberar. 
 * \returns NULL
 */
void *freep_error(char *str, void *p) {
	if(str != NULL)
		printf("%s\n", str);
	
	free(p);
	return NULL;	
}


/**
 * Retorna el número de caracteres que posee una string
 * \param str String a procesar.
 * \returns Tamaño de la string contando '\0'. Si falla, retorna 0.
*/
size_t _strlen(char *str) {
	if(str == NULL) 
		return 0;

	char *str_copy = str;
	size_t strlen_ = 0;
	while(*(str_copy + 1) != '\0') {
		strlen_++;
		str_copy++;
	}

	return ++strlen_;
}


/**
 * Retorna un puntero que apunta a varios punteros que cada
 * uno apunta a una string en especifico 
*/
char **strsplit(char *str) {
	return NULL;
}


/**
 * Retorna la string recibida volteada de fin a inicio.
 * \param str String a procesar.
 * \returns La string volteada. Si falla, retorna NULL
 */
char *_strrev(char *str) {
	if(str == NULL)
		return NULL;

	// Reserva la memoria con malloc de la nueva frase
	char *strrev_ = (char *)malloc(strlen(str) * sizeof(char));
	if(strrev_ == NULL) 
		return (char *)freep_error("[!] ERROR. malloc() fallo en strrev().\n", (void *)strrev_);

	// Se inicia desde el ultimo espacio de memoria de strrev_
	strrev_ += strlen(str);
	(*strrev_) = '\0'; 

	// Guarda por cada espacio
	char *str_copy = str;
	while(*(str_copy + 1) != '\0') {
		(*--strrev_) = *str_copy;
		str_copy++;
	}

	return strrev_;
}

char **split_and_reverse(char *frase, int *num_palabras) {
	// Si uno de los dos punteros esta vacio, se termina el programa
	if(frase == NULL || num_palabras == NULL)
		return NULL;


	return NULL;
}
