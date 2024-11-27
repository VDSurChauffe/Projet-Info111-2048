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
    //Pour ce faire il suffit simplement de décommenter la ligne ci-dessous
    tests();

    string couleurDuFond = "\x1b[48;5;237m";
    string couleurPrincipal = "\x1b[38;5;15m";
    string couleurNoir = "\x1b[38;5;0m";
    string couleurErreur = "\x1b[38;5;160m";
    
    cout << couleurDuFond << couleurPrincipal << endl;
    cout << "*****   *****   *   *   *****" << endl;
    cout << "    *   *   *   *   *   *   *" << endl;
    cout << "*****   *   *   *****   *****" << endl;
    cout << "*       *   *       *   *   *" << endl;
    cout << "*****   *****       *   *****" << endl << endl;
    cout << couleurNoir << endl;
    cout << "CRÉÉ PAR PARSA FARJAM ET VICTOR DAVIAU EN 2024" << endl << endl;
    cout << couleurPrincipal << "Veuillez choisir le mode d'interaction avec le jeu en tapant son numéro" << endl << couleurPrincipal << "1. \x1b[38;5;0m" << "WASD" << endl << couleurPrincipal << "2. \x1b[38;5;0m" << "ZQSD" << endl << couleurPrincipal << "3. " << couleurNoir << "Flèches" << endl;

    string mode_interaction = "";

    cin >> mode_interaction;

    while (mode_interaction != "1" and mode_interaction != "2" and mode_interaction != "3") {
        cout << couleurErreur << "Mode d'interaction saisi incorrect ! Veuillez reéssayer :" << endl;
        cin >> mode_interaction;
    }

    if (mode_interaction == "3") {
        cout << couleurPrincipal << "Flèche Haut " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers le haut" << endl << couleurPrincipal << "Flèche Gauche " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers la gauche" << endl << couleurPrincipal << "Flèche Droite " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers la droite" << endl << couleurPrincipal << "Flèche Bas " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers le bas" << endl << endl << couleurNoir;
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
        cout << couleurPrincipal << "W " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers le haut" << endl << couleurPrincipal << "A " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers la gauche" << endl << couleurPrincipal << "S " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers la droite" << endl << couleurPrincipal << "D " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers le bas" << endl << endl << couleurNoir;
    }
    if (mode_interaction == "2") {
        cout << "Z " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers le haut" << endl << "Q " << couleurPrincipal << "-> " << couleurPrincipal << "Déplacer vers la gauche" << endl << "S " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers la droite" << endl << "" << "D " << couleurNoir << "-> " << couleurPrincipal << "Déplacer vers le bas" << endl << endl << couleurNoir;
    }

    while (true) {
        dessine(plateauDuJeu);
        plateauPrecedent = plateauDuJeu;

        cout << couleurPrincipal << "SCORE : " << couleurNoir << score << endl << couleurNoir;
        cout << "Entrez une commande : ";
        cin >> commande;
        cout << couleurNoir;

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

    cout << "\x1b[0m";
    return 0;
}
