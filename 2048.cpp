#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <SDL2/SDL.h>
#include "modele.hpp"

using namespace std;

using Plateau = vector<vector<int>> ;

int main() {
    srand(time(NULL));
    
    //Teste automatiquement les fonctions de modele.hpp
    //Pour ce faire il suffit simplement de décommenter la ligne ci-dessous
    tests();
    
    cout << "*****   *****   *   *   *****" << endl;
    cout << "    *   *   *   *   *   *   *" << endl;
    cout << "*****   *   *   *****   *****" << endl;
    cout << "*       *   *       *   *   *" << endl;
    cout << "*****   *****       *   *****" << endl << endl;
    cout << "CRÉÉ PAR PARSA FARJAM ET VICTOR DAVIAU EN 2024" << endl << endl;
    cout << "Veuillez choisir le mode d'interaction avec le jeu en tapant son numéro" << endl << "1. WASD" << endl << "2. ZQSD" << endl << "3. Flèches" << endl;

    string mode_interaction = "";

    cin >> mode_interaction;

    while (mode_interaction != "1" and mode_interaction != "2" and mode_interaction != "3") {
        cout << "Mode d'interaction saisi incorrect ! Veuillez reéssayer :" << endl;
        cin >> mode_interaction;
    }

    if (mode_interaction == "3") {
        cout << "Flèche Haut -> Déplacer vers le haut" << endl << "Flèche Gauche -> Déplacer vers la gauche" << endl << "Flèche Droite -> Déplacer vers la droite" << endl << "Flèche Bas -> Déplacer vers le bas" << endl << endl;
        cout << "Ce mode de jeu sera bientôt disponible !";
        return 0;
    }

    string commande;
    int score = 0;
    int quatresNaturels = 0;
    int tirage;
    Plateau plateauDuJeu = plateauInitial();
    Plateau plateauPrecedent = plateauVide();

    if (mode_interaction == "1") {
        cout << "W -> Déplacer vers le haut" << endl << "A -> Déplacer vers la gauche" << endl << "S -> Déplacer vers la droite" << endl << "D -> Déplacer vers le bas" << endl << endl;
    }
    if (mode_interaction == "2") {
        cout << "Z -> Déplacer vers le haut" << endl << "Q -> Déplacer vers la gauche" << endl << "S -> Déplacer vers la droite" << endl << "D -> Déplacer vers le bas" << endl << endl;
    }

    while (true) {
        dessine(plateauDuJeu);
        plateauPrecedent = plateauDuJeu;

        cout << "SCORE : " << score << endl;
        cout << "Entrez une commande : ";
        cin >> commande;

        if (
            ((commande == "w" or commande == "W") and mode_interaction == "1")
            or ((commande == "z" or commande == "Z") and mode_interaction == "2")
        ) {
            plateauDuJeu = deplacement(plateauDuJeu, 1);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (
            ((commande == "a" or commande == "A") and mode_interaction == "1")
            or ((commande == "q" or commande == "Q") and mode_interaction == "2")
        ) {
            plateauDuJeu = deplacement(plateauDuJeu, 4);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "s" or commande == "S") {
            plateauDuJeu = deplacement(plateauDuJeu, 3);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "d" or commande == "D") {
            plateauDuJeu = deplacement(plateauDuJeu, 2);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else {
            cout << "Commande saisie inconnue." << endl;
        }

        if (estTermine(plateauDuJeu) == true) {
            cout << "Partie terminée ! ";
            if (estGagnant(plateauDuJeu) == true) {
                cout << "Vous avez gagné !" << endl << endl << "Sortie du programme. Au revoir !";
            } else {
                cout << "Vous avez perdu !" << endl << endl << "Sortie du programme. Au revoir !";
            }
            break;
        } else {
            if (estGagnant(plateauDuJeu)) {
                cout << "Vous avez gagné ! Continuez pour atteindre le meilleur score possible !" << endl;
            }
            if (plateauPrecedent != plateauDuJeu) {
                tirage = tireDeuxOuQuatre();
                if (tirage == 4) {quatresNaturels++;}
                plateauDuJeu = ajouteCase(plateauDuJeu, tirage);
            }
        }
    }

    return 0;
}
