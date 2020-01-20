#include "include.h"




int MINIJOKOA_miniJokoa(int* pertsonaia_Jok1, int* pertsonaia_Jok2)
{
    int denbora = 2, ebentu = 0, mugimenduKont = 0;
    MINIEGOERA aukera =-1;
    MINIMUGIMENDUA noraMugitu = GELDIK;
    JOKO_ELEMENTUA jokalaria, eszena;
    PERTSONAIMOTA aukeratuPertsonaia_Jok1 = NAIRU, aukeratuPertsonaia_Jok2 = IBAY;
    POSIZIOA aux;

    //************* Eszena tokiaren hasierako posizioa **********************
    eszena.pos.x = 0;
    eszena.pos.y = 0;

    //************* Petsonaiaren hasierako posizioa *************************
    jokalaria.pos.x = 660;
    jokalaria.pos.y = 500;

    //************ Soinua *******************

    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();

    //************ Eszenaren irudiak kargatu eta identifikatzaile bat eman ********************
    eszena.id = IRUDIAK_irudiaGehitu(IRUDIA_MAPA_2);
    //************ Pertsonaien irudiak kargatu eta identifikatzaile bat eman ********************
    jokalaria.id = IRUDIAK_irudiaGehitu(IRUDIA_MINIJOKOA_MINIUP_1);

    //*********** Pertsoniak hasierako mugimendua *******************
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();

    //******************* Jokoaren interakzioa hasten da ********************
    do
    {
        Sleep(denbora);
        pantailaGarbitu();

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT)  noraMugitu = ESKUMA;
        else if (ebentu == TECLA_LEFT) noraMugitu = EZKERRA;
        else if (ebentu == TECLA_DOWN) noraMugitu = BEHERA;
        else if (ebentu == TECLA_UP) noraMugitu = GORA;

        switch (noraMugitu)
        {
        case ESKUMA:
            aux = MUGIMENDUA_rightUpMugitu(jokalaria.pos);
            jokalaria.pos.x = aux.x;
            mugimenduKont++;
            switch (mugimenduKont)
            {
            case 0:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIRIGHT_1); break;
            case 1:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIRIGHT_2); break;
            case 2:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIRIGHT_3); break;
            case 3:
                jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIRIGHT_1);
                mugimenduKont = 0;
                break;
            }
            break;
        case EZKERRA:
            aux = MUGIMENDUA_leftDownMugitu(jokalaria.pos);
            jokalaria.pos.x = aux.x;
            mugimenduKont++;
            switch (mugimenduKont)
            {
            case 0:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINILEFT_1); break;
            case 1:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINILEFT_2); break;
            case 2:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINILEFT_3); break;
            case 3:
                jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINILEFT_1);
                mugimenduKont = 0;
                break;
            }
            break;
        case GORA:
            aux = MUGIMENDUA_leftDownMugitu(jokalaria.pos);
            jokalaria.pos.y = aux.y;
            mugimenduKont++;
            switch (mugimenduKont)
            {
            case 0:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIUP_1); break;
            case 1:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIUP_2); break;
            case 2: jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIUP_3); break;
            case 3:
                jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIUP_1);
                mugimenduKont = 0;
                break;
            }
            break;
        case BEHERA:
            aux = MUGIMENDUA_rightUpMugitu(jokalaria.pos);
            jokalaria.pos.y = aux.y;
            mugimenduKont++;
            switch (mugimenduKont)
            {
            case 0:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_1); break;
            case 1:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_2); break;
            case 2:jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_3); break;
            case 3:
                jokalaria.id = MINIJOKOA_jokalariarenDesplazamendua(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_1);
                mugimenduKont = 0;
                break;
            }
            break;

        }
    
        irudiakMarraztu();
        pantailaBerriztu();
        //******** Kolisioak *********
        if ((jokalaria.pos.x == 700) && (jokalaria.pos.y >= 540 && jokalaria.pos.y <= 580)) jokalaria.pos.x = 680;
        if ((jokalaria.pos.x >= 720 && jokalaria.pos.x <= 1160) && (jokalaria.pos.y == 520)) jokalaria.pos.y = 500;
        if ((jokalaria.pos.x == 1160) && (jokalaria.pos.y >= 460 && jokalaria.pos.y <= 500)) jokalaria.pos.x = 1140;
        if ((jokalaria.pos.x >= 1040 && jokalaria.pos.x <= 1160) && (jokalaria.pos.y == 460)) jokalaria.pos.y = 480;
        if ((jokalaria.pos.x == 1020) && (jokalaria.pos.y >= 360 && jokalaria.pos.y <= 440)) jokalaria.pos.x = 1000;
        if ((jokalaria.pos.x == 960) && (jokalaria.pos.y >= 360 && jokalaria.pos.y <= 440)) jokalaria.pos.x = 980;
        if ((jokalaria.pos.x >= 760 && jokalaria.pos.x <= 940) && (jokalaria.pos.y == 460)) jokalaria.pos.y = 480;
        if ((jokalaria.pos.x == 740) && (jokalaria.pos.y == 440)) jokalaria.pos.y = 460;
        if ((jokalaria.pos.x == 720) && (jokalaria.pos.y == 420)) jokalaria.pos.y = 440;
        if ((jokalaria.pos.x == 700) && (jokalaria.pos.y >= 300 && jokalaria.pos.y <= 440)) jokalaria.pos.x = 680;
        if ((jokalaria.pos.x == 640) && (jokalaria.pos.y >= 300 && jokalaria.pos.y <= 420)) jokalaria.pos.x = 660;
        if ((jokalaria.pos.x == 600) && (jokalaria.pos.y >= 420 && jokalaria.pos.y <= 440)) jokalaria.pos.x = 620;
        if ((jokalaria.pos.x == 620) && (jokalaria.pos.y == 420)) jokalaria.pos.y = 440;
        if ((jokalaria.pos.x >= 400 && jokalaria.pos.x <= 580) && (jokalaria.pos.y == 460)) jokalaria.pos.y = 480;
        if ((jokalaria.pos.x == 380) && (jokalaria.pos.y >= 340 && jokalaria.pos.y <= 440)) jokalaria.pos.x = 360;
        if ((jokalaria.pos.x == 320) && (jokalaria.pos.y >= 320 && jokalaria.pos.y <= 460)) jokalaria.pos.x = 340;
        if ((jokalaria.pos.x >= 240 && jokalaria.pos.x <= 320) && (jokalaria.pos.y == 460)) jokalaria.pos.y = 480;
        if ((jokalaria.pos.x == 220) && (jokalaria.pos.y >= 340 && jokalaria.pos.y <= 440)) jokalaria.pos.x = 200;
        if ((jokalaria.pos.x == 160) && (jokalaria.pos.y >= 320 && jokalaria.pos.y <= 460)) jokalaria.pos.x = 180;
        if ((jokalaria.pos.x >= 40 && jokalaria.pos.x <= 140) && (jokalaria.pos.y == 460)) jokalaria.pos.y = 480;
        if ((jokalaria.pos.x == 40) && (jokalaria.pos.y >= 460 && jokalaria.pos.y <= 520)) jokalaria.pos.x = 60;
        if ((jokalaria.pos.x >= 40 && jokalaria.pos.x <= 620) && (jokalaria.pos.y == 520)) jokalaria.pos.y = 500;
        if ((jokalaria.pos.x == 640) && (jokalaria.pos.y >= 540 && jokalaria.pos.y <= 580)) jokalaria.pos.x = 660;
        //******** Aukerak ***********
        if ((jokalaria.pos.x >= 660 && jokalaria.pos.x <= 680) && (jokalaria.pos.y >= 220 && jokalaria.pos.y <= 240)) aukera = BORROKA;
        if ((jokalaria.pos.x >= 620 && jokalaria.pos.x <= 640) && (jokalaria.pos.y >= 240 && jokalaria.pos.y <= 280)) aukera = MINIGALDU;
        if ((jokalaria.pos.x >= 700 && jokalaria.pos.x <= 740) && (jokalaria.pos.y >= 260 && jokalaria.pos.y <= 280)) aukera = MINIGALDU;
        if ((jokalaria.pos.x >= 180 && jokalaria.pos.x <= 200) && (jokalaria.pos.y >= 280 && jokalaria.pos.y <= 320)) aukera = KREDITUAK;
        if ((jokalaria.pos.x >= 340 && jokalaria.pos.x <= 360) && (jokalaria.pos.y >= 280 && jokalaria.pos.y <= 320)) aukera = LAGUNTZA;
        if ((jokalaria.pos.x >= 960 && jokalaria.pos.x <= 1020) && (jokalaria.pos.y >= 340 && jokalaria.pos.y <= 360)) aukera = PERTSONAIAK;
        if ((jokalaria.pos.x >= 640 && jokalaria.pos.x <= 700) && (jokalaria.pos.y >= 580 && jokalaria.pos.y <= 600)) aukera = MENU;
        
        switch (aukera)
        {
            case KREDITUAK:
                eszena = MINIJOKOA_eszenaIrudiaKudeatu(eszena, IRUDIA_MINIJOKOA_KREDITUAK);
                do { ebentu = ebentuaJasoGertatuBada(); } while (ebentu != TECLA_ESCAPE);
                eszena = MINIJOKOA_eszenaIrudiaKudeatu(eszena, IRUDIA_MAPA_2);
                jokalaria = MINIJOKOA_jokalariaAukeranBadago(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_1);
                aukera = -1;
                break;
            case LAGUNTZA:
                eszena = MINIJOKOA_eszenaIrudiaKudeatu(eszena, IRUDIA_MINIJOKOA_LAGUNTZA);
                do { ebentu = ebentuaJasoGertatuBada(); } while (ebentu != TECLA_ESCAPE);
                eszena = MINIJOKOA_eszenaIrudiaKudeatu(eszena, IRUDIA_MAPA_2);
                jokalaria = MINIJOKOA_jokalariaAukeranBadago(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_1);
                aukera = -1;
                break;
            case PERTSONAIAK:

                eszena = MINIJOKOA_eszenaIrudiaKudeatu(eszena, IRUDIA_MINIJOKOA_PERTSONAIA_NAIRU);
                aukeratuPertsonaia_Jok1 = MINIJOKOA_pertsonaiAukeratu();
                aukeratuPertsonaia_Jok2 = MINIJOKOA_pertsonaiAukeratu();
                eszena = MINIJOKOA_eszenaIrudiaKudeatu(eszena, IRUDIA_MAPA_2);
                jokalaria = MINIJOKOA_jokalariaAukeranBadago(jokalaria, IRUDIA_MINIJOKOA_MINIDOWN_1);
                aukera = -1;
                break;       
        }
        noraMugitu = GELDIK ;
    } while (aukera != MINIGALDU && aukera != BORROKA && aukera != MENU);
    // Lehenengo jokalaiaren pertsonaia
    *(pertsonaia_Jok1) = aukeratuPertsonaia_Jok1;
    // Bigarren joaklariaren pertsonaia
    *(pertsonaia_Jok2) = aukeratuPertsonaia_Jok2;
    return aukera;
}


