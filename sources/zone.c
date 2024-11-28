/**
 * @file zone.c
 * @author ANAIS ROCHE - YILDIZ TOLGA
 * @brief permet de gerer les zones.
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
#include "../heads/arbre.h"

/**
 * @brief Fait la distance euclidienne entre deux points
 * 
 * @param p1 premier point
 * @param p2 deuxième point
 * @return float 
 */
float distance_euc(point p1, point p2){
    float res;
    res = sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
    return res;
}
/**
 * @brief Fait la distance euclidienne entre un point et une zone
 * 
 * @param z zone
 * @param p point
 * @return float 
 */
float distance_zone(zone z, point p){
    float dx = fmax(fmax(z.x_ini - p.x, p.x - z.x_fin), 0);
    float dy = fmax(fmax(z.y_ini - p.y, p.y - z.y_fin), 0);
    return sqrt(dx * dx + dy * dy);
}
/**
 * @brief Recherche la distance max entre un point et un tableau de point pour un k donné.
 * 
 * @param ppv tableau de point contenant les k plus proches voisins
 * @param p point de cliquer
 * @param k nombre de plus proches voisins choisi
 * @return float 
 */
float distance_max(point *ppv, point *p, int k){
    float max_distance = 0.0;
    int i;
    for (i = 0; i < k; i++)
    {
        float distance = distance_euc(ppv[i], *p);
        if (distance > max_distance)
        {
            max_distance = distance;
        }
    }
    return max_distance;
}
/**
 * @brief  Vérifie si un point est dans une zone
 * 
 * @param z la zone
 * @param p le point dont on veut vérifier l'appartenance
 * @return int 
 */
int est_point_dans_zone(zone z, point p) {
    if (p.x < z.x_fin && p.x > z.x_ini && p.y < z.y_fin && p.y > z.y_ini) {
        return 1;
    }
    return 0;
}
/**
 * @brief Trouve le point le plus proche d'un point dans une zone
 * 
 * @param z zone où il peut y avoir le point le plus proche
 * @param p point à comparer
 * @return point* 
 */
point *point_proche_dans_zone(zone z, point p) {
    point *p_proche = (point *)malloc(sizeof(point));

    if (est_point_dans_zone(z, p)) {
        p_proche->x = p.x;
        p_proche->y = p.y;
        return p_proche;
    }

    if (p.x < z.x_ini) {
        p_proche->x = z.x_ini;
        if (p.y < z.y_ini) {
            p_proche->y = z.y_ini;
        }
        else if (p.y > z.y_fin) {
            p_proche->y = z.y_fin;
        }
        else {
            p_proche->y = p.y;
        }
    }
    else if (p.x > z.x_fin) {
        p_proche->x = z.x_fin;
        if (p.y < z.y_ini) {
            p_proche->y = z.y_ini;
        }
        else if (p.y > z.y_fin) {
            p_proche->y = z.y_fin;
        }
        else {
            p_proche->y = p.y;
        }
    }
    else {
        p_proche->x = p.x;
        if (p.y < z.y_ini) {
            p_proche->y = z.y_ini;
        }
        else {
            p_proche->y = z.y_fin;
        }
    }

    return p_proche;
}

/**
 * @brief Mettre à jour la liste des plus proches voisins.
 * 
 * @param p_tmp point que l'ont veut ajouter ou non dans la liste des k-ppv
 * @param pRech point de recherche
 * @param liste liste des plus proches voisins
 * @param nb_ppv nombre de plus proches voisins
 * @return point* 
 */
point *maj_liste(point *p_tmp, point *pRech, point *liste, int nb_ppv){
    int i, iMax = 0;
    float dist, distMax;
    distMax = distance_euc(*pRech, *p_tmp);

    for (i = 0; i < nb_ppv; i++) {
        dist = distance_euc(*pRech, liste[i]);
        if (dist > distMax) {
            distMax = dist;
            iMax = i;
        }
    }

    if (distMax != distance_euc(*pRech, *p_tmp)) {
        liste[iMax] = *p_tmp;
    }

    return liste;
}

/**
 * @brief Trouve la classe majoritaire.
 * 
 * @param liste liste des plus proches voisins
 * @param nb_ppv nombre de plus proches voisins
 * @return int 
 */
int trouver_classe(point *liste, int nb_ppv){
    int i=0;
    int c1=0, c2=0;
    point *p;
    p = (point *)malloc(sizeof(point));
    for(i=0 ; i<nb_ppv ; i++){
        *p=liste[i];
        if(p->classe==1){
            c1++;
        }
        if(p->classe==2){
            c2++;
        }
    }
    if(c1>c2){
        return 1;
    }
    if(c1<c2){
        return 2;
    }
return 1;
}
