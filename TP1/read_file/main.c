#include <stdio.h>

int main() {
    FILE *pFile;
    char c;

    if(pFile = fopen("fichier.html", "rt")) {
        for(c = fgetc(pFile); !feof(pFile); c = fgetc(pFile)) {
            printf("%c", c);
        }
        fclose(pFile);
    } else {
        printf("error");
    }
    return 0;
}