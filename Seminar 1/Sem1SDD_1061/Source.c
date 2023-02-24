#include <stdio.h>
#include <malloc.h>

typedef struct
{
	int *cod;
	char* den;
	float pret;
	float cant;
} produs;

void citireVectorProduse(produs* vp, int n)
{
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		printf("Cod = ");
		vp[i].cod = (int*)malloc(1 * sizeof(int));
		scanf("%d", vp[i].cod);
		printf("Denumire = ");
		scanf("%s", buffer);
		vp[i].den = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(vp[i].den, buffer);
		printf("Pret = ");
		scanf("%f", &vp[i].pret);
		printf("Cantitate = ");
		scanf("%f", &vp[i].cant);
	}
}

void citire4Vectori(int *coduri, char **denumiri, float *preturi, float *cantitati, int n)
{
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		printf("Cod = ");
		scanf("%d", &coduri[i]);
		printf("Denumire = ");
		scanf("%s", buffer);
		denumiri[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(denumiri[i], buffer);
		printf("Pret = ");
		scanf("%f", &preturi[i]);
		printf("Cantitate = ");
		scanf("%f", &cantitati[i]);
	}
}

void afisareVectorProduse(produs* vp, int n)
{
	for (int i = 0; i < n; i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			*(vp[i].cod), vp[i].den, vp[i].pret, vp[i].cant);
}

void afisare4Vectori(int* coduri, char** denumiri, float* preturi, float* cantitati, int n)
{
	for (int i = 0; i < n; i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			coduri[i], denumiri[i], preturi[i], cantitati[i]);
}

void dezalocareVectorProduse(produs* vp, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(vp[i].cod);
		free(vp[i].den);
	}
	free(vp);
}

void dezalocare4Vectori(int* coduri, char** denumiri, float* preturi, float* cantitati, int n)
{
	free(coduri);
	for (int i = 0; i < n; i++)
		free(denumiri[i]);
	free(denumiri);
	free(preturi);
	free(cantitati);
}

void citireMatrice(float** mat, char** denumiri, int n)
{
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		printf("Denumire = ");
		scanf("%s", buffer);
		denumiri[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(denumiri[i], buffer);
		for (int j = 0; j < 3; j++)
		{
			printf("mat[%d][%d]=", i, j);
			scanf("%f", &mat[i][j]);
		}
	}
}

void afisareMatrice(float** mat, char** denumiri, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nDenumire=%s", denumiri[i]);
		printf("\nCod=%5.2f", mat[i][0]);
		printf("\nPret=%5.2f", mat[i][1]);
		printf("\nCantitate=%5.2f", mat[i][2]);
	}
}

void dezalocareMatrice(float** mat, char** denumiri, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(denumiri[i]);
		free(mat[i]);
	}
	free(denumiri);
	free(mat);
}

void main()
{
	int n;
	printf("Nr. produse=");
	scanf("%d", &n);
	/*produs* vp = (produs*)malloc(n * sizeof(produs));
	citireVectorProduse(vp, n);
	afisareVectorProduse(vp, n);
	dezalocareVectorProduse(vp, n);*/
	/*int* coduri = (int*)malloc(n * sizeof(int));
	char** denumiri = (char**)malloc(n * sizeof(char*));
	float* preturi = (float*)malloc(n * sizeof(float));
	float* cantitati = (float*)malloc(n * sizeof(float));
	citire4Vectori(coduri, denumiri, preturi, cantitati, n);
	afisare4Vectori(coduri, denumiri, preturi, cantitati, n);
	dezalocare4Vectori(coduri, denumiri, preturi, cantitati, n);*/

	char** denumiri = (char**)malloc(n * sizeof(char*));
	float** mat = (float**)malloc(n * sizeof(float*));
	for (int i = 0; i < n; i++)
		mat[i] = (float*)malloc(3 * sizeof(float));
	citireMatrice(mat, denumiri, n);
	afisareMatrice(mat, denumiri, n);
	dezalocareMatrice(mat, denumiri, n);
}