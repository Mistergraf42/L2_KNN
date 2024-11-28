/**
 * @file conversion.h
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fichier contenant le prototype des fonctions
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef _CONVERSION_H_
#define _CONVERSION_H_
/**
 * @brief Permet de convertir des float en int
 * 
 * @param x premier float
 * @param y  second float
 * @param pixel_x x converti en INT
 * @param pixel_y y converti en INT
 */
void conversion_vers_pixel(float x, float y, int* pixel_x, int* pixel_y);
/**
 * @brief Permet de convertir des int en float
 * 
 * @param pixel_x premier INT
 * @param pixel_y second INT
 * @param x x converti en float
 * @param y y converti en float
 */
void pixel_vers_float(int pixel_x, int pixel_y, float *x, float *y);
/**
 * @brief Permet de convertir un x int en float
 * 
 * @param pixel_x premier INT
 * @param x x converti en float
 */
void pixel_vers_float_x(int pixel_x, float *x);
/**
 * @brief Permet de convertir un y int en float
 * 
 * @param pixel_y premier INT
 * @param y y converti en float
 */
void pixel_vers_float_y(int pixel_y, float *y);


#endif /* CONVERSION_H_*/