#include "automate.h"

enum Etats curEtat = EtatDeb; // initialisation de curEtat 
char string[20] = ""; // initialisation de string contenant la balise
int pos = 0; // initialisation de pos 
bool tagFermant = false; // initialisation de tagFermant
struct Pile *pile=NULL; // initialisation de la pile
int error = 0; // initialisation de error

void changeEtat(char c ){
    if(pile==NULL){
        pile = pileInit();
    } // Création de la pile si elle est NULL
    switch (curEtat) {
        case EtatDeb :
            if (c=='<'){
                curEtat = EtatBalise;
            } // si une balise ouvrante est détectée, on passe à l'état suivant
            break;
        case EtatBalise :
            if (c=='/'){
                tagFermant = true;
            } // si un / est détecté, on passe le tagFermant à true : signifie qu'on a trouvé le tag fermant du tag dans lequel on se trouve
            else {
                if (c == ' ' || c == '>') {
                    if (tagFermant) {
                        char *stringFerm = pilePop(pile); // si on ne détecte pas de / mais un espace ou une balise fermante, et si le tagFermant est à true, on définit un nouveau char stringFerm qui prend la dernière valeur mise dans la pile 
                        if (strcmp(stringFerm, string) != 0) {
                            printf("Erreur mauvaise parenthèse fermante à : %s\n", stringFerm);
                            error++;
                        } // si stringFerm et string ne sont pas les mêmes, on détecte une erreur car on ne retrouve pas la bonne parenthèse fermante
                        tagFermant = false;
                    } else {
                        pilePush(pile, string);
                    } // sinon, on stocke string dans la pile 
                    memset(string, 0, 20); //vider le tableau
                    pos = 0; // remettre à jour pos 
                    curEtat = EtatDeb; // se remettre à l'état initial
                } else {
                    string[pos] = c;
                    pos++;
                } // si on a autre chose qu'un espace ou une balise fermante, on ajoute le char dans string à la position pos et on incrémente pos 
            }
            break;
    }
}

void getNextChar(FILE *file){
    char c;
    for(c=fgetc(file);!feof(file);c=fgetc(file)){
        changeEtat(c);
    } // tant que le fichier n'est pas vide, on attribue à c un caractère du fichier
    // puis on applique la fonction changeEtat à c 
    printf("Nombre d'erreur dans le fichier : %d\n",error);
}






