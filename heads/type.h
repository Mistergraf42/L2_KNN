/**
 * @file type.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Les structures utilisées dans le programme.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _TYPE_H_
#define _TYPE_H_


#define X_FENETRE 450
#define Y_FENETRE 800
#define ZONE_AFFICHAGE 400
/**
 * @brief Structure point
 * 
 */
typedef struct{
    int classe;
    float x;
    float y;
}point;
/**
 * @brief Structure point en version int
 * 
 */
typedef struct{
    int classe;
    int x, y;
}save;

/**
 * @brief Structure point_k qui permet d'avoir les distances vers k
 * 
 */
typedef struct{
    int classe;
    float x;
    float y;
    float distance_vers_k;
}point_k;

/**
 * @brief Structure zone
 * 
 */
typedef struct zone{
    float x_ini, x_fin, y_ini, y_fin;
} zone;

/**
 * @brief Structure noeud 
 * 
 */
typedef struct noeud
{
    point * valeur;
    zone z;
    struct noeud * fils_droit;
    struct noeud * fils_gauche;
}noeud;
/**
 * @brief Structure arbre_kd
 * 
 */
typedef noeud * arbre_kd;


#endif /*_TYPE_H_*/

