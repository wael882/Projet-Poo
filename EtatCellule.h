#ifndef ETATCELLULE_H
#define ETATCELLULE_H
#include <iostream>

// Types d'etat pour identifier vivante/morte et les obstacles
enum class EtatType {
    Vivante,
    Morte,
    ObstacleVivante,
    ObstacleMorte
};

// Classe abstraite qui sert de base pour tous les etats possibles d'une cellule
class EtatCellule {
public:
    virtual bool estVivante() const = 0;
    virtual bool estObstacle() const { return false; }
    virtual EtatType type() const = 0;
    virtual ~EtatCellule() = default;
};

#endif
