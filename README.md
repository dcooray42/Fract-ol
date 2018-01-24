# Fract-ol

Deuxième projet de la branche graphique de l'école 42. Créer un programme qui affiche des fractales avec lesquelles 
on peut intéragir.

## Pour commencer

Ces instructions vous aiderons a avoir une copie du projet et de pouvoir le faire marcher sur votre ordinateur.

### Prérequis

#### Systeme d'exploitation

```
macOS Sierra
```

#### Téléchargement

Ce que vous devez faire pour télécharger les fichiers sources afin de pouvoir les compiler par la suite

```
git clone https://github.com/konamifox/Fract-ol.git [nom du PATH/dossier]
```

### Installation

Se placer dans le dossier dans lequel vous avez fait la copie des fichiers sources du projet puis rentrer la commande suivante

```
make
```
Plusieurs fichiers .o auront fait leur apparitions dans le dossier que vous avez cloné ainsi que le binaire

```
fractol
```
### Suppression

Pour supprimer les fichiers objets .o généré lors de la création du programme

```
make clean
```

Pour supprimer les fichiers objets .o et le programme

```
make fclean
```

Pour tout supprimer puis recompiler le programme

```
make re
```

## Faire des tests

Une fois que le programme a été crée, vous n'avez plus qu'à rentrer en ligne de commande le nom du programme + un nombre 
compris entre 1 et 4 correspondant à une fractale.

### Utilisation du programme

Ligne de commande

```
./fractol [nombre]
```

| Nombre |   Fractale   |
| ------ |:------------ |
|    1   | Mandelbrot   |
|    2   | Julia        |
|    3   | Burning ship |
|    4   | Multibrot    |

Le programme peut afficher les 4 fractales simultanément.

### Commandes

|          Touche         |                    Action                     |
| ----------------------- |:--------------------------------------------- |
| Flèches directionnelles | Déplacement                                   |
| Pavé numérique 1        | Changer de couleur                            |
| Pavé numérique 4        | Changer de couleur                            |
| Pavé numérique +        | Augmenter exposant (multibrot)                |
| Pavé numérique -        | Diminuer exposant (multibrot)                 |
| C                       | Changer les paramètres de l'ensemble (souris) |
| R                       | Réinitialiser les paramètres de la fractale   |
| Molette souris          | Zoom                                          |

#### Exemple
![alt text](https://raw.githubusercontent.com/konamifox/photo/master/Fractol.jpeg?token=AT6ePPXndZr_V9s0HgGJfDy75dVtQkgiks5acdrgwA%3D%3D)

## Compiler avec
* Minilibx - Librairie graphique

## Licence
* Minilibx - License BSD: Copyright Olivier Crouzet - 2014

## Auteur

* **Dimitri Cooray** - [Lien vers github](https://github.com/konamifox)
