#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} item;

int main()
{
    /*
        rb   open file for reading (file must exist)
        wb   open file for writing (file must exist)
        ab   open file for append (file need not exist)
        rb+  open file for reading and writing from beginning
        wb+  open file for reading and writing, overwrites file
        ab+  open file for reading and writing, appending to file
    */
    
    FILE *fileptr;
    fileptr = fopen("datafile.bin", "wb");

    if (fileptr == NULL)
    {
        printf("No se pudo abrir el archivo, saliendo...");
        return -1;
    }

    /*
        fwrite(ptr, item_size, num_items, fp)   writes num_items of item_size from ptr to file pointed by fp
        fread(ptr, item_size, num_items, fp)    reads num_items of item_size from the file pointed by fp into ptr
        fclose(fp)                              Closes file pointed by fp, returns 0 if was successfull or EOF other way
        feof(fp)                                Returns 0 when the end of the file is reached
    */

    int arr[10];
    int x[10];
    int k;

    for (k = 0; k < 10; k++)
        arr[k] = k;

    fwrite(arr, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fileptr);

    fclose(fileptr);

    fileptr = fopen("datafile.bin", "rb");

    if (fileptr == NULL)
    {
        printf("No se pudo abrir el archivo, saliendo...");
        return -1;
    }
    
    /*
        fread(ptr, item_size, num_items, fp)   Reads num_items items with item_size size from the file pointed by fp to ptr
    */

    fread(x, sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]), fileptr);
    
    fclose(fileptr);

    for (k = 0; k < 10; k++)
        printf("%d\n", x[k]);

    // CONTROLLING THE FILE POINTER
    /*
        ftell(fp)                        Returns a long int corresponding to fp position in number of bytes from start of the file
        fseek(fp, num_bytes, from_pos)   Moves fp position by num_bytes bytes relative to position from_pos, which can be of the following constants:
                                                - SEEK_SET Start of the file
                                                - SEEK_CUR Current position
                                                - SEEK_END End of file
    */

    item first, second, secondf;

    first.id = 10276;
    strcpy(first.name, "Widget");

    second.id = 11786;
    strcpy(second.name, "Gadget");

    fileptr = fopen("info.dat", "wb");
    if (fileptr == NULL)
    {
        printf("Failed to open file, exiting...");
        return -1;
    }

    fwrite(&first, 1, sizeof(first), fileptr);

    fwrite(&second, 1, sizeof(second), fileptr);

    fclose(fileptr);

    fileptr = fopen("info.dat", "rb");

    fseek(fileptr, 1 * sizeof(item), SEEK_SET);
    fread(&secondf, 1, sizeof(item), fileptr);

    printf("%d\t%s\n", secondf.id, secondf.name);

    fclose(fileptr);

    return 0;
}