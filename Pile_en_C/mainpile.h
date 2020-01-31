#ifndef MAINPILE_H_INCLUDED
#define MAINPILE_H_INCLUDED

typedef struct Vector3 Vector3;
struct Vector3
{
    int x;
    int y;
    int z;
};

typedef struct GameObject GameObject;
struct GameObject
{
    int key;
    char * mesh;
    Vector3 pos;
    GameObject *suivant;
    GameObject *precedent;
};

typedef struct objPile objPile;
struct objPile
{
    GameObject *premier;
    GameObject *dernier;
    int nbElement;
};

objPile *initialisationObj();
void empilerObjEmpty(objPile *oPile, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[]);
void empilerObjDebut(objPile *oPile, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[]);
void empilerObjFin(objPile *oPile, GameObject *currentObject, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[]);
void empilerObjPosition(objPile *oPile, int nvKey, int nvX, int nvY, int nvZ, char nvMesh[], int pos);
void depilerObjDebut(objPile *oPile);
void depilerObjPosition(objPile *oPile, int pos);
void afficherPileObj(objPile *oPile);

#endif // MAINPILE_H_INCLUDED
