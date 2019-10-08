#include "actor.h"

void actor_Menu(eActor* list,int lenActor)
{
    int opcion;
    int respuesta;
    int id=0;
    int flag=0;

    actor_InicializarActores(list,lenActor);
    actor_HardCodearActores(list,5,&id);

    do
    {
        getValidInt("1. Alta\n2. Modificar\n3. Baja\n4. Mostrar\n5. Salir\nElija una opcion: ","Error, solo numeros[1-5]",1,5,&opcion);

        switch(opcion)
        {
        case 1:
            borrar();
            respuesta =actor_Agregar(list,lenActor,&id);
            switch(respuesta)
            {
            case -1:
                borrar();
                printf("No hay espacio disponible\n");
                pausa();
                break;
            case 0:
                borrar();
                printf("Actor Cargado\n");
                flag=1;
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
            if(flag!=0)
            {
                respuesta =actor_ModificarActor(list,lenActor);
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
                }
            }
            else
            {
                printf("Debe cargar Actores Antes de Modificar uno\n");
                pausa();
            }
            break;
        case 3:
            borrar();
            if(flag!=0)
            {
                respuesta =actor_BorrarActor(list,lenActor);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("No se encontro el Actor o No hay Actores Cargados\n");
                    pausa();
                    break;
                case 0:
                    borrar();
                    printf("Actor Borrado\n");
                    pausa();
                    break;
                case 1:
                    borrar();
                    printf("Accion cancelada por el usuario\n");
                    pausa();
                    break;
                }
            }
            else
            {
                printf("Debe cargar Actores Antes de Darlos de Baja\n");
                pausa();
            }
            break;
        case 4:
            borrar();
            if(flag!=0)
            {
                respuesta =actor_ListarActor(list,lenActor);
                switch(respuesta)
                {
                case -1:
                    borrar();
                    printf("EROR. listaDeAlumnos == NULL || MAX_ACTOR == 0\n");
                    pausa();
                    break;
                }
            }
            else
            {
                printf("Debe cargar Actores Antes de Ordenarlos\n");
                pausa();
            }
            pausa();
            break;
        case 5:

            break;
        }
        borrar();
    }
    while(opcion!=5);

    printf("ADIOS VUELVA PRONTOS\n");
}

void actor_HardCodearActores(eActor* list,int lenActor,int* Codigo)
{
    int i;
    int id=*Codigo;
    char nombres[][50]={"Nicolas","Vin","Charlie","Will","Joaquin"};
    char apellidos[][50]={"Cage","Diesel","Sheen","Smith","Fenix"};
    char sexo[]={'M','M', 'M', 'M','M'};

    if( list!=NULL && lenActor!=0)
    {
        for(i=0;i<lenActor;i++)
        {
            list[i].codigo=id;
            strcpy(list[i].nombre,nombres[i]);
            strcpy(list[i].apellido,apellidos[i]);
            list[i].sexo=sexo[i];
            list[i].estado=OCUPADO;
            id++;

        }
        *Codigo=id;

    }


}
int actor_InicializarActores(eActor* list,int lenActor)
{
    int retorno=-1;
    int i;
    if(list!=NULL && lenActor!=0)
    {
        retorno=0;
        for(i=0;i<lenActor;i++)
        {
            list[i].estado=LIBRE;
        }

    }

    return retorno;
}

int actor_BuscarLibre(eActor* list,int lenActor)
{
    int retorno=-1;
    int i;

    if(list!=NULL && lenActor!=0)
    {
        for(i=0;i<lenActor;i++)
        {
            if(list[i].codigo==LIBRE)
            {
                retorno=i;
                break;
            }
        }

    }


    return retorno;
}

int actor_Agregar(eActor* list,int lenActor,int* codigo)
{
    int retorno=-1;
    int idActor=*codigo;
    int lugar=actor_BuscarLibre(list,lenActor);

    eActor auxActor;

    if(list!=NULL && lenActor!=0 && lugar!=-1)
    {

        auxActor.codigo=idActor;
        getValidString("Ingrese Nombre: ","Error, solo letras",0,50,auxActor.nombre);
        getValidString("Ingrese Apellido: ","Error, solo letras",0,50,auxActor.apellido);
        getValidSex(auxActor.sexo);
        auxActor.estado=OCUPADO;
        borrar();
        actor_MostrarUnActor(auxActor);
        if(verifyConformity("Esta seguro que desea guardar este actor?[Si/No]: ","Error, Ingrese [Si/No]")==1)
        {
            list[lugar]=auxActor;
            retorno=0;
            idActor++;
            *codigo=idActor;
        }
        else{

            retorno=1;
        }

    }



    return retorno;
}


void actor_MostrarUnActor(eActor unActor)
{

    printf("%5d %10s %10s %10c",unActor.codigo,unActor.nombre,unActor.apellido,unActor.sexo);
}

