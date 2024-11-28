/**
 * @file generation.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _GENERATION_H_
#define _GENERATION_H_
/**
 * @brief Permet de générer des floats aléatoires
 * 
 * @param a valeur min
 * @param b valeur max
 * @return double 
 */
float frand_a_b(float a, float b);
/**
 * @brief Permet de créer un fichier de données
 * 
 * @param name nom du fichier où seront stockées les données
 * @param n nombre de points
 * @param d dimension fixée à 2
 * @param c classes max
 */
void creation (char *name,int n,int d,int c);

#endif /* _GENERATION_H_ */