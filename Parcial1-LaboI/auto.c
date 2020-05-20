#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "utn.h"
#include "auto.h"


void inicializarAutos(eAuto vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int altaAuto(int idx, eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    eAuto auxAuto;

    system("cls");

    printf("***** Alta Auto *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxAuto.id = idx;

        printf("Ingrese patente: ");
        fflush(stdin);
        scanf("%s", auxAuto.patente);

        printf("\n");
        mostrarMarcas(marca, tamM);
        utn_getEntero(&auxAuto.idMarca, 2, "Ingrese Id Marca (1000-1005): ", "Error. vuelva a intentarlo: \n", 1000, 1005);

        printf("\n");
        mostrarColores(color, tamC);
        utn_getEntero(&auxAuto.idColor, 2, "Ingrese Id Color (5000-5005): ", "Error, vuelva a intentarlo: \n", 5000, 5005);

        utn_getEntero(&auxAuto.modelo, 2, "Ingrese modelo (1890-2020): ", "Error, vuelve a intentarlo: \n", 1890, 2020);

        auxAuto.isEmpty = 0;

        vec[indice] = auxAuto;
        todoOk = 1;

        printf("\n*Alta excitosa*\n\n");

    }

    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char descripcionM[20];
    char descripcionC[20];
	cargarDescripcionMarca(descripcionM, x.idMarca, marcas, tamM);
	cargarDescripcionColor(descripcionC, x.idColor, colores, tamC);

    printf("  %d    %s     %d        %s          %d        %s      %d   \n", x.id, x.patente, x.idMarca, descripcionM, x.idColor, descripcionC, x.modelo);
}

//---------------------------------------------------------------------------------------------------

void mostrarAutos(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    int flag = 0;
    system("cls");
    printf("***** Listado de Autos *****\n");
    printf("  Id      Patente    ID Marca    Marca       ID Color    Color     Modelo  \n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i], marcas, tamM, colores, tamC);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay autos que listar ***\n");
    }
}

//---------------------------------------------------------------------------------------------------

