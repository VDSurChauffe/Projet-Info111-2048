#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "modele.hpp"

using namespace std;

using Plateau = vector<vector<int>> ;

int main() {
    srand(time(NULL));

    string couleurDuFond;
    string couleurPrincipal;
    string couleurNoir;
    string couleurErreur;
    string couleurGagne;

    while (true) {
        cout << "Selectionner votre thème de couleur :" << endl;
        cout << "1. Classique" << endl << "2. Paris-Saclay" << endl << "3. GitHub" << endl << "4. Dracula" << endl << "5. Gruvbox Dark" << endl;

        string theme;

        cin >> theme;

        if (theme == "1") {
            couleurDuFond = "\x1b[48;5;250m";
            couleurPrincipal = "\x1b[38;5;166m";
            couleurNoir = "\x1b[38;5;0m";
            couleurErreur = "\x1b[38;5;160m";
            couleurGagne = "\x1b[38;5;82m";
            break;
        } else if (theme == "2") {

        } else if (theme == "3") {
        
        } else if (theme == "4") {

        } else if (theme == "5") {

        } else {
            cout << "Choix incorrecte. Veuillez reessayer";
        }

    }

    system("clear");
    cout << couleurDuFond << couleurPrincipal;
    cout << "Cela est pour eviter des bouges d'affichage" << endl;
    cout << couleurDuFond << couleurPrincipal << endl;
    
    string commande;
    int score = 0;
    int quatresNaturels = 0;
    int tirage;
    Plateau plateauDuJeu = plateauInitial();
    Plateau plateauPrecedent = plateauVide();

    while (true) {
        system("clear");
        cout << couleurDuFond << couleurPrincipal;
        cout << "*****   *****   *   *   *****" << endl;
        cout << "    *   *   *   *   *   *   *" << endl;
        cout << "*****   *   *   *****   *****" << endl;
        cout << "*       *   *       *   *   *" << endl;
        cout << "*****   *****       *   *****" << endl << endl;
        cout << couleurDuFond << couleurPrincipal << endl;
        cout << "CRÉÉ PAR PARSA FARJAM ET VICTOR DAVIAU EN 2024" << endl << endl;
        cout << couleurPrincipal << "Vous pouvez jouer avec soit les clés WASD, soit les clés ZQSD. Le jeu detectera cela automatiquement" << endl;
        dessine(plateauDuJeu);

        cout << couleurPrincipal << "SCORE : " << couleurNoir << score << endl << couleurNoir;

        if (estTermine(plateauDuJeu) == true) {
            cout << "Partie terminée ! ";
            if (estGagnant(plateauDuJeu) == true) {
                cout << couleurGagne << "Vous avez gagné !" << endl << endl << "Sortie du programme. Au revoir !" << endl;
            } else {
                cout << couleurErreur << "Vous avez perdu !" << endl << endl << "Sortie du programme. Au revoir !" << endl;
            }
            break;
        } else {
            if (estGagnant(plateauDuJeu)) {
                cout << "Vous avez gagné ! Continuez pour atteindre le meilleur score possible !" << endl << endl;
            }
        }

        plateauPrecedent = plateauDuJeu;
        cout << "Entrez une commande : ";
        cin >> commande;
        cout << couleurNoir << endl;

        if (commande == "w" or commande == "W" or commande == "z" or commande == "Z") {
            plateauDuJeu = deplacement(plateauDuJeu, 1);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "a" or commande == "A" or commande == "q" or commande == "Q") {
            plateauDuJeu = deplacement(plateauDuJeu, 4);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "s" or commande == "S") {
            plateauDuJeu = deplacement(plateauDuJeu, 3);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        } else if (commande == "d" or commande == "D") {
            plateauDuJeu = deplacement(plateauDuJeu, 2);
            score = scorePlateau(plateauDuJeu, quatresNaturels);
        }

        if (plateauPrecedent != plateauDuJeu) {
            tirage = tireDeuxOuQuatre();
            if (tirage == 4) {quatresNaturels++;}
            plateauDuJeu = ajouteCase(plateauDuJeu, tirage);
        }
    }

    cout << "\x1b[0m";
    return 0;
}
