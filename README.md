# Jeu de la Vie (C++)

Implémentation du Game of Life avec deux modes :
- Console : lit une grille depuis un fichier, exécute un nombre d’itérations et sauvegarde chaque état dans des fichiers texte.
- Graphique (SFML) : ouvre une fenêtre, affiche la grille en couleur, permet pause/reprise et réglage de la vitesse.

## Prérequis
- Compilateur C++17 (g++, clang, ou MSVC).
- SFML 2.5+ (modules graphics, window, system; audio/network sont listés mais non indispensables partout).

### Windows
- Option WSL (recommandé) : installer g++ et SFML côté Linux (`sudo apt install g++ libsfml-dev`), puis compiler depuis WSL. Adapter `CXXFLAGS`/`LDFLAGS` si `/usr/include/SFML` n’existe pas.

- Option MSYS2/MinGW : `pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-sfml`. Compiler dans l’environnement MSYS2/MinGW et ajouter le répertoire des DLL SFML au `PATH` pour l’exécution.

- Option Visual Studio : créer un projet CMake/VS et lier les libs/dll SFML (copier les DLL SFML dans le dossier d’exécution ou les mettre dans le `PATH`).

### Linux
- Paquets : `sudo apt install g++ libsfml-dev` (Debian/Ubuntu) ou équivalent (`dnf install SFML-devel`, `pacman -S sfml`…).

### macOS
- Homebrew : `brew install sfml`.
- Avec clang/Makefile, si Homebrew est dans `/opt/homebrew`, ajouter par exemple `CXXFLAGS += -I/opt/homebrew/include` et `LDFLAGS += -L/opt/homebrew/lib`.

## Construction (Makefile fourni)
```bash
make          # exécutable principal : jeu
make tests    # exécutable de tests unitaires : tests
make test     # compile puis lance les tests
make clean    # supprime les exécutables
```

## Utilisation
```bash
./jeu
```
Menu :
- 1 : Mode console — demande le fichier d’entrée et le nombre d’itérations, sauvegarde les états.
- 2 : Mode graphique — demande le fichier d’entrée et les itérations, affiche la grille SFML.
- 3 : Tests unitaires sur fichier — charge le fichier pour vérification, puis lance la suite de tests.

### Format des fichiers de grille
```
<nb_lignes> <nb_colonnes>
<etat_00> <etat_01> ... <etat_0n>...

```
Codes : 0 = morte, 1 = vivante, 2 = obstacle vivante, 3 = obstacle morte. 
Exemple 3x3 avec une cellule vivante au centre :
```
3 3
0 0 0
0 1 0
0 0 0
```

### Contrôles mode graphique
- `Esc` : quitter
- `Space` : pause / reprise
- `Flèche Haut` : accélérer
- `Flèche Bas` : ralentir

### Sortie mode console
- États sauvegardés dans `<fichier>_out/iter_<n>.txt`.
- Affichage de la grille finale dans la console (codes 0/1/2/3).

## Tests
- `make test` ou exécutable `./tests`.
- Couverture actuelle : oscillateur blinker, comportement torique.

## Arborescence
- `mainPrincipal.cpp` : menu
- `modeConsole.*` : mode console et sauvegarde
- `modeGraphique.*` : mode graphique SFML
- `Grille.*`, `Cellule.*`, états de cellules
- `LecteurFichier.*` : chargement de grille
- `test_unitaire.*`, `mainTests.cpp` : tests
- `Makefile`


