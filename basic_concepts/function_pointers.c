#include <stdio.h>

void say_hello(int);

int add(int, int);
int sub(int, int);
int mul(int, int);
int div(int, int);

int main(void) 
{
    void (*funptr)(int);
    funptr = say_hello;
    funptr(3);


    int x, y, choice, result;
    int (*op[4])(int, int);
    op[0] = add;
    op[1] = sub;
    op[2] = mul;
    op[3] = div;
    printf("Dame dos enteros: ");
    scanf("%d %d", &x, &y);
    //fflush(stdin);
    printf("Escribe 0 para sumar, 1 restar, 2 multiplicar, 3 dividir: ");
    scanf("%d", &choice);
    result = op[choice](x, y);
    printf("Resultado = %d\n", result);
    return 0;
}

void say_hello(int num_times)
{
    for (int k = 0; k < num_times; k++)
        printf("Hello\n");
}

int add(int num1, int num2)
{
    return num1 + num2;
}

int sub(int num1, int num2)
{
    return num1 - num2;
}

int mul(int num1, int num2)
{
    return num1 * num2;
}

int div(int num1, int num2)
{
    if (num2 != 0)
        return num1 / num2;
    else
        return 0;
}