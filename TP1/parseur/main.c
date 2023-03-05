#include <stdio.h>
#include "main.h"

enum Etats curEtat;
FILE *fp;

void AnalyseFicher(const char *nomFichier) {
    fp = fopen(*nomFichier, "rt");
    char c;
    while ((c=fgetc(fp)) != EOF)
    {
        enum EEtat ret = AnalyseProchaineBalise(c);
        if (ret == EEtatErreur) {
            printf("Error");
            break;
        }
        if (ret = EEtatTermine){
            
        }
    }
}

enum EEtat AnalyseProchaineBalise(char c) {
    switch (curEtat)
    {
    case SEtatDebut:
        if (c == '<') {
            curEtat = SEtat1;
        }
        break;
    case SEtat1:
        if (c == '/') {
            curEtat = SEtat2;
        } else {
            curEtat = SEtat3;
        }
        break;
    case SEtat2:
        if (c == '>') {
            curEtat = SEtatFin;
        }
        break;
    case SEtat3:
        if (c == '>') {
            curEtat = SEtatFin;
        }
        break;
    case SEtatFin:
        break;
    default:
        break;
    }
    
}

int main()
{
    curEtat = SEtatDebut;

    return 0;
}