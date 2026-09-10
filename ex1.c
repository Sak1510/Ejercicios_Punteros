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
char **strsplit(char *str, int *words_count);
char *_strrev(char *str);


char **split_and_reverse(char *frase, int *num_palabras); 
int main(void) {
	size_t buffer_size = 1024;
	char *str_buffer = (char *)malloc(sizeof(char) * buffer_size);
	if(str_buffer == NULL) {
		printf("[!] ERROR. malloc fallo.\n");
		return -1;
	}

	printf("Frase: ");
	if(fgets(str_buffer, buffer_size, stdin) == NULL) {
		printf("[!] Fallo fgets().");
		free(str_buffer);
		return -1;
	}


	// 	========	PRUEBAS		========
	printf("\n[+] str_buffer = %s\n", str_buffer);

	int num_palabras = 0;
	char **str_split = strsplit(str_buffer, &num_palabras);
	printf("[+] num_palabras = %d\n", num_palabras);

	char *str_rev = _strrev(str_buffer);
	if(str_rev == NULL) {
		printf("[!] Fallo _strrev().\n");
		free(str_split);
		free(str_buffer);
		return -1;
	}

	printf("[+] str_rev = %s\n", str_rev);

	// Se libera toda la memoria
	free(str_rev);
	free(str_split);
	free(str_buffer);

	printf("[!] Fin del programa\n");
	return 0;
}




/**
 * Llamar en caso de fallar malloc() dentro de una función. 
 * Libera la memoria del puntero el cual se procesa y se le asigna el valor NULL.
 * \param str String a imprimir por el error.
 * \param p Puntero para liberar. 
 * \returns NULL
 */
void *freep_error(char *str, void *p) {
	if(str != NULL)
		printf("%s\n", str);
	
	free(p);
	return p = NULL;
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
	while(*str_copy++ != '\0')
		strlen_++;

	return strlen_;
}


/**
 * Retorna un puntero que apunta a varios punteros que cada
 * uno apunta a una string en especifico 
*/
char **strsplit(char *str, int *words_count) {
	/** Algoritmo de la función
	    1. Verificar si str != NULL
	    2. Limpiar eapacios repetidos, de inicio y final en caso de existir
	    3. Contar cuantas palabras hay en la frase contando espacios
	    4. Reservar la memoria para cada palabra
	    5. Copiar denteo de cada casilla su respectiva palabra 
	*/

	// Si str esta vacio, retorna NULL 
	if(str == NULL)
		return NULL;

	// Se reserva la memoria necesaria para la string limpia de espacios repetidos
	char *str_clean = (char *)malloc(sizeof(char) * _strlen(str));
	char *memory_str_clean = str_clean;
	if(str_clean == NULL) 
		return (char **)freep_error("[!] ERROR. malloc() fallo en _strrev().\n", str_clean);

	// Eleminar espacios repetidos al inicio de la string
	char *str_copy = str;
	while(*str_copy == ' ') 
		str_copy++;

	// Si se identifica que el ultimo caracter es '\0',
	// se libera el espacio de memoria reservado y se termina la función
	if(*str_copy == '\0') {
		free(str_clean);
		return NULL;
	}

	// Se evitan los espacios repetidos dentro de la string entre palabras
	// y cuenta al mismo tiempo, cuantas palabras hay dentro de la string
	(*words_count) = 0;
	while(*(str_copy + 1) != '\0') {
		if(!(*str_copy == ' ' && *(str_copy + 1) == ' ')) {
			(*str_clean++) = *str_copy;

			if(*str_copy == ' ')
				(*words_count)++;
		}

		str_copy++;
	}

	// En caso de que el ultimo caracter guardado, sea un espacio, se descarta
	if(*(--str_clean) == ' ') {
		(*str_clean) = '\0';
		(*words_count)--;
	} else // Se hace que el ultimo caracter de la string sea \0 para cerrar
		(*++str_clean) = '\0';

	// Se vuelve a la memoria de inicio
	str_clean = memory_str_clean;

	// Se cuenta una palabra más
	(*words_count)++;

	printf("\t [*] \"%s\"\t => \"%s\"\n", str, str_clean);


	// Cuenta cuantas palabras hay dentro de str

	char **strsplit_ = NULL;
	return strsplit_;
}


/**
 * Retorna la string recibida volteada de fin a inicio.
 * \param str String a procesar.
 * \returns La string volteada. Si falla, retorna NULL
 */
char *_strrev(char *str) {
	// Si str esta vacio, retorna NULL
	if(str == NULL)
		return NULL;

	// Reserva la memoria con malloc de la nueva frase
	char *strrev_ = (char *)malloc(_strlen(str) * sizeof(char));
	if(strrev_ == NULL)
		return (char *)freep_error("[!] ERROR. malloc() fallo en strrev().\n", (void *)strrev_);

	// Se inicia desde el ultimo espacio de memoria de strrev_
	strrev_ += _strlen(str) - 1;
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
