/**
 * @file arbre.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _ARBRE_H_
#define _ARBRE_H_
#include "type.h"
#include "zone.h"
/**
 * @brief Permet de créer un arbre vide
 * 
 * @return arbre_kd 
 */
arbre_kd arbre_vide_kd();
/**
 * @brief Permet de verifier si un arbre est vide
 * 
 * @param a qui est un arbre
 * @return int 
 */
int est_vide_arbre_kd(arbre_kd a);
/**
 * @brief Cette fonction permet de crée un point
 * 
 * @param classe la classe du point
 * @param x ça coordonnée x
 * @param y ça coordonnée y
 * @return point* 
 */
point * creer_point(int classe, float x, float y);
/**
 * @brief Permet de créer un arbre kd ayant pour valeur le point p
 * 
 * @param p le point qui sera la valeur du noeud
 * @return arbre_kd 
 */
arbre_kd creer_arbre_kd(point *p);
/**
 * @brief Fonction permettant de comparer deux points
 * 
 * @param p1 premier point
 * @param p2 deuxième point
 * @return int 
 */
int compPoint(point *p1, point *p2);
/**
 * @brief Fonction recursive permettant d'insérer un point dans un arbre kd, elle est appelée par la fonction inserer. Elle permet de parcourir l'arbre et de trouver la bonne place pour le point en fonction de sa valeur x et y.La profondeur de l'arbre est utilisé pour savoir si on doit comparer la valeur x ou y du point avec la valeur x ou y du noeud.
 * 
 * @param a arbre kd où nous allons insérer le point
 * @param p le point que nous voulons insérer
 * @param profondeur la profondeur de l'arbre
 * @return arbre_kd 
 */
arbre_kd inserer_aux(arbre_kd a, point *p, int profondeur);
/**
 * @brief La fonction inserer fait appel à la fonction inserer_aux pour insérer un point dans un arbre kd, elle permet de verifier si l'arbre est vide et si c'est le cas elle crée un arbre kd avec le point p comme valeur. Sinon elle fait appel à la fonction inserer_aux. Elle definit une zone initial si l'arbre est vide.
 * 
 * @param a arbre où nous voullons insérer le point
 * @param p le point que nous voulons insérer
 * @return arbre_kd 
 */
arbre_kd inserer(arbre_kd a, point *p);

/**
 * @brief Elle permet de créer un arbre kd à partir d'un fichier. Elle lit le fichier et crée un point avec les valeurs lues. Elle crée un arbre kd avec le premier point lu et ensuite elle insère les autres points dans l'arbre kd.
 * 
 * @param name nom du fichier
 * @param nb_noeud nombre de noeud dans le fichier
 * @return arbre_kd 
 */
arbre_kd chargement_fich(char *name, int *nb_noeud);
/**
 * @brief Elle nous permet de connaître la profondeur de notre noeur dans l'arbre kd. Elle fait appel à elle même recursivement.
 * 
 * @param a arbre kd
 * @param val 
 * @return int 
 */
int profondeur_noeud_kd(arbre_kd a, point *val);
/**
 * @brief La fonction supprimer permet de supprimer un point de l'arbre kd. Elle fait appel à la fonction profondeur_noeud_kd pour connaître la profondeur du point dans l'arbre kd. Elle parcourt l'arbre kd jusqu'à trouver le point à supprimer. Elle fait appel à la fonction compPoint pour comparer le point courant avec le point à supprimer. Si le point est trouvé elle le supprime et retourne l'arbre kd. Sinon elle affiche un message d'erreur.
 * 
 * @param a arbre kd
 * @param p point à supprimer
 * @return arbre_kd 
 */
arbre_kd supprimer(arbre_kd a, point *p);
/**
 * @brief Permet de savoir si un noeud est une feuille
 * 
 * @param a arbre kd
 * @return int 
 */
int estfeuille_kd(arbre_kd a);
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
point *rechercher_aux(arbre_kd a, point *p, point *ppv, int k, int profondeur);
/**
 * @brief Fonction permettant de trouver les voisins les plus proches du point p. Elle fait appel à la fonction rechercher_aux. Elle crée une liste de k points et la retourne.
 * 
 * @param a l'arbre kd où nous cherchons les plus proches voisins
 * @param p le point dont nous voulons connaître les plus proches voisins
 * @param k nombre de voisins voulus par l'utilisateur
 * @return point* 
 */
point *rechercher(arbre_kd a, point *p, int k);







#endif /* ARBRE_H_*/
