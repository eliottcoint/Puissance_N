//
// Created by eliot on 23/05/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jeu.h"

int start (int *d){

    printf("\nBienvenue dans notre jeu: PuissanceN !\n\n");

    printf("Regles :\n\t- Avant de commencer, si vous voulez jouer a deux, definissez entre vous qui sera le joueur 1 et le joueur 2.\t\t(Attention, etre le joueur 1 ne veut pas dire que vous commencerez en premier).\n\t- A chaque tour, il vous sera demande d'ajouter, de retirer, ou de sauvegarder et de quitter.\n\t\tChoisissez l'action que vous souhaitez.\n\t- Pour gagner, il suffit juste d'aligner un certain nombre de jetons (defini plus tard)\n\t\tdans n'importe quel sens (ligne, colonne et diagonale).\n\n\t\t//\tBON JEU !\t//\n\n");

    do{
        printf("Que voulez-vous faire ? (tapez le chiffre correspondant a l'action voulu)\n\t1- Demarrer une nouvelle partie\n\t2- Charger une partie existante\n\t3- Quitter\n");
        scanf("%d", d);
    }while(*d != 1 && *d != 2 && *d != 3);

    return *d;  ///retourne la valeur choisie par l'utilisateur
}

void new_game(int *n_j, int *j, int *nb_j, int *ordi, int *player, int debut, int *az){

    int couleur_joueur;    ///choix de la couleur du joueur qui commence
    char j1[6], j2[6];  ///tableau comprenant la couleur de chaque joueurs
    char t1, t2;    ///tableau comprenant le jeton de chaque joueurs

    if (debut == 1){    ///si l'action choisie est créer une parite
        do {
            printf("\nNouvelle partie:\nCombien de joueurs joueront ? (1 ou 2)\n");
            scanf("%d", nb_j);
        } while (*nb_j != 1 && *nb_j != 2);     ///nombre de joueur enter 1 et 2

        do {
            printf("Combien de jetons N devront-etre alignes pour gagner ? (entre 3 et 10)\n");
            scanf("%d", n_j);
        } while (*n_j < 3 || *n_j > 10);    ///permet ensuite de determiner la taille su tableau dans une autre fonction

        couleur_joueur = rand() % 2;    ///création d'une variable aléatoire choisissant si le joueur 1 aura la couleur Rouge ou Jaune (de même en opposé pour le joueur 2(ou ordinateur))

        if (couleur_joueur == 1) {
            strcpy(j1, "Rouge");
            strcpy(j2, "Jaune");
            *j = 0;     ///variable incrémenté dans une autre fonction servant à identifier qui vient de jouer
            *az = 0;    ///variable servant pour le texte de victoire
        } else {
            strcpy(j1, "Jaune");
            strcpy(j2, "Rouge");
            *j = 1;
            *az = 1;
        }

        if (*nb_j == 1){    ///différent textes des différents cas en fonction du nombre de joueurs
            *ordi = rand()%2;    ///création d'une variable aléatoire choisissant si c'est l'ordi ou le jouer 1 qui commence
            *player = *ordi;
            if (*j == 0){   ///reprise de la variable j incrémenté plus haut pour savoir l'ordre des couleur
                if (*ordi == 0){
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'X'.\t//\n//\tL'ordinateur aura la couleur %s et le jeton 'O'.\t//\n\nLe joueur 1 commence.\n\n", j1, j2);
                }else{
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'X'.\t//\n//\tL'ordinateur aura la couleur %s et le jeton 'O'.\t//\n\nL'ordinateur commence.\n\n", j1, j2);
                }
            }else if (*j != 0){
                if (*ordi == 0){
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'O'.\t//\n//\tL'ordinateur aura la couleur %s et le jeton 'X'.\t//\n\nLe joueur 1 commence.\n\n", j1, j2);
                }else{
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'O'.\t//\n//\tL'ordinateur aura la couleur %s et le jeton 'X'.\t//\n\nL'ordinateur commence.\n\n", j1, j2);
                }
            }

        } else if (*nb_j == 2){
            *player = rand()%2;
            if (*j == 0){
                if (*player == 0){
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'X'.\t//\n//\tLe joueur 2 aura la couleur %s et le jeton 'O'.\t//\n\nLe joueur 1 commence.\n\n", j1, j2);
                }else {
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'X'.\t//\n//\tLe joueur 2 aura la couleur %s et le jeton 'O'.\t//\n\nLe joueur 2 commence.\n\n", j1, j2);
                }
            }else if (*j != 0){
                if (*player == 0){
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'O'.\t//\n//\tLe joueur 2 aura la couleur %s et le jeton 'X'.\t//\n\nLe joueur 1 commence.\n\n", j1, j2);
                }else{
                    printf("\n//\tLe joueur 1 aura la couleur %s et le jeton 'O'.\t//\n//\tLe joueur 2 aura la couleur %s et le jeton 'X'.\t//\n\nLe joueur 2 commence.\n\n", j1, j2);
                }
            }
        }

    }else if (debut == 2){  ///si l'action choisie est charger une partie
        do {
            printf("\nPartie chargee:\nCombien de joueurs joueront ? (1 ou 2)\n");
            scanf("%d", nb_j);
        } while (*nb_j != 1 && *nb_j != 2);

        if (*player == 0){  ///amélioration du code de la section précédente mais avec quelque modification de condition car on reprend les caractères chargés dans le fichier texte afin de reprendre là où l'on s'était arrêté. Juste l'association du joueur avec sa couleur précédente peut-être différentes, mais l'ordre des tours est conservé
            if (*j % 2 == 0){
                strcpy(j1, "Rouge");
                strcpy(j2, "Jaune");
                t1 = 'X';
                t2 = 'O';
            }else{
                strcpy(j1, "Jaune");
                strcpy(j2, "Rouge");
                t1 = 'O';
                t2 = 'X';
            }
        } else {
            if (*j % 2 != 0){
                strcpy(j1, "Jaune");
                strcpy(j2, "Rouge");
                t1 = 'O';
                t2 = 'X';
            }else{
                strcpy(j1, "Rouge");
                strcpy(j2, "Jaune");
                t1 = 'X';
                t2 = 'O';
            }

        }

        if (*nb_j == 1){
            if (*player == 0){
                printf("\n//\tLe joueur 1 aura la couleur %s et le jeton '%c'.\t//\n//\tL'ordinateur aura la couleur %s et le jeton '%c'.\t//\n\nLe joueur 1 commence.\n\n", j1, t1, j2, t2);
            }else {
                printf("\n//\tLe joueur 1 aura la couleur %s et le jeton '%c'.\t//\n//\tL'ordinateur aura la couleur %s et le jeton '%c'.\t//\n\nL'ordinateur commence.\n\n", j2, t2, j1, t1);
            }
        } else if (*nb_j == 2){
            if (*player == 0){
                printf("\n//\tLe joueur 1 aura la couleur %s et le jeton '%c'.\t//\n//\tLe joueur 2 aura la couleur %s et le jeton '%c'.\t//\n\nLe joueur 1 commence.\n\n", j1, t1, j2, t2);
            }else{
                printf("\n//\tLe joueur 1 aura la couleur %s et le jeton '%c'.\t//\n//\tLe joueur 2 aura la couleur %s et le jeton '%c'.\t//\n\nLe joueur 2 commence.\n\n", j1, t1, j2, t2);
            }
        }
    }
}

