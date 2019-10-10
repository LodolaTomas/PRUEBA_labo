#include "inputs.h"
#define OCUPADO 1
#define LIBRE 0

typedef struct
{

    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    int estado;

} eActor;

/**
 * \brief Muestra el menu Actores
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \param id*
 * \return --
 *
 */
void actor_Menu(eActor* list,int lenActor,int *id);

void actor_HardCodearActores(eActor* list,int lenActor,int* Codigo);

/**
 * \brief Inicializa los actores en LIBRE
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return retorna ( 0 ) Ok ( -1 ) si la list es nula o el len es <0
 *
 */
int actor_InicializarActores(eActor* list,int lenActor);

/**
 * \brief Busca posicion libre de los Actores
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return retorna ( -1 ) si la list es nula, lenActor<0
 o no se encontro espacio- retorna ( i ) posicion libre
 *
 */
int actor_BuscarLibre(eActor* list,int lenActor);

/**
 * \brief Agrega un Actor
 * \param list* Es la lista de Actores
 * \param lenActor el largo de los Actores
 * \param **codigo id de Actores
 * \return retorna (-1) lista nula, lenActor <0
 o no hay espacio libre-(o)Ok-(1) accion cancelada
 *
 */
int actor_Agregar(eActor* list,int lenActor,int** codigo);

/**
 * \brief Muestra Un Actor
 * \param unActor El Actor a ser mostrado
 * \return --
 *
 */
void actor_MostrarUnActor(eActor unActor);

/**
 * \brief Muestra los Actores
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return --
 *
 */
void actor_MostarActores(eActor* list,int lenActor);

/**
 * \brief Modifica todos los datos del Actor
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return retorna ( -1 ) lista nula, lenActor <0
 o no hay espacio libre-( 0 )Ok-(1) accion cancelada
 *
 */
int actor_ModificarActor(eActor* list,int lenActor);

/**
 * \brief Busca un Actor por codigo(id) y devuelve su posicion
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \param codigo la posicion del Actor a ser buscada
 * \return retona (-1) sino pudo se encontrada- (i)la posicion
 de la pelicula
 *
 */
int actor_BuscarCodigo(eActor* list,int lenActor,int Codigo);

/**
 * \brief Borra un actor
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return retorna ( -1 ) lista nula, lenActor <0
                ( 0 ) Ok - (1) accion cancelada
 *
 */
int actor_BorrarActor(eActor* list,int lenActor);

/**
 * \brief Ordena los Actores por Nombre y Apellido
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return --
 *
 */
void actor_OrdenarNombreApellido(eActor* list,int lenActor);

/**
 * \brief Muestra los Actores Ordenados
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return retorna ( -1 ) lista nula, lenActor <0 - ( 0 ) Ok
 *
 */
int actor_ListarActor(eActor* list,int lenActor);

/**
 * \brief Muestra los Actores Elijo uno y lo devuelvo
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return eActor retorna el Actor seleccionado
 *
 */
eActor actor_ElejitActor(eActor* list,int lenActor);

/**
 * \brief Cantidad de actores Disponibles
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \return retorna ( -1 ) lista nula, lenActor <0 - ( i++ ) Ok
 Cantadad de Actores dados de Alta
 *
 */
int actor_ActoresDisponibles(eActor* list,int lenActor);

/**
 * \brief Busca un Actor por codigo(id) y lo devuelve
 * \param list* Es la lista de los Actores
 * \param lenActor el largo de los Actores
 * \param codigo la posicion del Actor a ser buscada
 * \return eActor retona el Actor
 *
 */
eActor actor_ObtenerActor(eActor* list,int lenActor,int codigo);
