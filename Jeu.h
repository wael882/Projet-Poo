#ifndef JEU_H
#define JEU_H

#include "Grille.h"

// Encapsule la logique du jeu : détient une grille et avance d'itérations.
<<<<<<< HEAD
class Jeu
{
private:
    Grille m_grille;

=======
class Jeu {
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
public:
    explicit Jeu(Grille grilleInitiale);

    // Accès à la grille (lecture/écriture ou lecture seule).
<<<<<<< HEAD
    Grille &grille();
    const Grille &grille() const;
=======
    Grille& grille();
    const Grille& grille() const;
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5

    // Fait avancer le jeu d'une itération.
    void tick();

    // Fait avancer le jeu de 'iterations' itérations.
    void run(int iterations);
<<<<<<< HEAD
=======

private:
    Grille m_grille;
>>>>>>> 2ce32c5ed44646d8d1726e81cf78a24d92faa5f5
};

#endif
