#ifndef LECTEURFICHIER_H
#define LECTEURFICHIER_H

#include <string>

#include "Grille.h"

// Responsabilité : charger une grille à partir d'un fichier texte.
class LecteurFichier {
public:
    // Lit le fichier et retourne une Grille initialisée.
    // Quitte le programme en cas d'erreur d'ouverture/lecture.
    static Grille charger(const std::string& chemin);
};

#endif
