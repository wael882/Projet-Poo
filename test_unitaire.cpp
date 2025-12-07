#include <iostream>
#include <stdexcept>
#include "Grille.h"
#include "CellestVivante.h"
#include "CellestMorte.h"
#include "LecteurFichier.h"


// Petite fonction pratique qui compare deux grilles cellule par cellule.
// On verifie si :
//  - elles ont la même taille
//  - chaque position (i,j), les deux cellules sont soit toutes les deux vivantes, soit toutes les deux mortes.


bool comparerGrilles(const Grille& g1, const Grille& g2)
{
    // Vérifie les dimensions
    if (g1.getnblignes() != g2.getnblignes()) {
        return false;
    }

    if (g1.getnbcolonnes() != g2.getnbcolonnes()) {
        return false;
    }

    // Parcour toutes les cellules
    for (int i = 0; i < g1.getnblignes(); ++i) {
        for (int j = 0; j < g1.getnbcolonnes(); ++j) {

            bool v1 = g1.getCellule(i, j).estVivante();
            bool v2 = g2.getCellule(i, j).estVivante();

            if (v1 != v2) {
                // si cellule differente 
                return false;
            }
        }
    }

    // Tout est pareil
    return true;
}

// -----------------------------------------------------------------------------
// Test n°1 : oscillateur "blinker"
// On part d'une configuration verticale de 3 cellules vivantes.
// Après une itération (miseJour), le blinker doit devenir horizontal.
// Ce test vérifie que la logique de mise à jour de la grille est correcte.
// -----------------------------------------------------------------------------
bool testBlinker()
{
    // Grille 5x5, initialisée morte
    Grille g(5, 5);

    // On place un blinker vertical au centre :
    // (1,2), (2,2), (3,2) vivantes
    g.getCellule(1, 2).rendreVivante();
    g.getCellule(2, 2).rendreVivante();
    g.getCellule(3, 2).rendreVivante();

    // On applique une itération du jeu de la vie
    g.miseJour();

    // Grille attendue après une itération :
    // le blinker devient horizontal : (2,1), (2,2), (2,3) vivantes
    Grille attendu(5, 5);
    attendu.getCellule(2, 1).rendreVivante();
    attendu.getCellule(2, 2).rendreVivante();
    attendu.getCellule(2, 3).rendreVivante();

    // On compare la grille obtenue et la grille attendue
    return comparerGrilles(g, attendu);
}

// -----------------------------------------------------------------------------
// Test n°2 : comportement torique (grille "en donut")
// On met une cellule vivante en haut à gauche (0,0).
// On demande le nombre de voisins vivants pour la cellule en bas à droite (2,2)
// sur une grille 3x3 torique.
// Si la grille est bien torique, (0,0) est voisine de (2,2), donc le résultat
// attendu est 1 voisin vivant.
// -----------------------------------------------------------------------------
bool testToriqueCoin()
{
    // Petite grille 3x3
    Grille g(3, 3);

    // Une seule cellule vivante en haut à gauche
    g.getCellule(0, 0).rendreVivante();

    // On regarde les voisins de la cellule en bas à droite (2,2)
    int voisins = g.compter_VoisinsVivants(2, 2);

    // En mode torique, (0,0) est voisine de (2,2), donc on attend 1.
    return (voisins == 1);
}

// -----------------------------------------------------------------------------
// Fonction principale des tests unitaires
// Elle lance chaque test, affiche le résultat, et donne un petit bilan final.
// -----------------------------------------------------------------------------
void lancerTestsUnitaires()
{
    bool okBlinker = testBlinker();
    bool okTorique = testToriqueCoin();

    std::cout << "\nTest 1 : Oscillateur blinker (miseJour) : "
              << (okBlinker ? "OK" : "ECHEC") << "\n";

    std::cout << "Test 2 : Grille torique (compter_VoisinsVivants) : "
              << (okTorique ? "OK" : "ECHEC") << "\n\n";

    if (okBlinker && okTorique) {
        std::cout << "Résultat global : TOUS LES TESTS SONT PASSÉS\n";
    } else {
        std::cout << "Résultat global : AU MOINS UN TEST A ÉCHOUÉ\n";
        std::cout << "Pense à vérifier la logique correspondante.\n";
    }

    std::cout << "\n=== Fin des tests unitaires ===\n";
}

// ----------------------------------------------------------------------------- 
// Mode "test unitaire" depuis un fichier fourni par l'utilisateur.
// On charge simplement la grille pour vérifier que le fichier est valide,
// puis on enchaîne sur les tests unitaires génériques.
// ----------------------------------------------------------------------------- 
void lancerTestsUnitairesDepuisFichier(const std::string& fichier)
{
    try {
        Grille g = LecteurFichier::charger(fichier);
        std::cout << "Fichier charge avec succes : " << fichier << "\n";
        std::cout << "Dimensions detectees : " << g.getnblignes()
                  << " x " << g.getnbcolonnes() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du chargement du fichier '" << fichier
                  << "' : " << e.what() << "\n";
        return;
    }

    lancerTestsUnitaires();
}
