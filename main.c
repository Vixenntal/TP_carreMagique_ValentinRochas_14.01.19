#include <stdio.h>
#include <stdlib.h>

#define TAILLE 5 //Taille du tableau

typedef struct tPosition
{
	int nX;
	int nY;

} tPosition, *ptPosition;

enum Bool {false, true}; //Creation du booleen

//Prototypes des fonctions/procedures
int caseVide(int nTab[TAILLE][TAILLE], ptPosition jeton);
void avancerDroite(int nTab[TAILLE][TAILLE], ptPosition jeton);
void avancerGauche(int nTab[TAILLE][TAILLE], ptPosition jeton);
void corriger(int nTab[TAILLE][TAILLE], ptPosition jeton);
void placer(int nTab[TAILLE][TAILLE], ptPosition jeton, int nCpt);
void afficher(int nTab[TAILLE][TAILLE]);
void initTab(int nTab[TAILLE][TAILLE]);

int main()
{
    tPosition jeton;
    int nTab[TAILLE][TAILLE];
    jeton.nX = 2; //Initialisation des coordonnees
    jeton.nY = 1; //pour le premier chiffre
    ptPosition *position = &jeton;
    initTab(nTab);
    nTab[jeton.nX][jeton.nY] = 1; //Placement du "1" dans le tableau

    for (int nCpt = 2; nCpt < 26; ++nCpt) //Boucle de remplissage du tableau
     {
        avancerDroite(nTab, position);
        corriger(nTab, position);

        if (caseVide(nTab, position) == 1)
        {
        	placer(nTab, position, nCpt);
        }
        else
        {
        	corriger(nTab, position);
        	avancerGauche(nTab, position);
        	corriger(nTab, position);
        	placer(nTab, position, nCpt);
        }

             afficher(nTab);
             printf("\n");

     }

    return 0;
}

void initTab(int nTab[TAILLE][TAILLE]) //Initialisation du tableau
{
	for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            nTab[i][j] = 0;
        }
    }
}

int caseVide(int nTab[TAILLE][TAILLE], ptPosition jeton) //Verification par booleen, pour savoir si la case est vide ou non
{

	if (nTab[(*jeton).nX][(*jeton).nY] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void avancerDroite(int nTab[TAILLE][TAILLE], ptPosition jeton) //Permet de monter puis de tourner a droite, dans le tableau
{
	(*jeton).nX +=1;
	(*jeton).nY -=1;
}

void avancerGauche(int nTab[TAILLE][TAILLE], ptPosition jeton) //Permet de monter puis de tourner a gauche, dans le tableau
{
	(*jeton).nX -=1;
	(*jeton).nY -=1;
}

void corriger(int tab[TAILLE][TAILLE], ptPosition jeton) //Permet de "faire le tour du tableau" si jamais les coordonnees en sortent
{
    if(((*jeton).nX) == 5)
    {
        (*jeton).nX = 0;
    }
    if(((*jeton).nY) == -1)
    {
        (*jeton).nY = 4;
    }
    if(((*jeton).nX) == -1)
    {
        (*jeton).nX = 4;
    }
    if(((*jeton).nY) == 5)
    {
        (*jeton).nY = 0;
    }
}

void placer(int nTab[TAILLE][TAILLE], ptPosition jeton, int nCpt) //Place le chiffre dans la case du tableau
{
	nTab[(*jeton).nX][(*jeton).nY] = nCpt;
}

void afficher(int nTab[TAILLE][TAILLE]) //Affiche le tableau
{
	for (int nY = 0; nY < TAILLE; ++nY)
    {
        for (int nX = 0; nX < TAILLE; ++nX)
        {
            printf("%2d ", nTab[nX][nY]);
        }
        printf("\n");
    }
}
