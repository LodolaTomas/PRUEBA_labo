#include "actor.h"
#include "pelicula.h"

typedef struct
{
    //int codigoDeReparto;
    int codigoDePelicula;
    int codigoDeActor;
    float valorContrato;
    int estado;

}eElenco;


int elenco_AltaElenco(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
int elenco_InicializarElenco(eElenco* list,int lenElenco);
int elenco_BuscarLibre(eElenco* list,int lenElenco);
void elenco_menu(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG);
