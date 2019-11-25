

typedef struct{

    int id;
    char dominio[10];
    int anio;
    char tipo;

}eDominio;

eDominio* eDominio_new();
eDominio* eDominio_newParametros(char* idStr, char* dominioStr, char* anioStr);
int eDominio_delete(eDominio* this);

/** Setters **/
int eDominio_setId(eDominio* this, int id);
int eDominio_setDominio(eDominio* this, char* dominio);
int eDominio_setAnio(eDominio* this, int anio);
int eDominio_setTipo(eDominio* this, char* tipo);
/** Getters **/
int eDominio_getId(eDominio* this, int* id);
int eDominio_getIdDom(eDominio* this);
char* eDominio_getDominio(eDominio* this);
int eDominio_getAnio(eDominio* this, int* anio);
int eDominio_getAnioDom(eDominio* this);
char* eDominio_getTipo(eDominio* this);
/** **/
void  eDominio_showDomio(eDominio* this);
void  eDominio_showDominios(eDominio* this);
char eDominio_tipoDominio(void* dominio);
int  eDominio_isValidNumber(char charRecibido);
int eDominio_vehiculoDominio(void* vehiculos, char tipo);


