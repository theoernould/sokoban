#include "main.h"

int main(void) {

    printf("Veuillez choisir un niveau à charger :");

    char lvlChar = ' ';

	scanf("%c", &lvlChar);

    int lvlInt = lvlChar - '0';

    printf("Vous avez choisi le niveau %i\nChargement du niveau en cours ...\n", lvlInt);
    
    niveau_t* niveau = lecture_du_niveau(lvlInt);
 
    //printf("Score max = %i",lecture_du_score(lvlInt));

    while(!niveau_termine(niveau)) {
        //system("clear");
        printf("Score : %i\nCoords : %i %i\nMeilleur score : %i",niveau->nb_de_pas,niveau->perso->colonne,niveau->perso->ligne, niveau->nb_de_pas);

        affichage_niveau(niveau);

        printf("Où avancer ?(z,q,s,d)\n");
        char direction = entree_du_joueur();

        deplacement(niveau, direction);
    }

    if(niveau->nb_de_pas > lecture_du_score(lvlInt)) ecriture_du_score(lvlInt, niveau->nb_de_pas);

    printf("Comment vous appelez-vous ?\n");

    char* pseudo = nom_du_joueur();

    ajouter_score(lvlInt, niveau->nb_de_pas, pseudo);

    return 0;
}