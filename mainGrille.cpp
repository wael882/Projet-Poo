#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "Jeu.h"
#include "Grille.h"

// Petite démo graphique autonome :
// - crée une grille aléatoire
// - affiche les cellules vivantes en noir/blanc dans une fenêtre SFML
// - ne fait pas évoluer le jeu (état fixe), comme le main original

int main() {
    const int cellSize   = 10;
    const int gridWidth  = 80;
    const int gridHeight = 80;

    // Grille initialement morte
    Grille grille(gridHeight, gridWidth);
    Jeu jeu(std::move(grille));

    // Seed aléatoire et remplissage
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int x = 0; x < gridHeight; ++x) {
        for (int y = 0; y < gridWidth; ++y) {
            if (std::rand() % 2 == 1) {
                jeu.grille().getCellule(x, y).rendreVivante();
            } else {
                jeu.grille().getCellule(x, y).rendreMorte();
            }
        }
    }

    sf::RenderWindow window(
        sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize),
        "Game of Life - Demo statique");

    sf::RectangleShape cell(
        sf::Vector2f(static_cast<float>(cellSize - 1),
                     static_cast<float>(cellSize - 1)));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        // Rendu de la grille aléatoire (état fixe)
        for (int i = 0; i < jeu.grille().getnblignes(); ++i) {
            for (int j = 0; j < jeu.grille().getnbcolonnes(); ++j) {
                if (jeu.grille().getCellule(i, j).estVivante()) {
                    cell.setPosition(static_cast<float>(j * cellSize),
                                     static_cast<float>(i * cellSize));
                    window.draw(cell);
                }
            }
        }

        window.display();
        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