void show_grid(Grid *g1, int n_j){  ///affiche une seul fois le tableau et le dimensionne

    g1->hauteur = n_j + 2;  ///création de la hauteur de la grille (nombre de ligne) en fonction des caractéristiques choisie par l'utilisateur
    g1->largeur = n_j + 2;  ///création de la largeur de la grille (nombre de colonne) en fonction des caractéristiques choisie par l'utilisateur

    g1->grille = (char**) malloc(sizeof(int*) * g1->largeur);    ///défini la taille du tableau dinamique grille en fonction des précédentes valeurs

    printf("\n(numero des colonnes)\n");
    for(int a = 0; a< g1->largeur; a++) {
        printf("%d. ",a+1);
    }

    printf("\n");
    for(int i = 0; i < g1->largeur; i++) {

        g1->grille[i] = (char*) malloc(sizeof(int) * g1->hauteur);

        printf("\n");

        for(int j = 0; j< g1->hauteur; j++) {

            g1->grille[i][j] = '_';
            printf("%c  ", g1->grille[i][j]);
        }
    }

    printf("\n\n");
}

int add_token(Grid* g1, int c, char jt, int *n){

    int a=0;

    if(g1->grille[c][0] == '_' && c != *n){   ///vérification colonne pleine ou colonne ayant retiré un jeton au précédent tour
        while(a < g1->hauteur && g1->grille[c][a] == '_'){      ///permet au jeton de "tomber" dans la colonne désiré
            a++;
        }
        g1->grille[c][a-1] = jt;    ///place le jeton dans la place "-1" car sur la place "a" se situe soit un autre jeton soit c'est la fin du tableau
        *n = 99;
        return 1;
    }else if (g1->grille[c][0] != '_') {    ///si toutes les cases de la colonne sont déjà prisent
        printf("La colonne choisi est pleine.\n");
        return 0;
    }else{    ///si un jeton vient d'être retiré dans cette colonne
        printf("Un jeton vient d'etre retire dans cette colonne, vous ne pouvez pas en ajouter un ici.\n\n");
        return 0;
    }
}

