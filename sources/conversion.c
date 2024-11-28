/**
 * @file conversion.c
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Fonction de conversion de coordonnées.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Permet de convertir des float en int
 * 
 * @param x premier float
 * @param y  second float
 * @param pixel_x x converti en INT
 * @param pixel_y y converti en INT
 */
void conversion_vers_pixel(float x, float y, int *pixel_x, int *pixel_y){

    *pixel_x = (int)((x)*190.5);
    *pixel_y = (int)((y)*190.5);

    *pixel_x += 225.5;
    *pixel_y += 225.5;
}
/**
 * @brief Permet de convertir des int en float
 * 
 * @param pixel_x premier INT
 * @param pixel_y second INT
 * @param x x converti en float
 * @param y y converti en float
 */
void pixel_vers_float(int pixel_x, int pixel_y, float *x, float *y){
    *x = (pixel_x - 225.5) / 190.5;
    *y = (pixel_y - 225.5) / 190.5;
}
/**
 * @brief Permet de convertir un x int en float
 * 
 * @param pixel_x premier INT
 * @param x x converti en float
 */
void pixel_vers_float_x(int pixel_x, float *x){
    *x = (pixel_x - 225.5) / 190.5;
}
/**
 * @brief Permet de convertir un y int en float
 * 
 * @param pixel_y premier INT
 * @param y y converti en float
 */
void pixel_vers_float_y(int pixel_y, float *y){
    *y = (pixel_y - 225.5) / 190.5;
}



