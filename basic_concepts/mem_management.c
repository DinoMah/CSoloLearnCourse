#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int num;
    char *info;
} record;

typedef struct {
    int *elements;
    int size;
    int cap;
} dyn_array;

int main()
{
    /*
        Memory management functions
        malloc(bytes)                    regresa un puntero de un bloque continuo de tamaño bytes
        calloc(num_items, item_size)     regresa un puntero de un bloque continuo que tiene num_items objetos c/u tamaño item_size
        realloc(ptr, bytes)              agrega memoria a la memoria apuntada por ptr a determinados bytes. La nueva memoria no es inicializada
        free(ptr)                        libera la memoria apuntada por ptr
    */

    // MALLOC
    int *ptr;
    ptr = malloc(10 * sizeof(*ptr)); // Crea el espacio de memoria
    if (ptr != NULL)
    {
        *(ptr + 2) = 50;
    }
    printf("%d\n", *(ptr + 2));
    // FREE
    free(ptr); // Libera el espacio de memoria


    record *recs;
    int num_recs = 2;
    int k;
    char str[] = "This is information";
    recs = calloc(num_recs, sizeof(record));
    if (recs != NULL)
        for (k = 0; k < num_recs; k++)
        {
            (recs+k)->num = k;
            (recs+k)->info = malloc(sizeof(str));
            strcpy((recs+k)->info, str);
        }
    
    ptr = malloc(10 * sizeof(*ptr));
    if (ptr != NULL)
        *(ptr + 2) = 50;
    ptr = realloc(ptr, 100 * sizeof(*ptr));
    *(ptr + 30) = 75;

    char str20[20];
    char *strD = NULL;

    strcpy(str20, "12345");
    strD = malloc(strlen(str20) + 1);
    strcpy(strD, str20);
    printf("%s\n", strD);


    dyn_array arr;
    arr.size = 0;
    arr.elements = calloc(1, sizeof(*arr.elements));
    arr.cap = 1;
    arr.elements = realloc(arr.elements, (5+arr.cap) * sizeof(*arr.elements));
    if (arr.elements != NULL)
        arr.cap += 5;

    if (arr.size < arr.cap)
    {
        arr.elements[arr.size++] = 50; 
    }
    else
        printf("Need to expand the array");
    return 0;
}