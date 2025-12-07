#ifndef CELLESTVIVANTE_H
#define CELLESTVIVANTE_H
#include <iostream>
#include "EtatCellule.h"

class CelluleVivante : public EtatCellule {//classe qui reprǸsente l'Ǹtat d'une cellule vivante
public :
    bool estVivante() const override;
    EtatType type() const override { return EtatType::Vivante; }
};

#endif
