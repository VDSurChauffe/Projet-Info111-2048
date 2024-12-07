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
- Mouvement avec les flèches seules : fait avec l'UI graphique, et le jeu permet également WASD/ZQSD (l'interface graphique permet les deux modes en même temps et s'adapte au clavier de l'utilisateur pour gérer WASD/ZQSD, tandis que l'interface console demande de choisir *un* mode parmi les 3)
- Ecraser l'affichage à chaque mouvement : marche (bien entendu) sur l'interface graphique, fait sur l'interface terminal avec la bibliothèque `cstdlib` et la commande ```clear``` dans la console.
- Calcul de score par une fonction : fait, cependant la fonction requiert un argument suppémentaire (une variable dans `main()`) pour tenir compte du fait que les 4 apparus naturellement rapportent moins

### Niveau 2
- Utiliser un Makefile : fait
- Utiliser un gestionnaire de version : fait avec [un repo GitHub](https://github.com/VDSurChauffe/Projet-Info111-2048/)

### Niveau 3
- créer une IA : non traité *(?)*
- ajouter des variantes : non traité
- avoir une interface graphique :

    Fait par Victor en utilisant la bibliothèque SDL. La boucle du jeu reste intacte *modulo* quelques changements pour l'adapter au mode de contrôles légèrement différent ; tout l'affichage est géré par une fonction dans `modele.cpp` ; on utilise également l'extension `SDL_ttf` de la bibliothèque SDL pour pouvoir écrire du texte plus aisément.
- en faire une application pour téléphone : non traité

## Organisation du travail

*Décrivez en quelques phrases comment vous vous êtes organisés pour travailler sur le projet: nombre d'heures consacrées au projet, répartition du travail dans le binôme, moyens mis en œuvre pour collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle de vos enseigants), précisez le.*

Nous avons utilisé GitHub pour échanger nos progrès sur le jeu, avec un repo GitHub géré par Victor. Nous avons créé deux branches différentes pour l'interface graphique et l'interface terminal.

Nous avons d'abord travaillé en collaborant (environ 10 heures) en temps réel pour programmer le jeu de base, puis nous avons chacun géré une branche du projet : Parsa a développé l'interface console, et Victor a écrit l'interface graphique. Cela nous a pris chacun environ 10-20 heures de travail individuel.

## Prise de recul

Nous avons rencontré quelques problèmes lors de la réalisation de ce projet.

- Premièrement, les fonctions permettant de déplacer le plateau de jeu ont été difficiles à implanter car l'algorithme nécessaire est le plus complexe du projet.
- La bibliothèque `ncurses` ne fonctionnait pas correctement pour Parsa et pas du tout pour Victor, d'où le choix de ne pas l'utiliser et utiliser des caractères d'échappement ANSI et la fonction `system()` de la bibliothèque `cstdlib` pour les couleurs et le rafraîchissement de l'écran.
- La bibliothèque SDL a également posé des problèmes initialement car la procédure à suivre pour l'installer est assez complexe, et la compilation séparée requiert de nombreuses options de compilation (en raison de l'usage de deux bibliothèques) qui ont complexifié l'écriture du Makefile.

*TODO: que nous a appris ce projet ?*

"C++ est un très bon langage, très plaisant, tant qu'il ne s'agit pas de compiler des fichiers" -Victor