void actor_MostarActores(eActor* list,int lenActor)
{
    int i;

    if(list!=NULL && lenActor!=0)
    {
        printf("%5s %10s %10s %10s","Cod.", "Nombre","Apellido","Sexo");
        for(i=0;i<lenActor;i++)
        {
            if(list[i].estado==OCUPADO)
            {
                actor_MostrarUnActor(list[i]);
            }
        }


    }
}

int actor_ModificarActor(eActor* list,int lenActor)
{

    int opcion;
    int retorno=-1;
    int respuesta;
    int idActor;

    eActor auxActor;


    if(list!=NULL && lenActor!=0 )
    {
        borrar();
        actor_MostarActores(list,lenActor);
        getValidInt("Ingrese el Cod. del Actor a Modificar: ","Cuidado, Solo los Codigod",0,lenActor,&opcion);
        idActor=actor_BuscarCodigo(list,lenActor,opcion);

        if(idActor!=-1)
        {
            auxActor=list[idActor];

            do
            {

                actor_MostrarUnActor(auxActor);
                getValidInt("1- Nombre\n2- Apellido\n3- Sexo\n4- Volver al menu\nEliga una opcion: ","Cuidado, solo ingrese numeros",1,4,&respuesta);

                switch(respuesta)
                {

                case 1:
                    borrar();
                    getValidString("Ingrese nuevo nombre: ","Cuidado, Solo letras",0,49,auxActor.nombre);
                    break;
                case 2:
                    borrar();
                    getValidString("Ingrese nuevo apellido: ","Cuidado, Solo letras",0,49,auxActor.apellido);
                    break;
                case 3:
                    borrar();
                    getValidSex(auxActor.sexo);
                    break;
                case 4:
                    borrar();
                    actor_MostrarUnActor(auxActor);
                    if(verifyConformity("Esta seguro que desea guardar los cabios[Si/No]: ","Cuidado, [Si/No]")==1)
                    {
                        list[idActor]=auxActor;
                        retorno=0;
                    }
                    else
                    {
                        retorno=1;
                    }
                    break;
                }


            }
            while(respuesta!=4);

        }
    }

    return retorno;

}


int actor_BuscarCodigo(eActor* list,int lenActor,int Codigo)
{
    int retorno=-1;
    int i;

    if(list!=NULL && lenActor!=0 && Codigo>=0)
    {
            for(i=0;i<lenActor;i++)
            {
                if(list[i].codigo==Codigo)
                {
                    retorno=i;
                    break;
                }
            }

    }

    return retorno;
}

int actor_BorrarActor(eActor* list,int lenActor)
{
    int retorno=-1;
    int iActor;
    int respuesta;
    eActor auxActor;

    if(list!=NULL && lenActor!=0)
    {

        printf("%20s","BAJA ACTOR\n");
        actor_MostarActores(list,lenActor);
        getValidInt("Elija el Actor a dar de baja: ","Cuidado, solo el Codigo del Actor",0,lenActor,&iActor);
        respuesta=actor_BuscarCodigo(list,lenActor,iActor);
        if(respuesta!=-1)
        {
            auxActor=list[respuesta];
            borrar();
            actor_MostrarUnActor(auxActor);
            if(verifyConformity("Esta seguro que quiere darlo de baja?[Si/No]: ","Cudiado, responda[Si/No]")==1)
            {
                retorno=0;
                auxActor.estado=LIBRE;
                list[respuesta]=auxActor;
            }
            else
            {
                retorno=1;
            }

        }
    }
    return retorno;

}

void actor_OrdenarNombreApellido(eActor* list,int lenActor)
{
    int i;
    int j;
    eActor auxActor;

    for(i=0; i<lenActor-1; i++)
    {
        for(j=i+1; j<lenActor; j++)
        {
            if(strcmp(list[i].nombre,list[j].nombre)>0)
            {
                auxActor = list[i];
                list[i] = list[j];
                list[j] = auxActor;
            }

            else
            {
                if(strcmp(list[i].nombre,list[j].nombre)==0)
                {
                    if(strcmp(list[i].apellido,list[j].apellido)>0)
                    {
                        auxActor = list[i];
                        list[i] = list[j];
                        list[j] = auxActor;
                    }
                }
            }
        }

    }

}

int actor_ListarActor(eActor* list,int lenActor)
{
    int retorno=-1;


    if(list!=NULL && lenActor!=0)
    {
       printf("%20s","LISTAR");


       actor_OrdenarNombreApellido(list,lenActor);

       actor_MostarActores(list,lenActor);

    }


    return retorno;
}

eActor actor_ElejitActor(eActor* list,int lenActor)
{
     eActor retorno;
    int opcion;

    if(list!=NULL && lenActor!=0 )
    {
        actor_MostarActores(list,lenActor);
        getValidInt("Ingrese El Actor: ","Error. solo los cod de las peliculas",0,lenActor,&opcion);
        retorno=list[opcion];
    }

    return retorno;
}
