/**
 * @file sansdecision.c
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief permet de faire les calculs pour le kppv des listes.
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
#include <math.h>
#include "../heads/type.h"
#include "../heads/conversion.h"
#include "../heads/zone.h"

/**
 * @brief Calcul la distance euclidienne entre deux points
 * 
 * @param p1 premier point
 * @param p2 second point
 * @return float 
 */
float distance_points(point p1, point p2){
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    return ((dx * dx + dy * dy) * 0.5);
}

/**
 * @brief Calcul la distance euclidienne entre deux points en pixel
 * 
 * @param p1 premier point
 * @param p2 second point
 * @return int 
 */
int distance_save(point p1, point p2){
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return (int)((dx * dx + dy * dy) * 0.5);
}

/**
 * @brief Conversion de notre tableau de kppv 
 * 
 * @param saves tableau de save
 * @param n nombre de points
 * @param pts tableau de points
 */
void convert_save_to_point(save *saves, int n, point *pts)
{
    int i;
    for (i = 0; i < n; i++){
        float x = (saves[i].x - 225.5) / 190.5;
        float y = (saves[i].y - 225.5) / 190.5;
        pts[i].classe = saves[i].classe;

        pts[i].x = x;
        pts[i].y = y;
    }
}

/**
 * @brief Calcul la distance euclidienne pour float
 * 
 * @param p1x coordonnée x du premier point 
 * @param p1y coordonnée y du premier point
 * @param p2x coordonnée x du second point
 * @param p2y coordonnée y du second point
 * @return float 
 */
float distance_float(float p1x, float p1y, float p2x, float p2y){
    float dx = p1x - p2x;
    float dy = p1y - p2y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * @brief Permet de calculer la distance euclidienne entre deux points et la met dans un tableau de point_k
 * 
 * @param tableau tableau de points
 * @param n nombre de points
 * @param k point k pour la distance euclidienne
 * @param TAB_K le tableau de point_k avec les distances euclidiennes
 */
void tableau_pour_k(point *tableau, int n, point k, point_k **TAB_K){
    int i;
    *TAB_K = (point_k *)malloc(n * sizeof(point_k));
    for (i = 0; i < n; i++){
        (*TAB_K)[i].classe = tableau[i].classe;
        (*TAB_K)[i].x = tableau[i].x;
        (*TAB_K)[i].y = tableau[i].y;
        (*TAB_K)[i].distance_vers_k = distance_points(tableau[i], k);
    }
}

/**
 * @brief Permet de remplir un tableau de point_k avec les distances euclidiennes
 * 
 * @param tableau tableau de points
 * @param n  nombre de points
 * @param TAB_K tableau de point_k avec les distances euclidiennes
 * @param xx point pixel x
 * @param yy point pixel y
 */
void tableau_pour_k_sp(point *tableau, int n, point_k **TAB_K, int xx, int yy){
    int i;
    float new_x, new_y;
    point_k *ktab;
    point k_clique;
    pixel_vers_float(xx, yy, &new_x, &new_y);

    k_clique.x = new_x;
    k_clique.y = new_y;
    k_clique.classe = 0;
    ktab = (point_k *)malloc(n * sizeof(point_k));
    for (i = 0; i < n; i++)
    {
        ktab[i].classe = tableau[i].classe;
        ktab[i].x = tableau[i].x;
        ktab[i].y = tableau[i].y;
        ktab[i].distance_vers_k = distance_points(tableau[i], k_clique);
    }
    *TAB_K = ktab;
}

/**
 * @brief Tri le tableau de point_k par ordre croissant, en utilisant le tri à bulle
 * 
 * @param ktab le tableau de point_k a trier
 * @param n nombre de points
 */
void trier_ktab(point_k *ktab, int n){
    int i, j;
    point_k tmp;
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (ktab[i].distance_vers_k > ktab[j].distance_vers_k){
                tmp = ktab[i];
                ktab[i] = ktab[j];
                ktab[j] = tmp;
            }
        }
    }
}

/**
 * @brief Met en jaune les points les plus proches du point cliqué en fonction des classes
 * 
 * @param ktab le tableau de point_k
 * @param NB nombre de kppv
 */
