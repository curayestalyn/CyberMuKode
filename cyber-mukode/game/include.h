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
#include <stdlib.h>

typedef enum EGOERA { JOLASTEN, GALDU, IRABAZI } EGOERA;
typedef enum MOTA { IRUDIA, MARGOA, TESTUA } MOTA;

typedef struct JOKO_ELEMENTUA {
    POSIZIOA pos;
    int id;
    MOTA mota;
} JOKO_ELEMENTUA;


//********** Jokoa.c
EGOERA JOKOA_jokatu(int jokalaria_Jok1, int jokalaria_Jok2, int* puntuazioa_Jok1, int* puntuazioa_Jok2);
EGOERA JOKOA_egoera(JOKO_ELEMENTUA pertsonaia_Jok1, JOKO_ELEMENTUA pertsonaia_Jok2, int bizitzaBarra_Jok1, int bizitzaBarra_Jok2, int tenporizadorea);
int  AMAIERA_jokoAmaierakoa(EGOERA egoera);
POSIZIOA MUGIMENDUA_rightUpMugitu(POSIZIOA posizioa);
POSIZIOA MUGIMENDUA_leftDownMugitu(POSIZIOA posizioa);
//*********** Jokalaria interakzioarako
JOKO_ELEMENTUA JOKOA_lehenegoJokalaria(JOKO_ELEMENTUA jokalaria, SDL_Event event);
JOKO_ELEMENTUA JOKOA_bigarrenJokalaria(JOKO_ELEMENTUA jokalaria, SDL_Event event);
// Bizitza kudeatzeko
JOKO_ELEMENTUA JOKOA_bizitzaBarra(JOKO_ELEMENTUA bizitzaBarra, char* irudia);

//********** Minijokoa.c
JOKO_ELEMENTUA MINIJOKOA_eszenaIrudiaKudeatu(JOKO_ELEMENTUA eszena, char* irudia);
JOKO_ELEMENTUA MINIJOKOA_jokalariaAukeranBadago(JOKO_ELEMENTUA jokalaria, char* irudia);
int MINIJOKOA_jokalariarenDesplazamendua(JOKO_ELEMENTUA jokalaria, char* irudia);

//********* Jok1 eta Jok2 
JOKO_ELEMENTUA JOKALARIAK_pertsonaiarenDesplazamendua(JOKO_ELEMENTUA jokalaria, int aux, char* irudia);
#endif // !INCLUDE_H
