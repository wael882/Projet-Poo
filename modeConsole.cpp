#include "modeConsole.h"

#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

// =======================
//      CONSTRUCTEUR
// =======================

ModeConsole::ModeConsole(const std::string& fichierEntree, int iterations)
    : m_jeu(LecteurFichier::charger(fichierEntree)),
      m_fichierEntree(fichierEntree),
      m_dossierSortie(fichierEntree + "_out"),
      m_iterations(iterations)
{
    // Création du dossier de sortie s'il n'existe pas
    fs::create_directory(m_dossierSortie);
}

// =======================
//     MÉTHODES PUBLIQUES
// =======================

void ModeConsole::executer()
{
    // Sauvegarde de l'état initial
    sauvegarder(0);

    // Simulation
    for (int i = 1; i <= m_iterations; ++i) {
        m_jeu.tick();
        sauvegarder(i);
    }

    std::cout << "\n=== Grille finale avec " << m_iterations
              << " iterations ===\n";
    afficher(m_jeu.grille());

    std::cout << "Simulation terminee.\n";
    std::cout << "Resultats disponibles dans le dossier : "
              << m_dossierSortie << "\n";
}

// =======================
//     MÉTHODES PRIVÉES
// =======================

void ModeConsole::afficher(const Grille& grille)
{
    for (int i = 0; i < grille.getnblignes(); ++i) {
        for (int j = 0; j < grille.getnbcolonnes(); ++j) {
            int code = 0;
            switch (grille.getCellule(i, j).typeEtat()) {
                case EtatType::Vivante:          code = 1; break;
                case EtatType::ObstacleVivante:  code = 2; break;
                case EtatType::ObstacleMorte:    code = 3; break;
                case EtatType::Morte:
                default:                         code = 0; break;
            }
            std::cout << code << " ";
        }
        std::cout << "\n";
    }
    std::cout << "-------------------------\n";
}

void ModeConsole::sauvegarder(int iteration) const
{
    std::string nomFichier =
        m_dossierSortie + "/iter_" + std::to_string(iteration) + ".txt";

    std::ofstream out(nomFichier);

    if (!out.is_open()) {
        std::cerr << "Erreur : impossible d'écrire dans " << nomFichier << "\n";
        std::exit(1);
    }

    const Grille& grille = m_jeu.grille();
    out << grille.getnblignes() << " " << grille.getnbcolonnes() << "\n";

    for (int i = 0; i < grille.getnblignes(); ++i) {
        for (int j = 0; j < grille.getnbcolonnes(); ++j) {
            int code = 0;
            switch (grille.getCellule(i, j).typeEtat()) {
                case EtatType::Vivante:          code = 1; break;
                case EtatType::ObstacleVivante:  code = 2; break;
                case EtatType::ObstacleMorte:    code = 3; break;
                case EtatType::Morte:
                default:                         code = 0; break;
            }
            out << code << " ";
        }
        out << "\n";
    }
}

// =======================
//  FONCTION UTILITAIRE
// =======================

void lancerModeConsole()
{
    std::cout << "=== MODE CONSOLE ===\n";

    // Demande du fichier
    std::string fichierEntree;
    std::cout << "Entrez le fichier d'entree : ";
    std::cin >> fichierEntree;

    // Nombre d'itérations
    int iterations;
    std::cout << "Nombre d'iterations : ";
    std::cin >> iterations;

    ModeConsole mode(fichierEntree, iterations);
    mode.executer();
}
