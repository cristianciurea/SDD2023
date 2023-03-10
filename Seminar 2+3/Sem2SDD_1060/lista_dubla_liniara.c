#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int cod;
	char* denumire;
	float pret;
	float cantitate;
} produs;

typedef struct
{
	produs inf;
	struct nodls* next, *prev;
} nodls;

nodls* inserareNod(nodls* cap, nodls** ultim, produs p)
{
	//pas 1 - alocare spatiu pt un nod nou
	nodls* nou = (nodls*)malloc(sizeof(nodls));
	//pas 2 - initializare nod (informatie utila + pointer legatura)
	//nou->inf = p; //shallow copy
	nou->inf.cod = p.cod;
	nou->inf.denumire = (char*)malloc((strlen(p.denumire) + 1) *
		sizeof(char));
	strcpy(nou->inf.denumire, p.denumire);
	nou->inf.pret = p.pret;
	nou->inf.cantitate = p.cantitate;
	nou->next = NULL;
	nou->prev = NULL;
	//pas 3 - inserare nod in lista (la sfarsit sau la inceput)
	if (cap == NULL)
	{
		cap = nou;
		*ultim = nou;
	}
	else
	{
		nodls* temp = cap;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nou;
		nou->prev = temp;
		*ultim = nou;
	}
	return cap;
}

void stergereNod(nodls** cap, nodls** ultim, nodls* sters)
{
	if (*cap == NULL || sters == NULL || *ultim == NULL)
	{
		return;
	}

	if (*cap == sters)
	{
		*cap = (*cap)->next;
		if (*cap != NULL)
			(*cap)->prev = NULL;

		free(sters->inf.denumire);
		free(sters);

		return;
	}

	if (*ultim == sters)
	{
		*ultim = (*ultim)->prev;
		(*ultim)->next = NULL;

		free(sters->inf.denumire);
		free(sters);

		return;
	}

	nodls* urmator = sters->next;
	nodls* anterior = sters->prev;

	anterior->next = urmator;
	urmator->prev = anterior;

	free(sters->inf.denumire);
	free(sters);

	return;
}

void stergereDenumire(nodls** cap, nodls** ultim, char* denumire)
{
	nodls* temp = *cap;
	while (temp != NULL)
	{
		if (strcmp(denumire, temp->inf.denumire) == 0)
		{
			nodls* sters = temp;
			temp = temp->next;

			stergereNod(cap, ultim, sters);
		}
		else {
			temp = temp->next;
		}
	}
}

void traversare(nodls* cap)
{
	nodls* temp = cap;
	while (temp != NULL)
	{
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			temp->inf.cod, temp->inf.denumire, temp->inf.pret, temp->inf.cantitate);
		temp = temp->next;
	}
}

void salvareProduseCantitate(nodls* cap, produs* vect, int* nr)
{
	nodls* temp = cap;
	while (temp != NULL)
	{
		if (temp->inf.cantitate <= 5)
		{
			vect[*nr].cod = temp->inf.cod;
			vect[*nr].denumire = (char*)malloc((strlen(temp->inf.denumire) + 1) * sizeof(char));
			strcpy(vect[*nr].denumire, temp->inf.denumire);
			vect[*nr].pret = temp->inf.pret;
			vect[*nr].cantitate = temp->inf.cantitate;
			(*nr)++;
		}
		temp = temp->next;
	}
}

void traversareInvers(nodls* ultim)
{
	nodls* temp = ultim;
	while (temp != NULL)
	{
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			temp->inf.cod, temp->inf.denumire, temp->inf.pret, temp->inf.cantitate);
		temp = temp->prev;
	}
}

void dezalocare(nodls* cap)
{
	nodls* temp = cap;
	while (temp != NULL)
	{
		nodls* temp2 = temp->next;
		free(temp->inf.denumire);
		free(temp);
		temp = temp2;
	}
}

void main()
{
	int n;
	//printf("Nr. produse=");
	FILE* f = fopen("fisier.txt", "r");
	fscanf(f, "%d", &n);
	nodls* cap = NULL, *ultim = NULL;
	produs p;
	char buffer[20];
	for (int i = 0; i < n; i++)
	{
		//printf("Cod=");
		fscanf(f, "%d", &p.cod);
		//printf("Denumire=");
		fscanf(f, "%s", buffer);
		p.denumire = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(p.denumire, buffer);
		//printf("Pret=");
		fscanf(f, "%f", &p.pret);
		//printf("Cantitate=");
		fscanf(f, "%f", &p.cantitate);
		cap = inserareNod(cap, &ultim, p);
		free(p.denumire);
	}
	fclose(f);
	traversare(cap);
	traversareInvers(ultim);

	//salvare in vector
	printf("\n--------------------------------\n");
	produs* vect = (produs*)malloc(n * sizeof(produs));
	int nr = 0;
	salvareProduseCantitate(cap, vect, &nr);
	for (int i = 0; i < nr; i++)
		printf("\nCod=%d, Denumire=%s, Pret=%5.2f, Cantitate=%5.2f",
			vect[i].cod, vect[i].denumire, vect[i].pret, vect[i].cantitate);

	for (int i = 0; i < nr; i++)
		free(vect[i].denumire);
	free(vect);

	printf("\n--------------------------------\n");
	stergereDenumire(&cap, &ultim, "paine");
	traversare(cap);
	traversareInvers(ultim);

	dezalocare(cap);
}