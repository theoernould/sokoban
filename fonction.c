#include "main.h"


void place_sur_terrain (niveau_t* niveau, int colonne, int ligne, char car) {
    int index = ligne * niveau->nb_colonnes + colonne;
    niveau->terrain+index = car;
}

void initialise_le_terrain (niveau_t* niveau) {
    int nb_cases = niveau->nb_lignes * niveau->nb_colonnes;
    int no_ligne = -1;
    for(int i=0;i<nb_cases;i++) {
        if(i%niveau->nb_colonnes == 0) no_ligne++;
        place_sur_terrain(niveau, i%niveau->nb_colonnes, nb_ligne; '#');
    }
}

int getNbCases(niveau_t* niveau) {
    return niveau->nb_lignes * niveau->nb_colonnes;
}

affichage_niveau (niveau_t* niveau) {
    char* affichage;
    int no_ligne = -1;
    for(int i=0;i<getNbCases(niveau);i++) {
        if(i%niveau->nb_colonnes == 0) {
            no_ligne++;
            sprintf(affichage, "%c\n", lecture_du_terrain(niveau, i%niveau->nb_colonnes, no_ligne));
        } else {
            sprintf(affichage, "%c", lecture_du_terrain(niveau, i%niveau->nb_colonnes, no_ligne));
        }
    }
}

niveau_t* nouveau_niveau(int nb_colonnes, int nb_lignes){
	niveau_t* niveau;
	niveau = malloc(sizeof(niveau_t));
	niveau->nb_colonnes = nb_colonnes;
	niveau->nb_lignes = nb_lignes;
	niveau->terrain = malloc(sizeof(char)*nb_lignes*nb_colonnes)
	return terrain
}

char lecture_du_terrain (niveau_t* niveau, int colonne, int ligne){

}