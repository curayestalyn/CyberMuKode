#include "include.h"
/*
    Jokalaria 1 = Jok1
    Jokalaria 2 = Jok2

*/


EGOERA JOKOA_jokatu(int jokalaria_Jok1, int jokalaria_Jok2, int* puntuazioa_Jok1, int* puntuazioa_Jok2)
{
    int sleepDenbora = 2, tenporizadorea = 2150, tenporizadoreEgoera ,kontBizitzaBarra_Jok1 = 6, kontBizitzaBarra_Jok2 = 6, kontPuntuazioa_Jok1 = 0, kontPuntuazioa_Jok2 = 0, pausaArgazkiaId = -1, pausaAukera;
    SDL_Event event;
    EGOERA  egoera = JOLASTEN;
    JOKO_ELEMENTUA pertsonaia_Jok1, pertsonaia_Jok2, eszenatokia, bizitzaBarra_Jok1, bizitzaBarra_Jok2, profila_Jok1, profila_Jok2;

    //egoera = JOLASTEN;

    //************* Eszena tokiaren hasierako posizioa **********************

    eszenatokia.pos.x = 0;
    eszenatokia.pos.y = 0;

    //************* Pertsonaien hasierako posizioa ****************

    pertsonaia_Jok1.pos.x = 100;
    pertsonaia_Jok1.pos.y = 217;
    pertsonaia_Jok2.pos.x = 800;
    pertsonaia_Jok2.pos.y = 217;

    //************* Bizitza barrak hasierako posizioa ****************
    bizitzaBarra_Jok1.pos.x = 157;
    bizitzaBarra_Jok1.pos.y = 32;
    bizitzaBarra_Jok2.pos.x = 753;
    bizitzaBarra_Jok2.pos.y = 32;
    //********* Jokalari bakoitzaren profila jarri ********
    profila_Jok1.pos.x = 25;
    profila_Jok1.pos.y = 15;
    profila_Jok2.pos.x = 1125;
    profila_Jok2.pos.y = 15;
    //************ Soinua *******************

    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();

    //************ Eszenaren irudiak kargatu eta identifikatzaile bat eman ********************
    eszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);

    //************ Pertsonaien irudiak kargatu eta identifikatzaile bat eman ********************
    pertsonaia_Jok1.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
    pertsonaia_Jok2.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_IBAY_CAMINAR_1);
    //************ Elementuen irudiak kargatu eta identifikatzaile bat eman ********************
    bizitzaBarra_Jok2.id =IRUDIAK_irudiaGehitu(IRUDIA_ELEMENTUA_BITZITZA1);
    bizitzaBarra_Jok1.id = IRUDIAK_irudiaGehitu(IRUDIA_ELEMENTUA_BITZITZA1);
    //********** Profilak **********
    profila_Jok1.id = IRUDIAK_irudiaGehitu(IRUDIA_PROFILA_NAIRU_1L);
    profila_Jok2.id = IRUDIAK_irudiaGehitu(IRUDIA_PROFILA_IBAY_1R);
    //*********** Pertsoniak hasierako mugimendua *******************
    irudiaMugitu(pertsonaia_Jok1.id, pertsonaia_Jok1.pos.x, pertsonaia_Jok1.pos.y);
    irudiaMugitu(pertsonaia_Jok2.id, pertsonaia_Jok2.pos.x, pertsonaia_Jok2.pos.y);
    //*********** Elementuaren hasierako mugimendua *******************
    irudiaMugitu(bizitzaBarra_Jok2.id, bizitzaBarra_Jok2.pos.x, bizitzaBarra_Jok2.pos.y);
    irudiaMugitu(bizitzaBarra_Jok1.id, bizitzaBarra_Jok1.pos.x, bizitzaBarra_Jok1.pos.y);
    //********** Profilaren hasierkao mugimendua ****************
    irudiaMugitu(profila_Jok1.id, profila_Jok1.pos.x, profila_Jok1.pos.y);
    irudiaMugitu(profila_Jok2.id, profila_Jok2.pos.x, profila_Jok2.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();
    IRUDIA_argazkiaGehitu(IRUDIA_TENPORIZADOREA, 0, 0);
    //******************* Jokoaren interakzioa hasten da ********************
    do {
        Sleep(sleepDenbora);
        pantailaGarbitu();

        //********** while buklea teklako ebektoak gestionatzen du *************
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT: egoera = GALDU; break;
            }
            pertsonaia_Jok1 = JOKOA_lehenegoJokalaria(pertsonaia_Jok1, event);
            pertsonaia_Jok2 = JOKOA_bigarrenJokalaria(pertsonaia_Jok2, event);
       }

        //Bizitza barra jokalaria 2 - jokalaria 1 atakatzen denean
        if (pertsonaia_Jok1.pos.x > pertsonaia_Jok2.pos.x - 140 && pertsonaia_Jok1.pos.x < pertsonaia_Jok2.pos.x + 140 && event.key.keysym.sym == TECLA_SPACE)
        {
            kontPuntuazioa_Jok1 += 512;
            switch (kontBizitzaBarra_Jok2)
            {
                case 6: bizitzaBarra_Jok2 = JOKOA_bizitzaBarra(bizitzaBarra_Jok2, IRUDIA_ELEMENTUA_BIZITZA2R); break;
                case 5: bizitzaBarra_Jok2 = JOKOA_bizitzaBarra(bizitzaBarra_Jok2, IRUDIA_ELEMENTUA_BIZITZA3R); break;
                case 4:bizitzaBarra_Jok2 = JOKOA_bizitzaBarra(bizitzaBarra_Jok2, IRUDIA_ELEMENTUA_BIZITZA4R); break;
                case 3:bizitzaBarra_Jok2 = JOKOA_bizitzaBarra(bizitzaBarra_Jok2, IRUDIA_ELEMENTUA_BIZITZA5R); break;
                case 2:bizitzaBarra_Jok2 = JOKOA_bizitzaBarra(bizitzaBarra_Jok2, IRUDIA_ELEMENTUA_BIZITZA6R); break;
                case 1:bizitzaBarra_Jok2 = JOKOA_bizitzaBarra(bizitzaBarra_Jok2, IRUDIA_ELEMENTUA_BIZITZA7); break;
            }
            event.key.keysym.sym = TECLA_0;
            kontBizitzaBarra_Jok2--;
        }
        //Bizitza barra jokalaria 1 - 2 jokalaria atakatzen denean
        if (pertsonaia_Jok2.pos.x > pertsonaia_Jok1.pos.x - 140 && pertsonaia_Jok2.pos.x < pertsonaia_Jok1.pos.x + 140 && event.key.keysym.sym == TECLA_5)
        {
            kontPuntuazioa_Jok2 += 512;
            switch (kontBizitzaBarra_Jok1)
            {
                case 6: bizitzaBarra_Jok1 = JOKOA_bizitzaBarra(bizitzaBarra_Jok1, IRUDIA_ELEMENTUA_BIZITZA2L); break;
                case 5: bizitzaBarra_Jok1 = JOKOA_bizitzaBarra(bizitzaBarra_Jok1, IRUDIA_ELEMENTUA_BIZITZA3L); break;
                case 4:bizitzaBarra_Jok1 = JOKOA_bizitzaBarra(bizitzaBarra_Jok1, IRUDIA_ELEMENTUA_BIZITZA4L); break;
                case 3:bizitzaBarra_Jok1 = JOKOA_bizitzaBarra(bizitzaBarra_Jok1, IRUDIA_ELEMENTUA_BIZITZA5L); break;
                case 2:bizitzaBarra_Jok1 = JOKOA_bizitzaBarra(bizitzaBarra_Jok1, IRUDIA_ELEMENTUA_BIZITZA6L); break;
                case 1:bizitzaBarra_Jok1 = JOKOA_bizitzaBarra(bizitzaBarra_Jok1, IRUDIA_ELEMENTUA_BIZITZA7); break;
            }
            event.key.keysym.sym = TECLA_0;
            kontBizitzaBarra_Jok1--;
        }
        irudiakMarraztu();
        pantailaBerriztu();
        //*********** Denbora kudeatu,0 galdu  ****** 
        tenporizadoreEgoera = JOKOA_denboraKudeatuEtaBistaratu(&tenporizadorea);
        //****** Puntuazioa gorde **************
        *(puntuazioa_Jok1) = kontPuntuazioa_Jok1;
        *(puntuazioa_Jok2) = kontPuntuazioa_Jok2;
        //*********** Jokalarien egoera **************
        egoera = JOKOA_egoera(pertsonaia_Jok1, pertsonaia_Jok2, kontBizitzaBarra_Jok1, kontBizitzaBarra_Jok2, tenporizadorea);

        if (event.key.keysym.sym == TECLA_ESCAPE)
        {
            audioInit();
            loadTheMusic(JOKOA_SOUND_PAUSA);
            playMusic();
            pausaAukera = MENU_pausaMenua(&pausaArgazkiaId);
            switch (pausaAukera)
            {
                case 0: egoera = 5; break;
                case 1:
                    egoera = JOLASTEN;
                    irudiaKendu(pausaArgazkiaId);
                    pantailaBerriztu();
                    break;
            }
            pausaArgazkiaId = -1;
            event.key.keysym.sym = TECLA_0;
        }
    } while ((egoera == JOLASTEN));

    //***************************** Bukle amaiera **************************

    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}



