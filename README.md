# TP5_SMA
## Introduction 


Cette simulation s'inspire du jeux vidéo `Civilisation`. Le but est d'observer l'évolution de deux villes suivant différentes caractéristiques. Chaque ville contient des personnages masculins qui vont collecter des ressources dans le but de nourrir la ville et d'améliorer un hotel de ville et des personnages féminins qui peuvent donner naissance à des enfants. La puissance d'une ville se constate grâce au niveau de l'hôtel de ville.   

## Organisation des fichiers
* Le dossier `src` contient les fichiers sources `.cpp`.
* Le dossier `header` contient les fichiers `.hpp`.
* Le dossier `CHARACTERS` contient un fichier `.json` qui contient les personnages que vous pouvez choisir avec différentes caractéristiques.
* Le dossier `MAPS` contient un fichier `.json` qui contient les points de collectes de ressources que vous pouvez choisir.
* Le dossier `CONFIGURATIONS` contient un fichier `.json` qui contient des configurations de base que vous pouvez choisir. La config 1 est une config réaliste, la 2 permet d'accelerer la simulation.
* Le dossier compressé `Documentation_TP5_SMA.rar` contient la documentation générée à l'aide de l'outil `Doxygen` sous forme d'un site internet. Lancer le fichier `index.html` pour ouvrir un navigateur internet et visualiser la documentation. 

## MakeFile
* Compiler le programme avec `make`.
* Pour utiliser l'outil `cppcheck` utiliser la commande `make check`.
* Vous pouvez supprimer tous les fichiers de compilation avec `make clean`.
* Pour compiler et lancer la simulation, utiliser la commande `make run`.

## Simulation
* Lancer la simulation avec `./exe`
* Remarque : Il n'y a pas de fichier `main.cpp`. Les tests unitaires et le lancement du jeu se trouvent dans le fichier `tests_catch.cpp`. Le "main" est le dernier test unitaire.
* Le tests unitaires pour la gestion des exceptions est à la ligne `515`. Certains tests sont en commentaire car le lancement de l'exception provoque des fuites mémoire au niveau de valgrind. Vous pouvez les décommenter pour voir le bon fonctionnement.

BONNE SIMULATION
Gladieux Cunha Dimitri & Gonzales Florian
