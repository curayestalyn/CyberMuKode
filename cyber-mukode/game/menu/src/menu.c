#include "include.h"


int MENU_jokoaAurkeztu()
{
    int ebentu = 0, menuPosizioa = 3;
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();

    IRUDIA_argazkiaGehitu(IRUDIA_MENU_HASIJOKOA, 0, 0);

    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_DOWN)
        {
            menuPosizioa--;
            MENU_menuArgazkiak(menuPosizioa);
        }
        if (ebentu == TECLA_UP)
        {
            menuPosizioa++;
            MENU_menuArgazkiak(menuPosizioa);
        }
        if (menuPosizioa >= 3) menuPosizioa = 3;
        if (menuPosizioa <= 0) menuPosizioa = 1;

    } while (ebentu != TECLA_RETURN);

    return menuPosizioa;
}

void MENU_menuArgazkiak(int aukera)
{
    if (aukera >= 3) IRUDIA_argazkiaGehitu(IRUDIA_MENU_HASIJOKOA, 0, 0);
    if (aukera >= 2 && aukera < 3) IRUDIA_argazkiaGehitu(IRUDIA_MENU_PUNTUAZIOA, 0, 0);
    if (aukera >= 0 && aukera < 2) IRUDIA_argazkiaGehitu(IRUDIA_MENU_ITXIJOKOA, 0, 0);
}


void MENU_menuPuntuazioa()
{
    int ebentu = 0;
    char str[128];
    strcpy_s(str, 128, "kaixo");
    IRUDIA_argazkiaGehitu(IRUDIA_ESZENA_PUNTUAZIOA, 0, 0);
    //pantailaGarbitu();
    textuaIdatzi(100, 100, str);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE);
}