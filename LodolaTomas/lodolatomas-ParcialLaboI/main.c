#include <stdio.h>
#include <stdlib.h>


#include "elenco.h"

#define MAX_ACTOR 10
#define MAX_PELI 4
#define MAX_GENE 4
#define MAX_ELENCO 10

int main()
{
    int opcion;

    eActor listaDeActores[MAX_ACTOR];
    ePelicula listaDePeliuclas[MAX_PELI];
    eGenero listaDeGenero[MAX_GENE];
    eElenco listaDeElenco[MAX_ELENCO];

    do{
        getValidInt("1- Gestion de Actores\n2- Gestion de Elenco\nElija una Opcion: ","Eror, solo numeros",1,2,&opcion);
        switch(opcion){
    case 1:
         actor_Menu(listaDeActores,MAX_ACTOR);
         borrar();
        break;
    case 2:
        //elenco_menu(listaDeElenco,MAX_ELENCO,);
        break;
        }

    }while(opcion!=2);




    return 0;
}
