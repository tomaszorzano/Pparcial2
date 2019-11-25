#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "eDominio.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* eDominio = ll_newLinkedList();
    LinkedList* eDominioFilter = ll_newLinkedList();
   // LinkedList* eEnvioZona = ll_newLinkedList();
    char pathArch[20];
    char pathArch2[20];
    char pathArchbin[20];
    int nivel;

    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                system("cls");
                //printf("\nIngrese Nombre de Archivo a cargar: ");
                //scanf("%s", pathArch);
                controller_loadFromText("datos.csv" ,eDominio);
                break;
            case 2:
                system("cls");
                controller_ListEDominio(eDominio);
                break;
            case 3:
                system("cls");
                ll_map(eDominio, eDominio_tipoDominio);
                controller_ListEDominio(eDominio);
                break;

            case 4:
                system("cls");
                eDominioFilter =  ll_filter(eDominio, eDominio_vehiculoDominio);
                //system("cls");
                printf("\nIngrese Nombre de Archivo: ");
                scanf("%s", pathArch2);
                //pathArch2 = "vehiculo.csv";
                controller_saveAsText(pathArch2, eDominioFilter);
                break;
            case 5:
             //   printf("\nIngrese Nombre de Archivo bin segun Nivel elegido: ");
             //   scanf("%s", pathArchbin);
              //  controller_saveAsBinary(pathArchbin, eVendedorNivel);
                  controller_ListEDominio(eDominioFilter);
                break;
            case 6:
                break;
        }
    }while(option != 6);
    return 0;
}

int menuPpal()
{
    int r;
    do
    {
        system("cls");
        printf(" \n");
        printf("  Menu:                                                                          \n");
        printf("  1. Cargar datos                                                                \n");
        printf("  2. Imprimir Envios                                                             \n");
        printf("  3. Agregar tipo                                                                \n");
        printf("  4. Generar Archivos por tipo                                                   \n");
        printf("  5. Imprimir Lisa de Zonas                                                      \n");
        printf("  6. Salir                                                                       \n");
        printf(" \n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 10);

    return r;
}

int menuEdit()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione un campo a editar: \n");
        printf("     1. Nombre.                    \n");
        printf("     2. Horas Trabajadas.          \n");
        printf("     3. Sueldo                     \n");
        printf("     4. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 4);

    return r;
}

int menuSort()
{
    int r;

    do
    {
        system("cls");
        printf("***********************************\n");
        printf("     Seleccione el sort:           \n");
        printf("     1. Id.                        \n");
        printf("     2. Nombre.                    \n");
        printf("     3. Horas Trabajadas.          \n");
        printf("     4. Sueldo                     \n");
        printf("     5. Salir                      \n");
        printf("***********************************\n");
        scanf("%d", &r);
    }
    while(r < 1 || r > 5);

    return r;
}