int buscarAuto(char patente[], eAuto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if((strcmp(vec[i].patente, patente)) == 0 && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

void modificarAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char patente[20];
    int indice;
    char seguir = 's';
    char confirma;
    int nuevoColor;
    int nuevoModelo;

    system("cls");
    printf("***** Modificar Auto *****\n\n");

    printf("Ingrese patente: ");
    scanf("%s", patente);

    indice = buscarAuto(patente, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un auto con la patente: %s\n", patente);
    }
    else
    {
        printf("  Id      Patente     ID Marca    Marca    ID Color   Color   Modelo  \n");
        mostrarAuto(vec[indice], marcas, tamM, colores, tamC);

//SUBMENU QUE PERMITE MODIFICAR COLOR Y MARCA---------------------------------------------------
    do{
        switch(menuModificar())
        {
        case 1:
            printf("\nModifica Color? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                printf("\n");
                mostrarColores(colores, tamC);
                printf("Ingrese nuevo color: ");
                scanf("%d", &nuevoColor);

                vec[indice].idColor = nuevoColor;
                printf("Se ha actualizado el color con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 2:
            printf("\nModifica Modelo? (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                printf("Ingrese nuevo modelo: ");
                scanf("%d", &nuevoModelo);

                vec[indice].modelo = nuevoModelo;
                printf("Se ha actualizado el modelo con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 3:
            printf("Confirme salida (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            system("pause");
        }

    }while(seguir == 's');
    }
}

//---------------------------------------------------------------------------------------------------

int menuModificar()
{
    int opcion;

    printf("***** Modificar Color/Modelo *****\n\n");
    printf("1. Modificar Color\n");
    printf("2. Modificar Modelo\n");
    printf("3. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void mostrarMarcas(eMarca vec[], int tam)
{
    printf("***** Listado de Marcas *****\n");
    printf(" ID Marca     Descripcion \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d       %10s \n", vec[i].id, vec[i].descripcion);
    }
}

//---------------------------------------------------------------------------------------------------

void mostrarColores(eColor vec[], int tam)
{
    printf("***** Listado de Colores *****\n");
    printf(" ID Color    Descripcion \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d       %10s  \n", vec[i].id, vec[i].nombreColor);
    }
}

//---------------------------------------------------------------------------------------------------

void mostrarServicios(eServicio vec[], int tam)
{
    printf("***** Listado de Servicios *****\n");
    printf(" ID Servicio   Descripcion   Precio  \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d        %10s      %d  \n", vec[i].id, vec[i].descripcion, vec[i].precio);
    }
}

//---------------------------------------------------------------------------------------------------

void bajaAuto(eAuto vec[], int tam, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
    char patente[20];
    int indice;
    char confirma;

    system("cls");
    printf("***** Baja Auto *****\n\n");

    printf("Ingrese patente: ");
    scanf("%s", patente);

    indice = buscarAuto(patente, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un auto con la patente: %d\n", patente);
    }
    else
    {
        mostrarAuto(vec[indice], marcas, tamM, colores, tamC);

        printf("\nConfirma baja? (s/n): ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

//---------------------------------------------------------------------------------------------------

int buscarLibreT(eTrabajo vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int altaTrabajo(int idx, eTrabajo vec[], int tam, eServicio lavados[], int tamSer, eAuto autos[], int tamAu, eMarca marca[], int tamM, eColor color[], int tamC)
{
    int todoOk = 0;
    int indiceT = buscarLibre(autos, tamAu);
    eTrabajo auxTrabajo;
    int indice;
    char confirma;

    system("cls");

    printf("***** Alta Trabajo *****\n\n");


    auxTrabajo.id = idx;

    mostrarAutos(autos, tamAu, marca, tamM, color, tamC);

    printf("Ingrese patente: ");
    fflush(stdin);
    scanf("%s", auxTrabajo.patente);

    indice = buscarAuto(auxTrabajo.patente, autos, tamAu);

    if(indice == -1)
    {
        printf("No hay registro de un auto con esa patente\n");
    }
    else
    {
    mostrarServicios(lavados, tamSer);
    printf("Ingrese ID servicio: ");
    fflush(stdin);
    scanf("%d", &auxTrabajo.idServicio);
    while(auxTrabajo.idServicio != 20000 && auxTrabajo.idServicio != 20001 && auxTrabajo.idServicio != 20002 && auxTrabajo.idServicio != 20003)
    {
        printf("Error. vuelva a intentarlo: \n");
        fflush(stdin);
        scanf("%d", &auxTrabajo.idServicio);
    }

    printf("Ingrese fecha dd/mm/aaaa: ");
    fflush(stdin);
    scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

    printf("\nConfirma trabajo? (s/n): ");
    fflush(stdin);
    scanf("%c", &confirma);
    if(confirma == 's')
    {
        auxTrabajo.isEmpty = 0;

        vec[indiceT] = auxTrabajo;
        todoOk = 1;

        printf("\n*Alta excitosa*\n\n");
    }
    else
    {
        printf("Se ha cancelado la operacion\n\n");
    }

    }

    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamS)
{
    char descripcionS[20];
    cargarDescripcionServicio(descripcionS, x.idServicio, servicios, tamS);
    printf("%d  %10s   %d   %10s  %d/%d/%d   \n", x.id, x.patente, x.idServicio, descripcionS, x.fecha.dia, x.fecha.mes, x.fecha.anio);
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS)
{
    int flag = 0;
    system("cls");
    printf("***** Listado de Trabajos *****\n");
    printf("  Id      Patente     ID Servicio    Servicio    Fecha  \n\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
		{
			mostrarTrabajo(vec[i], servicios, tamS);
			flag = 1;
		}
    }
    if(flag == 0)
    {
        printf("***No hay trabajos que listar***\n");
    }
}

int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(marcas[i].id == id)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}



int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(colores[i].id == id)
        {
            strcpy(descripcion, colores[i].nombreColor);
            todoOk = 1;
        }
    }
    return todoOk;
}



int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam)
{
    int todoOk = 0;

    for(int i=0; i<tam; i++)
    {
        if(servicios[i].id == id)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}


