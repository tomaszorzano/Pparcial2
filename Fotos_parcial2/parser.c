#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "foto.h"
#include "parser.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_fotoFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;
    int cant = 0;
    char idFotoStr[50];
    char fechaFotoStr[50];
    char tipoFotoStr[50];
    char cantidadStr[50];
    char precioStr[50];
    char cuitStr[50];


    if(pFile != NULL)
    {
        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idFotoStr, fechaFotoStr, tipoFotoStr, cantidadStr, precioStr, cuitStr);
        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", idFotoStr, fechaFotoStr, tipoFotoStr, cantidadStr, precioStr, cuitStr);
            if(cant != 6)
            {
                printf("Error al cargar Arvhivo\n\n");
                system("pause");
            }
            else
            {
               efoto* pfoto;
                pfoto = foto_newParametros(idFotoStr, fechaFotoStr, tipoFotoStr, cantidadStr, precioStr, cuitStr);
                ll_add(pArrayList, pfoto);
            }
        }
    fclose(pFile);
   ret = RETURN_OK;
    }
    else
    {
        printf("Archivo hay datos\n\n");
        system("pause");
    }

    return ret;
}
