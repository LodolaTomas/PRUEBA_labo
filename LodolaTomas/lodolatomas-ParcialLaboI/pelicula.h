#include "inputs.h"
#include "genero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char descripcion[51];
    float duracion;
    int idGenero;

}ePelicula;

void pelicula_HardCodeoPeliculas(ePelicula* list,int lenPeliculas,int* codP);
ePelicula pelicula_ElejirPelicula(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero);
void pelicula_MostrarPeliculas(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero);
void pelicula_MostarUnaPelicula(ePelicula unaPelicula,eGenero unGenero);
