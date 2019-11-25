#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eDominio.h"
#define RETURN_OK 1
#define RETURN_ERROR 0


eDominio* eDominio_new()/**  **/
{
   //pDom = (eDominio*)malloc(sizeof(eDominio));
    eDominio* pDom = (eDominio *) calloc ( 1 , sizeof (eDominio));
    if(pDom == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }
   /* pDom->idEnvio = 0;
    strcpy(pDom->nombreProd, "");
    pDom->idCamion = 0;
    strcpy(pDom->zonaDestino, "");
    pDom->kmRecorrido = 0;
    pDom->tipoEntrega = 0;
    pDom->costoEnvio = 0;*/

    return pDom;
}

eDominio* eDominio_newParametros(char* idStr, char* dominioStr, char* anioStr)
{
    eDominio* pDom = eDominio_new();

    eDominio_setId(pDom, atoi(idStr));
    eDominio_setDominio(pDom, dominioStr);
    eDominio_setAnio(pDom, atoi(anioStr));

    return pDom;
}

int eDominio_delete(eDominio* this)
{
    int retorno = -1;

    if (this!=NULL )
    {
        free (this);
        retorno = RETURN_OK;
    }
    return retorno;
}

/** Setters **/
int eDominio_setId(eDominio* this, int id)
{
    int ret;
    ret = RETURN_ERROR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        ret = RETURN_OK;
    }
    return ret;
}


int eDominio_setDominio(eDominio* this, char* dominio)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->dominio, dominio);
        ret = RETURN_OK;
    }
    return ret;
}

int eDominio_setAnio(eDominio* this, int anio)
{
    int ret;
    ret = RETURN_ERROR;

    if(anio > 0 && this != NULL)
    {
        this->anio = anio;
        ret = RETURN_OK;
    }
    return ret;
}

int eDominio_setTipo(eDominio* this, char* tipo)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL)
    {
        strcpy(this->tipo, tipo);
        ret = RETURN_OK;
    }
    return ret;
}

/** Getters **/
int eDominio_getId(eDominio* this, int* id)
{
    int ret;
    if(id != NULL && this != NULL)
    {
        *id = this->id;
        ret = RETURN_OK;
    }
    return ret;
}

int eDominio_getIdDom(eDominio* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->id;;
    }
    return ret;
}

char* eDominio_getDominio(eDominio* this)
{
    return this->dominio;
}

int eDominio_getAnio(eDominio* this, int* anio)
{
    int ret;
    if(anio != NULL && this != NULL)
    {
        *anio = this->anio;
        ret = RETURN_OK;
    }
    return ret;
}

int eDominio_getAnioDom(eDominio* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->anio;;
    }
    return ret;
}

char* eDominio_getTipo(eDominio* this)
{

    return this->tipo;
}

/** **/
void  eDominio_showDomio(eDominio* this)
{
    if(this != NULL )
    {
        printf(" %4d  %10s  %4d  %c\n\n ", eDominio_getIdDom(this), eDominio_getDominio(this), eDominio_getAnioDom(this),
                 eDominio_getTipo(this));
    }
}

void  eDominio_showDominios(eDominio* this)
{
    eDominio* pDopm;
    int len;
    len = ll_len(this);
    if(this != NULL )
    {
        for(int i=0; i<len;i++)
        {
            pDopm = (eDominio*)ll_get(this, i);
            eDominio_showDomio(pDopm);
        }
    }
    else
    {
        printf("No hay envios cargados\n\n");
        system("pause");
    }
}


char eDominio_tipoDominio(void* vehiculo)
{
    char ret;
    int len = strlen(((eDominio*)vehiculo)->dominio);
    for(int i = 0; i <len;i++)
    {
       if(eDominio_isValidNumber(((eDominio*)vehiculo)->dominio[0]))
       {
            ret = ((eDominio*)vehiculo)->tipo = 'A';
       }
       else
       {
            ret = ((eDominio*)vehiculo)->tipo = 'M';
       }
    }
    return ret;

}



int eDominio_vehiculoDominio(void* vehiculos, char tipo)
{
    int retAux = 2;
    void* filterZona;
    if(((eDominio*)vehiculos)->tipo == 'A' && tipo == 'A')
    {
        filterZona = ((eDominio*)vehiculos);
        retAux = 0;
    }
    else if(((eDominio*)vehiculos)->tipo == 'M' && tipo == 'M')
    {
        filterZona = ((eDominio*)vehiculos);
        retAux = 1;
    }

    return retAux;
}

int  eDominio_isValidNumber(char charRecibido)
{
    int retorno = RETURN_ERROR ;
    if (charRecibido < '0' || charRecibido > '9')
    {
        retorno = RETURN_OK ;
    }
    return retorno;
}





