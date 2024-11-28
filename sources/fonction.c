/**
 * @file fonction.c
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief fonction principal du projet.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "../heads/type.h"
#include "../heads/conversion.h"
#include "../heads/sansdecision.h"
#include "../heads/arbre.h"

/**
 * @brief Crée un bouton avec un carré noir rempli et un carré violet au centre
 * 
 * @param x coordonnée x 
 * @param y coordonnée y
 */
void bouton_on(int x, int y){
    MLV_draw_filled_rectangle(x, y, 16, 16, MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle((x + 3), (y + 3), 10, 10, MLV_COLOR_PURPLE);
}
/**
 * @brief Crée un bouton avec un carré noir rempli
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 */
void bouton_off(int x, int y){
    MLV_draw_filled_rectangle(x, y, 16, 16, MLV_COLOR_BLACK);
}
/**
 * @brief Permet de changer l'état d'un bouton.
 * 
 * @param mode état du bouton
 * @param x coordonnée x
 * @param y coordonnée y
 */
void selection_on_off(int *mode, int x, int y){
    switch (*mode){
    case 1:
        bouton_off(x, y);
        break;

    case 2:
        bouton_on(x, y);
        break;

    default:
        break;
    }
}
/**
 * @brief Affichage principal de la fenêtre
 * 
 * @param bouton_1 Bouton voisinage
 * @param bouton_2 Bouton voisinage avec prise de décision
 * @param bouton_3 Bouton voisinage arbre
 * @param bouton_4 Bouton voisinage arbre avec prise de décision
 */
void affichage(int *bouton_1, int *bouton_2,int *bouton_3,int *bouton_4){

    MLV_draw_filled_rectangle(0, 0, X_FENETRE, Y_FENETRE, MLV_COLOR_PURPLE);
    MLV_draw_filled_rectangle(31, 31, 390, 390, MLV_COLOR_GREY);
    MLV_draw_line(31, 225, X_FENETRE - 30, 225, MLV_COLOR_WHITE);
    MLV_draw_line(225, 31, 225, 420, MLV_COLOR_WHITE);
    MLV_draw_text(
        205, 430,
        "reset",
        MLV_COLOR_BLACK);
    MLV_draw_filled_rectangle(175, 425, 100, 25, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(30, 488, 190, 30, MLV_COLOR_YELLOW);

    MLV_draw_filled_rectangle(30, 530, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(230, 488, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(30, 750, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(30, 580, 390, 150, MLV_COLOR_YELLOW);

    MLV_draw_text(
        (X_FENETRE / 2) - 25, 8,
        "KNN-BOY",
        MLV_COLOR_GREEN);

    MLV_draw_text(
        68, 495,
        "MODE : KPPV",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        (X_FENETRE / 2) - 70, 585,
        "OPTIONS D'AFFICHAGE :",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        80, 600,
        "Voisinage",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        80, 630,
        "Avec prise de décision",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        80, 660,
        "Voisinage Arbre",
        MLV_COLOR_BLACK);
    
    MLV_draw_text(
        80, 690,
        "Avec prise de décision Arbre",
        MLV_COLOR_BLACK);

    
    MLV_draw_filled_rectangle 	(230,530,190,30,MLV_COLOR_YELLOW1 ); 	
    MLV_draw_text(
        250, 535,
        "Ajouter point décision",
        MLV_COLOR_BLACK);	

    MLV_draw_filled_rectangle 	(430,0,20,20,MLV_COLOR_YELLOW1 ); 
    
    MLV_draw_line(430 , 0, 450, 20, MLV_COLOR_BLACK);
    MLV_draw_line(430, 20, 450, 0, MLV_COLOR_BLACK);	


    selection_on_off(bouton_1, 60, 600);
    selection_on_off(bouton_2, 60, 630);
    selection_on_off(bouton_3, 60, 660);
    selection_on_off(bouton_4, 60, 690);
    MLV_draw_text(
        80, 758,
        "Sauvegarder",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        250, 495,
        "Valeur de K :",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        43, 535,
        "Supprimer dernier point",
        MLV_COLOR_BLACK);

    MLV_draw_text(
        205, 430,
        "reset",
        MLV_COLOR_BLACK);
}
/**
 * @brief Chargement d'un fichier et met les données dans un tableau de point
 * 
 * @param name nom du fichier à charger
 * @param adresse_tab le tableau de point qui va être rempli
 * @param n nombre de point dans le fichier
 * @param d dimension ici fixée à 2
 * @param c les classes
 */
void chargement_fichier(char *name, point **adresse_tab, int *n, int *d, int *c){   

    int i;
    point *tab;
    /*ouverture du fichier*/
    FILE *fichier = NULL;
    fichier = fopen(name, "r+");
    if (fichier == NULL){   
        printf("\n\n*******************************\n\n      Fichier inexistant\n\n*******************************\n\n");
        exit(EXIT_FAILURE);
        
    }
    if (fscanf(fichier, "%d %d %d", n, d, c) != 3){
        fprintf(stderr, "Erreur de lecture du fichier.\n");
    }

    tab = (point *)malloc((*n) * sizeof(point));
    for (i = 0; i < (*n); i++){
        if (fscanf(fichier, "%d %f %f", &(tab[i].classe), &(tab[i].x), &(tab[i].y)) != 3){
            fprintf(stderr, "Erreur de lecture du fichier.\n");
        }
    }
    *adresse_tab = tab;

    fclose(fichier);
}
/**
 * @brief Chargement d'un fichier et rentre les données dans un tableau de sauvegarde de type save
 * 
 * @param name nom du fichier à charger
 * @param accu nombre de point dans le fichier
 * @return save* 
 */
save *chargement_fichier_bis(char *name, int *accu)
{
    int i;
    int newx, newy;
    int n, d, c;
    save *tab;
    point *tab1;

    FILE *fichier = NULL;
    fichier = fopen(name, "r+");
    if (fichier == NULL){
        fprintf(stderr,"Fichier inexistant\n");
        exit(EXIT_FAILURE) ;
    }
    if (fscanf(fichier, "%d %d %d", &n, &d, &c) != 3){
        fprintf(stderr, "Erreur de lecture du fichier.\n");
    }

    tab = (save *)malloc((n) * sizeof(save));
    tab1 = (point *)malloc((n) * sizeof(point));

    for (i = 0; i < n; i++){
        if (fscanf(fichier, "%d %f %f", &(tab1[i].classe), &(tab1[i].x), &(tab1[i].y)) != 3){
            fprintf(stderr, "Erreur 2de lecture du fichier.\n");
        }
        conversion_vers_pixel(tab1[i].x, tab1[i].y, &newx, &newy);
        tab[i].classe = (tab1[i].classe);
        tab[i].x = newx;
        tab[i].y = newy;
    }

    fclose(fichier);
    *accu = n+1 ;
    return tab;
}
/**
 * @brief Charge un fichier et renvoie un tableau de point
 * 
 * @param name nom du fichier à charger
 * @param accu nombre de point dans le fichier
 * @return point* 
 */
point *chargement_fichier_point(char *name, int *accu)
{
    int i;
    int n, d, c;
    point *tab1;

    FILE *fichier = NULL;
    fichier = fopen(name, "r+");
    if (fichier == NULL){
        fprintf(stderr,"Fichier inexistant !\n");
        exit(EXIT_FAILURE);

    }
    if (fscanf(fichier, "%d %d %d", &n, &d, &c) != 3){
        fprintf(stderr, "Erreur de lecture du fichier.\n");
    }

    tab1 = (point *)malloc((n) * sizeof(point));

    for (i = 0; i < n; i++){
        if (fscanf(fichier, "%d %f %f", &(tab1[i].classe), &(tab1[i].x), &(tab1[i].y)) != 3){
            fprintf(stderr, "Erreur 2de lecture du fichier.\n");
        }
    }
    fclose(fichier);
    *accu = n ;
    return tab1;
}
/**
 * @brief Cette fonction permet d'afficher les points du tableau de point en fonction de la classe
 * 
 * @param n nombre de point
 * @param tab tableau de point
 */
 
void Affiche_point(int n, point *tab){
    int i;
    int c;
    int x, y;
    float xbis, ybis;

    for (i = 0; i < n; i++){
        c = tab[i].classe;

        switch (c){
        case 1:
            xbis = tab[i].x;
            ybis = tab[i].y;
            conversion_vers_pixel(xbis, ybis, &x, &y);

            MLV_draw_line(x - 2, y - 2, x + 2, y + 2, MLV_COLOR_RED);
            MLV_draw_line(x - 2, y + 2, x + 2, y - 2, MLV_COLOR_RED);
            break;
        case 2:
            xbis = tab[i].x;
            ybis = tab[i].y;
            conversion_vers_pixel(xbis, ybis, &x, &y);

            MLV_draw_line(x - 2, y, x + 2, y, MLV_COLOR_BLUE);

            break;
        default:
            fprintf(stderr,"La classe n'est pas reconnue : %d", c);
        }
    }
}
/**
 * @brief Permet d'afficher les points du tableau de sauvegarde en fonction de la classe
 * 
 * @param n nombre de point
 * @param tab tableau de save
 */
 
void Affiche_save(int n, save *tab){
    int i;
    int c;
    int x, y;

    for (i = 0; i < n; i++){
        c = tab[i].classe;

        switch (c){
        case 1:
            x = tab[i].x;
            y = tab[i].y;

            MLV_draw_line(x - 2, y - 2, x + 2, y + 2, MLV_COLOR_RED);
            MLV_draw_line(x - 2, y + 2, x + 2, y - 2, MLV_COLOR_RED);
            break;
        case 2:
            x = tab[i].x;
            y = tab[i].y;

           MLV_draw_line(x - 2, y, x + 2, y, MLV_COLOR_BLUE);
            break;
        default:
            printf("La classe n'est pas reconnue : %d", c);
        }
    }
    MLV_actualise_window();
}

/**
 * @brief Interface graphique pour le mode creation
 * 
 * @param nomfichier nom du fichier si il y a chargement
 * @param classeselection la classe selectionné
 */
void mode_crea(char *nomfichier, int *classeselection){
    point *tab = NULL;
    int n, d, c;
    char nb[20];
    sprintf(nb, "%d", *classeselection);
    MLV_draw_filled_rectangle(5, 2, 100, 20, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(30, 488, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(230, 530, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_filled_rectangle(230, 750, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_text(7, 5, "Retour KPP-V", MLV_COLOR_BLACK);
    MLV_draw_text(255, 760, "Chargement fichier", MLV_COLOR_BLACK);
    MLV_draw_text(
        68, 495,
        "Mode : Création",
        MLV_COLOR_BLACK);
    MLV_draw_text(285, 537, "Classe : ", MLV_COLOR_BLACK);
    MLV_draw_text(345, 537, nb, MLV_COLOR_BLACK);
    chargement_fichier(nomfichier, &tab, &n, &d, &c);
    Affiche_point(n, tab);
    MLV_actualise_window();
}

/**
 * @brief Menu permettant de charger un fichier
 * 
 * @param nomfichier Le fichier à charger
 * @param bouton_1 état du bouton 1
 * @param bouton_2 état du bouton 2
 * @param bouton_3 état du bouton 3
 * @param bouton_4 état du bouton 4
 * @param classeselection la classe selectionnée
 * @param ANAIS tableau de save
 * @param TOONS tableau de point
 * @param TOLGA arbre kd
 * @param accu nombre de point
 */
void chargement_fichier_bouton(char *nomfichier, int *bouton_1, int *bouton_2,int *bouton_3,int *bouton_4, int *classeselection, save **ANAIS, point **TOONS,arbre_kd *TOLGA, int *accu){
    char nb[20];
    sprintf(nb, "%d", *classeselection);
    MLV_clear_window(MLV_COLOR_ANTIQUE_WHITE); 
    MLV_actualise_window();
    MLV_draw_filled_rectangle(0, 0, 450, 800, MLV_COLOR_PURPLE4);
    MLV_draw_text(150, 10, "Chargement de fichier :", MLV_COLOR_BLACK);
    MLV_wait_input_box(
        0, 200,
        450, 500,
        MLV_COLOR_YELLOW, MLV_COLOR_BLACK, MLV_COLOR_YELLOW,
        "Nom du fichier : ",
        &nomfichier);
    affichage(bouton_1, bouton_2, bouton_3, bouton_4);
    mode_crea(nomfichier, classeselection);
    *ANAIS = chargement_fichier_bis(nomfichier, accu);
    *TOONS = chargement_fichier_point(nomfichier, accu);
    *TOLGA = chargement_fich(nomfichier, accu);
}

/**
 * @brief Permet de changer la classe selectionnée (entre 1 et 2)
 * 
 * @param classe classe à changer
 */
void classe_changement(int *classe){
    char *new_classeselection;
    int k;
    MLV_wait_input_box(
        285, 537,
        100, 20,
        MLV_COLOR_YELLOW, MLV_COLOR_BLACK, MLV_COLOR_YELLOW,
        "Classe : ",
        &new_classeselection);
    k=atoi(new_classeselection);
    if(k>2 || k==0){
        MLV_draw_text(150,460,"Classe autorisé : 1 ou 2",MLV_COLOR_ALICEBLUE);
    }else{
        *classe = k;
    }
}

/**
 * @brief Affichage de la classe selectionnée
 * 
 * @param classeselection la classe actuelle
 */
void update_classe(int *classeselection){
    char nb[20];
    sprintf(nb, "%d", *classeselection);
    MLV_draw_filled_rectangle(230, 530, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_text(285, 537, "Classe : ", MLV_COLOR_BLACK);
    MLV_draw_text(345, 537, nb, MLV_COLOR_BLACK);

    MLV_actualise_window();
}

/**
 * @brief Permet de changer le nombre de voisins proches
 * 
 * @param kselection la valeur de k qui va changer
 */
void k_changement(int *kselection){
    char *new_kselection;
    MLV_wait_input_box(
        250, 495,
        100, 20,
        MLV_COLOR_YELLOW, MLV_COLOR_BLACK, MLV_COLOR_YELLOW,
        "Valeur K: ",
        &new_kselection);
    *kselection = atoi(new_kselection);
}
/**
 * @brief Affichage de la valeur de k.
 * 
 * @param kselection le k actuel.
 */
void update_k(int *kselection){
    char nb[20];
    sprintf(nb, "%d", *kselection);
    MLV_draw_filled_rectangle(230, 488, 190, 30, MLV_COLOR_YELLOW);
    MLV_draw_text(250, 495, "Valeur K : ", MLV_COLOR_BLACK);
    MLV_draw_text(320, 495, nb, MLV_COLOR_BLACK);

    MLV_actualise_window();
}
/**
 * @brief Permet de supprimer le dernier point et de faire l'affichage sans
 * 
 * @param n nombre de point
 * @param sauvegarde tableau contenant les points
 */
void supprimer_dernier_point(int n, save *sauvegarde){
    MLV_draw_filled_rectangle(31, 31, 390, 390, MLV_COLOR_GREY);
    MLV_draw_line(31, 225, X_FENETRE - 30, 225, MLV_COLOR_WHITE);
    MLV_draw_line(225, 31, 225, 420, MLV_COLOR_WHITE);
    Affiche_save(n - 1, sauvegarde);
    MLV_actualise_window();
}


