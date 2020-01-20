#include "include.h"

JOKO_ELEMENTUA JOKOA_bigarrenJokalaria(JOKO_ELEMENTUA jokalaria, SDL_Event event)
{

    POSIZIOA aux;
    int static kont = 0, saltoa = 0;
    if (event.key.keysym.sym == SDLK_UP && saltoa == 0) saltoa = 18;
    if (saltoa >= 10)
    {

        jokalaria.pos.y -= 10;
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        saltoa--;
    }
    if (10 > saltoa && saltoa > 0 || jokalaria.pos.y < 136)
    {
        jokalaria.pos.y += 10;
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        saltoa--;
    }
    switch (event.key.keysym.sym)
    {
        case SDLK_UP:
            //GORA
            jokalaria.pos.y -= 10;
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            //BEHERA
            jokalaria.pos.y += 10;
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            break;
        case SDLK_LEFT:
            aux = MUGIMENDUA_leftDownMugitu(jokalaria.pos);
            kont++;
            switch (kont)
            {
                case 0:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_IBAY_CAMINAR_2); break;
                case 1:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_IBAY_CAMINAR_3); break;
                case 2:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_IBAY_CAMINAR_1);
                    kont = 0;
                    break;
            }
            break;
        case SDLK_RIGHT:
            aux = MUGIMENDUA_rightUpMugitu(jokalaria.pos);
            kont++;
            switch (kont)
            {
            case 0:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_IBAY_CAMINAR_2); break;
            case 1:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_IBAY_CAMINAR_3); break;
            case 2:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_IBAY_CAMINAR_1);
                kont = 0;
                break;
            }
            break;
        case SDLK_5:
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_IBAY_ATAQUE_1);
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_IBAY_ATAQUE_2);

            break;
    }
    irudiakMarraztu();
    pantailaBerriztu();

    return jokalaria;
}


JOKO_ELEMENTUA JOKALARIAK_pertsonaiarenDesplazamendua(JOKO_ELEMENTUA jokalaria, int aux, char* irudia)
{
    jokalaria.pos.x = aux;
    irudiaKendu(jokalaria.id);
    jokalaria.id = IRUDIAK_irudiaGehitu(irudia);
    irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
    irudiakMarraztu();
    pantailaBerriztu();

    return jokalaria;
}