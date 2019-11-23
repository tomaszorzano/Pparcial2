
typedef struct
{
    int id;
    char fecha[11];
    char tipo[32];
    int cantidad;
    float precio;
    char cuit[41];
}efoto;

efoto* foto_new();
efoto* foto_newParametros(char* idFotoStr, char* fechaFotoStr, char* tipoFotoStr, char* cantidadStr, char* precioStr,
                           char* cuitStr);
int foto_delete(efoto* this);

int foto_setIdfoto(efoto* this, int idfoto);
int foto_getidfoto(efoto* this, int* idfoto);
int foto_setfechafoto(efoto* this, char* fechafoto);
int foto_getfechafoto(efoto* this, char* fechafoto);
int foto_setTipoFoto(efoto* this, char* tipofoto);
int foto_getTipoFoto(efoto* this, char* tipofoto);
int foto_setCantidadFoto(efoto* this, int cantidadfoto);
int foto_getCantidadFoto(efoto* this, int* cantidadfoto);
int foto_setPrecioFoto(efoto* this, float preciofoto);
int foto_getPrecioFoto(efoto* this, float* preciofoto);
int foto_setCuitFoto(efoto* this, char* cuitfoto);
int foto_getCuitFoto(efoto* this, char* cuitfoto);

int foto_fotoCantidadTotal(void* fotos);
int foto_ventasMayor150(void* venta);
int foto_ventasMayor300(void* venta);
int foto_cantidadFotosPolarodids(void* venta);
void  foto_showVenta(efoto* this);
void  foto_showVentas(efoto* this);
