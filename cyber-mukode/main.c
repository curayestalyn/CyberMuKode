#include "include.h"


int main(int argc, char* str[]) {
    int jarraitu = 1, menuAukera = 0, miniAukera, idAudioGame, id;
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
            miniAukera = JOKO_miniJokoa();
            switch (miniAukera)
            {
            case BORROKA:
                egoera = jokatu();
                if (egoera != 5) jarraitu = AMAIERA_jokoAmaierakoa(egoera);
                break;
            case KREDITUAK:
                printf("kredituak\n");

                break;
            case LAGUNTZA:
                printf("Laguntza\n");
                break;
            case PERTSONAIAK:
                printf("PERTSONAIAK\n");


                break;
            case MENU:
                menuAukera = MENU_jokoaAurkeztu();
                printf("MENU\n");
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

