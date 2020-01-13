#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//CONST VARIABLES
//#define NEWNAME "TextFiles/FileText.txt"
//#define OLDNAME "TextFiles/FileText1.txt"
#define TABSIZE 280
#define MAXSTRING 2500

//TYPES


//PROTOTYPES
int n_randomNumber(int n_min, int n_max);
void f_rename(char oldname[], char newname[]);
void f_askToRename();
void f_askToClearFile(FILE * myFile, char * fileName);
void f_readFile(FILE * myFile, char * fileName);
void color(int t, int f);

int main()
{
    srand(time(NULL));

    FILE * pfMyFolder;
    char c_fileName[] = "Students.txt";
    char name[50];
    int n, n_nbStudents;

    //CLEAR CONTENT
    f_askToClearFile(pfMyFolder, c_fileName);


    printf("How many student do you wish to enter ?\n");
    scanf("%d", &n_nbStudents);
    fflush(stdin);
    pfMyFolder = fopen(c_fileName,"a");
    if(pfMyFolder != NULL)
    {
        for(n = 0; n < n_nbStudents; n++)
        {
            printf("Please, enter a name: ");
            gets(name);
            fputs(name, pfMyFolder);
            fputs(" - LUDUS ACADEMIE'S STUDENT 2019-2020\n", pfMyFolder);
        }
        fclose(pfMyFolder);
    }

    f_readFile(pfMyFolder, c_fileName);
    f_askToRename();
    return 0;
}

//FONCTIONS

    //RANDOM NUMBER GENERATOR BASIC FUNCTION
int n_randomNumber(int n_min, int n_max)
{
    int n_random = (rand() % (n_max - n_min + 1)) + n_min;

    return n_random;
}

void f_rename(char oldname[], char newname[]) //FUNCTION TO RENAME A FOLDER
{
    int result;
    result = rename(oldname, newname);
    if(!result)
    {
        color(15,2);
        puts("File successfully renamed !\n");
        color(15,0);
    }else{
        color(15,12);
        perror("Error renaming file !\n");
        color(15,0);
    }
}

void f_askToRename() //FUNCTION TO ASK USER IF HE WANTS TO RENAME A FOLDER
{
    char oldname[TABSIZE], newname[TABSIZE];

    char answer;

    printf("Do you want to rename a folder ? (Y/N)\n");

    do{
        answer = getch();
    }while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n');

    if(answer == 'Y' || answer == 'y')
    {
        color(15,10);
        printf("Rename the folder. Please include the path. C:/AAAAA/BBBBB/CCCC.txt or CCCC.txt or BBBB/CCCC.txt\n");
        color(15,0);
        printf("Path of the current folder: ");
        scanf("%s", oldname);
        printf("Put a new name for the folder: ");
        scanf("%s", newname);
        f_rename(oldname, newname);
    }else{
        color(15,12);
        puts("EXIT");
        color(15,0);
    }
}

void f_askToClearFile(FILE * myFile, char * fileName) //FUNCTION TO ASK USER IF HE WANTS TO RENAME A FOLDER
{
    char answer;

    printf("Do you want to clear the content of the folder before edit ? (Y/N)\n");

    do{
        answer = getch();
    }while(answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n');

    if(answer == 'Y' || answer == 'y')
    {
        myFile = fopen(fileName, "w");
        fclose(myFile);
        color(15,10);
        printf("CONTENT CLEARED\n");
        color(15,0);
    }else{
        color(15,12);
        puts("CONTENT HAD NOT BEEN CLEARED");
        color(15,0);
    }
}

void f_readFile(FILE * myFile, char * fileName)
{
    printf("\n");
    char str[MAXSTRING];
    myFile = fopen(fileName, "r");

    if(myFile != NULL)
    {
        printf("[%s] content:\n", fileName);
        while(fgets(str, MAXSTRING, myFile) != NULL)
        {
            printf("%s", str);
        }
    }else{
        printf("Couldn't open file %s", fileName);
    }

    fclose(myFile);
    printf("\n");
}

void f_writeBinary(FILE * myFile)
{

    printf("Nom du chier a creer :\n");
}

void color(int t, int f)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole,f*16+t);

/*
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc
*/
}
