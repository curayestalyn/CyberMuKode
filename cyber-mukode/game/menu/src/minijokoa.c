#include "include.h"



int MINIJOKOA_miniJokoa(int* jokalaria)
{
    int denbora = 2, ebentu = 0, kont = 0, aukeratuJokalaria = NAIRU;
    MINIEGOERA aukera =-1;
    MUGIMENDUA mugitu = STOP;
    JOKO_ELEMENTUA pertsonaia, background;
    POSIZIOA aux;

    //************* Eszena tokiaren hasierako posizioa **********************
    background.pos.x = 0;
    background.pos.y = 0;

    //************* Petsonaiaren hasierako posizioa *************************
    pertsonaia.pos.x = 660;
    pertsonaia.pos.y = 500;

    //************ Soinua *******************

    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();

    //************ Eszenaren irudiak kargatu eta identifikatzaile bat eman ********************
    background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
    //************ Pertsonaien irudiak kargatu eta identifikatzaile bat eman ********************
    pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIUP_1);

    //*********** Pertsoniak hasierako mugimendua *******************
    irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();
    do
    {
        Sleep(denbora);
        pantailaGarbitu();

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT)  mugitu = RIGHTL;
        else if (ebentu == TECLA_LEFT) mugitu = LEFTL;
        else if (ebentu == TECLA_DOWN) mugitu = DOWNL;
        else if (ebentu == TECLA_UP) mugitu = UPL;

        if (mugitu == RIGHTL) {
            aux = MUGIMENDUA_rightUpMugitu(pertsonaia.pos);
            pertsonaia.pos.x = aux.x;
            kont++;
            if (kont == 0)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIRIGHT_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIRIGHT_2);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIRIGHT_3);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 3)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIRIGHT_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 3) kont = 0;
        }
        if (mugitu == LEFTL)
        {
            aux = MUGIMENDUA_leftDownMugitu(pertsonaia.pos);
            pertsonaia.pos.x = aux.x;
            kont++;
            if (kont == 0)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINILEFT_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINILEFT_2);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINILEFT_3);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 3)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINILEFT_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 3) kont = 0;
        }
        if (mugitu == UPL) {
            aux = MUGIMENDUA_leftDownMugitu(pertsonaia.pos);
            pertsonaia.pos.y = aux.y;
            kont++;
            if (kont == 0)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIUP_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIUP_2);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIUP_3);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 3)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIUP_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 3) kont = 0;
        }
        if (mugitu == DOWNL)
        {
            aux = MUGIMENDUA_rightUpMugitu(pertsonaia.pos);
            pertsonaia.pos.y = aux.y;
            kont++;
            if (kont == 0)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIDOWN_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIDOWN_2);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIDOWN_3);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 3)
            {
                background.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
                pertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIDOWN_1);
                irudiaMugitu(pertsonaia.id, pertsonaia.pos.x, pertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();

            }
            if (kont == 3) kont = 0;
        }

        if ((pertsonaia.pos.x >= 660 && pertsonaia.pos.x <= 680) && (pertsonaia.pos.y >= 220 && pertsonaia.pos.y <= 240)) aukera = BORROKA;
        if ((pertsonaia.pos.x >= 620 && pertsonaia.pos.x <= 640) && (pertsonaia.pos.y >= 240 && pertsonaia.pos.y <= 280)) aukera = MINIGALDU;
        if ((pertsonaia.pos.x >= 700 && pertsonaia.pos.x <= 740) && (pertsonaia.pos.y >= 260 && pertsonaia.pos.y <= 280)) aukera = MINIGALDU;
        if ((pertsonaia.pos.x >= 180 && pertsonaia.pos.x <= 200) && (pertsonaia.pos.y >= 280 && pertsonaia.pos.y <= 320)) aukera = KREDITUAK;
        if ((pertsonaia.pos.x >= 340 && pertsonaia.pos.x <= 360) && (pertsonaia.pos.y >= 280 && pertsonaia.pos.y <= 320)) aukera = LAGUNTZA;
        if ((pertsonaia.pos.x >= 960 && pertsonaia.pos.x <= 1020) && (pertsonaia.pos.y >= 340 && pertsonaia.pos.y <= 360)) aukera = PERTSONAIAK;
        if ((pertsonaia.pos.x >= 640 && pertsonaia.pos.x <= 700) && (pertsonaia.pos.y >= 580 && pertsonaia.pos.y <= 600)) aukera = MENU;

        if (aukera == KREDITUAK) { MINIJOKOA_kredituakLaguntzaAukerak(IRUDIA_MAPA_2, IRUDIA_MINIJOKOA_MINIDOWN_1, IRUDIA_MINIJOKOA_KREDITUAK, &background.id, &pertsonaia.id, &pertsonaia.pos.x, &pertsonaia.pos.y); aukera = -1; }
        if (aukera == LAGUNTZA) { MINIJOKOA_kredituakLaguntzaAukerak(IRUDIA_MAPA_2, IRUDIA_MINIJOKOA_MINIDOWN_1, IRUDIA_MINIJOKOA_LAGUNTZA, &background.id, &pertsonaia.id, &pertsonaia.pos.x, &pertsonaia.pos.y); aukera = -1; }
        if (aukera == PERTSONAIAK)
        {
            aukeratuJokalaria = MINIJOKOA_pertsonaienAukerak(IRUDIA_MAPA_2, IRUDIA_MINIJOKOA_MINIDOWN_1, IRUDIA_MINIJOKOA_PERTSONAIA_NAIRU, &background.id, &pertsonaia.id, &pertsonaia.pos.x, &pertsonaia.pos.y);
            (*jokalaria) = aukeratuJokalaria;
            aukera = -1;
        }
        printf("x:%d, y:%d", pertsonaia.pos.x, pertsonaia.pos.y);
        mugitu = STOP;
    } while (aukera != MINIGALDU && aukera != BORROKA && aukera != MENU);

    return aukera;
}


