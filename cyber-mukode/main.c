#include "include.h"


int main(int argc, char* str[]) {
    int jarraitu = 1, menuAukera = 0, miniAukera, idAudioGame, id, ebentu = 0, pertsonaia_Jok1 = NAIRU, pertsonaia_Jok2 = IBAY, puntuazioa_Jok1, puntuazioa_Jok2;
    EGOERA egoera;
    PUNTUAZIOA jokalariak[2] = { 0 };
    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 1250x640 video: %s\n", SDL_GetError());
        return 1;
    }
    textuaGaitu();
    do
    {
        menuAukera = MENU_jokoaAurkeztu();
        switch (menuAukera)
        {
        case 3:
            for (int i = 0; i < 2; i++)
            {
                id = IRUDIA_argazkiaGehitu(IRUDIA_MENU_IDATZIIZENA, 0, 0);
                jokalariak[i].id = i;
                eskatuIzena(jokalariak[i].izena);
                irudiaKendu(id);
            }
            if ( strlen(jokalariak[0].izena) != 0 && strlen(jokalariak[1].izena) != 0)
            {
                miniAukera = MINIJOKOA_miniJokoa(&pertsonaia_Jok1, &pertsonaia_Jok2);
                switch (miniAukera)
                {
                case BORROKA:
                    egoera = JOKOA_jokatu(pertsonaia_Jok1, pertsonaia_Jok2, &puntuazioa_Jok1, &puntuazioa_Jok2);
                    jokalariak[0].puntuzioa = puntuazioa_Jok1;
                    jokalariak[1].puntuzioa = puntuazioa_Jok2;
                    PUNTUAZIOA_fitxategiaIdatzi(FITXEROAREN_IZENA, jokalariak);
                    if (egoera != 5) {
                        jarraitu = AMAIERA_jokoAmaierakoa(egoera);
                    }
                    break;
                case MINIGALDU:
                    idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
                    playSound(idAudioGame);
                    id = IRUDIA_argazkiaGehitu(BUKAERA_IMAGE, 0, 0);
                    jokalariak[0].puntuzioa = 0;
                    jokalariak[1].puntuzioa = 0;
                    PUNTUAZIOA_fitxategiaIdatzi(FITXEROAREN_IZENA, jokalariak);
                    jarraitu = AMAIERA_jokoAmaierakoa(GALDU);
                    break;
                case MENU:
                    break;
                }
            }               
            break;
        case 2:
            MENU_menuPuntuazioa();
            break;
        default:
            jarraitu = 0;
            break;
        }
       

    } while (jarraitu);
    sgItxi();
    return 0;
}







