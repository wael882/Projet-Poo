#include "Jeu.h"

Jeu::Jeu(Grille grilleInitiale)
    : m_grille(std::move(grilleInitiale)) {}

Grille& Jeu::grille() {
    return m_grille;
}

const Grille& Jeu::grille() const {
    return m_grille;
}

void Jeu::tick() {
    m_grille.miseJour();
}

void Jeu::run(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        tick();
    }
}
