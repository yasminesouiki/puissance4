# puissance4
## explication :
Ce programme implémente une version simple et efficace du jeu Puissance 4 en utilisant les caractères X et O pour représenter les pions des deux joueurs. Le plateau est modélisé sous la forme d'une matrice 2D de caractères, où chaque case est initialisée avec un point (.) pour indiquer qu'elle est vide.

Les fonctions principales comprennent :
1- initializeBoard :
Cette fonction remplit la matrice avec des points (.), représentant un plateau vide.
2- printBoard :
Elle affiche l’état actuel du plateau, ainsi que les numéros des colonnes pour guider les joueurs.
3- dropDisc : 
Elle permet à un joueur de placer son pion dans une colonne choisie, en vérifiant d'abord si la colonne est valide et non pleine. Le pion tombe toujours dans la position la plus basse disponible de la colonne.
4- checkVictory : 
Cette fonction vérifie si un joueur a aligné quatre pions consécutifs horizontalement, verticalement ou en diagonale, signalant ainsi une victoire.
5- Alternance des joueurs :
Les joueurs jouent à tour de rôle en entrant un numéro de colonne. Si un joueur aligne quatre X ou O, il est déclaré vainqueur. Si le plateau est plein sans victoire, le jeu se termine sur un match nul.
