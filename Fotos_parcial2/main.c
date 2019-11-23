#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "foto.h"
#include "Parser.h"
#define RETURN_OK 1

#define RETURN_ERROR 0

int menuPpal();
int menuEdit();
int menuSort();



int main()
{
    int option = 0;
    LinkedList* venta = ll_newLinkedList();
    char path[20];
    do{
        option = menuPpal();
        switch(option)
        {
            case 1:
                system("cls");
                controller_loadFromText("data.csv", venta);
                break;
            case 2:
                system("cls");
                controller_ListVenta(venta);

                break;
            case 3:
                controller_ListVenta(venta);
                system("cls");
                break;
            case 4:
                system("cls");
                printf("\nIngrese Nombre de Archivo: ");
                scanf("%s", path);
                controller_saveAsText(path, venta);
                break;
            case 5:
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
        printf("  2. Informar                                                                    \n");
        printf("  3. Agregar tipo                                                                \n");
        printf("  4. Generar Archivo Informe                                                     \n");
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
