#ifndef MODEGRAPHIQUE_H
#define MODEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Jeu.h"
#include "LecteurFichier.h"
#include "Afficheur.h"

// Mode graphique du Game of Life avec SFML : charge une grille, execute des iterations et affiche la grille.
class ModeGraphique : public Afficheur {
public:
    // fichierEntree : chemin de configuration, iterationsMax : nombre d'iterations, tailleCellule : pixels par cellule (defaut 10)
    ModeGraphique(const std::string& fichierEntree,
                  int iterationsMax,
                  int tailleCellule = 10);

    // Lance la boucle principale (ouvre la fenetre, gere les evenements, etc.)
    void executer();

private:
    // Gere la file d'evenements SFML (fermeture, clavier...)
    void gererEvenements();

    // Met a jour la grille en fonction du temps et du nombre d'iterations
    void mettreAJour();

    // Dessine la grille dans la fenetre SFML
    void afficher(const Grille& grille) override;

    // Constantes de timing
    static constexpr float DELAY_INITIAL = 0.2f; // 200 ms
    static constexpr float DELAY_MIN = 0.05f;
    // Taille cible de la fenetre (fixe) pour eviter les affichages trop petits
    static constexpr int WINDOW_WIDTH = 800;  // zone grille
    static constexpr int WINDOW_HEIGHT = 800;
    static constexpr int INFO_PANEL_WIDTH = 200; // zone info a droite

    void initialiserOverlayTexte();

    Jeu m_jeu;
    int m_iterationsMax;
    int m_iterationCourante;
    int m_cellSize;
    bool m_pause;
    float m_delay;

    sf::RenderWindow m_window;
    sf::Clock m_clock;
    sf::Font m_font;
    sf::Text m_overlayText;
};

// Fonction utilitaire : demande le fichier et le nombre d'iterations puis lance le mode graphique.
void lancerModeGraphique();

#endif // MODEGRAPHIQUE_H
