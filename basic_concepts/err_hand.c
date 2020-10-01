#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // o por ejemplo, extern int errno;
#include <math.h>

int main()
{
    errno = 0;
    /*
        - Write code to prevent errors
        - Use exit statement to gracefully end program execution, closes any open file connections and processes
        - Use errno, perror() and strerror() to identify error through error codes
        - You can return 0 for success and -1 for failure, stdlib.h macros EXIT_SUCCESS and EXIT_FAILURE are commonly used
        - perror() debe incluir un mensaje de lo que sucedio
        - strerror() transforma errno en el mensaje de error apuntado por esa variable
    */
    int x = 10;
    int y = 1;

    if (y != 0)
        printf("x / y = %d\n", x / y);
    else
    {
        printf("El divisor es 0, saliendo...\n");
        exit(EXIT_FAILURE);
    }

    // errno es una variable global la cual debe ser puesta en 0 antes de llamar una funcion de libreria, esta definida en errno.h
    errno = 0;

    // codigos de error que existen (134)
    for (int i = 0; i < 135; i++)
        fprintf(stderr, "%d: %s\n", i, strerror(i));

    /*FILE *fileptr;
    fileptr = fopen("non_existant_file.txt", "r");
    if (fileptr == NULL)
    {
        perror("Error opening file. ");
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fclose(fileptr);*/

    float k = -5;
    float num = 1000;
    float result;

    errno = 0;

    sqrt(3.5);
    result = sqrt(k);

    if (errno == 0)
        printf("%f\n", result);
    else if (errno == EDOM)
        fprintf(stderr, "%s\n", strerror(errno));

    errno = 0;

    result = exp(num);

    if (errno == 0)
        printf("%f\n", result);
    else if (errno == ERANGE)
        fprintf(stderr, "%s\n", strerror(errno));

    // IO related error functions
    /*
        feof(fp)     Devuelve un valor diferente de 0 si se alcanzo el final, de otro modo 0. feof inicializa EOF
        ferror(fp)   Devuelve un valor diferente de 0 si hay un error, de otro modo 0.
    */

    FILE *fileptr;
    int c;

    errno = 0;

    fileptr = fopen("myfile.txt", "r");
    if (fileptr == NULL)
    {
        fprintf(stderr, "Error opening file. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((c = getc(fileptr)) != EOF)
        printf("%c", c);

    if (ferror(fileptr))
    {
        printf("I/O error reading file.");
        exit(EXIT_FAILURE);
    }
    else if(feof(fileptr))
        printf("End of file reached.");

    return 0;
}