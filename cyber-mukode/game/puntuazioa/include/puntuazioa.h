#ifndef PUNTUAZIOA_H
#define PUNTUAZIOA_H
#include "include.h"

typedef struct PUNTUAZIOA
{
	int id;
	char izena[128];
	int puntuzioa;
}PUNTUAZIOA;

#define FITXEROAREN_IZENA ".\\game\\puntuazioa\\data\\puntuazioa.txt"
#define MAX_PUNTUAK 10
#define MAX_JOKALARIAK 2

int PUNTUAZIOA_fitxategiaIrakurri(char fileName[], PUNTUAZIOA puntuazioa[]);
void PUNTUAZIOA_puntuazioaPantailaratu(PUNTUAZIOA puntuazioa, int idX, int idY, int izenaX, int izenaY, int puntuazioaX, int puntuazioaY);
void PUNTUAZIOA_puntuazioakPantailaratu(PUNTUAZIOA puntuazioa[], int puntuazioaKop);
void PUNTUAZIOA_fitxategiaIdatzi(char fileName[], PUNTUAZIOA puntuazioa[]);


#endif // !PUNTUAZIOA_H
