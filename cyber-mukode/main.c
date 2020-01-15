#include "include.h"


int main(int argc, char* str[]) {
    int jarraitu = 1, menuAukera = 0, miniAukera, idAudioGame, id, ebentu = 0, pertsonaia;
    EGOERA egoera;
    char jokalariIzena[128];

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
            IRUDIA_argazkiaGehitu(IRUDIA_MENU_IDATZIIZENA, 0, 0);
            eskatuIzena(jokalariIzena);
            miniAukera = MINIJOKOA_miniJokoa(&pertsonaia);
            switch (miniAukera)
            {
            case BORROKA:
                egoera = JOKOA_jokatu(pertsonaia);
                if (egoera != 5) jarraitu = AMAIERA_jokoAmaierakoa(egoera);
                break;
            case MINIGALDU:
                idAudioGame = loadSound(JOKOA_SOUND_LOOSE);
                playSound(idAudioGame);
                id = BUKAERA_irudiaBistaratu();
                jarraitu = AMAIERA_jokoAmaierakoa(GALDU);
                break;
            case MENU:
                break;
            }      
            break;
        case 2:
            MENU_menuPuntuazioa();
        default:
            jarraitu = 0;
            break;
        }
       

    } while (jarraitu);
    sgItxi();
    return 0;
}







