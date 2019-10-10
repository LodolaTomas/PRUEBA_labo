#include "elenco.h"

int elenco_AltaElenco(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int retorno=-1;
    int iElenco;
    int generolist;
    ePelicula auxPelicula;
    eGenero auxGenero;
    eActor auxActor;

    printf("%30s","Generar Elenco");
    iElenco=elenco_BuscarLibre(listE,lenElenco);
    if(iElenco!=-1)
    {
        auxPelicula=pelicula_ElejirPelicula(listP,lenP,listG,lenG);
        generolist=genero_BuscarGenero(listG,lenG,auxPelicula.idGenero);
        auxGenero=listG[generolist];
        borrar();
        auxActor=actor_ElejitActor(listaA,lenA);
        borrar();
        getValidFloat("Ingrese el valor del contrato: ","Error solo numeros",0,1000000000000000,&listE[iElenco].valorContrato);
        borrar();

        if(elenco_BuscarIgualdad(listE,lenElenco,auxActor,auxPelicula,listE[iElenco].valorContrato)!=-1)
        {
            printf("*******************************************************************************\n");
            elenco_MostrarUnElenco(listE[iElenco],auxActor,auxPelicula,auxGenero);
            printf("*******************************************************************************\n");
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
        else{
        retorno=-2;
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

    do
    {
        getValidInt("1. Alta Elenco\n2. Mostrar Elencos\n3. Salir\nElija una opcion: ","Error, solo numeros[1-3]",1,3,&opcion);
        switch(opcion)
        {
        case 1:
            borrar();
            respuesta =elenco_AltaElenco(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            switch(respuesta)
            {
            case -2:
                borrar();
                printf("Ya existe la Pelicula con el Actor\n");
                pausa();
                break;
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
                {lenPeliculas
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
            elenco_MostarElencos(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            pausa();
            break;
            case 3:

            break;
        }
        borrar();
    }
    while(opcion!=3);

    printf("ADIOS VUELVA PRONTOS\n");

}

void elenco_MostarElencos(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP,eGenero* listG,int lenG)
{
    int i;
    int actor;
    int pelicula;
    int genero;

    ePelicula auxPelicula;
    eActor auxActor;
    eGenero auxGenero;

    if(listE!=NULL && lenElenco!=0 && listaA!=NULL && lenA!=0 && listP!=NULL && lenP!=0 && listG!=NULL && lenG!=0)
    {
        //printf("%s %25s %15s %20s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
        for(i=0;i<lenElenco;i++)
        {

            if(listE[i].estado==OCUPADO)
            {
                    actor=actor_BuscarCodigo(listaA,lenA,listE[i].codigoDeActor);
                    auxActor=listaA[actor];
                    pelicula=pelicula_BuscarPelicula(listP,lenP,listE[i].codigoDePelicula);
                    auxPelicula=listP[pelicula];
                    genero=genero_BuscarGenero(listG,lenG,auxPelicula.idGenero);
                    auxGenero=listG[genero];
                    elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);
            }
        }

    }

}
void elenco_MostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero)
{
    printf("%s %20s %10s %5s %20.2f\n\n",unaPelicula.descripcion,unGenero.descripcion,unActor.nombre,unActor.apellido,unElenco.valorContrato);
}

int elenco_BuscarIgualdad(eElenco* listE,int lenElenco,eActor elActor,ePelicula laPelicula,int valorContrato)
{
    int i;
    int retorno=0;
    for(i=0;i<lenElenco;i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            if(listE[i].codigoDeActor==elActor.codigo && listE[i].codigoDePelicula==laPelicula.codigo && listE[i].valorContrato==valorContrato)
            {
                retorno=-1;
            }
        }
    }

    return retorno;
}
