#include "Grille.h"
#include "CellestMorte.h"      // ou "CelluleMorte.h" selon ton fichier
#include "CellestVivante.h"    // ou "CelluleVivante.h"
#include "CelluleObstacleVivante.h"
#include "CelluleObstacleMorte.h"
#include <utility>             // pour std::move


// Initialise la grille avec toutes les cellules mortes
Grille::Grille(int lignes, int colonnes)
    : nb_ligne(lignes), nb_colonne(colonnes)
{
    // On redimensionne le vecteur de lignes
    matr_grille.resize(nb_ligne);

    // Pour chaque ligne, on crée 'nb_colonne' cellules mortes
    for (int i = 0; i < nb_ligne; ++i) {
        matr_grille[i].reserve(nb_colonne);
        for (int j = 0; j < nb_colonne; ++j) {
            // Chaque cellule commence avec un état "morte"
            std::unique_ptr<EtatCellule> etatMorte = std::make_unique<CelluleMorte>();
            matr_grille[i].emplace_back(std::move(etatMorte));
        }
    }
}


int Grille::getnblignes() const {
    return nb_ligne;
}

int Grille::getnbcolonnes() const {
    return nb_colonne;
}

//Accès à une cellule///
Cellule& Grille::getCellule(int ligne, int colonne) {
    return matr_grille[ligne][colonne];
}

/// Accès à une cellule (lecture seule)///
const Cellule& Grille::getCellule(int ligne, int colonne) const {
    return matr_grille[ligne][colonne];
}

///Compter les voisins vivants d'une cellule///
int Grille::compter_VoisinsVivants(int ligne, int colonne) const {
    int compteur = 0;

    // On parcourt les 8 voisins potentiels autour de (ligne, colonne)
    for (int dl = -1; dl <= 1; ++dl) {
        for (int dc = -1; dc <= 1; ++dc) {
            // On ignore la cellule elle-même
            if (dl == 0 && dc == 0) {
                continue;
            }

            int nl = (ligne + dl + nb_ligne)%nb_ligne;   
            int nc = (colonne + dc + nb_colonne)%nb_colonne; 
            

            // Si le voisin est vivant, on incrémente
            if (matr_grille[nl][nc].estVivante()) {
                ++compteur;
            }
        }
    }

    return compteur;
}

//Mise à jour de la grille (une itération du jeu)
void Grille::miseJour() {
    // On crée une nouvelle grille pour stocker le prochain état
    std::vector<std::vector<Cellule>> nouvelleGrille;
    nouvelleGrille.resize(nb_ligne);

    for (int i = 0; i < nb_ligne; ++i) {
        nouvelleGrille[i].reserve(nb_colonne);

        for (int j = 0; j < nb_colonne; ++j) {
            EtatType typeActuel = matr_grille[i][j].typeEtat();

            // Obstacles : on ne les fait pas évoluer
            if (typeActuel == EtatType::ObstacleVivante) {
                nouvelleGrille[i].emplace_back(std::make_unique<CelluleObstacleVivante>());
                continue;
            }
            if (typeActuel == EtatType::ObstacleMorte) {
                nouvelleGrille[i].emplace_back(std::make_unique<CelluleObstacleMorte>());
                continue;
            }

            int voisinsVivants = compter_VoisinsVivants(i, j);

            // On récupère si la cellule actuelle est vivante ou morte
            bool estActuellementVivante = matr_grille[i][j].estVivante();

            // On décide du nouvel état selon les règles de Conway
            std::unique_ptr<EtatCellule> nouvelEtat;

            if (estActuellementVivante) {
                // Une cellule vivante survit si elle a 2 ou 3 voisines vivantes
                if (voisinsVivants == 2 || voisinsVivants == 3) {
                    nouvelEtat = std::make_unique<CelluleVivante>();
                } else {
                    nouvelEtat = std::make_unique<CelluleMorte>();
                }
            } else {
                // Une cellule morte devient vivante si elle a exactement 3 voisines vivantes
                if (voisinsVivants == 3) {
                    nouvelEtat = std::make_unique<CelluleVivante>();
                } else {
                    nouvelEtat = std::make_unique<CelluleMorte>();
                }
            }

            // On ajoute cette nouvelle cellule dans la nouvelle grille
            nouvelleGrille[i].emplace_back(std::move(nouvelEtat));
        }
    }

    // On remplace l'ancienne grille par la nouvelle
    matr_grille = std::move(nouvelleGrille);
}


 