EGOERA JOKOA_egoera(JOKO_ELEMENTUA pertsonaia_Jok1, JOKO_ELEMENTUA pertsonaia_Jok2, int bizitzaBarra_Jok1, int bizitzaBarra_Jok2, int tenporizadorea)
{
    EGOERA ret = JOLASTEN;

    if (pertsonaia_Jok1.pos.x <= 40 || pertsonaia_Jok1.pos.x >= 1020) ret = GALDU;
    else if (pertsonaia_Jok2.pos.x <= 40 || pertsonaia_Jok2.pos.x >= 1020) ret = GALDU;
    if (bizitzaBarra_Jok1 == 0 || bizitzaBarra_Jok2 == 0) ret = GALDU;
    if (tenporizadorea == 0) ret = GALDU;

    return ret;
}


int  AMAIERA_jokoAmaierakoa(EGOERA egoera)
{
    int ebentu = 0, ret = 0, idAudioGame, id;
    loadTheMusic(BUKAERA_SOUND_BAT);

    if (egoera == IRABAZI) {
        idAudioGame = loadSound(JOKOA_SOUND_WIN);
        playSound(idAudioGame);
    }
    else {

        idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
        playSound(idAudioGame);
    }
    id = IRUDIA_argazkiaGehitu(BUKAERA_IMAGE,0,0);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_ESCAPE) ret = 1;
    } while (ebentu != TECLA_ESCAPE);

    audioTerminate();
    irudiaKendu(id);
    return ret;
}


