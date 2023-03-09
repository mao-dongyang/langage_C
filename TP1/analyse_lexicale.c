#include "analyse_lexicale.h"
#include "automate.h"
#include <stdio.h>

int main() {
    FILE *pFile;

    pFile = fopen("fichier.html", "rt"); // ouvre le fichier html
    if(pFile != NULL){
        getNextChar(pFile);
        fclose (pFile);
    } 
    else printf("Erreur d'ouverture du fichier\n");
    return 0;
}
