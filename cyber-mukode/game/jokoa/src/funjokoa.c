#include "include.h"

int IRUDIAK_irudiaGehitu(char* irudiaIzena)
{
    int irudiaId = -1;
    irudiaId = irudiaKargatu(irudiaIzena);
    return irudiaId;
}



int BUKAERA_irudiaBistaratu() {
    int id = -1;
    id = irudiaKargatu(BUKAERA_IMAGE);
    irudiaMugitu(id, 0, 0);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return id;
}

void IRUDIA_argazkiaGehitu(char* irudiaIzena, int posX, int posY)
{
    int id = -1;
    id = irudiaKargatu(irudiaIzena);
    irudiaMugitu(id, posX, posY);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
}


POSIZIOA MUGIMENDUA_rightUpMugitu(POSIZIOA posizioa)
{
    posizioa.y = posizioa.y + 20;
    posizioa.x = posizioa.x + 20;
    return posizioa;
}

POSIZIOA MUGIMENDUA_leftDownMugitu(POSIZIOA posizioa)
{
    posizioa.y = posizioa.y - 20;
    posizioa.x = posizioa.x - 20;
    return posizioa;

}