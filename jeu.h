//
// Created by eliot on 23/05/2021.
//

#ifndef REPUISSANCEN_JEU_H
#define REPUISSANCEN_JEU_H

typedef struct{
    char** grille;  ///tableau de caractères
    int hauteur;
    int largeur;
}Grid;

///choix de la premier action (créer ou charger une partie et quitter)
int start (int *d);

///question de démarage d'une partie en fonction si c'est une partie créé ou chargé
void new_game(int *n_j, int *j, int *nb_j, int *ordi, int *player, int debut, int *az);

///création de la taille de la grille souhaitée
void show_grid(Grid *g1, int n_j);

///défini une action à réaliser "ajouter" ou "retirer" un jeton
int choose_action(Grid *g1, int j, int *a, char *jt, int *c, int *n, int player, int ordi);

///Placement du jeton sous certaines conditions
int add_token(Grid* g1, int c, char jt, int *n);

///On retire un jeton sous certaines conditions
int remove_token(Grid *g1, int c);

///Affiche la nouvelle grille avec les jetons ajoutés ou retirés à chaque tours
void show_new_grid(Grid *g1);

///regarde dans chaque direction à partir du dernier jeton posé
int check_direction(Grid *grille,int ligne,int colonne,int dir_x,int dir_y,char token);

///Vérifie si "check_direction" a retourné 1 et affiche le message de victoire en fonction
int check_winner(Grid *grille,char token, int az, int nb_j);

///en fonction du nombre de joueur, lance "choose_action" ou joue aléatoirement pour l'ordinateur
void jeu(int nb_joueur, int *ordi, int *c, int *j, char *jt, Grid *g1, int *action, int player, int *n, int az);

///Vérifie à chaque tour si la grille est vide pour ne pas proposer le choix de retirer un jeton
int Verification(Grid *g1);

///sauvegarde du fichier dans un fichier texte avec comme info la la taille de la grille, le dernier tour joué, qui a commencé et le compteur de l'ordi(pour une potentiel amélioration)
int save(Grid *g1, int j, int player, int ordi);

///reprise des valeurs sauvegardées
int load(Grid *g1, int *j, int *player, int *ordi);

///libère les malloc
void libre(Grid *g1);

///message de victoire
void victory(int nb_j, int az, char token);

///ajout jeton pour le bot
void bot_add(Grid *g1, int *c, int j, int player, char *jt, int *n);

#endif //REPUISSANCEN_JEU_H