/**
 * @file main.c
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Elle contient le main.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <time.h>
#include "../heads/conversion.h"
#include "../heads/fonction.h"
#include "../heads/type.h"
#include "../heads/sansdecision.h"
#include "../heads/menu.h"

int main()
{
    int XM, YM;
    save *sauvegarde=NULL;
    int accumulateur = 0;
    int MODE=1;
    FILE *fichier;
    int bouton_1 = 1;
    int bouton_2 = 1;
    int bouton_3 = 1;
    int bouton_4 = 1;
    int supprimer_pts=0;
    int tour=0;
    int POINT_NOIR = 0;
    char *nomfichier="vide.txt";
    int classeselection=1;
    int kselection=1;
    point *TOONS=NULL;
    point_k *TAB_K=NULL;
    arbre_kd TOLGA=NULL;
    point *dernier=NULL;
    point *ajoute_classe_selection=NULL;
    

    ajoute_classe_selection = (point *)malloc(1 * sizeof(point));
    if(ajoute_classe_selection==NULL){
        fprintf(stderr,"Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    } 

    dernier = (point *)malloc(1 * sizeof(point));
    if(dernier==NULL){
        fprintf(stderr,"Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }  
    
    TOONS = (point *)malloc(1 * sizeof(point));
    if(TOONS==NULL){
        fprintf(stderr,"Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    TAB_K = (point_k *)malloc(1 * sizeof(point_k));
    if(TAB_K==NULL){
        fprintf(stderr,"Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    sauvegarde = (save *)malloc(1 * sizeof(save));
    if(sauvegarde == NULL){
        fprintf(stderr," Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    fichier = fopen("save.txt", "r+");
    if (fichier == NULL)
    {
        fprintf(stderr, " Impossible d'ouvrir le fichier.\n ");
    }

    MLV_create_window("KPPV", "shapes", X_FENETRE, Y_FENETRE);
    srand(time(NULL));
    affichage(&bouton_1, &bouton_2,&bouton_3,&bouton_4);
    MLV_actualise_window();   



    do{
        MLV_wait_mouse(&XM, &YM);
        option_bouton(&XM, &YM, &bouton_1, &bouton_2, &bouton_3, &bouton_4, 
        nomfichier,&classeselection,&kselection,&sauvegarde,
        &accumulateur,fichier,&MODE,&TOONS,&TAB_K,&POINT_NOIR,&TOLGA, dernier,ajoute_classe_selection,&supprimer_pts);
    }   while(tour!=2);
    



    MLV_wait_seconds(360);
    free(TOONS);
    TOONS=NULL;
    free(TAB_K);
    TAB_K=NULL;
    free(TOLGA);
    TOLGA=NULL;
    free(dernier);
    dernier=NULL;
    free(ajoute_classe_selection);
    ajoute_classe_selection=NULL;
    MLV_free_window();
    exit(EXIT_SUCCESS);
}
