#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "mainpile.h"


void mainpile(){
    printf("Hello world!");
}

objPile *initialisation()
{
    objPile *oPile = malloc(sizeof(*oPile)); //Allocation of Pile size in the RAM
    GameObject *gObjet = malloc(sizeof(*gObjet)); //Allocation of Element size in the RAM

    if (oPile == NULL || gObjet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    gObjet->key = 0; //Set the Element property <number> to 0
    gObject->suivant = NULL;
    gObjet->mesh = "abc"; //Set the Element property <number> to NULL -> The next element in the pile is NULL
    gObjet->pos.x = 0;
    gObjet->pos.y = 0;
    gObjet->pos.z = 0;
    oPile->nbElement = 1; //Set the number of elements in the targeted pile
    oPile->premier = gObjet; //Set the first element of the pile <element>

    return oPile;
}

void empiler(objPile *oPile, int nvNombre)
{
    /* Création du nouvel élément */
    GameObject *nouveau = malloc(sizeof(*nouveau));
    if (oPile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->key = nvNombre;

    /* empiler de l'élément au début de la Pile */
    nouveau->suivant = oPile->premier;
    oPile->premier = nouveau;
    oPile->nbElement += 1;
}
void depiler(objPile *oPile)
{
    if (oPile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (oPile->premier != NULL)
    {
        Element *aSupprimer = oPile->premier;
        oPile->premier = oPile->premier->suivant;
        oPile->nbElement -= 1;
        free(aSupprimer);
    }
}
void afficherPile(objPile *oPile)
{
    if (oPile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = oPile->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
    printf("Nombre d'elements dans la Pile : %d\n\n",oPile->nbElement);
}
