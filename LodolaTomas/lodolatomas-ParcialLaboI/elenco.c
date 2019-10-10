#include "elenco.h"

void elenco_HardcodeElenco(eElenco* listE,int lenElenco)
{
    int i;
    int codActor[]={0,12,14,2,5,17,19,8,9,12};
    float valorContrato[]={30000,2000,500000,9000,20000,10000,30000,2000,500000,9000};
    int codPelicula[]={12,10,12,7,8,4,10,8,4,7};

    for(i=0;i<lenElenco;i++)
    {
        listE[i].codigoDeActor=codActor[i];
        listE[i].codigoDePelicula=codPelicula[i];
        listE[i].valorContrato=valorContrato[i];
        listE[i].estado=OCUPADO;
    }

}

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

        if(elenco_BuscarIgualdad(listE,lenElenco,auxActor,auxPelicula)!=-1)
        {
            getValidFloat("Ingrese el valor del contrato: ","Error solo numeros",0,1000000000000000,&listE[iElenco].valorContrato);
            borrar();
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
            else
            {

                retorno=1;
            }

        }
        else
        {
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
        for(i=0; i<lenElenco; i++)
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
        for(i=0; i<lenElenco; i++)
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
            printf("%50s\n","ELENCOS");
            elenco_MostarElencos(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            pausa();
            borrar();
            printf("%50s\n","ELENCOS ORDENADOS");
            elenco_OrdenarPorPeliculaActor(listE,lenElenco,listaA,lenA,listP,lenP);
            elenco_MostarElencos(listE,lenElenco,listaA,lenA,listP,lenP,listG,lenG);
            pausa();
            borrar();
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

    ePelicula auxPelicula;
    eActor auxActor;
    eGenero auxGenero;

    if(listE!=NULL && lenElenco!=0 && listaA!=NULL && lenA!=0 && listP!=NULL && lenP!=0 && listG!=NULL && lenG!=0)
    {
        printf("***********************************************************************************************************\n");
        printf("%30s %20s %25s %20s\n","Pelicula","Genero","Nombre y Apellido","Valor Contrato");
        printf("***********************************************************************************************************\n");
        for(i=0; i<lenElenco; i++)
        {

            if(listE[i].estado==OCUPADO)
            {
                auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);
                auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
                auxGenero=genero_ObtenerGenero(listG,lenG,auxPelicula.idGenero);
                elenco_MostrarUnElenco(listE[i],auxActor,auxPelicula,auxGenero);
            }
        }
        printf("***********************************************************************************************************\n");
    }

}
void elenco_MostrarUnElenco(eElenco unElenco,eActor unActor,ePelicula unaPelicula,eGenero unGenero)
{
    printf("%35s %15s %15s %10s %15.2f\n\n",unaPelicula.descripcion,unGenero.descripcion,unActor.nombre,unActor.apellido,unElenco.valorContrato);
}

int elenco_BuscarIgualdad(eElenco* listE,int lenElenco,eActor elActor,ePelicula laPelicula)
{
    int i;
    int retorno=0;
    for(i=0; i<lenElenco; i++)
    {
        if(listE[i].estado==OCUPADO)
        {
            if(listE[i].codigoDeActor==elActor.codigo && listE[i].codigoDePelicula==laPelicula.codigo)
            {
                retorno=-1;
            }
        }
    }

    return retorno;
}
void elenco_OrdenarPorPeliculaActor(eElenco* listE,int lenElenco,eActor* listaA,int lenA,ePelicula* listP,int lenP)
{
    int i,j;
    eElenco auxElenco;
    ePelicula auxPelicula;
    ePelicula auxPelicula2;
    eActor auxActor;
    eActor auxActor2;

    for(i=0; i<lenElenco-1; i++)
    {
        for(j=i+1; j<lenElenco; j++)
        {
            auxPelicula=pelicula_ObtenerPelicula(listP,lenP,listE[i].codigoDePelicula);
            auxPelicula2=pelicula_ObtenerPelicula(listP,lenP,listE[j].codigoDePelicula);
            if(strcmp(auxPelicula.descripcion,auxPelicula2.descripcion)>0)
            {
                auxElenco=listE[i];
                listE[i]=listE[j];
                listE[j]=auxElenco;
            }
            else
            {
                if(strcmp(auxPelicula.descripcion,auxPelicula2.descripcion)==0)
                {
                    auxActor=actor_ObtenerActor(listaA,lenA,listE[i].codigoDeActor);
                    auxActor2=actor_ObtenerActor(listaA,lenA,listE[j].codigoDeActor);
                    if(strcmp(auxActor.nombre,auxActor2.nombre)>0)
                    {
                        auxElenco=listE[i];
                        listE[i]=listE[j];
                        listE[j]=auxElenco;
                    }
                }
            }
        }
    }
}