//************** Funtzioak jokoarentzako ***************
JOKO_ELEMENTUA JOKOA_bizitzaBarra(JOKO_ELEMENTUA bizitzaBarra, char* irudia)
{

    irudiaKendu(bizitzaBarra.id);
    bizitzaBarra.id = IRUDIAK_irudiaGehitu(irudia);
    irudiaMugitu(bizitzaBarra.id, bizitzaBarra.pos.x, bizitzaBarra.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();

    return bizitzaBarra;
}

int IRUDIAK_irudiaGehitu(char* irudiaIzena)
{
    int irudiaId = -1;
    irudiaId = irudiaKargatu(irudiaIzena);
    return irudiaId;
}


int IRUDIA_argazkiaGehitu(char* irudiaIzena, int posX, int posY)
{
    int id = -1;
    id = irudiaKargatu(irudiaIzena);
    irudiaMugitu(id, posX, posY);
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
    return id;
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


int JOKOA_denboraKudeatuEtaBistaratu(int* tenporizadorea)
{
    int ret, denbora;
    char denboraTextua[10];

   denbora = *(tenporizadorea);

    sprintf(denboraTextua, "%d", (denbora / 215));
    textuaIdatzi(620, 73, denboraTextua);
    pantailaBerriztu();
    denbora--;
    *(tenporizadorea) = denbora;
    if ((denbora / 215) == 0) ret = 0;
    else ret = 1;

    return ret;
}

