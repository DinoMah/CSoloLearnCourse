#include <stdio.h>
#include <string.h> // Libreria para manipular strings

int main()
{
    char string[5] = "Hola";
    char string1[] = {'H', 'O', 'L', 'A', '\0'};
    int i;
    for (i = 0; i < sizeof(string)/sizeof(char); i++)
        printf("%c\n", string[i]);

    for (i = 0; i < strlen(string1); i++)
        printf("%c\n", string1[i]);

    /*
        Funciones para strings
        strlen(string) me da el size de la cadena sin el \0
        strcat(str1, str2) agrega al final de str1 str2 y devuelve el puntero de str1
        strcpy(str1, str2) copia st2 en str1. util para asignar un nuevo string
        strlwr() pone en minusculas la cadena
        strupr() pone en mayusculas la cadena
        strrev() invierte la cadena
        strcmp() compara dos strings

        Para leer cadenas desde consola
        scanf(%s, string) lee hasta que encuentra un espacio y solo almacena la capacidad del array
        gets(string) lee hasta un salto de linea, no es seguro por que puede ocasionar un buffer overflow
        fgets(string, 50, stdin) lee n-1 caracteres, stdin significa que lee desde la entrada estandar (aka el teclado)

        Para mostrar cadenas a la salida estandar (aka la consola)
        fputs(string, stdout) necesita el string a mostrar y a donde lo vas a mostrar (stdout) 
        puts(string) muestra el string y agrega un salto de linea
        printf("%s", string)
    */
    char *constString = "constante"; // Cadena constante debido a su tipo de declaracion

    char info[100];
    char dept[] = "HR";
    int emp = 75;
    sprintf(info, "The %s dept has %d employees.", dept, emp); // Guarda la cadena en info
    printf("%s\n", info);

    char info1[] = "Snoqualmie WA 13190";
    char city[50];
    char state[50];
    int population;
    sscanf(info1, "%s %s %d", city, state, &population); // Lee de un string hacia las variables
    printf("%d peoplie live in %s, %s.\n", population, city, state);


    char s1[] = "The grey fox";
    char s2[] = " jumped.";

    strcat(s1, s2);
    printf("%s\n", s1);
    printf("Length of s1 is %ld\n", strlen(s1));
    strcpy(s1, s2);
    printf("s1 is now %s\n", s1);

    /*
        strncat(str1, str2, n) Concatena los 1ros n carac. de str2 al final de str1 y regresa puntero a str1
        strncpy(str1, str2, n) Copia los primeros n carac. de str1 a str1
        strcmp(str1, str2)     Regresa 0 cuando son iguales, < 0 cuando str1 < str2 y > 0 cuando str1 > str2
        strchr(str1, c)        Regresa un puntero a la primera ocurrencia de c en str1 o NULL si c no se encontro
        strrchr(str1, c)       Busca c en str1 de manera inversa, regresa un puntero a c o NULL si c no se encontro
        strstr(str1, str2)     Regresa un puntero a la primera ocurrencia de str2 en str1 o NULL si str2 no se encontro
    */

    // CONVERSION DE STRING A NUMERO
    char input[10];
    int num;
    printf("Dame un numero: ");
    fgets(input, 10, stdin);
    num = atoi(input); // Se le manda un string como argumento y regresa un numero, regresa 0 si no es un numero
    /*
        Otras funcionas para lo mismo en distintos tipos de datos
        double atof(str)    Convierte de string a double, default regresa 0.0
        long int atol(str)  Convierte de string a long int, default regresa 0
        Se recomienda el uso de strtol() para el manejo de errores
    */
    printf("Numero dado: %d\n", num);


    // ARREGLO DE CADENAS
    char trip[3][15] = {
        "maleta",
        "pasaporte",
        "ticket"
    };

    printf("Por favor, traiga lo siguiente:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", trip[i]);
    }

    strcpy(trip[0], trip[1]);
    printf("%s\n", trip[0]);

    // Al declarar char *items[3]; solo reserva espacio para 3 punteros, las cadenas son referenciadas por los punteros
    char *names[] = { // Son cadenas constantes
        "John",
        "Jill",
        "Janet"
    };

    //strcpy(names[0], names[1]);
    printf("%s\n", names[0]);
    return 0;
}