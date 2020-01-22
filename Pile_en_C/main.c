#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//PS: ce .c n'est pas propre.
//PS2: l'autre .c est propre.

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};
typedef struct Pile Pile;
struct Pile
{
    Element *premier;
    int nbElement;
};
typedef struct File File;
struct File
{
    Element *premier;
};

void color(int t, int f); //METHOD TO COLORIZE CONSOLE TEXT
void separateur(char couleur[]); //METHOD TO DISPLAY A SEPARATOR
void s();
void display_algorithme();

int main()
{
    printf("Gestion des piles en C\n");
    printf("Pile d'entier\n");
    printf("Creation d'un systeme de pile : ALGORITHMIE\n");
    separateur("blanc"); //white red purple yellow blue
    printf("= = = = = = = = = = = = MENU = = = = = = = = = = = =");s(2);
    printf("Appuyez sur 1 pour executer les piles en C");s(1);
    printf("Appuyez sur 2 pour afficher le programme des piles en algorithmie");s(2);
    int user_input;
    printf(">>> "); scanf("%d", &user_input);
    fflush(stdin);
    separateur("blanc");
    switch(user_input)
    {
    case 1:
        pile_c();
        break;
    case 2:
        pile_algorithme();
        break;
    default:
        printf("Erreur, au revoir.");
        break;
    }
    return 0;
}

