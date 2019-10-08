#include "elenco.h"

int elenco_AltaElenco(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int retorno=-1;
    int iElenco;
    ePelicula auxPelicula;
    eActor auxActor;

    printf("%30s","Generar Elenco");
    iElenco=elenco_BuscarLibre(listE,lenElenco);
    if(iElenco!=-1)
    {
        auxPelicula=pelicula_ElejirPelicula(listP,lenP,listG,lenG);
        auxActor=actor_ElejitActor(listaA,lenA);
        getValidFloat("Ingrese el valor del contrato: ","Error solo numeros",0,10000000000000,&listE[iElenco].valorContrato);
        if(verifyConformity("esta seguro que desea crear este elenco?[Si/No]: ","Error, solo [Si/No]")==1)
        {
            retorno=0;
            listE[iElenco].codigoDeActor=auxActor.codigo;
            listE[iElenco].codigoDePelicula=auxPelicula.codigo;
            listE[iElenco].estado=OCUPADO;

        }
        else{

            retorno=1;
        }
    }

    return retorno;
}

int elenco_InicializarElenco(eElenco* list,int lenElenco)
{
    int retorno=-1;
    int i;
    if(list!=NULL && lenElenco!=0)
    {
        retorno=0;
        for(i=0;i<lenElenco;i++)
        {
            list[i].estado=LIBRE;
        }

    }

    return retorno;
}

int elenco_BuscarLibre(eElenco* list,int lenElenco)
{
    int retorno=-1;
    int i;

    if(list!=NULL && lenElenco!=0)
    {
        for(i=0;i<lenElenco;i++)
        {
            if(list[i].estado==LIBRE)
            {
                retorno=i;
                break;
            }
        }

    }


    return retorno;
}

void elenco_menu(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
  int opcion;
    int respuesta;

    elenco_InicializarElenco(listE,lenElenco);


    do
    {
        getValidInt("1. Alta Elenmco\n2. Mostrar Elencos\n3. Salir\nElija una opcion: ","Error, solo numeros[1-3]",1,3,&opcion);

        switch(opcion)
        {
        case 1:
            borrar();
            respuesta =elenco_AltaElenco(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            switch(respuesta)
            {
            case -1:
                borrar();
                printf("No hay espacio disponible\n");
                pausa();
                break;
            case 0:
                borrar();
                printf("Elenco Cargado\n");
                pausa();
                break;
            case 1:
                borrar();
                printf("Accion cancelada por el usuario\n");
                pausa();
                break;
            }
            break;
        case 2:
            borrar();
                /*respuesta =actor_ModificarActor(list,lenActor);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("No se encontro el Actor o No hay Actores Cargados\n");
                    pausa();
                    break;
                case 0:
                    borrar();
                    printf("Actor Modificado\n");
                    pausa();
                    break;
                case 1:
                    borrar();
                    printf("Accion cancelada por el usuario\n");
                    pausa();
                    break;
                }*/


            break;
        }
        borrar();
    }
    while(opcion!=2);

    printf("ADIOS VUELVA PRONTOS\n");


}
