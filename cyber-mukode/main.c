#include "include.h"


int main(int argc, char* str[]) {
    int jarraitu = 1, menuAukera = 0, miniAukera, idAudioGame, id, ebentu = 0, jokalaria;
    EGOERA egoera;

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 1250x640 video: %s\n", SDL_GetError());
        return 1;
    }
    textuaGaitu();
    do
    {

        menuAukera = MENU_jokoaAurkeztu();
        if (menuAukera == 3)
        {
            miniAukera = MINIJOKOA_miniJokoa(&jokalaria);

            switch (miniAukera)
            {
            case BORROKA:
                egoera = JOKOA_jokatu(jokalaria);
                if (egoera != 5) jarraitu = AMAIERA_jokoAmaierakoa(egoera);
                break;
            case MENU:
                break;
            case MINIGALDU:
                idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
                playSound(idAudioGame);
                id = BUKAERA_irudiaBistaratu();
                jarraitu = AMAIERA_jokoAmaierakoa(GALDU);
                break;
            }
        }
        else if (menuAukera == 2)  MENU_menuPuntuazioa();
        else if (menuAukera == 1) jarraitu = 0;
    } while (jarraitu);
    sgItxi();
    return 0;
}