int remove_token(Grid *g1, int c){

    int a=0;

    while(a < g1->hauteur && g1->grille[c][a] == '_'){    ///vérification colonne vide
        a++;
    }
    if(a < g1->hauteur){
        g1->grille[c][a] = '_';     ///place le symbole "_" sur le premier jeton rencontré dans la colonne
        return 1;
    }else{
        printf("La colonne choisi est vide.\n");
        return 0;
    }
}

void show_new_grid(Grid *g1){

    printf("\n");
    for(int i = 0; i< g1->hauteur; i++) {
        printf("%d. ",i+1);
    }

    printf("\n");
    for(int z = 0; z < g1->hauteur; z++) {  ///double boucle permettant d'afficher la nouvelle grille de jeu à chaque tour
        printf("\n");
        for(int e = 0; e< g1->largeur; e++) {
            printf("%c  ", g1->grille[e][z]);
        }
    }

    printf("\n\n");

}

int check_direction(Grid *g1, int ligne, int colonne, int dir_x, int dir_y, char token) {

    int compteur=0;

    if(dir_x == 0 && dir_y == 0){    /// Cette condition permet de ne pas compter plusieurs fois le même jeton.
        return 0;
    }

    while(ligne < g1->hauteur && ligne >= 0 && colonne >= 0 && colonne < g1->largeur && g1->grille[ligne][colonne] == token && compteur < g1->hauteur - 2 ){    ///Cette condition continue lorsque l'on ne sort pas du tableau, ou que l'on attend le bon nombre de jeton à aligné ou que le jeton est different.
        compteur++;
        ligne = ligne + 1 * dir_y;
        colonne = colonne + 1 * dir_x;
    }

    if(compteur == g1->hauteur - 2){    /// Ce if est vérifié lorsque le compteur attends le bon nombre de jetons alignés.
        return 1;
    }else{
        return 0;
    }


}

int check_winner(Grid *grille, char token, int az, int nb_j){

    for(int l=0; l < grille->largeur; l++) {    ///double boucle pour vérifier tout le tableau
        for(int h= 0; h < grille->hauteur; h++){
            if(grille->grille[l][h] != '_'){    /// Cette condition est vérifiée lorsqu'il y'a un jeton dans une case du tableau.
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {    /// Ici ce double for va permettre de regarder l'alignement des jetons dans toutes les 8 directions autour d'un jeton du tableau.
                        if(check_direction(grille, l, h, x, y, grille->grille[l][h]) == 1){    ///Cette condition est vérifiée lorsque check direction est validé, donc quand le bon nombre de jeton est aligné.

                            victory(nb_j, az, token);    ///affichage du message de victoire

                            return 1;
                        }
                    }
                }
            }
        }
    }

    ///check de l'égalité
    int ct_colonne = 0;

    while(ct_colonne < grille->largeur && grille->grille[ct_colonne][0] != '_'){  ///vérification pour savoir si il y a bien que des jetons sur la première ligne du tableau
        ct_colonne++;
    }

    if (ct_colonne == grille->largeur) {
        printf("\n//\tEgalite parfaite, aucun gagnant.\t//\n");
        return -1;
    }

    return 0;
}

