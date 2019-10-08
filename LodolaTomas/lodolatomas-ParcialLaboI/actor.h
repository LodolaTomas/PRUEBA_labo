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

}eActor;

void actor_Menu(eActor* list,int lenActor);

void actor_HardCodearActores(eActor* list,int lenActor,int* Codigo);

int actor_InicializarActores(eActor* list,int lenActor);

int actor_BuscarLibre(eActor* list,int lenActor);

int actor_Agregar(eActor* list,int lenActor,int* codigo);

void actor_MostrarUnActor(eActor unActor);

void actor_MostarActores(eActor* list,int lenActor);

int actor_ModificarActor(eActor* list,int lenActor);

int actor_BuscarCodigo(eActor* list,int lenActor,int Codigo);

int actor_BorrarActor(eActor* list,int lenActor);

void actor_OrdenarNombreApellido(eActor* list,int lenActor);

int actor_ListarActor(eActor* list,int lenActor);

eActor actor_ElejitActor(eActor* list,int lenActor);
