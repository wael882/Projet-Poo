#ifndef JEU_H
#define JEU_H

#include "Grille.h"

// Encapsule la logique du jeu : detient une grille et avance d'iterations.
class Jeu {
public:
    explicit Jeu(Grille grilleInitiale);

    // Acces a la grille (lecture/ecriture ou lecture seule).
    Grille& grille();
    const Grille& grille() const;

    // Fait avancer le jeu d'une iteration.
    void tick();

    // Fait avancer le jeu de 'iterations' iterations.
    void run(int iterations);

private:
    Grille m_grille;
};

#endif
