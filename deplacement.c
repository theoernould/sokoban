#include "main.h"

char entree_du_joueur (void){
	char lettre = 'k';
	while(lettre != 'z' || lettre != 'q' || lettre != 's' || lettre != 'd'){
		scanf("%c", &lettre);
	}
	return lettre;
}

void deplacement (niveau_t* niveau, char direction){
	
}