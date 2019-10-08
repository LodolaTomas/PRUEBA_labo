#include <string.h>

typedef struct
{
    int id;
    char descripcion[51];

}eGenero;


void genero_hardCodear(eGenero*list, int lenGenero);
int genero_BuscarGenero(eGenero* list,int lenGenero,int idGenero);
