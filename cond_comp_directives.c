#include <stdio.h>

/*
    #define RATE 0.08
    #ifndef TERM
        #define TERM 24
    #endif
*/

// #define LEVEL 4

// # operator, stringizer, scape sequences are recognized, whitespace and either side of the argument are ignored
#define TO_STR(x) #x

// ## operator is called the token pasting because it appends tokens together
#define VAR(name, num) name##num

int main()
{
    /*#ifndef RATE // Este pedazo será compilado
        #undef RATE
        printf("Rendering RATE\n");
        #define RATE 0.068
    #else // Este pedazo no sera compilado
        #define RATE 0.068
    #endif

    printf("%f %d\n", RATE, TERM);

    /*
        #ifdef    Verifica si esta definido, ejemplo: #ifdef CONS
        #ifndef   Verifica si NO esta definido, ejemplo: #ifndef CONS, se usa regularmente con #else
        #else     
        #elif
        #endif
    */
    
    /*#if LEVEL > 6
        // Hacer algo
    #elif LEVEL > 5
        // else if option
    #elif LEVEL > 4
        // another else if option
    #else
        // last option here
    #endif

    #if !defined(LEVEL)
        // Hacer algo
    #endif */

    // PREPROCESSOR OPERATORS
    printf("%s\n", TO_STR(123\\12));

    int x1 = 125;
    int x2 = 250;
    int x3 = 500;

    printf("%d\n", VAR(x, 3));

    return 0;
}