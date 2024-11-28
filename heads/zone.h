/**
 * @file zone.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _ZONE_H_
#define _ZONE_H_
#include "type.h"


/**
 * @brief Fait la distance euclidienne entre deux points
 * 
 * @param p1 premier point
 * @param p2 deuxième point
 * @return float 
 */
float distance_euc(point p1, point p2);
/**
 * @brief Fait la distance euclidienne entre un point et une zone
 * 
 * @param z zone
 * @param p point
 * @return float 
 */
float distance_zone(zone z, point p);
/**
 * @brief Recherche la distance max entre un point et un tableau de point pour un k donné.
 * 
 * @param ppv tableau de point contenant les k plus proches voisins
 * @param p point de cliquer
 * @param k nombre de plus proches voisins choisi
 * @return float 
 */
float distance_max(point *ppv, point *p, int k);
/**
 * @brief  Vérifie si un point est dans une zone
 * 
 * @param z la zone
 * @param p le point dont on veut vérifier l'appartenance
 * @return int 
 */
int est_point_dans_zone(zone z, point p);
/**
 * @brief Trouve le point le plus proche d'un point dans une zone
 * 
 * @param z zone où il peut y avoir le point le plus proche
 * @param p point à comparer
 * @return point* 
 */
point *point_proche_dans_zone(zone z, point p);

/**
 * @brief Mettre à jour la liste des plus proches voisins.
 * 
 * @param p_tmp point que l'ont veut ajouter ou non dans la liste des k-ppv
 * @param pRech point de recherche
 * @param liste liste des plus proches voisins
 * @param nb_ppv nombre de plus proches voisins
 * @return point* 
 */
point *maj_liste(point *p_tmp, point *pRech, point *liste, int nb_ppv);

/**
 * @brief Trouve la classe majoritaire.
 * 
 * @param liste liste des plus proches voisins
 * @param nb_ppv nombre de plus proches voisins
 * @return int 
 */
int trouver_classe(point *liste, int nb_ppv);

#endif /* ZONE_H_*/