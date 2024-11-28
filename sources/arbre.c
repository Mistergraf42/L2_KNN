/**
 * @file arbre.c
 * @author ANAIS ROCHE - YILDIZ TOLGA
 * @brief  Fichier contenant les fonctions de gestion d'arbre
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../heads/type.h"
#include "../heads/zone.h"

/**
 * @brief Permet de créer un arbre vide
 * 
 * @return arbre_kd 
 */
arbre_kd arbre_vide_kd(){
    return NULL;
}
/**
 * @brief Permet de verifier si un arbre est vide
 * 
 * @param a qui est un arbre
 * @return int 
 */
int est_vide_arbre_kd(arbre_kd a){
    if (a == arbre_vide_kd()){
        return 1;
    }
    return 0;
}
/**
 * @brief Cette fonction permet de crée un point
 * 
 * @param classe la classe du point
 * @param x ça coordonnée x
 * @param y ça coordonnée y
 * @return point* 
 */
point * creer_point(int classe, float x, float y){
    point * p=NULL;
    p=(point *)malloc(sizeof(point));
    if(p== NULL){
        fprintf(stderr, "Erreur d'allocation mémoiermémoire de nouveau arbre.\n");
        exit(EXIT_FAILURE);
    }
    p->classe = classe;
    p->x = x;
    p->y = y;
    return p;
}
/**
 * @brief Permet de créer un arbre kd ayant pour valeur le point p
 * 
 * @param p le points qui sera la valeur du noeud
 * @return arbre_kd 
 */
arbre_kd creer_arbre_kd(point *p){
    arbre_kd nouveau_arbre = arbre_vide_kd();
    nouveau_arbre = (arbre_kd)malloc(sizeof(noeud));
    if (nouveau_arbre == NULL){
        fprintf(stderr, "Erreur d'allocation mémoier de nouveau arbre.\n");
        exit(EXIT_FAILURE);
    }
    nouveau_arbre->valeur = p;
    nouveau_arbre->z.x_ini = -1;
    nouveau_arbre->z.x_fin = 1;
    nouveau_arbre->z.y_ini = -1;
    nouveau_arbre->z.y_fin = 1;
    nouveau_arbre->fils_droit = NULL;
    nouveau_arbre->fils_gauche = NULL;
    return nouveau_arbre;
}
/**
 * @brief Fonction permettant de comparer deux points
 * 
 * @param p1 premier point
 * @param p2 deuxième point
 * @return int 
 */
int compPoint(point *p1, point *p2){
    if(p1->x==p2->x && p1->y==p2->y){
        return 1;
    }
    return 0;
}
/**
 * @brief Fonction recursive permettant d'insérer un point dans un arbre kd, elle est appelée par la fonction inserer. Elle permet de parcourir l'arbre et de trouver la bonne place pour le point en fonction de sa valeur x et y.La profondeur de l'arbre est utilisé pour savoir si on doit comparer la valeur x ou y du point avec la valeur x ou y du noeud.
 * 
 * @param a arbre kd où nous allons insérer le point
 * @param p le point que nous voulons insérer
 * @param profondeur la profondeur de l'arbre
 * @return arbre_kd 
 */
arbre_kd inserer_aux(arbre_kd a, point *p, int profondeur) {
    int axe;
    float valeur_axe;
    float valeur_axe_prime;

    if (a == NULL) {
        a = (noeud *)malloc(sizeof(noeud));
        a->valeur = (point *)malloc(sizeof(point));
        *a->valeur = *p;
        a->fils_droit = NULL;
        a->fils_gauche = NULL;
        return a;
    }

    axe = profondeur % 2;
    valeur_axe = p->x;
    valeur_axe_prime = a->valeur->x;
    if (axe == 1) {
        valeur_axe = p->y;
        valeur_axe_prime = a->valeur->y;
    }

    if (valeur_axe < valeur_axe_prime) {
        if (a->fils_gauche == NULL) {
            a->fils_gauche = (noeud *)malloc(sizeof(noeud));
            a->fils_gauche->valeur = (point *)malloc(sizeof(point));
            *a->fils_gauche->valeur = *p;
            a->fils_gauche->z = a->z;
            if (axe == 0) {
                a->fils_gauche->z.x_fin = a->valeur->x;
            } else {
                a->fils_gauche->z.y_fin = a->valeur->y;
            }
            a->fils_gauche->fils_gauche = NULL;
            a->fils_gauche->fils_droit = NULL;
        } else {
            inserer_aux(a->fils_gauche, p, profondeur + 1);
        }
    } else {
        if (a->fils_droit == NULL) {
            a->fils_droit = (noeud *)malloc(sizeof(noeud));
            a->fils_droit->valeur = (point *)malloc(sizeof(point));
            *a->fils_droit->valeur = *p;
            a->fils_droit->z = a->z;
            if (axe == 0) {
                a->fils_droit->z.x_ini = a->valeur->x;
            } else {
                a->fils_droit->z.y_ini = a->valeur->y;
            }
            a->fils_droit->fils_gauche = NULL;
            a->fils_droit->fils_droit = NULL;
        } else {
            inserer_aux(a->fils_droit, p, profondeur + 1);
        }
    }

    return a;
}
/**
 * @brief La fonction inserer fait appel à la fonction inserer_aux pour insérer un point dans un arbre kd, elle permet de verifier si l'arbre est vide et si c'est le cas elle crée un arbre kd avec le point p comme valeur. Sinon elle fait appel à la fonction inserer_aux. Elle definit une zone initial si l'arbre est vide.
 * 
 * @param a arbre où nous voullons insérer le point
 * @param p le point que nous voulons insérer
 * @return arbre_kd 
 */
