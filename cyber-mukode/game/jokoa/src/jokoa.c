#include "include.h"

EGOERA JOKOA_jokatu(int jokalaria)
{
<<<<<<< .mine
    int denbora = 2, pixelKopurua = 100, pixelUp, pixelDown, kont = 0, ebentuR = 0, ebentuL;
=======
    int denbora = 2, pixelKopurua =100, pixelUp, pixelDown, kont = 0, ebentuR = 0, ebentuL, P1life=360, P2life=360;
>>>>>>> .theirs
    MUGIMENDUA mugituR = STOP;
    MUGIMENDUA mugituL = STOP;
    EGOERA  egoera = JOLASTEN;
    JOKO_ELEMENTUA lehenengoPertsonaia, bigarrenPertsonaia, lehenengoEszenatokia;
    POSIZIOA aux;
    PUNTUAZIOA puntuazioa;
    puntuazioa.id = 0;

    //egoera = JOLASTEN;

    //************* Eszena tokiaren hasierako posizioa **********************

    lehenengoEszenatokia.pos.x = 0;
    lehenengoEszenatokia.pos.y = 0;

    //************* Pertsonaien hasierako posizioa ****************

    lehenengoPertsonaia.pos.x = 100;
    lehenengoPertsonaia.pos.y = 217;
    bigarrenPertsonaia.pos.x = 800;
    bigarrenPertsonaia.pos.y = 217;
    //************ Soinua *******************

    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();

    //************ Eszenaren irudiak kargatu eta identifikatzaile bat eman ********************
    lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);

    //************ Pertsonaien irudiak kargatu eta identifikatzaile bat eman ********************
    lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
    bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_IBAY_CAMINAR_1);
	bizitzaBarrak(P1life, P2life);

    //*********** Pertsoniak hasierako mugimendua *******************
    irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
    irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
    pantailaBerriztu();
    //******************* Jokoaren interakzioa hasten da ********************

    do {
        Sleep(denbora);
        pantailaGarbitu();

        ebentuL = ebentuaJasoGertatuBada();
        if (ebentuL == TECLA_d) mugituL = RIGHTL;
        else if (ebentuL == TECLA_a) mugituL = LEFTL;
        else if (ebentuL == TECLA_w) mugituL = UPL;

        ebentuR = ebentuaJasoGertatuBada();
        if (ebentuR == TECLA_RIGHT) mugituR = RIGHTR;
        else if (ebentuR == TECLA_LEFT) mugituR = LEFTR;
        else if (ebentuR == TECLA_UP) mugituR = UPR;

        //********* Lehenengo pertsonaia ******
        if (mugituL == UPL)
        {

            for (pixelUp = 0; pixelUp < pixelKopurua; pixelUp++)
            {
                lehenengoPertsonaia.pos.y--;
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();

                ebentuL = ebentuaJasoGertatuBada();
                if (ebentuL == TECLA_a)
                {
                    aux = MUGIMENDUA_leftDownMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
                else if (ebentuL == TECLA_d)
                {
                    aux = MUGIMENDUA_rightUpMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
            }
            for (pixelDown = 0; pixelDown < pixelKopurua; pixelDown++)
            {
                Sleep(1);
                lehenengoPertsonaia.pos.y++;
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
                ebentuL = ebentuaJasoGertatuBada();
                if (ebentuL == TECLA_a)
                {
                    aux = MUGIMENDUA_leftDownMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
                else if (ebentuL == TECLA_d)
                {
                    aux = MUGIMENDUA_rightUpMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
            }
        }
        if (mugituL == RIGHTL)
        {
            aux = MUGIMENDUA_rightUpMugitu(lehenengoPertsonaia.pos);
            lehenengoPertsonaia.pos.x = aux.x;
            kont++;
            if (kont == 0)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_2);
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_3);
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 2) kont = 0;
        }
        if (mugituL == LEFTL)
        {
            aux = MUGIMENDUA_leftDownMugitu(lehenengoPertsonaia.pos);
            lehenengoPertsonaia.pos.x = aux.x;
            kont++;
            if (kont == 0)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_2);
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_3);
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 2) kont = 0;

        }
        if (ebentuL == TECLA_SPACE)
        {
            lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
            lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_ATAQUE_3);
            irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
            irudiakMarraztu();
            pantailaBerriztu();
        }
        mugituL = STOP;

        //********* Bigarren pertsonaia ******
        if (mugituR == UPR)
        {

            for (pixelUp = 0; pixelUp < pixelKopurua; pixelUp++)
            {
                bigarrenPertsonaia.pos.y--;
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();

                ebentuR = ebentuaJasoGertatuBada();
                if (ebentuR == TECLA_LEFT)
                {
                    aux = MUGIMENDUA_leftDownMugitu(bigarrenPertsonaia.pos);
                    bigarrenPertsonaia.pos.x = aux.x;
                }
                else if (ebentuR == TECLA_RIGHT)
                {
                    aux = MUGIMENDUA_rightUpMugitu(bigarrenPertsonaia.pos);
                    bigarrenPertsonaia.pos.x = aux.x;
                }
            }
            for (pixelDown = 0; pixelDown < pixelKopurua; pixelDown++)
            {
                Sleep(1);
                bigarrenPertsonaia.pos.y++;
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
                ebentuR = ebentuaJasoGertatuBada();
                if (ebentuR == TECLA_LEFT)
                {
                    aux = MUGIMENDUA_leftDownMugitu(bigarrenPertsonaia.pos);
                    bigarrenPertsonaia.pos.x = aux.x;
                }
                else if (ebentuR == TECLA_RIGHT)
                {
                    aux = MUGIMENDUA_rightUpMugitu(bigarrenPertsonaia.pos);
                    bigarrenPertsonaia.pos.x = aux.x;
                }
            }
        }
        if (mugituR == RIGHTR)
        {
            aux = MUGIMENDUA_rightUpMugitu(bigarrenPertsonaia.pos);
            bigarrenPertsonaia.pos.x = aux.x;
            kont++;
            if (kont == 0)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_2);
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_3);
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 2) kont = 0;
        }
        if (mugituR == LEFTR)
        {
            aux = MUGIMENDUA_leftDownMugitu(bigarrenPertsonaia.pos);
            bigarrenPertsonaia.pos.x = aux.x;
            kont++;
            if (kont == 0)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_2);
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 1)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_3);
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            else if (kont == 2)
            {
                lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
                bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
                irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
            }
            if (kont == 2) kont = 0;

        }
        if (ebentuR == TECLA_p)
        {
            lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
            bigarrenPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_ATAQUE_3);
            irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);
            irudiakMarraztu();
            pantailaBerriztu();
        }
        mugituR = STOP;
        egoera = JOKOA_egoera(lehenengoPertsonaia, bigarrenPertsonaia);

    } while (egoera == JOLASTEN);

    //***************************** Bukle amaiera **************************

    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}



EGOERA JOKOA_egoera(JOKO_ELEMENTUA lehenengoPertsonaia, JOKO_ELEMENTUA bigarrenPertsonaia)
{
    EGOERA ret = JOLASTEN;

    if (lehenengoPertsonaia.pos.x <= 40 || lehenengoPertsonaia.pos.x >= 1020)
    {
        ret = GALDU;
    }
    else if (bigarrenPertsonaia.pos.x <= 40 || bigarrenPertsonaia.pos.x >= 1020)
    {
        ret = GALDU;
    }

    return ret;
}

void bizitzaBarrak(int P1life, int P2life) {
	karratuaMarraztu(155, 30, P1life, 55, 0, 255, 255, 150);
	karratuaMarraztu(750, 30, P2life, 55, 0, 255, 255, 150);
	pantailaBerriztu();
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
    id = BUKAERA_irudiaBistaratu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_ESCAPE) ret = 1;
    } while (ebentu != TECLA_ESCAPE);

    audioTerminate();
    irudiaKendu(id);
    return ret;
}