void victory(int nb_j, int az, char token){

    if (nb_j == 2){     ///message de victoire selon différente condition
        if (az == 0){   ///Si c'est Rouge puis Jaune
            if (token == 'X'){      ///en fonction du dernier jeton posé
                printf("\n//\tLe joueur 1 a gagne avec le jeton %c.\t//\n", token);
            }else{
                printf("\n//\tLe joueur 2 a gagne avec le jeton %c.\t//\n", token);
            }
        }else {
            if (token == 'X') {
                printf("\n//\tLe joueur 2 a gagne avec le jeton %c.\t//\n", token);
            } else {
                printf("\n//\tLe joueur 1 a gagne avec le jeton %c.\t//\n", token);
            }
        }
    }else if (nb_j == 1) {
        if (az == 0){
            if (token == 'X'){
                printf("\n//\tLe joueur 1 a gagne avec le jeton %c.\t//\n", token);
            }else {
                printf("\n//\tL'ordinateur a gagne avec le jeton %c.\t//\n", token);
            }
        }else {
            if (token == 'X'){
                printf("\n//\tL'ordinateur a gagne avec le jeton %c.\t//\n", token);
            }else{
                printf("\n//\tLe joueur 1 a gagne avec le jeton %c.\t//\n", token);
            }
        }
    }

}

int choose_action(Grid *g1, int j, int *a, char *jt, int *c, int *n, int player, int ordi){

    if (Verification(g1) == 1) {        ///pose une question spécifique si le tableau est vide ou non
        do {
            printf("Choisissez une action:\n\t1- Ajouter un jeton\n\t3- Sauvegarder et quitter\n");
            scanf("%d", a);
        } while (*a != 1 && *a != 3);
    } else {
        do {
            printf("Choisissez une action:\n\t1- Ajouter un jeton\n\t2- Retirer un jeton\n\t3- Sauvegarder et quitter\n");
            scanf("%d", a);
        } while (*a != 1 && *a != 2 && *a != 3);
    }

    if (*a == 1) {      ///repose une question spécifique en fonction de la réponse à la question précédente. Ici ajout d'un jeton

        do {
            do {
                printf("Dans quelle colonne voulez-vous placer votre jeton ? (entre 1 et %d)\n", g1->largeur);
                scanf("%d", c);
                *c = *c - 1;    ///"-1" car le tableau est entre 0 et ...
            } while (*c > g1->largeur || *c < 0);    ///vérifie que l'utilisateur entre bien une valeur acceptable

            if (j % 2 == 0) {    ///Savoir qui à joué
                if (player == 0){   ///ordre Rouge et Jaune
                    *jt = 'X';
                }else {
                    *jt = 'O';
                }
            } else  if (j % 2 != 0){
                if (player == 0){
                    *jt = 'O';
                }else {
                    *jt = 'X';
                }
            }

        } while (add_token(g1, *c, *jt, n) == 0);    ///recommence tant que l'utilisateur choisi une colonne pleine ou une colonne où l'on a retiré un jeton

    }else if (*a == 2){     ///retirer un jeton

        do {
            do {
                printf("Dans quelle colonne voulez-vous retirer un jeton ? (entrer 1 et %d)\n", g1->largeur);
                scanf("%d",c);
                *c = *c - 1;
                *n = *c;    ///indice de la colonne. On s'en sert pour ne pas ajouter un jeton dans cette colone
            } while (*c > g1->largeur || *c < 0);    ///vérifie que l'utilisateur entre bien une valeur acceptable

        } while (remove_token(g1, *c) != 1);    ///recommence tant que l'utilisateur choisi une colonne pleine

    }else if (*a == 3){     ///sauvegarder et quitter

        if (save(g1, j, player, ordi) == 0){    ///si la sauvegarde rencontre un problème
            printf("Le fichier a rencontre un probleme lors de la sauvegarde.\n");
        }
        return 0;
    }
    return 1;
}