JOKO_ELEMENTUA MINIJOKOA_eszenaIrudiaKudeatu(JOKO_ELEMENTUA eszena, char* irudia)
{

    irudiaKendu(eszena.id);
    eszena.id = IRUDIAK_irudiaGehitu(irudia);
    irudiakMarraztu();
    pantailaBerriztu();

    return eszena;
}
JOKO_ELEMENTUA MINIJOKOA_jokalariaAukeranBadago(JOKO_ELEMENTUA jokalaria, char* irudia)
{
    irudiaKendu(jokalaria.id);
    jokalaria.id = IRUDIAK_irudiaGehitu(irudia);
    jokalaria.pos.y += 30;
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();

    return jokalaria;
}

int MINIJOKOA_pertsonaiAukeratu()
{
    int ebentu = 0, pertsonaiaPosizioa = 4, aukeratuJokalaria = NAIRU;
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT)
        {
            pertsonaiaPosizioa--;
            aukeratuJokalaria = MINIJOKOA_pertsonaienArgazkiak(pertsonaiaPosizioa);
        }
        if (ebentu == TECLA_LEFT)
        {
            pertsonaiaPosizioa++;
            aukeratuJokalaria = MINIJOKOA_pertsonaienArgazkiak(pertsonaiaPosizioa);
        }
        if (pertsonaiaPosizioa >= 4) pertsonaiaPosizioa = 4;
        if (pertsonaiaPosizioa <= 0) pertsonaiaPosizioa = 1;
    } while (ebentu != TECLA_RETURN);

    return aukeratuJokalaria;
}





int MINIJOKOA_pertsonaienArgazkiak(int aukera)
{
    int jokalaria = 0, id = -1;
    if (aukera >= 4) {
        id = IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_NAIRU, 0, 0);
        jokalaria = NAIRU;
    }
    if (aukera >= 3 && aukera < 4) {
        id = IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_IBAY, 0, 0);
        jokalaria = IBAY;
    }
    if (aukera >= 2 && aukera < 3) {
        id = IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_THALIEL, 0, 0);
        jokalaria = THALIEL;
    }
    if (aukera >= 0 && aukera < 2) {
        id = IRUDIA_argazkiaGehitu(IRUDIA_MINIJOKOA_PERTSONAIA_TRYDAN, 0, 0);
        jokalaria = TRYDAN;
    }
    irudiaKendu(id);
    return jokalaria;
}



int MINIJOKOA_jokalariarenDesplazamendua(JOKO_ELEMENTUA jokalaria, char* irudia)
{
    irudiaKendu(jokalaria.id);
    jokalaria.id = IRUDIAK_irudiaGehitu(irudia);
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);

    return jokalaria.id;
}