#ifndef MINIJOKOA_H
#define MINIJOKOA_H
#include "include.h"

typedef enum MINIEGOERA { BORROKA, KREDITUAK, LAGUNTZA, PERTSONAIAK, MENU, MINIGALDU} MINIEGOERA;
typedef enum MINIMUGIMENDUA{GELDIK, GORA, BEHERA, ESKUMA, EZKERRA} MINIMUGIMENDUA;
typedef enum PERTSONAIMOTA {NAIRU, IBAY, THALIEL, TRYDAN}PERTSONAIMOTA;
//*** Hasi jokoa ***
int MINIJOKOA_miniJokoa(int* jokalaria_Jok1, int* jokalaria_Jok2);

//**** Pertsonien argazkiak kargatu eta aukeratu
int MINIJOKOA_pertsonaienArgazkiak(int aukera);
int MINIJOKOA_pertsonaiAukeratu();

#endif // !MINIJOKOA_H
