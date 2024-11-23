#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "modele.hpp"

using namespace std;

using Plateau = vector<vector<int>> ;

int main() {
    srand(time(NULL));
    
    //Teste automatiquement les fonctions de modele.hpp
    tests();
    
    cout << "*****   *****   *   *   *****" << endl;
    cout << "    *   *   *   *   *   *   *" << endl;
    cout << "*****   *   *   *****   *****" << endl;
    cout << "*       *   *       *   *   *" << endl;
    cout << "*****   *****       *   *****" << endl << endl;
    cout << "CRÉE PAR PARSA FARJAM ET VICTOR DAVIAU EN 2024" << endl << endl;
    cout << "Veuillez choisir le mode d'interaction avec le jeu en tapant son numéro" << endl << "1. WASD" << endl << "2. ZQSD" << endl << "3. Flèches" << endl;

    string mode_interaction = "";

    cin >> mode_interaction;

    while (mode_interaction != "1" and mode_interaction != "2" and mode_interaction != "3") {
        cout << "Mode d'interaction saisi incorrect ! Veuillez reéssayer :" << endl;
        cin >> mode_interaction;
    }

    string commande;
    int direction;

    if (mode_interaction == "1") {
        cout << "W -> Déplacer vers le haut" << endl << "A -> Déplacer vers la gauche" << endl << "S -> Déplacer vers la droite" << endl << "D -> Déplacer vers le bas" << endl << endl;

        int score = 0;

        int quatresNaturels = 0;

        Plateau plateauDuJeu = plateauInitial();


        while (true) {
            dessine(plateauDuJeu);
            cout << "SCORE : " << score << endl;
            cout << "Entrez une commande : ";

            cin >> commande;

            if (commande == "w" or commande == "W") {
                direction = 1;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else if (commande == "a" or commande == "A") {
                direction = 4;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else if (commande == "s" or commande == "S") {
                direction = 3;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else if (commande == "d" or commande == "D") {
                direction = 2;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else {
                cout << "commande saisi inconnue" << endl;
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
                if (estGagnant(plateauDuJeu) == true) {
                    cout << "vous avez gagné ! Continuez pour atteindre un meilleur score possible" << endl;
                }
                plateauDuJeu = ajouteCase(plateauDuJeu, quatresNaturels);
            }
        }
    } else if (mode_interaction == "2") {
        cout << "Z -> Déplacer vers le haut" << endl << "Q -> Déplacer vers la gauche" << endl << "S -> Déplacer vers la droite" << endl << "D -> Déplacer vers le bas" << endl << endl;
        
        int score = 0;

        int quatresNaturels = 0;

        Plateau plateauDuJeu = plateauInitial();
        Plateau plateauDEtapeDAvant = plateauVide();

        while (true) {
            dessine(plateauDuJeu);
            cout << "SCORE : " << score << endl;
            cout << "Entrez une commande :";

            cin >> commande;

            if (commande == "z" or commande == "Z") {
                direction = 1;
                plateauDEtapeDAvant = plateauDuJeu;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else if (commande == "q" or commande == "Q") {
                direction = 4;
                plateauDEtapeDAvant = plateauDuJeu;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else if (commande == "s" or commande == "S") {
                direction = 3;
                plateauDEtapeDAvant = plateauDuJeu;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else if (commande == "d" or commande == "D") {
                direction = 2;
                plateauDEtapeDAvant = plateauDuJeu;
                plateauDuJeu = deplacement(plateauDuJeu, direction);
                score = scorePlateau(plateauDuJeu, quatresNaturels);
            } else {
                cout << "commande saisi inconnue" << endl;
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
                if (estGagnant(plateauDuJeu) == true) {
                    cout << "vous avez gagné ! Continuez pour atteindre un meilleur score possible" << endl;
                }
                if (plateauDEtapeDAvant != plateauDuJeu) {
                    plateauDuJeu = ajouteCase(plateauDuJeu, quatresNaturels);
                }
            }
        }
    } else {
        cout << "Flèche Haut -> Déplacer vers le haut" << endl << "Flèche Gauche -> Déplacer vers la gauche" << endl << "Flèche Droite -> Déplacer vers la droite" << endl << "Flèche Bas -> Déplacer vers le bas" << endl << endl;
        cout << "Ce mode de jeu sera bientôt disponible!";
    }

    return 0;
}
