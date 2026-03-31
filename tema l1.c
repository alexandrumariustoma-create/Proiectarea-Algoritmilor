#include <stdio.h>
#include <string.h>

typedef struct{
    char nume[10];
    char prenume[20];
    char oras[20];
    char liceu[50];
    char hobby[3][15];
}elev;

void afisare(elev e) {
    printf("Nume: %s %s \n", e.nume, e.prenume);
    printf("Oras: %s \n", e.oras);
    printf("Liceu: %s \n", e.liceu);
    printf("Hobby-uri: \n");
    for (int i = 0; i < 3; i++) {
        printf("%s \n", e.hobby[i]);
    }
}
void ordonare(elev *e) {
    char copie[15];
    for (int i = 0; i < 2; i++)
        for (int j = i+1; j < 3; j++)
            if (strcmp(e->hobby[i], e->hobby[j]) > 0) {
                strcpy(copie, e->hobby[i]);
                strcpy(e->hobby[i], e->hobby[j]);
                strcpy(e->hobby[j], copie);
            }

}
int main() {
    elev e = {
        "Toma",
        "Alexandru-Marius",
        "Bucuresti",
        "Colegiul National Elena Cuza",
        {"Programare","Jocuri","Fotografie"}
    };
    afisare(e);
    ordonare(&e);
    printf("\n");
    afisare(e);
}