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


/*void MENU_menuPuntuazioa()
{
    int ebentu = 0, x = 100;
    char str[128];
    strcpy_s(str, 128, "kaixo\n");
    IRUDIA_argazkiaGehitu(IRUDIA_MENU_PUNTUAZIOABISTARATU, 0, 0);
    //pantailaGarbitu();
    for (int i = 1; i < 10; i++)
    {
        textuaIdatzi(x, 100, str);
        x += 50;
        
    }
    
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE);
}*/
void MENU_menuPuntuazioa()
{
    int ebentu = 0;
    PUNTUAZIOA puntuazioa[MAX_PUNTUAK];
    int puntuazioKop;
    IRUDIA_argazkiaGehitu(IRUDIA_MENU_PUNTUAZIOABISTARATU, 0, 0);

    puntuazioKop = PUNTUAZIOA_fitxategiaIrakurri(FITXEROAREN_IZENA, puntuazioa);
    printf("%i", puntuazioKop);

    PUNTUAZIOA_puntuazioakPantailaratu(puntuazioa, puntuazioKop);
    //PUNTUAZIOA_fitxategiaIdatzi(FITXEROAREN_IZENA, puntuazioa);
    pantailaBerriztu();
    do
    {
        ebentu = ebentuaJasoGertatuBada();
    } while (ebentu != TECLA_ESCAPE);
}