/**
 * @file sansdecision.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _SANSDECISION_H_
#define _SANSDECISION_H_



/**
 * @brief Calcul la distance euclidienne entre deux points
 * 
 * @param p1 premier point
 * @param p2 second point
 * @return float 
 */
float distance_points(point p1, point p2);

/**
 * @brief Calcul la distance euclidienne entre deux points en pixel
 * 
 * @param p1 premier point
 * @param p2 second point
 * @return int 
 */
int distance_save(point p1, point p2);



/**
 * @brief Conversion de notre tableau de kppv 
 * 
 * @param saves tableau de save
 * @param n nombre de points
 * @param pts tableau de points
 */
void convert_save_to_point(save *saves, int n, point *pts);

/**
 * @brief Calcul la distance euclidienne pour float
 * 
 * @param p1x coordonnée x du premier point 
 * @param p1y coordonnée y du premier point
 * @param p2x coordonnée x du second point
 * @param p2y coordonnée y du second point
 * @return float 
 */
float distance_float(float p1x, float p1y, float p2x, float p2y);


/**
 * @brief Permet de calculer la distance euclidienne entre deux points et la met dans un tableau de point_k
 * 
 * @param tableau tableau de points
 * @param n nombre de points
 * @param k point k pour la distance euclidienne
 * @param TAB_K le tableau de point_k avec les distances euclidiennes
 */
void tableau_pour_k(point *tableau, int n, point k, point_k **TAB_K);

/**
 * @brief Permet de remplir un tableau de point_k avec les distances euclidiennes
 * 
 * @param tableau tableau de points
 * @param n  nombre de points
 * @param TAB_K tableau de point_k avec les distances euclidiennes
 * @param xx point pixel x
 * @param yy point pixel y
 */
void tableau_pour_k_sp(point *tableau, int n, point_k **TAB_K, int xx, int yy);


/**
 * @brief Tri le tableau de point_k par ordre croissant, en utilisant le tri à bulle
 * 
 * @param ktab le tableau de point_k a trier
 * @param n nombre de points
 */
void trier_ktab(point_k *ktab, int n);


/**
 * @brief Met en jaune les points les plus proches du point cliqué en fonction des classes
 * 
 * @param ktab le tableau de point_k
 * @param NB nombre de kppv
 */
void plus_proche_colorer(point_k *ktab, int NB);


/**
 * @brief Permet de colorer les points les plus proches du point cliqué en fonction des classes en utilisant la version arbre
 * 
 * @param arbre_tab arbre de points
 * @param NB nombre de kppv
 */
void plus_proche_colorer_arbre(point *arbre_tab, int NB);



/**
 * @brief TRI FUSION algorithme de tri
 * 
 * @param ktab tableau de point_k
 * @param l 
 * @param m 
 * @param r 
 */
void tri_fusion_aux(point_k* ktab, int l, int m, int r);
/**
 * @brief TRI FUSION algorithme de tri
 * 
 * @param ktab tableau de point_k
 * @param l 
 * @param r 
 */
void tri_fusion(point_k* ktab, int l, int r);
/**
 * @brief  Permet de trier le tableau de point_k par ordre croissant et de colorer les points les plus proches du point cliqué en fonction des classes
 * 
 * @param ktab tableau de point_k
 * @param n nombre de kppv
 */
void fusion_deux_fonction_ktab(point_k *ktab, int n);

/**
 * @brief Trouve la classe majoritaire qui sont les plus proches du point cliqué
 * 
 * @param ktab tableau de point_k
 * @param NB nombre de kppv
 * @return int 
 */
int classe_majoritaire(point_k *ktab, int NB);

/**
 * @brief Trouver le point le plus éloigné d'un point spécifique dans une liste de points
 * 
 * @param p point
 * @param liste liste de points a parcourir
 * @param nb_ppv nombre de kppv
 * @return point 
 */
point est_plus_loins_arbre(point p ,point *liste,int nb_ppv);

/**
 * @brief Dessine un cercle
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 * @param diametre diamètre du cercle
 */
void dessiner_cercle(int *x, int *y, int diametre);

/**
 * @brief il crée les points en fonction de leur classe
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 * @param classe classe du point 
 */
void cree_points(int x, int y, int classe);


/**
 * @brief Fait la distance entre 2 x et 2 y
 * 
 * @param x1 premier x
 * @param y1 premier y
 * @param x2 premier x
 * @param y2 premier y
 * @return int 
 */
int distance_INT(int x1, int y1, int x2, int y2);

/**
 * @brief  Dessiner un cercle
 * 
 * @param x coordonnée x
 * @param y coordonnée y
 * @param xx coordonnée float x
 * @param yy coordonnée float y
 */
void dessiner_cercle_bis(int *x, int *y,float xx,float yy );
















#endif /*_SANSDECISION_H_*/