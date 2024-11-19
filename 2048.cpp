#include <vector>
#include <string>
#include <iostream>
#include "modele.hpp"

using namespace std;

using Plateau = vector<vector<int>> ;

int main() {
    //Teste automatiquement les fonctions de modele.hpp
    tests();
    
    cout << "Veuillez choisir le mode d'intéraction avec le jeu en tapant son numéro" << endl << "1. WASD" << endl << "2. ZQSD" << endl << "3. Fléches" << endl;

    string mode_interaction = "";

    cin >> mode_interaction;

    while (mode_interaction != "1" and mode_interaction != "2" and mode_interaction != "3") {
        cout << "Mode interaction saisi incorrecte ! Veuillez reéssayer" << endl;
        cin >> mode_interaction;
    }
    // A compléter
    return 0;
}
