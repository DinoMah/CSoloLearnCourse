#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*
        Mode options:
        - r  open for reading (file must exist)
        - w  open for writing (file need not exist)
        - a  open for append (file need not exist)
        - r+ open for reading and writing from beginning
        - w+ open for reading and writing, overwriting file
        - a+ open for reading and writing, appending to file
    */
    FILE *fileptr;
    int stock;
    char c;
    char buffer[200], item[10];
    float price;
    fileptr = fopen("./myfile.txt", "r");
    if (fileptr == NULL)
    {
        printf("Error opening file.");
        return -1;
    }
    fgets(buffer, 20, fileptr);
    printf("%s\n", buffer);

    fscanf(fileptr, "%d%s%f", &stock, item, &price);
    printf("%d %s %4.2f\n", stock, item, price);

    while ((c = getc(fileptr)) != EOF)
        printf("%c", c);

    // WRITING TO FILES
    char filename[50];
    printf("Enter the filename of the file to create: ");
    fgets(filename, 50, stdin);
    fileptr = fopen(filename, "w");

    //fputc(char, ptr) writes a character to the file pointed by ptr
    // Prints string to the file pointed by ptr. string can optionally include format specifiers and a list of variables
    fprintf(fileptr, "Inventario\n");
    fprintf(fileptr, "%d %s %f\n", 100, "Widget", 0.29);
    
    // fputs(str, fp); writes str to the file pointed by fp
    fputs("End of List", fileptr);

    fclose(fileptr);
    return 0;
}