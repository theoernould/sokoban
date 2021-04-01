#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int colonne;
	int ligne;
} point_t;


typedef struct {
	char* terrain;
	char nb_colonnes;
	char nb_lignes;
	point_t* perso;
} niveau_t;

#include "niveau.h"

