#include "main.h"

char entree_du_joueur (void){
	char lettre = 'k';
	while(lettre != 'z' && lettre != 'q' && lettre != 's' && lettre != 'd'){
		scanf("%c", &lettre);
	}

	return lettre;
}

//renvoie le char correspondant à la zone désignée
char lectureAtterissage(niveau_t* niveau, int y, int z){
	return lecture_du_terrain(niveau, (niveau->perso->colonne) + y, (niveau->perso->ligne) + z );
}

//vérifie si le déplacement est possible
int deplacementPossible(niveau_t* niveau, int y, int z){

	//return (lectureAtterissage(niveau, y, z) == ' ' || lectureAtterissage(niveau, y, z) == '.') || ( (lectureAtterissage(niveau, y, z) == '$') && (lectureAtterissage(niveau, y*2, z*2) == ' ' || lectureAtterissage(niveau, y*2, z*2) == '.')) || lectureAtterissage(niveau, y, z) == '*' && ()   );

	if(lectureAtterissage(niveau, y, z) == ' ' || lectureAtterissage(niveau, y, z) == '.'){ //vérifie si le lieu d'atterrissage après le déplacement est vide ou est une zone de rangement
        return 1;
    }else if(lectureAtterissage(niveau, y, z) == '$'){ //vérifie si le lieu d'atterrissage après le déplacement est une caisse
        if(lectureAtterissage(niveau, y*2, z*2) == ' ' || lectureAtterissage(niveau, y*2, z*2) == '.'){   //vérifie s'il y a de la place après une caisse
            return 1;
        }else{
            return 0;
        }
    }else if(lectureAtterissage(niveau, y, z) == '*'){
        if(lectureAtterissage(niveau, y*2, z*2) == ' ' || lectureAtterissage(niveau, y*2, z*2) == '.'){   //vérifie s'il y a de la place après une caisse
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}


void deplacement (niveau_t* niveau, char direction){
	int y = 0; // x
	int z = 0; // y
	int plus = 0;
	if(direction=='z'){
		z = z - 1;
	}else if(direction=='q'){
		y = y - 1;
	}else if(direction=='s'){
		z = z + 1;
	}else if(direction=='d'){
		y = y + 1;
	}
	if(deplacementPossible(niveau, y, z) == 1){
		//Cas où un caisse est en face
		if(lectureAtterissage(niveau, y, z) == '$'){ 

			//la caisse est poussé sur un point et se transforme en *
			if(lectureAtterissage(niveau, y*2, z*2) == '.'){
				place_sur_terrain (niveau, (niveau->perso->colonne) + y*2, (niveau->perso->ligne) + z*2, '*');
			}else{
				place_sur_terrain (niveau, (niveau->perso->colonne) + y*2, (niveau->perso->ligne) + z*2, '$'); //placement de la caisse à son nouvel emplacement
			}
		}else if(lectureAtterissage(niveau, y, z) == '*'){ //lorsqu'il y a une caisse rangée là où on va
			plus = 1;
			if(lectureAtterissage(niveau, y*2, z*2) == ' '){                                    
				place_sur_terrain (niveau, (niveau->perso->colonne) + y*2, (niveau->perso->ligne) + z*2, '$');
			}else if(lectureAtterissage(niveau, y*2, z*2) == '.'){
				place_sur_terrain (niveau, (niveau->perso->colonne) + y*2, (niveau->perso->ligne) + z*2, '*');
			}
			
		}

		if(lectureAtterissage(niveau, y, z) == '.' ){
			place_sur_terrain (niveau, (niveau->perso->colonne) + y, (niveau->perso->ligne) + z, '+');
		}else{
			place_sur_terrain (niveau, (niveau->perso->colonne) + y, (niveau->perso->ligne) + z, '@');
			if(plus){
				place_sur_terrain (niveau, (niveau->perso->colonne) + y, (niveau->perso->ligne) + z, '+');
			}
		}
		

		//ce qui est placé à l'ancien emplacement du joueur, si le joueur était un '+' ou un '@', l'emplacement devient respectivement un '.' ou un ' '
		if(lecture_du_terrain(niveau, (niveau->perso->colonne), (niveau->perso->ligne)) == '+'){ 
			place_sur_terrain (niveau, (niveau->perso->colonne), (niveau->perso->ligne), '.');
		}else{
			place_sur_terrain (niveau, (niveau->perso->colonne), (niveau->perso->ligne), ' ');
		}

		niveau->perso->colonne += y;
		niveau->perso->ligne += z;
		
		niveau->nb_de_pas++;

	}
}