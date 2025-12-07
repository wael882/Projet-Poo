#include <iostream>
#include <stdexcept>
#include "Grille.h"
#include "CellestVivante.h"
#include "CellestMorte.h"
#include "LecteurFichier.h"

// Compare deux grilles cellule par cellule
bool comparerGrilles(const Grille& g1, const Grille& g2)
{
    if (g1.getnblignes() != g2.getnblignes()) {
        return false;
    }
    if (g1.getnbcolonnes() != g2.getnbcolonnes()) {
        return false;
    }

    for (int i = 0; i < g1.getnblignes(); ++i) {
        for (int j = 0; j < g1.getnbcolonnes(); ++j) {
            bool v1 = g1.getCellule(i, j).estVivante();
            bool v2 = g2.getCellule(i, j).estVivante();
            if (v1 != v2) {
                return false;
            }
        }
    }
    return true;
}

// Test 1 : oscillateur "blinker" (verifie la mise a jour de la grille)
bool testBlinker()
{
    Grille g(5, 5);

    // Blinker vertical au centre
    g.getCellule(1, 2).rendreVivante();
    g.getCellule(2, 2).rendreVivante();
    g.getCellule(3, 2).rendreVivante();

    // Une iteration du jeu de la vie
    g.miseJour();

    // Forme attendue : blinker horizontal
    Grille attendu(5, 5);
    attendu.getCellule(2, 1).rendreVivante();
    attendu.getCellule(2, 2).rendreVivante();
    attendu.getCellule(2, 3).rendreVivante();

    return comparerGrilles(g, attendu);
}

// Test 2 : comportement torique (la grille boucle correctement)
bool testToriqueCoin()
{
    Grille g(3, 3);

    // Une cellule vivante en haut a gauche
    g.getCellule(0, 0).rendreVivante();

    // En torique, (0,0) est voisine de (2,2), donc on attend 1 voisin
    int voisins = g.compter_VoisinsVivants(2, 2);
    return (voisins == 1);
}

// Fonction principale des tests unitaires
void lancerTestsUnitaires()
{
    bool okBlinker = testBlinker();
    bool okTorique = testToriqueCoin();

    std::cout << "\nTest 1 : Oscillateur blinker (miseJour) : "
              << (okBlinker ? "OK" : "ECHEC") << "\n";

    std::cout << "Test 2 : Grille torique (compter_VoisinsVivants) : "
              << (okTorique ? "OK" : "ECHEC") << "\n\n";

    if (okBlinker && okTorique) {
        std::cout << "Resultat global : TOUS LES TESTS SONT PASSES\n";
    } else {
        std::cout << "Resultat global : AU MOINS UN TEST A ECHOUE\n";
        std::cout << "Pense a verifier la logique correspondante.\n";
    }

    std::cout << "\n=== Fin des tests unitaires ===\n";
}

// Mode "test unitaire" depuis un fichier fourni par l'utilisateur
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
