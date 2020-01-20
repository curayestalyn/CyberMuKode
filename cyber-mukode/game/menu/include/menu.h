#ifndef MENU_H
#define MENU_H

#include "include.h"

int MENU_jokoaAurkeztu();
void MENU_menuArgazkiak(int aukera);
void MENU_menuPuntuazioa();

// pausa argazkiak kudeatu
int MENU_pausaArgazkiak(int aukera);
int MENU_pausaMenua(int* pausaId);

#endif // !MENU_H
