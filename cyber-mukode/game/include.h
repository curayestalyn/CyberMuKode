#ifndef INCLUDE_H
#define INCLUDE_H

#define _CRT_SECURE_NO_WARNINGS

//********** SDL include *******
#include "ebentoak.h"
#include "imagen.h"
#include "graphics.h"
#include "text.h"
#include "soinua.h"
//********* Visual Studio *******
#include <stdio.h>
#include <windows.h>
//******** Gure include *********
#include "img.h"
#include "sound.h"
#include "menu.h"
#include "minijokoa.h"
#include "puntuazioa.h"
#include "jokoa.h"

typedef enum EGOERA { JOLASTEN, GALDU, IRABAZI } EGOERA;
typedef enum MOTA { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct JOKO_ELEMENTUA {
    POSIZIOA pos;
    int id;
    MOTA mota;
} JOKO_ELEMENTUA;

typedef enum MUGIMENDUA { STOP, UPL, RIGHTL, LEFTL, DOWNL, UPR, RIGHTR, LEFTR, DOWNR } MUGIMENDUA;


EGOERA JOKOA_jokatu(int jokalaria);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA lehenengoPertsonaia, JOKO_ELEMENTUA bigarrenPertsonaia);
int  AMAIERA_jokoAmaierakoa(EGOERA egoera);
POSIZIOA MUGIMENDUA_rightUpMugitu(POSIZIOA posizioa);
POSIZIOA MUGIMENDUA_leftDownMugitu(POSIZIOA posizioa);

#endif // !INCLUDE_H