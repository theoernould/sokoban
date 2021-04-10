#include "main.h"

int lecture_du_score (int quel_niveau) {
    int score = 0;
    //int maxScore = 0;
    char fichierScore[50];

    sprintf(fichierScore, "./Scores/score_%i",quel_niveau);

    FILE* fichier = fopen(fichierScore,"r");

    /*int nb_scores = 0;
    fscanf(fichier, "%d",&nb_scores);

    for(int i=0; i<nb_scores;i++) {
        fscanf(fichier, "%d", &score);
        if(score > maxScore) maxScore = score;
    }*/

    fscanf(fichier, "%d", &score);

    fclose(fichier);
    
    return score;
}

void ecriture_du_score (int quel_niveau, int score) {
    char fichierScore[50];

    sprintf(fichierScore, "./Scores/score_%i",quel_niveau);

    FILE* fichier = fopen(fichierScore,"w");

    fprintf(fichier,"%i",score);

    fclose(fichier);
}

int get_string_length(char* str) {
    int i = 0;
    while(*(str+i) != '\0') i++;
    return i;
}

int get_file_lines_count(char* chemin_fichier) {
    FILE* fichier = fopen(chemin_fichier,"r");
    
    int count = 0;

    char car = getc(fichier);

    while(car != EOF) {
        if(car == '\n') count++;
        car = getc(fichier);
    }

    fclose(fichier);

    return count;
}

char* nom_du_joueur (void) {
    char* pseudo = "";
    scanf("%s",pseudo);
    return pseudo;
}

void ajouter_score(int quel_niveau, int score, char* pseudo) {
    char fichierScore[50];

    sprintf(fichierScore, "./Scores/score_multi_%i",quel_niveau);

    FILE* fichier = fopen(fichierScore,"a");
    
    fprintf(fichier, "%i %s", score, pseudo);

    fclose(fichier);
}

ligne_score_t* nouveau_score(int score, char* pseudo) {
	ligne_score_t* new_score = malloc(sizeof(ligne_score_t));
        new_score->score = score;
        new_score->pseudo = pseudo;
    return new_score;
}

void trier_scores(int quel_niveau) {
    char fichierScore[50];

    sprintf(fichierScore, "./Scores/score_multi_%i",quel_niveau);
    
    FILE* fichier;
    
    fichier = fopen(fichierScore,"a");

    int lines_count = get_file_lines_count(fichierScore);

    ligne_score_t* scores[lines_count];
    
    for(int i=0;i<lines_count;i++) {
        int score;
        char* pseudo = "";
        fscanf(fichier, "%d %s", &score, pseudo);
        scores[i] = nouveau_score(score,pseudo);
    }

    int i,j;
    ligne_score_t* c;
    for(i=0;i<lines_count-1;i++) {
        for(j=i+1;j<lines_count;j++) {
            if ( scores[i]->score > scores[j]->score ) {
                c = scores[i];
                scores[i] = scores[j];
                scores[j] = c;
            }
        }
    }

    fclose(fichier);

    fichier = fopen(fichierScore,"w");

    for(int i=0;i<lines_count;i++) {
        fprintf(fichier, "%i %s", scores[i]->score, scores[i]->pseudo);
    }

    fclose(fichier);
}