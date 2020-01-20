#include "include.h"
JOKO_ELEMENTUA JOKOA_lehenegoJokalaria(JOKO_ELEMENTUA jokalaria, SDL_Event event)
{
    int static kont = 0, saltoa = 0;
    POSIZIOA aux;
    if (event.key.keysym.sym == TECLA_w && saltoa == 0) saltoa = 18;
    if (saltoa >= 10)
    {

        jokalaria.pos.y -= 10;
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        saltoa--;
    }
    if (10 > saltoa&& saltoa > 0 || jokalaria.pos.y < 136)
    {
        jokalaria.pos.y += 10;
        irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
        saltoa--;
    }
    switch (event.key.keysym.sym)
    {
        case TECLA_w: //UP
            //GORA
            jokalaria.pos.y -= 10;
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            //BEHERA
            jokalaria.pos.y += 10;
            irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
            break;
        case TECLA_d: //RIGHT
            aux = MUGIMENDUA_rightUpMugitu(jokalaria.pos);
            kont++;

            switch (kont)
            {
                case 0:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_NAIRU_CAMINAR_2);break;
                case 1:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_NAIRU_CAMINAR_3);break;
                case 2:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1);
                    kont = 0;
                    break;
                }
            break;
        case TECLA_a: // Left
            aux = MUGIMENDUA_leftDownMugitu(jokalaria.pos);
            kont++;
            switch (kont)
            {
                case 0: jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_NAIRU_CAMINAR_2);break;
                case 1:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_NAIRU_CAMINAR_3); break;
                case 2:jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, aux.x, IRUDIA_PERTSONAIA_NAIRU_CAMINAR_1); 
                    kont = 0;
                    break;
            }
            break;
        case TECLA_SPACE: //ERASO
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_NAIRU_ATAQUE_1);
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_NAIRU_ATAQUE_2);
            Sleep(10);
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_NAIRU_ATAQUE_3);
            Sleep(100);
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_NAIRU_ATAQUE_2);
            Sleep(10);
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_NAIRU_ATAQUE_1);
            Sleep(10);
            jokalaria = JOKALARIAK_pertsonaiarenDesplazamendua(jokalaria, jokalaria.pos.x, IRUDIA_PERTSONAIA_NAIRU_ATAQUE_1);
            break;
    }
    irudiakMarraztu();
    pantailaBerriztu();

    return jokalaria;
}
