#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "mainpile.h"


void mainpile(){
    printf("Hello world!");
}

objPile *initialisationObj()
{
    objPile *oPile = malloc(sizeof(*oPile)); //Allocation of Pile size in the RAM
    GameObject *gObjet = malloc(sizeof(*gObjet)); //Allocation of object size in the RAM

    if (oPile == NULL || gObjet == NULL)
    {
        exit(EXIT_FAILURE);
    }

    gObjet->key = 0; //Set the object property <key> to 0
    gObjet->precedent = NULL;
    gObjet->suivant = NULL;
    gObjet->mesh = "abc"; //Set the string property <char[]> to NULL -> The next object in the pile is NULL
    gObjet->pos.x = 0;
    gObjet->pos.y = 0;
    gObjet->pos.z = 0;
    oPile->nbElement = 1; //Set the number of objects in the targeted pile
    oPile->premier = gObjet; //Set the first element of the object pile
    oPile->dernier = gObjet; //Set the last element of the object pile

    return oPile;
}

void empilerObjEmpty(objPile *oPile, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[])
{
    //Create new object
    GameObject *nouveau = malloc(sizeof(*nouveau));
    if (oPile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->key = nvKey;
    nouveau->pos.x = nvX;
    nouveau->pos.y = nvY;
    nouveau->pos.z = nvZ;
    nouveau->mesh = nvMesh;

    //Stack new object
    nouveau->suivant = NULL;
    oPile->premier = nouveau;
    oPile->dernier = nouveau;
    oPile->nbElement += 1;
}
void empilerObjDebut(objPile *oPile, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[])
{
    //Create new object
    GameObject *nouveau = malloc(sizeof(*nouveau));
    if (oPile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->key = nvKey;
    nouveau->pos.x = nvX;
    nouveau->pos.y = nvY;
    nouveau->pos.z = nvZ;
    nouveau->mesh = nvMesh;

    //Stack new object
    nouveau->suivant = oPile->premier;
    oPile->premier = nouveau;
    oPile->nbElement += 1;
}
void empilerObjFin(objPile *oPile, GameObject *currentObject, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[])
{
    //Create new object
    GameObject *nouveau = malloc(sizeof(*nouveau));
    if (oPile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->key = nvKey;
    nouveau->pos.x = nvX;
    nouveau->pos.y = nvY;
    nouveau->pos.z = nvZ;
    nouveau->mesh = nvMesh;

    //Stack new object
    currentObject->suivant = nouveau;
    nouveau->suivant = NULL;
    oPile->dernier = nouveau;
    oPile->nbElement += 1;
}
void empilerObjPosition(objPile *oPile, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[], int pos)
{
    if(oPile->nbElement < 2)
    {
        exit(EXIT_FAILURE);
    }
    if(pos < 1 || pos >= oPile->nbElement)
    {
        exit(EXIT_FAILURE);
    }
    //Create new object
    GameObject *currentObject = malloc(sizeof(*currentObject));
    GameObject *nouveau = malloc(sizeof(*nouveau));
    int i;
    if (oPile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    currentObject = oPile->premier;
    for(i = 1; i < pos; ++i)
        currentObject = currentObject->suivant;
    if(currentObject->suivant == NULL)
        exit(EXIT_FAILURE);

    nouveau->key = nvKey;
    nouveau->pos.x = nvX;
    nouveau->pos.y = nvY;
    nouveau->pos.z = nvZ;
    nouveau->mesh = nvMesh;

    //Stack new object
    nouveau->suivant = currentObject;
    currentObject->suivant = nouveau;
    oPile->nbElement += 1;
}
void depilerObjDebut(objPile *oPile)
{
    if(oPile->nbElement == 0)
    {
        exit(EXIT_FAILURE);
    }
    if (oPile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    GameObject *gObject_to_delete;

    gObject_to_delete = oPile->premier;
    oPile->premier = oPile->premier->suivant;
    if(oPile->nbElement==1)
        oPile->dernier=NULL;
    free(gObject_to_delete->key);
    free(gObject_to_delete->mesh);
    free(gObject_to_delete->pos.x);
    free(gObject_to_delete->pos.y);
    free(gObject_to_delete->pos.z);
    free(gObject_to_delete->precedent);
    free(gObject_to_delete->suivant);
    free(gObject_to_delete);
    oPile->nbElement--;

}
void depilerObjPosition(objPile *oPile, int pos)
{
    if(oPile->nbElement <= 1 || pos < 1 || pos >= oPile->nbElement)
    {
        exit(EXIT_FAILURE);
    }
    int i;
    GameObject *current_gameObj;
    GameObject *gObject_to_delete;
    current_gameObj = oPile->premier;

    for(i = 1; i < pos; ++i)
        current_gameObj = current_gameObj->suivant;

    gObject_to_delete = current_gameObj->suivant;
    current_gameObj->suivant = current_gameObj->suivant->suivant;
    if(current_gameObj->suivant == NULL)
        oPile->dernier = current_gameObj;
    free(gObject_to_delete->key);
    free(gObject_to_delete->mesh);
    free(gObject_to_delete->pos.x);
    free(gObject_to_delete->pos.y);
    free(gObject_to_delete->pos.z);
    free(gObject_to_delete->precedent);
    free(gObject_to_delete->suivant);
    free(gObject_to_delete);
    oPile->nbElement--;
}
void afficherPileObj(objPile *oPile)
{
    if (oPile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    GameObject *current_gameObj;
    current_gameObj = oPile->premier;

    while (current_gameObj != NULL)
    {
        printf("Key: %d / Mesh: %s / Pos: [%dx;%dz;%dy].", current_gameObj->key, current_gameObj->mesh, current_gameObj->pos.x, current_gameObj->pos.z, current_gameObj->pos.y);
        current_gameObj = current_gameObj->suivant;
    }
    s(1);
    printf("Nombre d'elements dans la Pile : %d\n\n",oPile->nbElement);
}
