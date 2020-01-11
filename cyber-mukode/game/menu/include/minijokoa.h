#ifndef MINIJOKOA_H
#define MINIJOKOA_H
#include "include.h"

typedef enum MINIEGOERA { BORROKA, KREDITUAK, LAGUNTZA, PERTSONAIAK, MENU, MINIGALDU} MINIEGOERA;
typedef enum PERTSONAIMOTA {NAIRU, IBAY, THALIEL, TRYDAN}PERTSONAIMOTA;
int MINIJOKOA_miniJokoa(int* jokalaria);
void MINIJOKOA_kredituakLaguntzaAukerak(char* irudiMapaOrg, char* irudiPertsonaia, char* irudiAukera, int* mapaId, int* perId, int* perX, int* perY);

int MINIJOKOA_pertsonaienArgazkiak(int aukera);
int MINIJOKOA_pertsonaienAukerak(char* irudiMapaOrg, char* irudiPertsonaia, char* irudiAukera, int* mapaId, int* perId, int* perX, int* perY);
#endif // !MINIJOKOA_H
