#include <stdio.h>
#include <stdlib.h> // esta libreria incluye qsort

void * cuadrado(const void *);
int compare(const void *, const void *);

int main(void)
{
    int x = 33;
    float y = 12.4;
    char c = 'a';
    void *ptr; // no se puede realizar aritmetica de punteros en un puntero void

    ptr = &x;
    printf("void ptr points to %d\n", *((int *)ptr));
    ptr = &y;
    printf("void ptr points to %f\n", *((float *)ptr));
    ptr = &c;
    printf("void ptr points to %c\n", *((char *)ptr));

    int sq_int;
    x = 6;
    sq_int = cuadrado(&x);
    printf("el cuadrado de %d es %d\n", x, sq_int);


    // QSORT
    int arr[5] = {52, 23, 56, 19, 4};
    int num, width, i;
    num = sizeof(arr) / sizeof(arr[0]);
    width = sizeof(arr[0]);
    qsort( (void *)arr, num, width, compare);
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

void * cuadrado(const void *num)
{
    int result;
    result = (*(int *)num) * (*(int *)num);
    return result;
}

int compare(const void *elem1, const void *elem2)
{
    if ( *(int *)elem1 == *(int *)elem2 )
        return 0;
    else if ( *(int *)elem1 < *(int *)elem2 )
        return -1;
    else
        return 1;
}