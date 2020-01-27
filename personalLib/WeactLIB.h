#ifndef WEACTLIB_H_INCLUDED
#define WEACTLIB_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color(int t, int f); //METHOD TO COLORIZE CONSOLE TEXT
void separateur(char couleur[]); //METHOD TO DISPLAY A SEPARATOR
void s();

void color(int t, int f)
{
/*
COLOR CODE
1st: fgcolor
2nd: bgcolor

0: noir                 1: bleu foncé
2: vert                 3: bleu-gris
4: marron               5: pourpre
6: kaki                 7: gris clair
8: gris                 9: bleu
10: vert fluo           11: turquoise
12: rouge               13: rose fluo
14: jaune fluo          15: blanc
*/

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,f*16+t);
}

void separateur(char couleur[])
{
    if(couleur == "blanc")
        color(15,15);
    if(couleur == "rouge")
        color(12,12);
    if(couleur == "vert")
        color(10,10);
    if(couleur == "violet")
        color(5,5);
    if(couleur == "jaune")
        color(14,14);
    if(couleur == "bleu")
        color(9,9);

    printf("\n                                                                 \n\n");
    color(15,0);
}

void s(n) //Line method
{
    for(int i = 0; i < n; i++)
        printf("\n");
}

#endif // WEACTLIB_H_INCLUDED
