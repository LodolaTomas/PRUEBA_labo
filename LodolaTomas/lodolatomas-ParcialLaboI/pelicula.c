#include "pelicula.h"

void pelicula_HardCodeoPeliculas(ePelicula* list,int lenPeliculas,int* codP)
{
    int i;
    int id=*codP;
    char descripcion[][51]={"Avengers","Joker","IT","Aladin"};
    float duracion[]={264,124,59.5,165} ;
    int genero[]={100,101,102,103};

    if(list !=NULL && lenPeliculas!=0)
    {
        for(i=0;i<lenPeliculas;i++)
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
        getValidInt("Ingrese La Pelicula","Error. solo los cod de las peliculas",1,4,&opcion);
        retorno=list[opcion];

    }

    return retorno;
}
void pelicula_MostrarPeliculas(ePelicula* list,int lenPeliculas,eGenero* listG,int lenGenero)
{

    int i;
    int index;

    printf("\n%5s %5s %5s %5s \n","Cod.","Descripcion","Duracion","Genero");
    for(i=0; i<lenPeliculas; i++)
    {
            index  = genero_BuscarGenero(listG,lenGenero,list[i].idGenero);
            if(index!=-1)
            {
                pelicula_MostarUnaPelicula(list[i],listG[index]);
            }

    }
    printf("\n");

}

void pelicula_MostarUnaPelicula(ePelicula unaPelicula,eGenero unGenero)
{
    printf("%5d %5s %5.2f %5s",unaPelicula.codigo,unaPelicula.descripcion,unaPelicula.duracion,unGenero.descripcion);
}
