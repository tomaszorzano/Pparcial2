#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foto.h"
#include "Validaciones.h"

#define RETURN_OK 1

#define RETURN_ERROR 0

efoto* foto_new()
{
    efoto* pfoto = (efoto *) calloc ( 1 , sizeof (efoto));
    if(pfoto == NULL)
    {
        printf("No se pudo encontrar el espacio para liberar o reiniciar el programa ... ");
        system("pause");
    }

    return pfoto;
};

efoto* foto_newParametros(char* idFotoStr, char* fechaFotoStr, char* tipoFotoStr, char* cantidadStr, char* precioStr,
                           char* cuitStr)
{
    efoto* pfoto = foto_new();

    foto_setIdfoto(pfoto, atoi(idFotoStr));
    foto_setfechafoto(pfoto, fechaFotoStr);
    foto_setTipoFoto(pfoto, tipoFotoStr);
    foto_setCantidadFoto(pfoto, atoi(cantidadStr));
    foto_setPrecioFoto(pfoto, atof(precioStr));
    foto_setCuitFoto(pfoto, cuitStr);

    return pfoto;
}
int foto_delete(efoto* this)
{
    int retorno = -1;

    if (this!=NULL )
    {
        free(this);
        retorno = RETURN_OK;
    }
    return retorno;
}
int foto_setIdfoto(efoto* this, int idfoto)
{
    int ret;
    ret = RETURN_ERROR;

    if(idfoto > 0 && this != NULL)
    {
        this->id = idfoto;
        ret = RETURN_OK;
    }
    return ret;
}

int foto_getidfoto(efoto* this, int* idfoto)
{
    int ret;
    ret = RETURN_ERROR;

    if(idfoto > 0 && this != NULL)
    {
        *idfoto = this->id;
        ret = RETURN_OK;
    }
    return ret;
}
int foto_setfechafoto(efoto* this, char* fechafoto)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL && isValidFecha(fechafoto))
    {
        strcpy(this->fecha, fechafoto);
        ret = RETURN_OK;
    }
    return ret;
}
int foto_getfechafoto(efoto* this, char* fechafoto)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && fechafoto!=NULL )
    {
        strcpy(fechafoto,this->fecha);
        ret = RETURN_OK;
    }
    return ret;
}
int foto_setTipoFoto(efoto* this, char* tipofoto)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL && tipofoto != NULL )
    {
        strcpy(this->tipo, tipofoto);
        ret = RETURN_OK;
    }
    return ret;
}
int foto_getTipoFoto(efoto* this, char* tipofoto)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && tipofoto!=NULL )
    {
        strcpy(tipofoto,this->tipo);
        ret = RETURN_OK;
    }
    return ret;
}

int foto_setCantidadFoto(efoto* this, int cantidadfoto)
{
     int ret;
    ret = RETURN_ERROR;

    if(cantidadfoto > 0 && this != NULL && isValidInt(cantidadfoto, 0, 1000))
    {
        this->cantidad = cantidadfoto;
        ret = RETURN_OK;
    }
    return ret;
}
int foto_getCantidadFoto(efoto* this, int* cantidad)
{
    int ret;
    ret = RETURN_ERROR;
    if(cantidad != NULL && this != NULL)
    {
        *cantidad = this->cantidad;
        ret = RETURN_OK;
    }
    return ret;
}

int foto_setPrecioFoto(efoto* this, float preciofoto)
{
    int ret;
    ret = RETURN_ERROR;

    if(preciofoto > 0 && this != NULL && isValidFloat(preciofoto, 0, 5000))
    {
        this->precio = preciofoto;
        ret = RETURN_OK;
    }
    return ret;
}
int foto_getPrecioFoto(efoto* this, float* preciofoto)
{
     int ret;
    ret = RETURN_ERROR;
    if(preciofoto != NULL && this != NULL)
    {
        *preciofoto = this->precio;
        ret = RETURN_OK;
    }
    return ret;
}

int foto_setCuitFoto(efoto* this, char* cuitfoto)
{
    int ret;
    ret = RETURN_ERROR;
    if(this != NULL && cuitfoto != NULL )
    {
        strcpy(this->cuit, cuitfoto);
        ret = RETURN_OK;
    }
    return ret;
}
int foto_getCuitFoto(efoto* this, char* cuitfoto)
{
    int ret = RETURN_ERROR;

    if (this!=NULL && cuitfoto!=NULL )
    {
        strcpy(cuitfoto,this->cuit);
        ret = RETURN_OK;
    }
    return ret;
}

int foto_fotoCantidadTotal(void* venta)
{
    int ret = RETURN_ERROR;
    int cantidad = 0;
    efoto* aux;
    aux = (efoto*)venta;
    if(aux != NULL)
    {
        foto_getCantidadFoto((efoto*)venta, &cantidad);
        ret = cantidad;
    }
    return ret;
}

int foto_ventasMayor150(void* venta)
{
    int ret = RETURN_ERROR;
    float total;
    int cantidad = 0;
    float precio = 0;
    foto_getCantidadFoto(venta, &cantidad);
    foto_getPrecioFoto(venta, &precio);
    total = precio * cantidad;
    if(total > 150)
    {
        ret = RETURN_OK;
    }
    return ret;
}

int foto_ventasMayor300(void* venta)
{
    int ret = RETURN_ERROR;
    float total;
    int cantidad = 0;
    float precio = 0;
    foto_getCantidadFoto(venta, &cantidad);
    foto_getPrecioFoto(venta, &precio);
    total = precio * cantidad;
    if(total > 300)
    {
        ret = RETURN_OK;
    }
    return ret;
}
int foto_cantidadFotosPolarodids(void* venta)
{
    int ret = RETURN_ERROR;
    char auxTipo[50];
    foto_getTipoFoto(venta, auxTipo);
    if(strcmp(auxTipo, "POLAROID_11x9") == 0 || strcmp(auxTipo, "POLAROID_10x10") == 0)
    {
        ret = RETURN_OK;
    }
    return ret;
}

void  foto_showVenta(efoto* this)
{
    int idAux;
    char auxFecha[50];
    char auxTipoFoto[50];
    char auxCuit[50];
    int auxCant;
    float auxPrecioUnit;
    if((efoto*)this != NULL )
    {
        if( foto_getidfoto((efoto*)this, &idAux)&&
            foto_getfechafoto((efoto*)this, auxFecha)&&
            foto_getCantidadFoto((efoto*)this, &auxCant)&&
            foto_getTipoFoto((efoto*)this, auxTipoFoto)&&
            foto_getPrecioFoto((efoto*)this, &auxPrecioUnit)&&
            foto_getCuitFoto((efoto*)this, auxCuit))
        {
            printf("%4d %15s %20s %4d %.2f %15s\n\n ", idAux, auxFecha, auxTipoFoto,
               auxCant, auxPrecioUnit, auxCuit);
        }
    }

}

void  foto_showVentas(efoto* this)
{
    efoto* pFoto;
    int len;
    len = ll_len(this);
    if(this != NULL )
    {
        for(int i=0; i<len;i++)
        {
            pFoto = (efoto*)ll_get(this, i);
            foto_showVenta(pFoto);
        }
    }
    else
    {
        printf("No hay envios cargados\n\n");
        system("pause");
    }

}
