#include "main.h"

void place_sur_terrain (niveau_t* niveau, int colonne, int ligne, char car) {
    int index = ligne * niveau->nb_colonnes + colonne;
    *(niveau->terrain+index) = car;
}

char lecture_du_terrain (niveau_t* niveau, int colonne, int ligne) {
    return *(niveau->terrain+(ligne*niveau->nb_colonnes + colonne));
}

void initialise_le_terrain (niveau_t* niveau) {
    int nb_cases = niveau->nb_lignes * niveau->nb_colonnes;
    int no_ligne = -1;
    for(int i=0;i<nb_cases;i++) {
        if(i%niveau->nb_colonnes == 0) no_ligne++;
        place_sur_terrain(niveau, i%niveau->nb_colonnes, no_ligne, '#');
    }
}

int getNbCases(niveau_t* niveau) {
    return niveau->nb_lignes * niveau->nb_colonnes;
}

void affichage_niveau (niveau_t* niveau) {
    int no_ligne = -1;
    for(int i=0;i<getNbCases(niveau);i++) {
        if(i%niveau->nb_colonnes == 0) {
            no_ligne++;
            printf("\n");
        }
        printf("%c", lecture_du_terrain(niveau, i%niveau->nb_colonnes, no_ligne));
    }
    printf("\n");
}

niveau_t* nouveau_niveau(int nb_colonnes, int nb_lignes) {
	niveau_t* niveau = malloc(sizeof(niveau_t));
        niveau->nb_colonnes = nb_colonnes;
        niveau->nb_lignes = nb_lignes;
        niveau->terrain = malloc(sizeof(char)*nb_lignes*nb_colonnes);
	return niveau;
}

void lecture_du_niveau(int quel_niveau) {
    char nomNiveau[20];
    sprintf(nomNiveau, "./Niveaux/niveau_%i",quel_niveau);
    FILE* niveau = fopen(nomNiveau,"r");
    char car = fgetc(niveau);
    while(car != EOF) {
        putchar(car);
        car = fgetc(niveau); 
    }
    fclose(niveau);
}