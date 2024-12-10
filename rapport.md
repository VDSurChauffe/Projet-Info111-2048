# Rapport de projet 2048

## Auteurs

- DAVIAU Victor, victor.daviau@etu-upsaclay.fr (LDD1-IM2)
- FARJAM Parsa, parsa.farjam@etu-upsaclay.fr (LDD1-IM2)


## Résumé du travail effectué

### Niveau 0
- Jeu fonctionnel et complet :

Nous avons écrit quelques fonctions en plus de celles déjà présentes dans le sujet, pour permettre d'effectuer des tests automatiques et faciliter les calculs dans certaines fonctionnalités. La version SDL utilise quelques fonctions pour faciliter l'affichage du jeu.

Toutes les fonctions sont documentées et ont été testées, presque toutes sont également testées automatiquement par ``tests()``, et certaines sont commentées pour clarifier leur fonctionnement.

Le jeu fonctionne parfaitement, respecte les règles de 2048, exécute correctement les instructions de l'utilisateur, ignore les instructions incorrectes et/ou inconnues.

### Niveau 1
- Couleurs : contenues dans l'interface graphique et dans l'interface terminal ; cette dernière utilise pour ce faire des caractères d'échappement ANSI.
- Mouvement avec les flèches seules : fait avec l'UI graphique, et le jeu permet également WASD/ZQSD (les deux interfaces permettent les deux modes en même temps et s'adaptent au clavier de l'utilisateur pour gérer WASD/ZQSD)
- Ecraser l'affichage à chaque mouvement : marche (bien entendu) sur l'interface graphique, fait sur l'interface terminal avec la bibliothèque `cstdlib` et la commande ```clear``` dans la console. 

Le score est calculé par une fonction qui prend en argument le plateau du jeu et une variable supplémentaire, nécessaire pour tenir compte du fait que les 4 apparus naturellement rapportent moins de points.

### Niveau 2
- Utiliser un Makefile : fait
- Utiliser un gestionnaire de version et le comprendre : fait avec [un repo GitHub](https://github.com/VDSurChauffe/Projet-Info111-2048/) (Nous avons utilisé des branches différentes pour gérer notre travail et des Pull Requests pour gérer les merges à la branche ```main```. Les messages de commit, les noms de branches et le README sont en anglais pour respecter des standards internationaux de code.)

### Niveau 3
- créer une IA : non traité
- ajouter des variantes : non traité
- avoir une interface graphique :

    Fait par Victor en utilisant la bibliothèque SDL. La boucle du jeu reste intacte *modulo* quelques changements pour l'adapter au mode de contrôles légèrement différent ; tout l'affichage est géré par une fonction dans `modele.cpp` ; on utilise également l'extension `SDL_ttf` de la bibliothèque SDL pour pouvoir écrire du texte plus aisément.
- en faire une application pour téléphone : non traité
- Le jeu présente un sélecteur de thème : 

## Organisation du travail

Nous avons utilisé GitHub pour échanger nos progrès sur le jeu, avec un repo GitHub. Nous avons créé deux branches différentes pour l'interface graphique et l'interface terminal.

Nous avons d'abord travaillé en collaborant (environ 2 heures) en temps réel, puis (environ 10 heures chacun) chez nous pour programmer le jeu de base (boucle de jeu, mouvements, score et l'interface terminal simple), puis nous avons chacun géré une branche du projet : Parsa a développé l'interface console, et Victor a écrit l'interface graphique, ce qui nous a pris chacun environ 10-20 heures de travail individuel.

Parsa a écrit :
- Toutes les fonctions de deplacement
- Les fonctions auxilières `choisirTheme`, `inverseVector`, `tourneGauche`, `tourneDroite`
- Boucle principale du jeu
- Fonction affichage (interface terminal)
- Interface console avec les couleurs 

Victor a écrit :
- La fonction de calcul de score et la fonction `logCase` (un logarithme base 2 simple)
- Les tests automatiques des fonctions
- L'interface graphique complète

Nous avons fait le rapport et le README ensemble.

## Prise de recul

Nous avons rencontré quelques problèmes lors de la réalisation de ce projet :
- Les fonctions permettant de déplacer le plateau de jeu ont été difficiles à implanter car l'algorithme nécessaire est le plus complexe du projet.
- La bibliothèque `ncurses` ne fonctionnait pas correctement pour Parsa et pas du tout pour Victor, d'où le choix de ne pas l'utiliser et utiliser des caractères d'échappement ANSI et la fonction `system()` de la bibliothèque `cstdlib` pour les couleurs et le rafraîchissement de l'écran.
- La bibliothèque SDL a également posé des problèmes initialement car la procédure à suivre pour l'installer est assez complexe, et la compilation séparée requiert de nombreuses options de compilation (en raison de l'usage de deux bibliothèques) qui ont complexifié l'écriture du Makefile.

Ce projet nous a permis d'explorer quelques bibliothèques (notamment SDL) et nous a rappelé qu'il est important d'écrire du code flexible, sous peine de devoir tout réécrire (ou que le code devienne illisible) lorsque l'on veut y ajouter des fonctionnalités (ex. la fonction `dessineGUI` qui prend ***8*** arguments).

"C++ est un très bon langage, très plaisant, tant qu'il ne s'agit pas de compiler des fichiers" -Victor