void plus_proche_colorer(point_k *ktab, int NB){
    int i;
    int pixel_x, pixel_y;
    for (i = 0; i < NB; i++){
        conversion_vers_pixel(ktab[i].x, ktab[i].y, &pixel_x, &pixel_y);
        if(ktab[i].classe == 1){
            MLV_draw_line(pixel_x - 2, pixel_y - 2, pixel_x + 2, pixel_y + 2, MLV_COLOR_YELLOW1);
            MLV_draw_line(pixel_x - 2, pixel_y + 2, pixel_x + 2, pixel_y - 2, MLV_COLOR_YELLOW1);

        }
        if(ktab[i].classe == 2){
        MLV_draw_line(pixel_x - 2, pixel_y, pixel_x + 2, pixel_y, MLV_COLOR_YELLOW4);       
        }
    }
}

/**
 * @brief Permet de colorer les points les plus proches du point cliqué en fonction des classes en utilisant la version arbre
 * 
 * @param arbre_tab arbre de points
 * @param NB nombre de kppv
 */
void plus_proche_colorer_arbre(point *arbre_tab, int NB){
    int i;
    int pixel_x, pixel_y;
    for (i = 0; i < NB; i++){
        conversion_vers_pixel(arbre_tab[i].x, arbre_tab[i].y, &pixel_x, &pixel_y);
        if(arbre_tab[i].classe == 1){
            MLV_draw_line(pixel_x - 2, pixel_y - 2, pixel_x + 2, pixel_y + 2, MLV_COLOR_YELLOW1);
            MLV_draw_line(pixel_x - 2, pixel_y + 2, pixel_x + 2, pixel_y - 2, MLV_COLOR_YELLOW1);
        }
        if(arbre_tab[i].classe == 2){
        MLV_draw_line(pixel_x - 2, pixel_y, pixel_x + 2, pixel_y, MLV_COLOR_YELLOW1);   
        }
    }
}

/**
 * @brief TRI FUSION algorithme de tri
 * 
 * @param ktab tableau de point_k
 * @param l 
 * @param m 
 * @param r 
 */
