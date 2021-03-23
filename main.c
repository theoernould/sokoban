#include "main.h"

int main(void) {
    niveau_t* niveau = nouveau_niveau(4,4);
    initialise_le_terrain(niveau);
    affichage_niveau(niveau);
    return 0;
}