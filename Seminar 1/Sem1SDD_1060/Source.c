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
		printf("Cod=");
		vp[i].cod = (int*)malloc(1 * sizeof(int));
		scanf("%d", vp[i].cod);
		printf("Denumire=");
		scanf("%s", buffer);
		vp[i].den = (char*)malloc((strlen(buffer)+1) * sizeof(char));
		strcpy(vp[i].den, buffer);
		printf("Pret=");
		scanf("%f", &vp[i].pret);
		printf("Cantitate=");
		scanf("%f", &vp[i].cant);
	}
}

void citire4Vectori(int *coduri, char **denumiri, float *preturi, float *cantitati, int n)
{
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		printf("Cod=");
		scanf("%d", &coduri[i]);
		printf("Denumire=");
		scanf("%s", buffer);
		denumiri[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(denumiri[i], buffer);
		printf("Pret=");
		scanf("%f", &preturi[i]);
		printf("Cantitate=");
		scanf("%f", &cantitati[i]);
	}
}

void afisareVectorProduse(produs* vp, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Codul=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			*(vp[i].cod), vp[i].den, vp[i].pret, vp[i].cant);
		printf("\n");
	}
}

void afisare4Vectori(int* coduri, char** denumiri, float* preturi, float* cantitati, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Codul=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			coduri[i], denumiri[i], preturi[i], cantitati[i]);
		printf("\n");
	}
}

void citireMatrice(float** mat, char** denumiri, int n)
{
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		printf("Denumire=");
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
		printf("\nDenumire=%s ", denumiri[i]);
		printf("\nCoduri=%5.2f ", mat[i][0]);
		printf("\nPreturi=%5.2f ", mat[i][1]);
		printf("\nCantitati=%5.2f ", mat[i][2]);
		printf("\n");
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

void main()
{
	int nr;
	printf("Nr. produse=");
	scanf("%d", &nr);
	/*produs* vp = (produs*)malloc(nr * sizeof(produs));
	citireVectorProduse(vp, nr);
	afisareVectorProduse(vp, nr);
	dezalocareVectorProduse(vp, nr);*/
	/*int* coduri = (int*)malloc(nr * sizeof(int));
	char** denumiri = (char**)malloc(nr * sizeof(char*));
	float* preturi = (float*)malloc(nr * sizeof(float));
	float* cantitati = (float*)malloc(nr * sizeof(float));
	citire4Vectori(coduri, denumiri, preturi, cantitati, nr);
	afisare4Vectori(coduri, denumiri, preturi, cantitati, nr);
	dezalocare4Vectori(coduri, denumiri, preturi, cantitati, nr);*/
	char** denumiri = (char**)malloc(nr * sizeof(char*));
	float** mat = (float**)malloc(nr * sizeof(float*));
	for (int i = 0; i < nr; i++)
		mat[i] = (float*)malloc(3 * sizeof(float));
	citireMatrice(mat, denumiri, nr);
	afisareMatrice(mat, denumiri, nr);
	dezalocareMatrice(mat, denumiri, nr);
}