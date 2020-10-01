#include <stdio.h>
#include <string.h>

union val {
    int num_entero;
    float num_flotante;
    char cadena[20];
};

typedef struct 
{
    char make[20];
    int model_year;
    int id_type; // 0 for id_num, 1 for VIN
    union
    {
        int id_num;
        char VIN[20];
    } id;
} vehicle;

union id {
    int id_num;
    char name[20];
};

void set_id(union id *);
void show_id(union id);

int main()
{
    union val test;
    test.num_entero = 123;
    test.num_flotante = 98.76;
    strcpy(test.cadena, "Hola");
    printf("%d\n", test.num_entero);
    printf("%f\n", test.num_flotante);
    printf("%s\n", test.cadena);

    vehicle car1;
    strcpy(car1.make, "Ford");
    car1.model_year = 2017;
    car1.id_type = 0;
    car1.id.id_num = 123098;

    printf("Make: %s\n", car1.make);
    printf("Model: %d\n", car1.model_year);
    if (car1.id_type == 0)
        printf("ID: %d\n", car1.id.id_num);
    else
        printf("ID: %s\n", car1.id.VIN);


    union val info;
    union val *ptr = NULL;
    ptr = &info;
    ptr->num_entero = 10;
    printf("info.num_entero es %d\n", info.num_entero);

    union id newId;
    newId.id_num = 42;
    set_id(&newId);
    show_id(newId);


    union val nums[10];
    int k;
    for (k = 0; k < 10; k++)
    {
        nums[k].num_entero = k;
        printf("%d\n", nums[k].num_entero);
    }
    return 0;
}

void set_id(union id *item)
{
    item->id_num = 42;
}

void show_id(union id item)
{
    printf("ID is %d\n", item.id_num);
}