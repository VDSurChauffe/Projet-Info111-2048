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

    // CES VARIABLES SERENT A DEFINIR DES COULEURS QUI NE CHANGERONT PAS EN FONCTION DES THEMES
    string couleurDuFond;
    string couleurPrincipal;
    string couleurBlanc = "\x1b[38;5;15m";;
    string couleurErreur = "\x1b[38;5;196m";;
    string couleurGagne = "\x1b[38;5;190m";

    while (true) {
        // SELECTIONNEUR DE THEME
        cout << "Selectionner votre thème de couleur :" << endl;
        cout << "1. Classique" << endl << "2. Paris-Saclay" << endl << "3. GitHub" << endl << "4. Slack" << endl;

        string theme;

        cin >> theme;

        // CES TESTS DEFINISSENT DES COULEURS PAR RAPPORT AU THEME CHOISI
        if (theme == "1") {
            couleurDuFond = "\x1b[48;5;235m";
            couleurPrincipal = "\x1b[38;5;214m";
            choisirTheme(1);
            break;
        } else if (theme == "2") {
            couleurDuFond = "\x1b[48;5;53m";
            couleurPrincipal = "\x1b[38;5;15m";
            choisirTheme(2);
            break;
        } else if (theme == "3") {
            couleurDuFond = "\x1b[48;5;236m";
            couleurPrincipal = "\x1b[38;5;15m";
            choisirTheme(3);
            break;
        } else if (theme == "4") {
            couleurDuFond = "\x1b[48;5;235m";
            couleurPrincipal = "\x1b[38;5;161m";
            choisirTheme(4);
            break;
        } else {
            cout << "Choix incorrecte. Veuillez reessayer";
        }

    }

    // CETTE PHRASE N'EST JAMAIS VU PAR L'UTILISATEUR. ELLE SERT A CORRIGER UN BUG D'AFFICHAGE SUR CERTAINS CONSOLES
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

    // BOUCLE PRINCIPALE DU JEU 
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
        cout << couleurPrincipal << "Vous pouvez jouer avec soit les clés WASD, soit les clés ZQSD. Le jeu détectera cela automatiquement. Tapez \"r\" pour recommencer la partie" << endl;
        dessine(plateauDuJeu);

        cout << couleurPrincipal << "SCORE : " << couleurBlanc << score << endl << couleurBlanc;

        // VERIFIE SI LE JEU EST TERMINEE
        if (estTermine(plateauDuJeu) == true) {
            cout << "Partie terminée ! ";
            if (estGagnant(plateauDuJeu) == true) {
                cout << couleurGagne << "Vous avez gagné !" << endl << endl << couleurBlanc << "Voulez-vous recommencer ? Tapez la commande \"o\" pour oui et n'importe quel autre commande pour non : ";

                string recommenceOuNon;
                cin >> recommenceOuNon;

                if (recommenceOuNon == "O" or recommenceOuNon == "o") {
                    plateauDuJeu = plateauInitial();
                    plateauPrecedent = plateauVide();
                    score = 0;
                    continue;
                } else {
                    cout << "Au Revoir !";
                    break;
                }

                
            } else {
                cout << couleurErreur << "Vous avez perdu !" << endl << endl << couleurBlanc << "Voulez-vous recommencer ? Tapez la commande \"o\" pour oui et n'importe quelle autre commande pour non : ";

                string recommenceOuNon;
                cin >> recommenceOuNon;

                if (recommenceOuNon == "O" or recommenceOuNon == "o") {
                    plateauDuJeu = plateauInitial();
                    plateauPrecedent = plateauVide();
                    score = 0;
                    continue;
                } else {
                    cout << "Au Revoir !";
                    break;
                }
            }
        } else {
            if (estGagnant(plateauDuJeu)) {
                cout << "Vous avez gagné ! Continuez pour atteindre le meilleur score possible !" << endl << endl;
            }
        }

        // RECEPTION DE LA COMMANDE DE L'UTILISATEUR
        plateauPrecedent = plateauDuJeu;
        cout << "Entrez une commande : ";
        cin >> commande;
        cout << couleurBlanc << endl;

        // EXECUTION DE LA COMMANDE DE L'UTILISATEUR
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
        } else if (commande == "r" or commande == "R") {
            plateauDuJeu = plateauInitial();
            plateauPrecedent = plateauVide();
            score = 0;
            continue;
        }

        // AJOUTE UNE CASE AU PLATEAU SI LE PLATEAU A CHANGE DEPUIS LA DERNIERE FOIS
        if (plateauPrecedent != plateauDuJeu) {
            tirage = tireDeuxOuQuatre();
            if (tirage == 4) {quatresNaturels++;}
            plateauDuJeu = ajouteCase(plateauDuJeu, tirage);
        }
    }

    cout << "\x1b[0m";
    return 0;
}
