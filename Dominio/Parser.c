#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eDominio.h"
#include "Parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0

/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_EDominioFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idStr[6];
    char dominioStr[10];
    char anioStr[20];
    char tipoStr;


    if(pFile != NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,\n]\n", idStr, dominioStr, anioStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,\n]\n", idStr, dominioStr, anioStr);
            if(cant != 3)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
                eDominio* pDom;
                pDom = eDominio_newParametros(idStr, dominioStr, anioStr);
                pDom->tipo = '-';
                ll_add(pArrayList, pDom);
            }
        }
    fclose(pFile);
    RETURN_OK;
    }
    else
    {
        printf("Arvhivo hay datos\n\n");
        system("pause");
    }

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListVendedor LinkedList*
 * \return int
 *
 */
 /*
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListVendedor)
{
    int ret;
    ret = RETURN_ERROR;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {

                Vendedor* env = vendedor_new();
                ret = fread(env, sizeof(Vendedor),1,pFile);
                if(ret != 1)
                {
                    printf("Error al caargar datos\n");
                }
                else
                {
                    ll_add(pArrayListVendedor, env);
                }
        }
    fclose(pFile);
    ret = RETURN_OK;
    }
    else
    {
        printf("No hay datos");
        system("pause");
    }

    return ret;
}
*/



