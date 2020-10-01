#include <stdio.h>
#include <time.h> // time/date utilities
#include <string.h>
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
// PREDEFINED MACROS
/*
    __DATE__ Current date as a string in the format Mm dd yyyy
    __TIME__ Current time as a string in the format hh:mm:ss
    __FILE__ Current filename as a string
    __LINE__ Current line number as an int value
    __STDC__ 1
*/

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

    char curr_time[10];
    char curr_date[12];
    int std_c;

    strcpy(curr_time, __TIME__);
    strcpy(curr_date, __DATE__);

    printf("%s %s\n", curr_time, curr_date);
    printf("This is line %d\n", __LINE__);

    std_c = __STDC__;

    printf("STDC is %d\n", std_c);

    return 0;
}