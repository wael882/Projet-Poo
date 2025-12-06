#ifndef CELLULEOBSTACLEVIVANTE_H
#define CELLULEOBSTACLEVIVANTE_H

#include "EtatCellule.h"

class CelluleObstacleVivante : public EtatCellule {
public:
    bool estVivante() const override { return true; }
    bool estObstacle() const override { return true; }
    EtatType type() const override { return EtatType::ObstacleVivante; }
};

#endif
