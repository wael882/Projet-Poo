#ifndef CELLESTMORTE_H
#define CELLESTMORTE_H
#include <iostream>
#include "EtatCellule.h"


class CelluleMorte : public EtatCellule {//classe qui reprǸsente l'Ǹtat d'une cellule morte
public : 
    bool estVivante() const override;
    EtatType type() const override { return EtatType::Morte; }
};
    
#endif