void jeu(int nb_joueur, int *ordi, int *c, int *j, char *jt, Grid *g1, int *action, int player, int *n, int az){

    do {
        if(nb_joueur == 2){     ///si les deux joueurs joue chaque tour
            choose_action(g1, *j, action, jt, c, n, player, *ordi);     ///lancement de la série de question pour chaque joueur

        }else if (nb_joueur == 1){      ///si il n'y a qu'un seul joueur
            if (*ordi % 2 != 0){    ///l'ordi ne joue qu'un tour sur deux

                bot_add(g1, c, *j, player, jt, n);      ///ajout du jeton du bot

            }else if (*ordi % 2 == 0){      ///si c'est pas au tour de l'ordi lorsque qu'il n'y a que 1 joueur
                choose_action(g1, *j, action, jt ,c, n, player, *ordi);
            }
        }

        show_new_grid(g1);

        *j = *j + 1;
        *ordi = *ordi + 1;

    } while (*action != 3 && check_winner(g1, *jt, az, nb_joueur) == 0 );
}

void bot_add(Grid *g1, int *c, int j, int player, char *jt, int *n){

    do {
        *c = rand()%g1->largeur;    ///joue aléatoirement mais peu surprendre parfois

        if (j % 2 == 0) {    ///Savoir qui à joué
            if (player == 0){   ///ordre Rouge et Jaune
                *jt = 'X';
            }else {
                *jt = 'O';
            }
        } else  if (j % 2 != 0){      ///même chose mais en inversé
            if (player == 0){   ///ordre Rouge et Jaune
                *jt = 'O';
            }else {
                *jt = 'X';
            }
        }

    } while (add_token(g1, *c, *jt, n) == 0);   ///tant que l'ajout du jeton est valide

    *n = 99;
}

int Verification(Grid *g1) {

    int v = 0;

    while(v < g1->largeur && g1->grille[v][(g1->hauteur)-1] == '_'){    ///regarde si la dernière ligne du tableau est vide ou non
        v++;
    }

    if (v == g1->largeur) {     ///correspond à un tableau vide
        return 1;
    } else {
        return 0;
    }
}

int save(Grid *g1, int j, int player, int ordi){

    FILE * f;
    f = fopen("Game.txt", "w");     ///création du fichier s'il n'existe pas et écriture dedans


    if (f != NULL){     ///vérification de l'ouverture du fichier

        fprintf(f, "%d %d %d %d", j-1, g1->hauteur, player, ordi);      ///écriture de ces informations

        for(int z = 0; z < g1->hauteur; z++) {      ///même chose pour le tableau
            fprintf(f,"\n");
            for(int e = 0; e< g1->largeur; e++) {
                fprintf(f,"%c", g1->grille[e][z]);
            }
        }

    } else{

        return 0;
    }

    fclose(f);  ///fermeture du fichier

    return 1;
}

int load(Grid *g1, int *j, int *player, int *ordi){

    char tab[256];
    int z = 0;

    FILE * f;
    f = fopen("Game.txt", "r");     ///ouvre le fichier en mode lecture


    if (f != NULL){     ///vérification de l'ouverture du fichier

        fseek(f, 0, SEEK_SET);     ///récupération des informations copier dans le fichier en fonction du placement de chaque caractères
        fscanf(f, "%d", j);
        fseek(f, 2, SEEK_SET);
        fscanf(f, "%d", &g1->hauteur);
        g1->largeur = g1->hauteur;
        fseek(f, 4, SEEK_SET);
        fscanf(f, "%d", player);

        if (*player == 1){
            *player = 0;
        }else{
            *player = 1;
        }

        fseek(f, 6, SEEK_SET);
        fscanf(f, "%d", ordi);
        *ordi = 0;

        g1->grille = (char**) malloc(sizeof(int*) * g1->largeur);    ///redimension du tableau dynamique avec les valeurs trouvées
        for(int i = 0; i < g1->largeur; i++) {
            g1->grille[i] = (char*) malloc(sizeof(int) * g1->hauteur);
        }

        while(fgets(tab,256,f) != NULL){        ///même chose pour le tableau
            for(int e = 0; e < g1->largeur; e++) {
                fscanf(f,"%c",&tab[e]);
                g1->grille[e][z] = tab[e];
            }
            z++;
        }

    } else{

        return 0;
    }

    fclose(f);  ///fermeture du fichier

    show_new_grid(g1);      ///permet d'afficher la grille chargée

    return 1;
}

void libre(Grid *g1){

    for(int i = 0; i<g1->largeur; i++) {    ///libère les malloc

        free(g1->grille[i]);
        g1->grille[i] = NULL;
    }

    free(g1->grille);
    g1->grille = NULL;

}