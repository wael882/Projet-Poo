#ifndef CELLULEOBSTACLEMORTE_H
#define CELLULEOBSTACLEMORTE_H

#include "EtatCellule.h"

class CelluleObstacleMorte : public EtatCellule {
public:
    bool estVivante() const override { return false; }
    bool estObstacle() const override { return true; }
    EtatType type() const override { return EtatType::ObstacleMorte; }
};

#endif
