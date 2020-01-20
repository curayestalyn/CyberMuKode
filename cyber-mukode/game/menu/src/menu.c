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
    PUNTUAZIOA puntuazioa[MAX_PUNTUAK];
    int puntuazioKop;
    IRUDIA_argazkiaGehitu(IRUDIA_MENU_PUNTUAZIOABISTARATU, 0, 0);

    puntuazioKop = PUNTUAZIOA_fitxategiaIrakurri(FITXEROAREN_IZENA, puntuazioa);
    printf("%i", puntuazioKop);

    PUNTUAZIOA_puntuazioakPantailaratu(puntuazioa, puntuazioKop);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE);
}

int MENU_pausaMenua(int* pausaId)
{
    audioInit();
    loadTheMusic(JOKOA_SOUND);
    playMusic();


    int ebentu = 0, pausaPosizioa = 1;
    int id = 0;
    id = IRUDIA_argazkiaGehitu(IRUDIA_MENU_PAUSAJARRAITU, 0, 0);
    do
    {
        ebentu = ebentuaJasoGertatuBada();
        if (ebentu == TECLA_DOWN) {
            pausaPosizioa--;
            id = MENU_pausaArgazkiak(pausaPosizioa);
        }
        if (ebentu == TECLA_UP) {
            pausaPosizioa++;
            id = MENU_pausaArgazkiak(pausaPosizioa);
        }
        if (pausaPosizioa >= 1) pausaPosizioa = 1;
        if (pausaPosizioa <= 0) pausaPosizioa = 0;

    } while (ebentu != TECLA_RETURN);
    *(pausaId) = id;
    return pausaPosizioa;
}

int MENU_pausaArgazkiak(int aukera)
{
    int id = -1;
    if (aukera >= 1 && aukera < 2) id = IRUDIA_argazkiaGehitu(IRUDIA_MENU_PAUSAJARRAITU, 0, 0);
    if (aukera >= 0 && aukera < 1) id = IRUDIA_argazkiaGehitu(IRUDIA_MENU_PAUSAMENU, 0, 0);
    return id;
}