arbre_kd inserer(arbre_kd a, point *p) {
    if (a == NULL) {
        a = (noeud *)malloc(sizeof(noeud));
        a->valeur = (point *)malloc(sizeof(point));
        *a->valeur = *p;
        a->fils_droit = NULL;
        a->fils_gauche = NULL;
        a->z.x_ini = -1;
        a->z.x_fin = 1;
        a->z.y_ini = -1;
        a->z.y_fin = 1;
        return a;
    } else {
        return inserer_aux(a, p, 0);
    }
}

/**
 * @brief Elle permet de créer un arbre kd à partir d'un fichier. Elle lit le fichier et crée un point avec les valeurs lues. Elle crée un arbre kd avec le premier point lu et ensuite elle insère les autres points dans l'arbre kd.
 * 
 * @param name nom du fichier
 * @param nb_noeud nombre de noeud dans le fichier
 * @return arbre_kd 
 */
arbre_kd chargement_fich(char *name, int *nb_noeud){
    arbre_kd a = arbre_vide_kd();
    point * p;
    int classe;
    float x, y;
    int d, c, i;

    FILE *fichier = NULL;
    fichier = fopen(name, "r+");
    if (fichier == NULL){
        fprintf(stderr, "Erreur lors de l'ouverture du fichier.\n");
        exit(EXIT_FAILURE);
    }
    if (fscanf(fichier, "%d %d %d", nb_noeud, &d, &c) != 3){
        fprintf(stderr, "Erreur de lecture du fichier.\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < (*nb_noeud); i++){
        if (fscanf(fichier, "%d %f %f", &classe, &x, &y) != 3){
            fprintf(stderr, "Erreur de lecture du fichier.\n");
            exit(EXIT_FAILURE);
        }
        p = creer_point(classe,x,y);
        if (i == 0){
            a = creer_arbre_kd(p);
        }
        else{
            inserer(a, p);
        }
    }
    printf("Fin du chargement de fichier.\n");
    printf("n = %d \n", *nb_noeud);
    fclose(fichier);
    return a;
}
/**
 * @brief Elle nous permet de connaître la profondeur de notre noeur dans l'arbre kd. Elle fait appel à elle même recursivement.
 * 
 * @param a arbre kd
 * @param val 
 * @return int 
 */
int profondeur_noeud_kd(arbre_kd a, point *val){
    if (est_vide_arbre_kd(a)){
        return 0;
    }
    /* Si c'est la racine prof = 0  */
    if (a->valeur->x == val->x){
        return 0;
    }

    /* récursivité pour trouver la valeur dans l'arbre */
    if (val->x < a->valeur->x && !est_vide_arbre_kd(a->fils_gauche)){
        return profondeur_noeud_kd(a->fils_gauche, val) + 1;
    }
    if (val->x > a->valeur->x && !est_vide_arbre_kd(a->fils_droit)){
        return profondeur_noeud_kd(a->fils_droit, val) + 1;
    }
    return 0;
}
/**
 * @brief La fonction supprimer permet de supprimer un point de l'arbre kd. Elle fait appel à la fonction profondeur_noeud_kd pour connaître la profondeur du point dans l'arbre kd. Elle parcourt l'arbre kd jusqu'à trouver le point à supprimer. Elle fait appel à la fonction compPoint pour comparer le point courant avec le point à supprimer. Si le point est trouvé elle le supprime et retourne l'arbre kd. Sinon elle affiche un message d'erreur.
 * 
 * @param a arbre kd
 * @param p point à supprimer
 * @return arbre_kd 
 */
arbre_kd supprimer(arbre_kd a, point *p) {
    arbre_kd courant, precedent, debut;
    courant = a;
    debut = a;
    precedent = arbre_vide_kd();

    if (est_vide_arbre_kd(courant)) {
        fprintf(stderr, "L'arbre est vide.\n");
        return a;
    }

    if(compPoint(courant->valeur, p)){
         free(courant);
         courant=NULL;
         return arbre_vide_kd();
    }

    while (!est_vide_arbre_kd(courant)) {
        if (compPoint(courant->valeur, p)) {
            if (!est_vide_arbre_kd(precedent)) {
                if (precedent->fils_gauche == courant) {
                    precedent->fils_gauche = arbre_vide_kd();
                } else {
                    precedent->fils_droit = arbre_vide_kd();
                }
            }
            free(courant);
            return debut;
        }

        precedent = courant;

        if (profondeur_noeud_kd(a, courant->valeur) % 2 == 0) {
            if (courant->valeur->x > p->x) {
                courant = courant->fils_gauche;
            } else {
                courant = courant->fils_droit;
            }
        } else {
            if (courant->valeur->y > p->y) {
                courant = courant->fils_gauche;
            } else {
                courant = courant->fils_droit;
            }
        }
    }

    printf("Point non trouvé dans l'arbre.\n");
    return debut;
} 
/**
 * @brief Permet de savoir si un noeud est une feuille
 * 
 * @param a arbre kd
 * @return int 
 */
int estfeuille_kd(arbre_kd a){
    if (!est_vide_arbre_kd(a)){
        return 0;
    }
    if (a->fils_gauche == NULL && a->fils_droit == NULL){
        return 1;
    }
    return 0;
}
/**
 * @brief La fonction rechecher_aux est la plus complexe de la partie arbre, elle utilise les axes pour parcourir l'arbre kd et trouver les plus proches voisins. Elle fait appel à la fonction maj_liste pour mettre à jour la liste des plus proches voisins. Elle fait appel à elle même recursivement pour voir si dans un sous arbre il n'y a pas de plus proche voisin. Elle compare la distance entre le point et le plus proche voisin avec la distance entre le point et l'axe pour savoir si elle doit parcourir le sous arbre gauche ou droit.
 * 
 * @param a l'arbre kd où nous cherchons les plus proches voisins
 * @param p le point dont nous voulons connaître les plus proches voisins
 * @param ppv la liste temporaire des plus proches voisins et qui sera la liste finale
 * @param k nombre de k plus proches voisins voulus par l'utilisateur
 * @param profondeur la profondeur de l'arbre kd
 * @return point* 
 */
point *rechercher_aux(arbre_kd a, point *p, point *ppv, int k, int profondeur)
{
    int axe;
    float valeur_axe, valeur_axe_prime;
    float distance_min_ppv;
    float distance_axe_point;
    arbre_kd sous_arbre_proche, sous_arbre_loin;

    if (a == NULL){
        return ppv;
    }

    axe = profondeur % 2;

    if (axe == 0) {
        valeur_axe = p->x;
        valeur_axe_prime = a->valeur->x;
    } else {
        valeur_axe = p->y;
        valeur_axe_prime = a->valeur->y;
    }

    if (valeur_axe < valeur_axe_prime) {
        sous_arbre_proche = a->fils_gauche;
        sous_arbre_loin = a->fils_droit;
    } else {
        sous_arbre_proche = a->fils_droit;
        sous_arbre_loin = a->fils_gauche;
    }

    ppv = maj_liste((a->valeur), p, ppv, k);

    if (sous_arbre_proche != NULL){
        ppv = rechercher_aux(sous_arbre_proche, p, ppv, k, profondeur + 1);
    }

    if (sous_arbre_loin != NULL){
        distance_min_ppv = distance_max(ppv, p, k);
        distance_axe_point = valeur_axe - valeur_axe_prime;
        distance_axe_point *= distance_axe_point;

        if (distance_min_ppv > distance_axe_point){
            ppv = rechercher_aux(sous_arbre_loin, p, ppv, k, profondeur + 1);
        }
    }

    return ppv;
}
/**
 * @brief Fonction permettant de trouver les voisins les plus proches du point p. Elle fait appel à la fonction rechercher_aux. Elle crée une liste de k points et la retourne.
 * 
 * @param a l'arbre kd où nous cherchons les plus proches voisins
 * @param p le point dont nous voulons connaître les plus proches voisins
 * @param k nombre de voisins voulus par l'utilisateur
 * @return point* 
 */
point *rechercher(arbre_kd a, point *p, int k)
{
    int i;
    point *ppv = (point *)malloc(sizeof(point) * k);

    if (ppv == NULL){
        fprintf(stderr, "Erreur d'allocation mémoire lors de la recherche->\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < k; i++){
        ppv[i].x = 1000;
        ppv[i].y = 1000;
    }

    return rechercher_aux(a, p, ppv, k, 0);
}



