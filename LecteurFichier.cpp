#include "LecteurFichier.h"

#include <fstream>
#include <iostream>
#include <cstdlib>

Grille LecteurFichier::charger(const std::string& chemin) {
    std::ifstream fichier(chemin);

    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << chemin << "\n";
        std::exit(1);
    }

    int lignes = 0;
    int colonnes = 0;
    fichier >> lignes >> colonnes;

    Grille g(lignes, colonnes);

    // Lecture de la matrice d'états (0,1,2,3)
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            int etat = 0;
            fichier >> etat;

            switch (etat) {
                case 1:
                    g.getCellule(i, j).rendreVivante();
                    break;
                case 2:
                    g.getCellule(i, j).rendreObstacleVivante();
                    break;
                case 3:
                    g.getCellule(i, j).rendreObstacleMorte();
                    break;
                default:
                    g.getCellule(i, j).rendreMorte();
                    break;
            }
        }
    }

    return g;
}
