#include <stdio.h>
#include <time.h> // time/date utilities
// the preprocessor expects <> when it gonna be searched in the include paths
// user-defined header files are also with .h extension but should be included with "" and not with <>
// Example: #include "myheader.h"

#define PI 3.14
#define AREA(r) (PI*r*r)
// You can define multiline #define with "\"
#define VERY_LONG_CONSTANT \
23.678901
#define MAX 100
#define MIN 0
#define SQUARE(x) \
    x*x

int main()
{
    /*
        Preprocessor directives:
        - #include                                    Includes header files
        - #define, #undef                             Defines and undefines macros
        - #ifdef, #ifndef, #if, #else #elif, #endif   Condicional compilation
        - #pragma                                     Implementation and compiler specific
        - #error, #warning                            Output and error or warning message. An error halts compilation
    */
    float radius = 2;
    
    printf("%3.2f\n", PI);
    printf("Area is %5.2f\n", AREA(radius));
    printf("Area with radius + 1: %5.2f\n", AREA(radius + 1)); // This might lead to unexpected results such as PI*radius+1*radius+1
    // define should be: #define AREA(r) (PI*(r)*(r))

    return 0;
}