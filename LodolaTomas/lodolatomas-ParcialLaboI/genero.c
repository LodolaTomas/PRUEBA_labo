#include "genero.h"



void genero_hardCodear(eGenero*list, int lenGenero)
{
    int i;

    int id[]={100,101,102,103};
    char descripcion[][51]={"Accion","Terror","Romance","Suspenso"};

    for(i=0;i<lenGenero;i++)
    {
        list[i].id=id[i];
        strcpy(list[i].descripcion,descripcion[i]);
    }

}

int genero_BuscarGenero(eGenero* list,int lenGenero,int idGenero)
{
    int retorno=-1;
    int i;

    if(list!=NULL && lenGenero!=0)
    {
            for(i=0;i<lenGenero;i++)
            {
                if(list[i].id==idGenero)
                {
                    retorno=i;
                    break;
                }
            }

    }

    return retorno;


}
