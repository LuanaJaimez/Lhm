#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;

}eServicio;

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // AUTO_H_INCLUDED


void inicializarAutos(eAuto vec[], int tam);
int buscarLibre(eAuto vec[], int tam);
int altaAuto(int idx, eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
void mostrarAuto(eAuto x, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarAutos(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
int buscarAuto(char patente[], eAuto vec[], int tam);
void modificarAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
int menuModificar();
void mostrarMarcas(eMarca vec[], int tam);
void mostrarColores(eColor vec[], int tam);
void mostrarServicios(eServicio vec[], int tam);
void bajaAuto(eAuto vec[], int tam, eMarca marca[], int tamM, eColor color[], int tamC);
int buscarLibreT(eTrabajo vec[], int tam);
int altaTrabajo(int idx, eTrabajo vec[], int tam, eServicio lavados[], int tamSer, eAuto autos[], int tamAu, eMarca marca[], int tamM, eColor color[], int tamC);
void mostrarTrabajo(eTrabajo x, eServicio servicios[], int tamS);
void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamS);
int cargarDescripcionMarca(char descripcion[], int id, eMarca marcas[], int tam);
int cargarDescripcionColor(char descripcion[], int id, eColor colores[], int tam);
int cargarDescripcionServicio(char descripcion[], int id, eServicio servicios[], int tam);
