#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"

int main() {

    srand(time(NULL));

    char r;     ///variable pour recommencer

    do{
        Grid g1;    ///création du tableau de jeu

        int debut=0;    ///choix de la premier action (créer ou charger une partie et quitter)
        int nb_jetons = 0;  ///nombre de jetons à aligner pour gagner
        int nb_joueur = 0;  ///nombre de joueur
        int ordi = 0;   ///incrémentation pour que l'ordi joue 1 tour sur 2
        int j = 0;  ///incrémentation pour savoir qui à joué et donc de savoir quel jeton mettre dans le tableau
        int start_win = 0;     ///variable prenant une valeur seulement lors du lancement d'une nouvelle partie afin de savoir qui a commencé à jouer (Rouge ou Jaune) pour ensuite en déterminer l'affichage des victoires
        int action=0;   ///premet de choisir quelle action le pragramme va t-il exécuter (ajouter, retirer,...)
        char jt;    ///le caractère du jeton
        int c;  ///indice de la colonne choisie lors d'un action
        int player = 0;     /// 0 ou 1 pour savoir qui joue en premier le joueur 1 ou 2(ou l'ordi)
        int n = 99;     ///permet de prendre la valeur de la colonne choisie lorsque l'utilisateur retire un jeton pour esnuite empêcher l'autre d'en reposer un au même endroit

        debut = start(&debut); ///fonction contenant les choix de la premier action (créer ou charger une partie et quitter)

        if (debut == 3){    ///si l'action choisie est quitter

            return 0;

        }else if (debut == 1) {    ///si l'action choisie est créer

            new_game(&nb_jetons, &j, &nb_joueur, &ordi, &player, debut, &start_win);

            show_grid(&g1, nb_jetons);

            jeu(nb_joueur, &ordi, &c, &j, &jt, &g1, &action, player, &n, start_win);

        }else if (debut == 2){    ///si l'action choisie est charger

            if(load(&g1, &j, &player, &ordi) == 0){
                printf("Le fichier a rencontre un probleme lors du chargement.\n");
            }else{
                new_game(&nb_jetons, &j, &nb_joueur, &ordi, &player, debut, &start_win);

                jeu(nb_joueur, &ordi, &c, &j, &jt, &g1, &action, player, &n, start_win);
            }

        }

        libre(&g1); ///fonction permettant de libérer les malloc

        getchar();  ///prend le caractère "Enter"
        do{
            printf("\n//\tFIN DE PARTIE. Voulez-vous rejouer ? (O/N)\t//\n");
            gets(&r);
        }while (r != 'O' && r != 'N');

    }while(r != 'N');   ///recommence tant que la variable "r" est "O"

    return 0;
}