Pile *initialisation()
{
    Pile *Pile = malloc(sizeof(*Pile)); //Allocation of Pile size in the RAM
    Element *Element = malloc(sizeof(*Element)); //Allocation of Element size in the RAM

    if (Pile == NULL || Element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element->nombre = 0; //Set the Element property <number> to 0
    Element->suivant = NULL; //Set the Element property <number> to NULL -> The next element in the pile is NULL
    Pile->nbElement = 1; //Set the number of elements in the targeted pile
    Pile->premier = Element; //Set the first element of the pile <element>

    return Pile;
}
void empiler(Pile *Pile, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (Pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;

    /* empiler de l'élément au début de la Pile */
    nouveau->suivant = Pile->premier;
    Pile->premier = nouveau;
    Pile->nbElement += 1;
}
void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL)
        {
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;
    }
    else /* La file est vide, notre élément est le premier */
    {
        file->premier = nouveau;
    }
}
void depiler(Pile *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (pile->premier != NULL)
    {
        Element *aSupprimer = pile->premier;
        pile->premier = pile->premier->suivant;
        pile->nbElement -= 1;
        free(aSupprimer);
    }
}
int defiler(File *file)
{
    if (file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL)
    {
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}
void afficherPile(Pile *Pile)
{
    if (Pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = Pile->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
    printf("Nombre d'elements dans la Pile : %d\n\n",Pile->nbElement);
}

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

void pile_c()
{
    Pile *maPile = initialisation();
    int continuer = 1;
    int rep;
    int choix;
    while(continuer != 0)
    {
        afficherPile(maPile);
        printf("Voulez vous ajouter ou supprimer des elements dans la Pile ?\n");
        printf("Quitter(0) Ajouter(1) Supprimer(2)\n");
        scanf("%d",&choix);
        fflush(stdin);
        while((choix < 0)||(choix > 2))
        {
            system("cls");
            printf("Entrez un chiffre valide \n");
            printf("Quitter(0) Ajouter(1) Supprimer(2)\n");
            scanf("%d",&choix);
            fflush(stdin);
        }
        if(choix == 1)
        {
            system("cls");
            printf("Quel nombre voulez vous ajouter dans la Pile ?\n");
            scanf("%d",&rep);
            fflush(stdin);
            empiler(maPile,rep);
            system("cls");
            printf("empilage reussi\n\n");
        }
        else if(choix == 2)
        {
            if(maPile->nbElement < 1)
            {
                system("cls");
                printf("depilage impossible (La Pile est vide)\n\n");
            }else
            {
                depiler(maPile);
                system("cls");
                printf("depilage reussi\n\n");
            }
        }
        else if(choix == 0)
        {
            break;
        }
        printf("Voulez-vous continuer ?\n");
        printf("Non(0) Oui(1) ?\n");
        scanf("%d",&continuer);
        fflush(stdin);
        while((continuer < 0)||(continuer > 1))
        {
            system("cls");
            printf("Entrez un chiffre valide \n");
            printf("Non(0) Oui(1) ?\n");
            scanf("%d",&continuer);
            fflush(stdin);
        }
        system("cls");
    }
    system("cls");
    afficherPile(maPile);

}

void pile_algorithme()
{
    printf("ALGORITHME: piles");                        s(1);
    printf("//BUT: Apprendre a exploiter les piles");   s(1);
    printf("//ENTREE:");                                s(1);
    printf("//SORTIE:");                                s(2);

    separateur("jaune");

    printf("TYPE:");                                    s(1);
    printf("    TYPE Element ENREGISTREMENT");              s(1);
    printf("    DEBUT");                                    s(1);
    printf("        nombre : ENTIER");                      s(1);
    printf("        *suivant : Element");                   s(1);
    printf("    FIN ENREGISTREMENT");                       s(2);

    printf("    TYPE Pile ENREGISTREMENT");              s(1);
    printf("    DEBUT");                                    s(1);
    printf("        premier : Element");                      s(1);
    printf("    FIN ENREGISTREMENT");                       s(2);

    printf("VAR:");                                     s(1);
    printf("    *maPile -> Pile"); s(2);

    separateur("jaune");

    separateur("rouge");

    printf("PROCEDURES ET FONCTIONS:");                               s(1);
    printf("    Procedure empiler(*pile : Pile, nouveauNombre : ENTIER)"); s(1);
    printf("    //BUT: Empiler des nombres entier"); s(1);
    printf("    //ENTREE: Pile, Entier"); s(1);
    printf("    //SORTIE: Liste des nombres empiles"); s(2);
    printf("    VAR:"); s(1);
    printf("        *nouveau : Element"); s(2);
    printf("    DEBUT");    s(1);
    printf("        *nouveau -> mallocation(taillede(*nouveau))"); s(2);
    printf("        SI(pile = NULL OU nouveau = NULL)");     s(1);
    printf("        DEBUT SI");     s(1);
    printf("            quitter()");    s(1);
    printf("        FIN SI");       s(2);
    printf("        nouveau--->nombre -> nvNombre");    s(1);
    printf("        nouveau--->suivant -> pile--->premier"); s(1);
    printf("        pile--->premier -> nouveau"); s(1);
    printf("    FIN");      s(2);

    separateur("bleu");

    printf("    FONCTION depiler(*pile : Pile) : ENTIER"); s(1);
    printf("    //BUT: Retourner un entier qui se trouvait en tête de pile"); s(1);
    printf("    //ENTREE: pointeur pile"); s(1);
    printf("    //SORTIE: Entier en tête de la pile"); s(2);
    printf("    VAR:"); s(1);
    printf("        nombreDePile : Entier"); s(1);
    printf("        *elementDePile : Element"); s(2);
    printf("    DEBUT"); s(2);

    printf("        SI(pile = NULL)"); s(1);
    printf("        DEBUT SI"); s(1);
    printf("            quitter()"); s(1);
    printf("        FIN SI");   s(2);
    printf("        nombreDePile -> 0"); s(1);
    printf("        *elementDePile -> pile--->premier"); s(2);
    printf("        SI(pile <> NULL ET pile--->premier <> NULL");   s(1);
    printf("        DEBUT SI"); s(1);
    printf("            nombreDePile = elementDePile--->nombre");   s(1);
    printf("            pile--->premier -> elemenetDePile--->suivant"); s(1);
    printf("            LIBERER(elementDePile)"); s(1);
    printf("        FIN SI"); s(2);
    printf("        RETOURNER nombreDePile"); s(2);
    printf("    FIN"); s(2);

    separateur("bleu");

    printf("    PROCEDURE afficherPile(*pile : Pile)"); s(1);
    printf("    //BUT: Afficher la pile"); s(1);
    printf("    //ENTREE: La pile a afficher"); s(1);
    printf("    //SORTIE: Affichage de la pile"); s(2);
    printf("    VAR:"); s(2);
    printf("        *actuel : Element -> pile--->premier"); s(2);
    printf("    DEBUT"); s(2);
    printf("        SI(pile = NULL)");  s(1);
    printf("        DEBUT SI"); s(1);
    printf("            quitter()"); s(1);
    printf("        FIN SI"); s(2);
    printf("        *actual -> pile--->premier"); s(2);
    printf("        TANTQUE(actuel <> NULL"); s(1);
    printf("        DEBUT TANTQUE"); s(1);
    printf("            ECRIRE(actuel--->nombre)"); s(1);
    printf("        FIN TANTQUE"); s(2);
    printf("        ECRIRE('')"); s(2);

    printf("    FIN"); s(2);

    separateur("bleu");

    printf("    FONCTION initialisation() : Pile"); s(1);
    printf("    //BUT: Initialiser la pile"); s(1);
    printf("    //ENTREE:"); s(1);
    printf("    //SORTIE:"); s(2);
    printf("    VAR:"); s(2);
    printf("        *pile : Pile"); s(1);
    printf("        *element : Element"); s(2);
    printf("    DEBUT"); s(2);
    printf("        *pile -> mallocation(taillede(*Pile))"); s(1);
    printf("        *element -> mallocation(taillede(*Element))");
    printf("            SI(pile = NULL OU element = NULL)");  s(1);
    printf("            DEBUT SI"); s(1);
    printf("                quitter()"); s(1);
    printf("            FIN SI"); s(2);
    printf("        element--->nombre -> 0"); s(1);
    printf("        element--->suivant -> NULL"); s(1);
    printf("        pile--->premier -> element"); s(2);

    printf("        RETOURNER Pile"); s(2);

    printf("    FIN"); s(2);

    separateur("rouge");

    separateur("violet");

    printf("    DEBUT //int main();"); s(2);
    printf("        *maPile -> i"); s(2);
    printf("        empiler(maPile, 4)");s(1);
    printf("        empiler(maPile, 8)");s(1);
    printf("        empiler(maPile, 15)");s(1);
    printf("        empiler(maPile, 16)");s(1);
    printf("        empiler(maPile, 23)");s(1);
    printf("        empiler(maPile, 42)");s(2);
    printf("        ECRIRE('Etat de la pile :')"); s(2);
    printf("        afficherPile(maPile)"); s(2);
    printf("        ECRIRE('Je depile ' , depiler(maPile)) ");s(1);
    printf("        ECRIRE('Je depile ' , depiler(maPile)) ");s(2);
    printf("        ECRIRE('Etat de la pile :') "); s(2);
    printf("        afficherPile(maPile)"); s(2);
    printf("        RETOURNER maPile"); s(2);

    printf("    FIN //int main();"); s(2);

    separateur("violet");

}
