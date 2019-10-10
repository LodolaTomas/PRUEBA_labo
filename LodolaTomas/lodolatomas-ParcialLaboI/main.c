#include <stdio.h>
#include <stdlib.h>

#include "elenco.h"

#define MAX_ACTOR 25
#define MAX_PELI 13
#define MAX_GENE 4
#define MAX_ELENCO 10

int main()
{
    int opcion;
    int idPeliculas=0;
    int idActores=0;
    eActor listaDeActores[MAX_ACTOR];
    ePelicula listaDePeliculas[MAX_PELI];
    eGenero listaDeGenero[MAX_GENE];
    eElenco listaDeElenco[MAX_ELENCO];

    elenco_InicializarElenco(listaDeElenco,MAX_ELENCO);
    genero_hardCodear(listaDeGenero,MAX_GENE);
    pelicula_HardCodeoPeliculas(listaDePeliculas,MAX_PELI,&idPeliculas);
    actor_InicializarActores(listaDeActores,MAX_ACTOR);
    actor_HardCodearActores(listaDeActores,20,&idActores);

    do{
        getValidInt("1- Gestion de Actores\n2- Gestion de Elenco\n3- Salir\nElija una Opcion: ","Eror, solo numeros",1,3,&opcion);
        switch(opcion){
    case 1:
        borrar();
        actor_Menu(listaDeActores,MAX_ACTOR,&idActores);
        break;
    case 2:
        borrar();
        elenco_menu(listaDeElenco,MAX_ELENCO,listaDeActores,MAX_ACTOR,listaDePeliculas,MAX_PELI,listaDeGenero,MAX_GENE);
        break;
    case 3:
        borrar();
        printf("Bish spater");
    break;
        }

    borrar();
    }while(opcion!=3);

    return 0;
}
