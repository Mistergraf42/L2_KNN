/**
 * @file generation.c
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief fonction de génération de données.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @brief Permet de générer des floats aléatoires
 * 
 * @param a valeur min
 * @param b valeur max
 * @return double 
 */
double frand_a_b(double a, double b){
    return ( rand()/(double)RAND_MAX ) * (b-a) + a ;
}

/**
 * @brief Permet de créer un fichier de données
 * 
 * @param name nom du fichier où seront stockées les données
 * @param n nombre de points
 * @param d dimension fixée à 2
 * @param c classes max
 */
void creation (char *name,int n,int d,int c){
    int i,classe;
    float x,y;
    /*ouverture du fichier*/
    FILE* fichier = NULL;
    fichier = fopen(name, "r+");
        if (fichier == NULL){ /* si le fichier n'existe pas */
            printf("Fichier inexistant\n");
            exit(EXIT_FAILURE);
    }
    fprintf(fichier,"%d %d %d\n",n,d,c);
    /*création de chiffres aléatoires et insertion de données*/
    for(i=0;i<n;i++){
        classe = rand()%c+1;
        x=frand_a_b(-1.0,1.0);
        y=frand_a_b(-1.0,1.0);
        /* printf("\n%d %lf %lf\n",classe,x,y); */
        fprintf(fichier,"%d %f %f\n",classe,x,y);
    }
    fclose(fichier);
    return;
}



