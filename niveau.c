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
    printf("\n");
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
        niveau->nb_de_pas = 0;
        niveau->perso = malloc(sizeof(point_t));
        niveau->terrain = malloc(sizeof(char)*nb_lignes*nb_colonnes);
	return niveau;
}

niveau_t* lecture_du_niveau(int quel_niveau) {
    int nbColonnes = 0;
    int nbLignes = 0;
    char nomNiveau[50];         

    sprintf(nomNiveau, "./Niveaux/niveau_%i",quel_niveau);
    FILE* fichier = fopen(nomNiveau,"r");

    fscanf(fichier, "%d %d", &nbColonnes, &nbLignes);
    
    niveau_t* niveau = nouveau_niveau(nbColonnes, nbLignes);

    char car = getc(fichier);

    for(int lig=0;lig<niveau->nb_lignes;lig++) {
        int col = 0;
        
        do {
            car = getc(fichier);
            if(car == '@') definir_coords_perso(niveau, col, lig);
            place_sur_terrain(niveau, col, lig, car);
            col++;
        } while(car != '\n');

    }

    fclose(fichier);
    return niveau;
    
}

void definir_coords_perso(niveau_t* niveau, int colonne, int ligne) {
    niveau->perso->colonne = colonne;
    niveau->perso->ligne = ligne;
}

void liberation_du_niveau (niveau_t* niveau) {
    free(niveau->terrain);
    free(niveau);
}

int niveau_termine (niveau_t* niveau) {
    int cpt = 0;
    int nbCases = niveau->nb_colonnes * niveau->nb_lignes;
    int no_ligne = -1;
    int caissePresente = 0;

    while(cpt < nbCases && !caissePresente) {
        if(cpt%niveau->nb_colonnes == 0) no_ligne++;
        caissePresente = lecture_du_terrain(niveau, cpt%niveau->nb_colonnes, no_ligne) == '$';
        cpt++;
    }

    return !caissePresente;
}

niveau_t* copie_du_niveau (niveau_t* niveau){
    niveau_t* cpNiveau = nouveau_niveau(niveau->nb_colonnes, niveau->nb_lignes);
    cpNiveau->nb_de_pas = niveau->nb_de_pas;
    cpNiveau->perso->colonne = niveau->perso->colonne;
    cpNiveau->perso->ligne = niveau->perso->ligne;
    for(int col = 0 ; col < cpNiveau->nb_colonnes ; col ++){
        for(int lig = 0 ; lig < cpNiveau->nb_lignes ; lig++){
            place_sur_terrain(cpNiveau, cpNiveau->nb_colonnes, cpNiveau->nb_lignes, lecture_du_terrain(niveau, niveau->nb_colonnes, niveau->nb_lignes));
        }
    }
    return cpNiveau;
}


