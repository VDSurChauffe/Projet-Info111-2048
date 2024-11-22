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

    if (mode_interaction == "1" or mode_interaction == "2") {
        // Ce tableau sera utilisé pour déterminer que souhaite l'utilisateur
        vector<string> controles;
        controles = vector<string> (8);

        if (mode_interaction == "1") {
            controles = {"w", "a", "s", "d", "W", "A", "S", "D"};
            cout << "W -> Déplacer vers le haut" << endl << "A -> Déplacer vers la gauche" << endl << "S -> Déplacer vers la droite" << endl << "D -> Déplacer vers le bas" << endl << endl;
        } else {
            controles = {"z", "q", "s", "d", "Z", "Q", "S", "D"};
            cout << "Z -> Déplacer vers le haut" << endl << "Q -> Déplacer vers la gauche" << endl << "S -> Déplacer vers la droite" << endl << "D -> Déplacer vers le bas" << endl << endl;
        }
    } else {
        cout << "Flèche Haut -> Déplacer vers le haut" << endl << "Flèche Gauche -> Déplacer vers la gauche" << endl << "Flèche Droite -> Déplacer vers la droite" << endl << "Flèche Bas -> Déplacer vers le bas" << endl << endl;
    }

    return 0;
}
