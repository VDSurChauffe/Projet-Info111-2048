# Rapport de projet 2048

## Auteurs

- DAVIAU Victor, victor.daviau@etu-upsaclay.fr (LDD1-IM2)
- FARJAM Parsa, parsa.farjam@etu-upsaclay.fr (LDD1-IM2)


## Résumé du travail effectué

*Pour les questions «Aller plus loin» plus ouvertes, décrivez plus en détail ce que vous avez choisi de réaliser. Précisez les difficultés rencontrées, les choix d'implantation que vous avez fait, etc.*

*En plus du rapport, la documentation de chaque fonction dans le code devra préciser son auteur et votre degré de confiance dans l'implantation, ainsi que les éléments factuels motivant cette confiance: présence de tests, bogues et limitations connus, etc.*

### Niveau 0
- Jeu fonctionnel et complet :

Nous avons écrit quelques fonctions en plus de celles déjà présentes dans le sujet, pour permettre d'effectuer des tests automatiques et faciliter les calculs dans certaines fonctionnalités.

Toutes les fonctions sont documentées et ont été testées, presque toutes sont également testées automatiquement par ``tests()``, et certaines sont commentées pour clarifier leur fonctionnement.

Le jeu fonctionne parfaitement, respecte les règles de 2048, execute correctement les instructions de l'utilisateur, ignore les instructions incorrectes

### Niveau 1
- Couleurs : contenues dans l'interface graphique et dans l'interface terminal avec les caracteres d'echappement ANSI
- Mouvement avec les flèches seules : fait avec l'UI graphique, et le jeu permet de choisir le mode de contrôles (ZQSD ou WASD)
- Ecraser l'affichage à chaque mouvement : marche sur l'interface graphique, sur l'interface terminale avec la bibliothèque ```cstdlib``` et la commande ```clear``` au console.
- Calcul de score par une fonction : fait, cependant la fonction requiert un argument suppémentaire (une variable dans ``main()``)pour tenir compte du fait que les 4 apparus naturellement rapportent moins

### Niveau 2
- Utiliser un Makefile : Fait
- Utiliser un gestionnaire de version : fait avec [un repo GitHub](https://github.com/VDSurChauffe/Projet-Info111-2048/)

### Niveau 3
- créer une IA : non-traité
- ajouter des variantes : non-traité
- avoir une interface graphique : fait
- en faire une application pour téléphone : non traité


## Démonstration

*Soutenez ce que vous affirmez dans la section précédente au moyen de quelques exemples **bien choisis**. Vous pouvez par exemple compiler et lancer certains de vos programmes, lancer des tests, etc.*

*Ne gardez que des exemples pertinents qui mettent en valeur votre travail. Inutile de perdre du temps sur le premier programme si vous avez fait les suivants plus compliqués; l'auditeur se doutera bien que vous avez réussi à le faire.*


## Organisation du travail

*Décrivez en quelques phrases comment vous vous êtes organisés pour travailler sur le projet: nombre d'heures consacrées au projet, répartition du travail dans le binôme, moyens mis en œuvre pour collaborer, etc. Si vous avez bénéficié d'aide (en dehors de celle de vos enseigants), précisez le.*

Nous avons utilisé GitHub pour échanger nos progrès sur le jeu, avec un repo GitHub géré par Victor. On a utilisé des Pull Requests pour gérer les merges à la branche main, et des branches separées pour nos travaux.

Nous avons chacun travaillé (principalement en collaborant en temps réel) *environ 20-30 heures **actuellement.**

## Prise de recul

*Décrivez en quelques phrases les difficultés rencontrées, ce que vous avez appris à l'occasion du projet, le cas échéant comment vous vous y prendriez si vous aviez à le refaire.*

La bibliothèque ```ncurses``` ne fonctionnait pas correctement pour Parsa et pas du tout pour Victor, d'où le choix de ne pas l'utiliser et utiliser des caractères d'échappement ANSI et la fonction ```system()``` de la bibliothèque ```cstdlib``` pour les couleurs et le rafraîchissement de l'écran.
