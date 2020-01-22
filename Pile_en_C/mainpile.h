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
    /** \brief
     *
     * \param
     * \param
     * \return
     *
     */
    int key;
    char * mesh;
    Vector3 pos;
};

typedef struct objPile objPile;
struct objPile
{
    GameObject *premier;
    int nbElement;
};

objPile *initialisation();
void empilerObj(objPile *oPile, int nvNombre);
void depilerObj(objPile *oPile);
void afficherPileObj(objPile *oPile);

#endif // MAINPILE_H_INCLUDED
