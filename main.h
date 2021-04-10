#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int score;
	char* pseudo;
} ligne_score_t;

typedef struct {
	int colonne;
	int ligne;
} point_t;


typedef struct {
	char* terrain;
	char nb_colonnes;
	char nb_lignes;
	int nb_de_pas;
	point_t* perso;
} niveau_t;

#include "niveau.h"
#include "deplacement.h"
#include "score.h"