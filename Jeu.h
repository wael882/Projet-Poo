#ifndef JEU_H
#define JEU_H

#include "Grille.h"

// Encapsule la logique du jeu : détient une grille et avance d'itérations.
class Jeu {
public:
    explicit Jeu(Grille grilleInitiale);

    // Accès à la grille (lecture/écriture ou lecture seule).
    Grille& grille();
    const Grille& grille() const;

    // Fait avancer le jeu d'une itération.
    void tick();

    // Fait avancer le jeu de 'iterations' itérations.
    void run(int iterations);

private:
    Grille m_grille;
};

#endif
