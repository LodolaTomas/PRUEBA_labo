#include "pelicula.h"

void pelicula_HardCodeoPeliculas(ePelicula* list,int lenPeliculas,int* codP)
{
    int i;
    int id=*codP;
    char descripcion[][51]= {"Avengers: End Game","Joker","IT","Aladin","Kill Bill","Titanic","El llanero Solitario","Proyecto Geminis","Batman: El caballero de la Noche","Amor a Quemarropa","Los indestructibles","El Juez","La Mascara","Los juegos del Hambre"};
    int duracion[]= {181,123,135,128,247,195,149,117,152,123,152,252,120} ;
    int genero[]= {100,101,102,103,101,103,100,100,101,103,101,102,103};
    if(list !=NULL && lenPeliculas!=0)
    {
        for(i=0; i<lenPeliculas; i++)
        {
            list[i].codigo=id;
            strcpy(list[i].descripcion,descripcion[i]);
            list[i].duracion=duracion[i];
            list[i].idGenero=genero[i];
            id++;
        }
        *codP=id;
    }
}


ePelicula pelicula_ElejirPelicula(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero)
{
    ePelicula retorno;
    int opcion;
    if(list!=NULL && lenPeliculas!=0 && listG!=NULL && lenGenero!=0)
    {
        pelicula_MostrarPeliculas(list,lenPeliculas,listG,lenGenero);
        getValidInt("Ingrese La Pelicula: ","Error. solo los cod de las peliculas",0,lenPeliculas-1,&opcion);
        retorno=pelicula_ObtenerPelicula(list,lenPeliculas,opcion);
    }
    return retorno;
}
void pelicula_MostrarPeliculas(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero)
{
    int i;
    int index;
    printf("\n*******************************************************************************\n");
    printf("%s %30s %18s %12s\n\n","Cod.","Descripcion","Duracion","Genero");
    printf("*******************************************************************************\n");
    for(i=0; i<lenPeliculas; i++)
    {
        index  = genero_BuscarGenero(listG,lenGenero,list[i].idGenero);
        if(index!=-1)
        {
            pelicula_MostarUnaPelicula(list[i],listG[index]);
        }
    }
    printf("*******************************************************************************");
    printf("\n");
}

void pelicula_MostarUnaPelicula(ePelicula unaPelicula,eGenero unGenero)
{
    printf("%d %35s %10d %15s\n",unaPelicula.codigo,unaPelicula.descripcion,unaPelicula.duracion,unGenero.descripcion);
}

int pelicula_BuscarPelicula(ePelicula* list,int lenPeliculas,int codigo)
{
    int retorno=-1;
    int i;
    if(list!=NULL && lenPeliculas!=0 && codigo>=0)
    {
        for(i=0; i<lenPeliculas; i++)
        {
            if(list[i].codigo==codigo)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}
ePelicula pelicula_ObtenerPelicula(ePelicula* list,int lenPeliculas,int codigo)
{
    ePelicula retorno;
    int i;
    if(list!=NULL && lenPeliculas!=0 && codigo>=0)
    {
        for(i=0; i<lenPeliculas; i++)
        {
            if(list[i].codigo==codigo)
            {
                retorno=list[i];
                break;
            }
        }
    }
    return retorno;
}
