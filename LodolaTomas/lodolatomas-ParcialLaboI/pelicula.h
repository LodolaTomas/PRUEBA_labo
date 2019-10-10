#include "inputs.h"
#include "genero.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char descripcion[51];
    int duracion;
    int idGenero;

} ePelicula;

void pelicula_HardCodeoPeliculas(ePelicula* list,int lenPeliculas,int* codP);

/**
 * \brief Muestra las peliculas y la devuelve una Pelicula
 * \param list* Es la lista de peliculas
 * \param lenPeliculas el largo de las peliculas
 * \param listG* Es la lista de generos
 * \param listG* el largo de las peliculas
 * \return ePelicula retorna la pelicula seleccionada
 *
 */
ePelicula pelicula_ElejirPelicula(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero);

/**
 * \brief Muestra las peliculas
 * \param list* Es la lista de peliculas
 * \param lenPeliculas el largo de las peliculas
 * \param listG* Es la lista de generos
 * \param listG* el largo de las peliculas
 * \return --
 *
 */
void pelicula_MostrarPeliculas(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero);

/**
 * \brief Muestra una pelicula con su genero
 * \param list* Es la lista de peliculas
 * \param listG* Es la lista de generos
 * \return --
 *
 */
void pelicula_MostarUnaPelicula(ePelicula unaPelicula,eGenero unGenero);

/**
 * \brief Busca una pelicula y devuelve su posicion
 * \param list* Es la lista de peliculas
 * \param lenPeliculas el largo de las peliculas
 * \param codigo la posicion de la pelicula a ser buscada
 * \return retona (-1) sino pudo se encontrada- (i)la posicion
 de la pelicula
 *
 */
int pelicula_BuscarPelicula(ePelicula* list,int lenPeliculas,int codigo);

/**
 * \brief Busca una pelicula y devuelve la pelicula
 * \param list* Es la lista de peliculas
 * \param lenPeliculas el largo de las peliculas
 * \param codigo la posicion de la pelicula a ser buscada
 * \return ePelicula retorna la pelicula seleccionada
 *
 */
ePelicula pelicula_ObtenerPelicula(ePelicula* list,int lenPeliculas,int codigo);
