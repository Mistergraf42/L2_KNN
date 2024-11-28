/**
 * @file fonction.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _FONCTION_
#define _FONCTION_
#include "type.h"
/**
 * @brief Crée un bouton avec un carré noir rempli et un carré violet au centre
 * 
 * @param x coordonnée x 
 * @param y coordonnée y
 */
void bouton_on(int x, int y);
/**
 * @brief Crée un bouton avec un carré noir rempli
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 */
void bouton_off(int x, int y);
/**
 * @brief Permet de changer l'état d'un bouton.
 * 
 * @param mode état du bouton
 * @param x coordonnée x
 * @param y coordonnée y
 */
void selection_on_off(int *mode, int x, int y);
/**
 * @brief Affichage principal de la fenêtre
 * 
 * @param bouton_1 Bouton voisinage
 * @param bouton_2 Bouton voisinage avec prise de décision
 * @param bouton_3 Bouton voisinage arbre
 * @param bouton_4 Bouton voisinage arbre avec prise de décision
 */
void affichage(int *bouton_1, int *bouton_2, int *bouton_3, int *bouton_4);
/**
 * @brief Chargement d'un fichier et met les données dans un tableau de point
 * 
 * @param name nom du fichier à charger
 * @param adresse_tab le tableau de point qui va être rempli
 * @param n nombre de point dans le fichier
 * @param d dimension ici fixée à 2
 * @param c les classes
 */
void chargement_fichier(char *name, point **adresse_tab, int *n, int *d, int *c);
/**
 * @brief Chargement d'un fichier et rentre les données dans un tableau de sauvegarde de type save
 * 
 * @param name nom du fichier à charger
 * @param accu nombre de point dans le fichier
 * @return save* 
 */
save *chargement_fichier_bis(char *name, int *accu);
/**
 * @brief Charge un fichier et renvoie un tableau de point
 * 
 * @param name nom du fichier à charger
 * @param accu nombre de point dans le fichier
 * @return point* 
 */
point *chargement_fichier_point(char *name, int *accu);
/**
 * @brief Cette fonction permet d'afficher les points du tableau de point en fonction de la classe
 * 
 * @param n nombre de point
 * @param tab tableau de point
 */

void Affiche_point(int n, point *tab);
/**
 * @brief Permet d'afficher les points du tableau de sauvegarde en fonction de la classe
 * 
 * @param n nombre de point
 * @param tab tableau de save
 */
void Affiche_save(int n, save *tab);
/**
 * @brief Interface graphique pour le mode creation
 * 
 * @param nomfichier nom du fichier si il y a chargement
 * @param classeselection la classe selectionné
 */
void mode_crea(char *nomfichier, int *classeselection);
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
void chargement_fichier_bouton(char *nomfichier, int *bouton_1, int *bouton_2,int *bouton_3,int *bouton_4, int *classeselection, save **ANAIS, point **TOONS,arbre_kd *TOLGA, int *accu);
/**
 * @brief Permet de changer la classe selectionnée (entre 1 et 2)
 * 
 * @param classe classe à changer
 */
void classe_changement(int *classe);
/**
 * @brief Affichage de la classe selectionnée
 * 
 * @param classeselection la classe actuelle
 */
void update_classe(int *classeselection);
/**
 * @brief Permet de changer le nombre de voisins proches
 * 
 * @param kselection la valeur de k qui va changer
 */
void k_changement(int *kselection);
/**
 * @brief Affichage de la valeur de k
 * 
 * @param kselection le k actuel
 */
void update_k(int *kselection);
/**
 * @brief Permet de supprimer le dernier point et de faire l'affichage sans
 * 
 * @param n nombre de point
 * @param sauvegarde tableau contenant les points
 */
void supprimer_dernier_point(int n, save *sauvegarde);

#endif /* _FONCTION_ */
