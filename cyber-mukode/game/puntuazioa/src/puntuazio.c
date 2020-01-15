#include "include.h"





int PUNTUAZIOA_fitxategiaIrakurri(char fileName[], PUNTUAZIOA puntuazioa[])
{
	FILE* fitxategia;
	fitxategia = fopen(fileName, "rt");
	int karakterea = 0, posizioa = 0;
	if (fitxategia == NULL) printf("ERROR!!! Fitxategia ezin da zabaldu\n");
	else
	{
		do
		{
			karakterea = fscanf(fitxategia, "%i\t%s\t%i", &puntuazioa[posizioa].id, puntuazioa[posizioa].izena, &puntuazioa[posizioa].puntuzioa);
			if (karakterea > EOF) posizioa++;
		} while (karakterea > EOF&& posizioa < MAX_PUNTUAK);
	}
	//fclose(fitxategia);

	return posizioa;
}

void PUNTUAZIOA_fitxategiaIdatzi(char fileName[], PUNTUAZIOA puntuazioa[])
{

	FILE* fitxategia;
	fitxategia = fopen(fileName, "wt");
	int karakterea = 0, posizioa = 0;
	if (fitxategia == NULL) printf("ERROR!!! Fitxategia ezin da zabaldu\n");
	else
	{
		do
		{
			fprintf(fitxategia, "%i\t%s\t%i\n", puntuazioa[posizioa].id, puntuazioa[posizioa].izena, puntuazioa[posizioa].puntuzioa);
			posizioa++;
		} while (posizioa < MAX_PUNTUAK);
	}
	//fclose(fitxategia);
}

void PUNTUAZIOA_puntuazioaPantailaratu(PUNTUAZIOA puntuazioa, int idX, int idY, int izenaX, int izenaY, int puntuazioaX, int puntuazioaY)
{
	char id[100];
	char puntuazioak[100];
	sprintf(id, "%d", puntuazioa.id);
	textuaIdatzi(idX, idY, id);
	textuaIdatzi(izenaX, izenaY, puntuazioa.izena);
	sprintf(puntuazioak, "%d", puntuazioa.puntuzioa);
	textuaIdatzi(puntuazioaX, puntuazioaY, puntuazioak);


}

void PUNTUAZIOA_puntuazioakPantailaratu(PUNTUAZIOA puntuazioa[], int puntuazioaKop)
{
	int idX = 70, idY = 170, izenaX = 220, izenaY = 170, puntuazioaX = 440, puntuazioaY = 170;
	for (int i = 0; i < puntuazioaKop; i++)
	{
		PUNTUAZIOA_puntuazioaPantailaratu(puntuazioa[i], idX, idY, izenaX,izenaY,puntuazioaX, puntuazioaY);
		idY += 20;
		izenaY += 20;
		puntuazioaY += 20;
	}
}

