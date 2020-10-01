#include <stdio.h>
#include <string.h>

struct course 
{
    int id;
    char title[40];
    float hours;
};

typedef struct 
{
    int id;
    char name[70];
    int age;
} alumno;

typedef struct
{
    int x, y;
} punto;

typedef struct
{
    float radio;
    punto centro;
} circulo;

void getAlumnData(alumno *);
void update_course(struct course *);
void display_course(struct course);

int main()
{
    // Las estructuras se pueden declarar asi
    struct course c1 = {1, "Biologia", 37.5};
    // O asi
    struct course c2;
    c2 = (struct course) {2, "Matematicas", 50.8};
    // O tambien asi
    struct course c3 = {.title = "Filosofia", .id = 3, .hours = 40.0};
    // Para acceder a los miembros de la estructura
    c1.hours = 45.7;
    strcpy(c1.title, "BioloGia");
    struct course temp;
    temp = c1;
    c1 = c2;
    c1 = temp;

    struct course cs1 = {341279, "Intro to C", 12.5};
    struct course cs2;

    // Inicializando cs2
    cs2.id = 341281;
    strcpy(cs2.title, "Advanced C");
    cs2.hours = 14.25;

    printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
    printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);

    alumno a1 = {.id = 345682, .name = "Cesar Emanuel Rosales Alvarez", .age = 18};
    printf("%d\t%s\t%d\n", a1.id, a1.name, a1.age);

    circulo c = {4.5, {1, 3}};
    printf("%f %d %d\n", c.radio, c.centro.x, c.centro.y);

    getAlumnData(&a1);
    update_course(&cs2);
    display_course(cs2);

    // Arreglo de estructuras
    struct course cursos[] = {
        {.id = 333333, .title = "Estructuras de Datos", .hours = 50.0},
        {444444, "Redes", 37.2},
        {555555, "Sistemas Operativos", 56.3}
    };

    for (int i = 0; i < sizeof(cursos) / sizeof(struct course); i++)
        printf("%d\t%s\t%f\n", cursos[i].id, cursos[i].title, cursos[i].hours);
    return 0;
}

void getAlumnData(alumno *a)
{
    printf("Alumno: %s\n", a->name);
    printf("ID: %d\n", a->id);
    printf("Edad: %d\n", a->age);
}

void update_course(struct course *c)
{
    strcpy(c->title, "C++ Fundamentals");
    c->id = 111;
    c->hours = 12.30;
}

void display_course(struct course c)
{
    printf("%d\t%s\t%f\n", c.id, c.title, c.hours);
}