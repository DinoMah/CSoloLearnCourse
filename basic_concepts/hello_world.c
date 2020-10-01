#include <stdio.h>

void cambiar(int *, int *);
int * dame_pares();

int main()
{
    int j = 63;
    int *p = NULL;
    p = &j;

    printf("La direccion de j es %x\n", &j);
    printf("p contiene la direccion %x\n", p);
    printf("el valor de j es %d\n", j);
    printf("p esta apuntando al valor %d\n", *p);

    // Algunos algoritmos usan puntero a puntero.
    int x = 12;
    int *p1 = NULL;
    int **pDoble = NULL;
    p1 = &x;
    pDoble = &p1;
    printf("Valor al que apunta pDoble: %d\n",**pDoble);
    (**pDoble)++;
    printf("Aumentando 1 a pDoble es: %d\n", **pDoble);


    // Aritmetica de punteros
    int a[5] = {22, 33, 44, 55, 66};
    int *ptr = NULL;
    int i;
    ptr = a;
    for (i = 0; i < 5; i++)
        printf("%d\n", *(ptr + i));
    ptr++;
    ptr += 2;
    ptr--;
    ptr -= 2;
    printf("%d\n", *ptr);

    printf("Valores de j y x antes de cambiar: %d, %d\n", j, x);
    cambiar(p, p1);
    printf("Valores de j y x despues de cambiar: %d, %d\n", j, x);

    int *arreglo;
    int k;
    arreglo = dame_pares();
    for(k = 0; k < 5; k++)
        printf("%d\n", arreglo[k]);
    return 0;
}

void cambiar(int *num1, int *num2)
{
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int * dame_pares()
{
    static int numeros[5];
    int k;
    int par = 0;
    for (k = 0; k < 5; k++)
        numeros[k] = par += 2;
    return numeros;
}
// las variables estaticas conservan su valor entre llamadas de funcion y no son destruidas al salir de la funcion