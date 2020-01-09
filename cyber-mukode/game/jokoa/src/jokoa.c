#include "include.h"

EGOERA jokatu(void)
{
    int denbora = 2, pixelKopurua = 200, pixelUp, pixelDown, kont = 0, ebentu = 0;
    MUGIMENDUA mugitu = STOP;
    EGOERA  egoera = JOLASTEN;
    JOKO_ELEMENTUA lehenengoPertsonaia, bigarrenPertsonaia, lehenengoEszenatokia;
    POSIZIOA aux;



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


    //*********** Pertsoniak hasierako mugimendua *******************
    irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
    irudiaMugitu(bigarrenPertsonaia.id, bigarrenPertsonaia.pos.x, bigarrenPertsonaia.pos.y);

    //******************* Jokoaren interakzioa hasten da ********************

    do {
        Sleep(denbora);
        pantailaGarbitu();

        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_RIGHT || ebentu == TECLA_d) mugitu = RIGHT;
        else if (ebentu == TECLA_LEFT || ebentu == TECLA_a) mugitu = LEFT;
        else if (ebentu == TECLA_UP || ebentu == TECLA_w) mugitu = UP;

        if (mugitu == UP)
        {

            for (pixelUp = 0; pixelUp < pixelKopurua; pixelUp++)
            {
                lehenengoPertsonaia.pos.y--;
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();

                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == TECLA_LEFT || ebentu == TECLA_a)
                {
                    aux = MUGIMENDUA_leftDownMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
                else if (ebentu == TECLA_RIGHT || ebentu == TECLA_d)
                {
                    aux = MUGIMENDUA_rightUpMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
            }
            for (pixelDown = 0; pixelDown < pixelKopurua; pixelDown++)
            {
                //Sleep(1);
                lehenengoPertsonaia.pos.y++;
                irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
                irudiakMarraztu();
                pantailaBerriztu();
                ebentu = ebentuaJasoGertatuBada();
                if (ebentu == TECLA_LEFT || ebentu == TECLA_a)
                {
                    aux = MUGIMENDUA_leftDownMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
                else if (ebentu == TECLA_RIGHT || ebentu == TECLA_d)
                {
                    aux = MUGIMENDUA_rightUpMugitu(lehenengoPertsonaia.pos);
                    lehenengoPertsonaia.pos.x = aux.x;
                }
            }
        }
        if (mugitu == RIGHT)
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
        if (mugitu == LEFT)
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
        if (ebentu == TECLA_SPACE)
        {
            lehenengoEszenatokia.id = IRUDIAK_irudiaGehitu(IRUDIA_ESZENA_BORROKA_1);
            lehenengoPertsonaia.id = IRUDIAK_irudiaGehitu(IRUDIA_PERTSONAIA_NAIRU_ATAQUE_3);
            irudiaMugitu(lehenengoPertsonaia.id, lehenengoPertsonaia.pos.x, lehenengoPertsonaia.pos.y);
            irudiakMarraztu();
            pantailaBerriztu();
        }
        mugitu = STOP;
        egoera = JOKOA_egoera(lehenengoPertsonaia, bigarrenPertsonaia);

    } while (egoera == JOLASTEN);

    //***************************** Bukle amaiera **************************

    toggleMusic();
    audioTerminate();
    pantailaGarbitu();
    pantailaBerriztu();
    return egoera;
}

EGOERA JOKOA_egoera(JOKO_ELEMENTUA nairu_caminar_1, JOKO_ELEMENTUA bigarrenPertsonaia)
{
    EGOERA ret = JOLASTEN;

    if ((nairu_caminar_1.pos.x <= 40 || nairu_caminar_1.pos.x >= 1020) || (bigarrenPertsonaia.pos.x <= 40 || bigarrenPertsonaia.pos.x >= 1020))
    {
        ret = GALDU;
    }

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

