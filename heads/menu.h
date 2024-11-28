/**
 * @file menu.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _MENU_H_
#define _MENU_H_
/**
 * @brief Fonction qui permet de gérer toute la partie graphique.
 * 
 * @param x variable qui récupère la position en x de la souris
 * @param y variable qui récupère la position en y de la souris
 * @param bouton_1 valeur du bouton 1
 * @param bouton_2 valeur du bouton 2
 * @param bouton_3 valeur du bouton 3
 * @param bouton_4 valeur du bouton 4
 * @param nomfichier fichier pour les sauvegardes ou chargement
 * @param classeselection classe selectionnée
 * @param kselection k selectionné
 * @param sauvegarde tableau de type save qui contient les points
 * @param accu nombre de points
 * @param fichier fichier servant à la sauvegarde
 * @param MODE mode kppv ou creation
 * @param TOONS tableau de type point qui contient les points
 * @param TAB_K tableau de type point_k qui contient les points avec les distances euclidiennes
 * @param POINT_NOIR Permet de savoir si on a cliqué sur un point ou non
 * @param TOLGA arbre kd
 * @param dernier dernier point cliqué en mode création
 * @param ajoute_classe_selection permet de stocker les valeurs du point en mode Kppv avec prise de décision
 * @param supprimer_pts vérifie si on a supprimer le dernier point
 */
void option_bouton(int *x, int *y, int *bouton_1, int *bouton_2, int *bouton_3, int *bouton_4, char *nomfichier, int *classeselection, int *kselection, save **sauvegarde, int *accu, FILE *fichier, int *MODE, point **TOONS, point_k **TAB_K,int *POINT_NOIR, arbre_kd *TOLGA, point *dernier, point *ajoute_classe_selection,int *supprimer_pts);

#endif /* _MENU_H_ */