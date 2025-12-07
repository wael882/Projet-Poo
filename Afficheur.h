#ifndef AFFICHEUR_H
#define AFFICHEUR_H

#include "Grille.h"

// Interface d'affichage : chaque implémentation choisit son rendu
// (console, graphique, etc.) à partir d'une grille.
class Afficheur {
public:
    virtual ~Afficheur() = default;
    virtual void afficher(const Grille& grille) = 0;
};

#endif
