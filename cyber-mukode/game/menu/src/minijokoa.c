#include "include.h"


int JOKO_miniJokoa()
{
    int denbora = 2, ebentu = 0, kont = 0;
    MINIEGOERA aukera = -1;
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
        if (ebentu == TECLA_RIGHT)  mugitu = RIGHT;
        else if (ebentu == TECLA_LEFT) mugitu = LEFT;
        else if (ebentu == TECLA_DOWN) mugitu = DOWN;
        else if (ebentu == TECLA_UP) mugitu = UP;

        if (mugitu == RIGHT) {
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
        if (mugitu == LEFT)
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
        if (mugitu == UP) {
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
        if (mugitu == DOWN)
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
        mugitu = 0;

    } while (aukera != BORROKA && aukera != KREDITUAK && aukera != LAGUNTZA && aukera != PERTSONAIAK && aukera != MENU && aukera != MINIGALDU);

    return aukera;
}