void MINIJOKOA_kredituakLaguntzaAukerak(char* irudiMapaOrg, char* irudiPertsonaia, char* irudiAukera, int* mapaId, int* perId, int* perX, int* perY)
{
    int ebentu = 0, idMapa, idPer;
    IRUDIA_argazkiaGehitu(irudiAukera, 0, 0);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE);
    idMapa = IRUDIAK_irudiaGehitu(irudiMapaOrg);
    (*mapaId) = idMapa;
    idPer = IRUDIAK_irudiaGehitu(irudiPertsonaia);
    (*perId) = idPer;
    (*perY) += 30;
    irudiaMugitu(*perId, *perX, *perY);
    irudiakMarraztu();
    pantailaBerriztu();
}

int MINIJOKOA_pertsonaienArgazkiak(int aukera)
{
    int jokalaria = 0;
    if (aukera >= 4) {
        IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_NAIRU, 0, 0);
        jokalaria = NAIRU;
    }
    if (aukera >= 3 && aukera < 4) {
        IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_IBAY, 0, 0);
        jokalaria = IBAY;
    }
    if (aukera >= 2 && aukera < 3) {
        IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_THALIEL, 0, 0);
        jokalaria = THALIEL;
    }
    if (aukera >= 0 && aukera < 2) {
        IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_TRYDAN, 0, 0);
        jokalaria = TRYDAN;
    }
    return jokalaria;
}

int MINIJOKOA_pertsonaienAukerak(char* irudiMapaOrg, char* irudiPertsonaia, char* irudiAukera, int* mapaId, int* perId, int* perX, int* perY)
{
    int ebentu = 0, idMapa, idPer, menuPosizioa = 4, aukeratuJokalaria = NAIRU;
    IRUDIA_argazkiaGehitu(irudiAukera, 0, 0);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT)
        {
            menuPosizioa--;
            aukeratuJokalaria = MINIJOKOA_pertsonaienArgazkiak(menuPosizioa);
        }
        if (ebentu == TECLA_LEFT)
        {
            menuPosizioa++;
            aukeratuJokalaria = MINIJOKOA_pertsonaienArgazkiak(menuPosizioa);
        }
        if (menuPosizioa >= 4) menuPosizioa = 4;
        if (menuPosizioa <= 0) menuPosizioa = 1;

    } while (ebentu != TECLA_RETURN);


    idMapa = IRUDIAK_irudiaGehitu(irudiMapaOrg);
    (*mapaId) = idMapa;
    idPer = IRUDIAK_irudiaGehitu(irudiPertsonaia);
    (*perId) = idPer;
    (*perY) += 30;
    irudiaMugitu(*perId, *perX, *perY);
    irudiakMarraztu();
    pantailaBerriztu();

    return aukeratuJokalaria;
}
