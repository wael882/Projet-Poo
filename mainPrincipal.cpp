#include <iostream>
#include <string>

#include "modeConsole.h"
#include "modeGraphique.h"

int main() {
    int choix = 0;

    std::cout << "==============================\n";
    std::cout << "     JEU DE LA VIE - MENU     \n";
    std::cout << "==============================\n\n";
    std::cout << "Choisissez un mode :\n";
    std::cout << "  1 - Mode console\n";
    std::cout << "  2 - Mode graphique (SFML)\n";
    std::cout << "Votre choix : ";
    std::cin >> choix;

    if (!std::cin) {
        std::cerr << "Erreur de saisie.\n";
        return 1;
    }

    // On demande les paramètres communs aux deux modes
    std::string fichierEntree;
    std::cout << "\nEntrez le fichier d'entree : ";
    std::cin >> fichierEntree;

    int iterations = 0;
    std::cout << "Nombre d'iterations : ";
    std::cin >> iterations;

    if (!std::cin || iterations < 0) {
        std::cerr << "Nombre d'iterations invalide.\n";
        return 1;
    }

    switch (choix) {
        case 1: {
            std::cout << "\n>>> Lancement du mode console...\n\n";
            ModeConsole mode(fichierEntree, iterations);
            mode.executer();
            break;
        }
        case 2: {
            std::cout << "\n>>> Lancement du mode graphique...\n\n";
            ModeGraphique mode(fichierEntree, iterations, 10);
            mode.executer();
            break;
        }
        default:
            std::cout << "Choix invalide. Fin du programme.\n";
            break;
    }

    return 0;
}
