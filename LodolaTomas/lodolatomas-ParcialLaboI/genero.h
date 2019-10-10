#include <string.h>

typedef struct
{
    int id;
    char descripcion[51];

} eGenero;


void genero_hardCodear(eGenero*list, int lenGenero);
/**
 * \brief Busca un Genero por codigo(id) y devuelve su posicion
 * \param list* Es la lista de los Generos
 * \param lenGenero Cantiadad de Generos
 * \param codigo la posicion del Genero a ser buscado
 * \return int retona (-1) sino pudo se encontrada- (i)la posicion
 de la pelicula
 *
 */
int genero_BuscarGenero(eGenero* list,int lenGenero,int idGenero);

/**
 * \brief Busca un Genero por codigo(id) y lo devuelve
 * \param list* Es la lista de los Generos
 * \param lenGenero Cantiadad de Generos
 * \param codigo la posicion del Genero a ser buscado
 * \return eActor retona el Genero
 *
 */
eGenero genero_ObtenerGenero(eGenero* list,int lenGenero,int idGenero);