void tri_fusion_aux(point_k* ktab, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    point_k *GAUCHE = (point_k*)malloc(n1 * sizeof(point_k));
    point_k *DROIT = (point_k*)malloc(n2 * sizeof(point_k));
    if(GAUCHE==NULL){
        fprintf(stderr,"Erreur d'allocation mémoire :) \n");
        exit(EXIT_FAILURE);
    }
    if(DROIT==NULL){
        fprintf(stderr,"Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < n1; i++){
        GAUCHE[i] = ktab[l + i];}
    for(j = 0; j < n2; j++){
        DROIT[j] = ktab[m + 1 + j];}

    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2){
        if(GAUCHE[i].distance_vers_k <= DROIT[j].distance_vers_k){
            ktab[k] = GAUCHE[i];
            i++;
        }
        else{
            ktab[k] = DROIT[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        ktab[k] = GAUCHE[i];
        i++;
        k++;
    }

    while(j < n2){
        ktab[k] = DROIT[j];
        j++;
        k++;
    }
    free(GAUCHE);
    GAUCHE=NULL;
    free(DROIT);
    DROIT=NULL;
}
/**
 * @brief TRI FUSION algoritme de tri
 * 
 * @param ktab tableau de point_k
 * @param l 
 * @param r 
 */
void tri_fusion(point_k* ktab, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        tri_fusion(ktab, l, m);
        tri_fusion(ktab, m + 1, r);
        tri_fusion_aux(ktab, l, m, r);
    }
}
/**
 * @brief  Permet de trier le tableau de point_k par ordre croissant et de colorer les points les plus proches du point cliqué en fonction des classes
 * 
 * @param ktab tableau de point_k
 * @param n nombre de kppv
 */
void fusion_deux_fonction_ktab(point_k *ktab, int n){
    int i;
    int pixel_x, pixel_y;
    tri_fusion(ktab, 0, n - 1);
    for (i = 0; i < n; i++){
        conversion_vers_pixel(ktab[i].x, ktab[i].y, &pixel_x, &pixel_y);
        if(ktab[i].classe == 1){
            MLV_draw_line(pixel_x - 2, pixel_y - 2, pixel_x + 2, pixel_y + 2, MLV_COLOR_YELLOW1);
            MLV_draw_line(pixel_x - 2, pixel_y + 2, pixel_x + 2, pixel_y - 2, MLV_COLOR_YELLOW1);
        }
        if(ktab[i].classe == 2){
            MLV_draw_line(pixel_x - 2, pixel_y, pixel_x + 2, pixel_y, MLV_COLOR_YELLOW1);
        }
    }
}

/**
 * @brief Trouve la classe majoritaire qui sont les plus proches du point cliqué
 * 
 * @param ktab tableau de point_k
 * @param NB nombre de kppv
 * @return int 
 */
int classe_majoritaire(point_k *ktab, int NB){
    int i, j, classe_maxi, compteur_maxi;
    int *compteur = (int *)calloc(2, sizeof(int));
    for (i = 0; i < NB; i++){
        compteur[ktab[i].classe]++;
    }
    classe_maxi = ktab[0].classe;
    compteur_maxi = compteur[classe_maxi];
    for (j = 1; j < 2; j++){
        if (compteur[j] > compteur_maxi){
            classe_maxi = j;
            compteur_maxi = compteur[j];
        }
    }
    free(compteur);
    compteur=NULL;
    return classe_maxi;
}

/**
 * @brief Trouver le point le plus éloigné d'un point spécifique dans une liste de points
 * 
 * @param p point
 * @param liste liste de points a parcourir
 * @param nb_ppv nombre de kppv
 * @return point 
 */
point est_plus_loins_arbre(point p ,point *liste,int nb_ppv){
    float distMax=0;
    float distTemps=0;
    point max;
    int i;
    for (i=0;i<nb_ppv;i++){
        distMax = distance_euc(p,liste[i]);
        if (distMax>distTemps){
            distTemps = distMax;
            max=liste[i];
        }
    }
    return max;
}

/**
 * @brief Dessine un cercle
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 * @param diametre diamètre du cercle
 */
void dessiner_cercle(int *x, int *y, int diametre){

    MLV_draw_circle(*x + 2, *y + 2, diametre, MLV_COLOR_AQUAMARINE2);
    MLV_actualise_window();
}

/**
 * @brief il crée les points en fonction de leur classe
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 * @param classe classe du point 
 */
void cree_points(int x, int y, int classe){
    switch (classe){
    case 1:
        MLV_draw_filled_rectangle(x, y, 5, 5, MLV_COLOR_RED);
        MLV_actualise_window();
        break;
    case 2:
        MLV_draw_filled_rectangle(x, y, 5, 5, MLV_COLOR_BLUE);
        MLV_actualise_window();
        break;
    default:
        printf("La classe n'est pas reconnue : %d", classe);
    }
}

/**
 * @brief Fait la distance entre 2 x et 2 y
 * 
 * @param x1 premier x
 * @param y1 premier y
 * @param x2 premier x
 * @param y2 premier y
 * @return int 
 */
int distance_INT(int x1, int y1, int x2, int y2){
    float nx_x1 = (float)x1 / 400.0;
    float nx_y1 = (float)y1 / 400.0;
    float nx_x2 = (float)x2 / 400.0;
    float nx_y2 = (float)y2 / 400.0;
    float dx = nx_x2 - nx_x1;
    float dy = nx_y2 - nx_y1;
    float distance_norm = sqrt(dx * dx + dy * dy);
    int distance_pixel = (int)(distance_norm * 400.0);
    return distance_pixel;
}

/**
 * @brief  Dessiner un cercle
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 * @param xx coordonnée float x
 * @param yy coordonnée float y
 */
void dessiner_cercle_bis(int *x, int *y,float xx,float yy ){
    int pixel_x, pixel_y;
    int diametre;
    conversion_vers_pixel(xx, yy, &pixel_x, &pixel_y);
    diametre=distance_INT(*x,*y,pixel_x,pixel_y);
    MLV_draw_circle(*x + 2, *y + 2, diametre, MLV_COLOR_BLACK);
    MLV_actualise_window();
}








