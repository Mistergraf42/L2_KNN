/**
 * @file menu.c
 * @author ANAIS ROCHE - TOLGA YILDIZ
 * @brief Permet de gerer toutes la partie graphique.
 * @version 0.1
 * @date 2023-05-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#include "../heads/type.h"
#include "../heads/conversion.h"
#include "../heads/sansdecision.h"
#include "../heads/fonction.h"
#include "../heads/arbre.h"
#include "../heads/zone.h"


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
void option_bouton(int *x, int *y, int *bouton_1, int *bouton_2, int *bouton_3, int *bouton_4, char *nomfichier, int *classeselection, int *kselection, save **sauvegarde, int *accu, FILE *fichier, int *MODE, point **TOONS, point_k **TAB_K,int *POINT_NOIR, arbre_kd *TOLGA,point *dernier,point *ajoute_classe_selection,int *supprimer_pts){
    int reset = 1;
    int boucle = 0;
    int XM, YM;
    int i;
    float xx, yy;
    float newx;
    float newy;
    int LACLASSE;
    float conversionx, conversiony;
    point *clique;
    save *nx_pts;
    point *partie_deux;
    point *liste_kppv_arbre;
    point cercle_arbre;
    int ajout_deux_x;
    int ajout_deux_y;



    /*Allocation mémoire*/
    nx_pts = (save *)malloc(sizeof(save));
    clique = (point *)malloc(sizeof(point));
    partie_deux = (point *)malloc(sizeof(point));


     if (*x > 430 && *x < 450 && *y > 0 && *y < 20){
        free(nx_pts);
        nx_pts=NULL;
        free(clique);
        clique=NULL;
        free(partie_deux);
        partie_deux=NULL;
        MLV_free_window();
        exit(EXIT_SUCCESS);
     }



    if (*x > 30 && *x < 220 && *y > 530 && *y < 560 && *accu!=0 && *MODE==1){   
        *POINT_NOIR = 0;
        affichage(bouton_1, bouton_2, bouton_3, bouton_4);
        Affiche_save(*accu, *sauvegarde);
        MLV_actualise_window();
    }
/*SI SANS CLASSE DE TABLEAU*/
    if (*x > 25 && *x < 425 && *y > 25 && *y < 425 && *MODE == 1 && *bouton_4 == 1 && *bouton_3 == 1 && *bouton_1 == 2 && *bouton_2 == 1 && *accu != 0 && *POINT_NOIR==0){
        *POINT_NOIR = 1;   
        if (*kselection > *accu){
            *kselection = *accu;

        }
        nx_pts->x = *x;
        nx_pts->y = *y;
        nx_pts->classe = 0;
        pixel_vers_float(*x, *y, &newx, &newy);
        clique->x = newx;
        clique->y = newy;
        clique->classe = 0;


        tableau_pour_k(*TOONS, *accu, *clique, TAB_K);

        MLV_draw_filled_rectangle(nx_pts->x, nx_pts->y, 5, 5, MLV_COLOR_BLACK);
        trier_ktab(*TAB_K, *accu);
        MLV_clear_window(MLV_COLOR_PURPLE4);
        affichage(bouton_1, bouton_2, bouton_3, bouton_4);
        Affiche_save(*accu, *sauvegarde);
        dessiner_cercle_bis(x, y, (*TAB_K)[*kselection - 1].x, (*TAB_K)[*kselection - 1].y);
        Affiche_save(*accu, *sauvegarde);
        
        fusion_deux_fonction_ktab(*TAB_K, *kselection);
        
        MLV_draw_filled_rectangle(nx_pts->x, nx_pts->y, 5, 5, MLV_COLOR_BLACK);
        MLV_actualise_window();


    }
/*SI PAR CLASSE MAIS DE TABLEAU*/
    if (*x > 25 && *x < 425 && *y > 25 && *y < 425 && *MODE == 1 && *bouton_1 == 1 && *bouton_2 == 2 && *bouton_3 == 1 && *bouton_4 == 1 && *accu != 0 && *POINT_NOIR == 0 ){
        
        *POINT_NOIR = 1; 
        if (*kselection > *accu){
            *kselection = *accu;
        }

        nx_pts->x = *x;
        nx_pts->y = *y;
        nx_pts->classe = 0;
        pixel_vers_float(*x, *y, &newx, &newy);
        clique->x = newx;
        clique->y = newy;
        clique->classe = 0;



        tableau_pour_k(*TOONS, *accu, *clique, TAB_K);




        
        MLV_draw_filled_rectangle(nx_pts->x, nx_pts->y, 5, 5, MLV_COLOR_BLACK);
        trier_ktab(*TAB_K, *accu);
        MLV_clear_window(MLV_COLOR_PURPLE4);
        affichage(bouton_1, bouton_2, bouton_3, bouton_4);
        Affiche_save(*accu, *sauvegarde);

        fusion_deux_fonction_ktab(*TAB_K, *kselection);

        MLV_draw_filled_rectangle(nx_pts->x, nx_pts->y, 5, 5, MLV_COLOR_BLACK);
        MLV_actualise_window();
        dessiner_cercle_bis(x, y, (*TAB_K)[*kselection - 1].x, (*TAB_K)[*kselection - 1].y);
        MLV_draw_filled_rectangle(nx_pts->x, nx_pts->y, 5, 5, MLV_COLOR_GREY);
        LACLASSE = classe_majoritaire(*TAB_K, *kselection);
        ajoute_classe_selection->classe=LACLASSE;
        ajoute_classe_selection->x=newx;
        ajoute_classe_selection->y=newy;

        cree_points(*x, *y, LACLASSE);
    }














/*Si voisin proche ARBRE*/
if (*x > 30 && *x < 420 && *y > 30 && *y < 420 && *MODE == 1 && *bouton_1 == 1 && *bouton_2 == 1 && *bouton_3 == 2 && *bouton_4 == 1 && *accu != 0 && *POINT_NOIR == 0){
        
        *POINT_NOIR = 1; 
        if (*kselection > *accu){
            *kselection = *accu;
        }

        nx_pts->x = *x;
        nx_pts->y = *y;
        nx_pts->classe = 0;
        pixel_vers_float(*x, *y, &newx, &newy);
        clique->x = newx;
        clique->y = newy;
        clique->classe = 0;
        
        liste_kppv_arbre = rechercher(*TOLGA, clique, *kselection);
        
        MLV_actualise_window();
        MLV_clear_window(MLV_COLOR_PURPLE4);
        affichage(bouton_1, bouton_2, bouton_3, bouton_4);
        cercle_arbre = est_plus_loins_arbre(*clique ,liste_kppv_arbre,*kselection);
        Affiche_save(*accu, *sauvegarde);

        plus_proche_colorer_arbre(liste_kppv_arbre, *kselection);

        dessiner_cercle_bis(x, y,cercle_arbre.x,cercle_arbre.y );
        MLV_draw_filled_rectangle(nx_pts->x, nx_pts->y, 5, 5, MLV_COLOR_BLACK);
        MLV_actualise_window();


    }


/*Si Classe proche Arbre*/

if (*x > 30 && *x < 420 && *y > 30 && *y < 430 && *MODE == 1 && *bouton_1 == 1 && *bouton_2 == 1 && *bouton_3 == 1 && *bouton_4 == 2 && *accu != 0 && *POINT_NOIR == 0){
        
        *POINT_NOIR = 1; 
        if (*kselection > *accu){
            *kselection = *accu;
        }

        nx_pts->x = *x;
        nx_pts->y = *y;
        nx_pts->classe = 0;
        pixel_vers_float(*x, *y, &newx, &newy);
        clique->x = newx;
        clique->y = newy;
        clique->classe = 0;

        
        liste_kppv_arbre = rechercher(*TOLGA, clique, *kselection);
       
        LACLASSE=trouver_classe(liste_kppv_arbre, *kselection);
        MLV_actualise_window();
        MLV_clear_window(MLV_COLOR_PURPLE4);
        affichage(bouton_1, bouton_2, bouton_3, bouton_4);
        cercle_arbre = est_plus_loins_arbre(*clique ,liste_kppv_arbre,*kselection);
        dessiner_cercle_bis(x, y,cercle_arbre.x,cercle_arbre.y );
        Affiche_save(*accu, *sauvegarde);

        plus_proche_colorer_arbre(liste_kppv_arbre, *kselection);

        cree_points(*x, *y, LACLASSE);
        ajoute_classe_selection->classe=LACLASSE;
        ajoute_classe_selection->x=newx;
        ajoute_classe_selection->y=newy;
        

        MLV_actualise_window();



    }



if (*x > 230 && *x < 420 && *y > 530 && *y < 560 && *MODE == 1  && *accu != 0){
        *TOLGA=inserer(*TOLGA,ajoute_classe_selection);
        (*accu)=(*accu);
        *sauvegarde = (save *)realloc(*sauvegarde, (*accu+1) * sizeof(save));
        *TOONS = (point *)realloc(*TOONS, (*accu+1) * sizeof(point)); 
        (*TOONS)[*accu].x = ajoute_classe_selection->x;
        (*TOONS)[*accu].y = ajoute_classe_selection->y;
        (*TOONS)[*accu].classe = ajoute_classe_selection->classe;
        conversion_vers_pixel(ajoute_classe_selection->x,ajoute_classe_selection->y,&ajout_deux_x,&ajout_deux_y);
        (*sauvegarde)[*accu].x = ajout_deux_x;
        (*sauvegarde)[*accu].y = ajout_deux_y;
        (*sauvegarde)[*accu].classe = ajoute_classe_selection->classe;
        (*accu)++;
}

    


/*======>LES BOUTON<========*/
/*======>1<========*/



    if (*x > 60 && *x < 75 && *y > 600 && *y < 615 && *MODE == 1 && *bouton_2 == 1 && *bouton_3 == 1 && *bouton_4 == 1 )
    {
        if (*bouton_1 == 1)
        {
            *bouton_1 = 2;
            selection_on_off(bouton_1, 60, 600);
            MLV_actualise_window();
        }
        else
        {
            *POINT_NOIR = 0;
            *bouton_1 = 1;
            selection_on_off(bouton_1, 60, 600);
            affichage(bouton_1, bouton_2, bouton_3, bouton_4);
            Affiche_save(*accu, *sauvegarde);
            MLV_actualise_window();
        }
    }

    /*======>2<========*/

    if (*x > 60 && *x < 75 && *y > 630 && *y < 645 && *MODE == 1 && *bouton_1 == 1 && *bouton_3 == 1 && *bouton_4 == 1 ){
        if (*bouton_2 == 1){
            *bouton_2 = 2;
            selection_on_off(bouton_2, 60, 630);
            MLV_actualise_window();
        }
        else{
            *POINT_NOIR = 0;
            *bouton_2 = 1;
            selection_on_off(bouton_2, 60, 630);
            affichage(bouton_1, bouton_2, bouton_3, bouton_4);
            Affiche_save(*accu, *sauvegarde);
            MLV_actualise_window();
        }
    }

/*======>3<========*/

if (*x > 60 && *x < 75 && *y > 660 && *y < 675 && *MODE == 1 && *bouton_1 == 1 && *bouton_2 == 1 && *bouton_4 == 1 ){
        if (*bouton_3 == 1){
            *bouton_3 = 2;
            selection_on_off(bouton_3, 60, 660);
            MLV_actualise_window();
        }
        else
        {
            *POINT_NOIR = 0;
            *bouton_3 = 1;
            selection_on_off(bouton_3, 60, 660);
            affichage(bouton_1, bouton_2, bouton_3, bouton_4);
            Affiche_save(*accu, *sauvegarde);
            MLV_actualise_window();
        }
    }

/*======>4<========*/

if (*x > 60 && *x < 75 && *y > 690 && *y < 705 && *MODE == 1 && *bouton_1 == 1 && *bouton_2 == 1 && *bouton_3 == 1 )
    {
        if (*bouton_4 == 1){
            *bouton_4 = 2;
            selection_on_off(bouton_4, 60, 690);
            MLV_actualise_window();
        }
        else{
            *POINT_NOIR = 0;
            *bouton_4 = 1;
            selection_on_off(bouton_4, 60, 690);
            affichage(bouton_1, bouton_2, bouton_3, bouton_4);
            Affiche_save(*accu, *sauvegarde);
            MLV_actualise_window();
        }
    }

    /*=======================================================*/


    if (*x > 30 && *x < 220 && *y > 488 && *y < 518 && *MODE == 1 && *POINT_NOIR==0 && *bouton_1==1 && *bouton_2==1 && *bouton_3==1 && *bouton_4==1) /*quand on clique sur KPPV au debut passer au MODE = 2*/ /*MODE 2*/{
        *MODE = 0;
        mode_crea("vide.txt", classeselection);
    }

    if (*x > 227 && *x < 425 && *y > 750 && *y < 780 && *MODE == 0) /*MODE 2*/{
        chargement_fichier_bouton(nomfichier, bouton_1, bouton_2,bouton_3,bouton_4, classeselection, sauvegarde, TOONS, TOLGA,accu);
    }

    if (*x > 227 && *x < 425 && *y > 532 && *y < 560 && *MODE == 0) /*MODE 2*/{
        classe_changement(classeselection);
        update_classe(classeselection);
    }
    if (*x > 174 && *x < 274 && *y > 425 && *y < 450 && *MODE == 0) /*MODE 2*/{
        *accu = 0;
        affichage(&reset, &reset, &reset, &reset);
        mode_crea("vide.txt", classeselection);
        *TOLGA=arbre_vide_kd();
    }
    if (*x > 230 && *x < 419 && *y > 488 && *y < 517) /*MODE 1&2*/{
        k_changement(kselection);
        update_k(kselection);
    }

    if (*x > 5 && *x < 105 && *y > 5 && *y < 25 && *MODE == 0) /*MODE 2  qui permet un retours en mode 1*/{
        *MODE = 1;
        MLV_clear_window(MLV_COLOR_PURPLE4);
        affichage(bouton_1, bouton_2, bouton_3, bouton_4);
        Affiche_save(*accu, *sauvegarde);
        MLV_actualise_window();
    }

    if (*x > 30 && *x < 420 && *y > 30 && *y < 420 && *MODE == 0) /*MODE 2 PERMET de cree un fichier avec des pts*/{
        MLV_draw_filled_rectangle(175, 425, 100, 25, MLV_COLOR_YELLOW);
        MLV_draw_text(205, 430, "STOP", MLV_COLOR_BLACK);
        while (boucle != 1){
            MLV_wait_mouse(&XM, &YM);

            if (XM > 227 && XM < 425 && YM > 532 && YM < 560 && *MODE == 0) /*MODE 2*/{

                classe_changement(classeselection);
                update_classe(classeselection);
            }
            if (XM > 30 && XM < 420 && YM > 30 && YM < 420){   
                *supprimer_pts=0;
                *sauvegarde = (save *)realloc(*sauvegarde, (*accu+1) * sizeof(save));
                *TOONS = (point *)realloc(*TOONS, (*accu+1) * sizeof(point)); 
                (*sauvegarde)[*accu].x = XM;
                (*sauvegarde)[*accu].y = YM;
                (*sauvegarde)[*accu].classe = *classeselection;

                pixel_vers_float(XM, YM, &conversionx, &conversiony);
                (*TOONS)[*accu].x = conversionx;
                (*TOONS)[*accu].y = conversiony;
                (*TOONS)[*accu].classe = *classeselection;
                partie_deux->x=conversionx;
                partie_deux->y=conversiony;
                partie_deux->classe = *classeselection;
                *TOLGA = inserer(*TOLGA, partie_deux);
                (*accu)++;

                dernier->x=conversionx;
                dernier->y=conversiony;
                dernier->classe=*classeselection;

                if (*classeselection == 1){
                    MLV_draw_line(XM - 2, YM - 2, XM + 2, YM + 2, MLV_COLOR_RED);
                    MLV_draw_line(XM - 2, YM + 2, XM + 2, YM - 2, MLV_COLOR_RED);
                    
                }

                else if (*classeselection == 2){
                    MLV_draw_line(XM - 2, YM, XM+ 2, YM, MLV_COLOR_BLUE);
                    
                }
                else{
                    printf("classe inexistante\n");
                }
                MLV_actualise_window();
            }
            if (XM > 175 && XM < 275 && YM > 425 && YM < 450){
                boucle = 1;
                MLV_draw_filled_rectangle(175, 425, 100, 25, MLV_COLOR_YELLOW);
                MLV_draw_text(205, 430, "reset", MLV_COLOR_BLACK);
                MLV_actualise_window();
            }
            if (XM > 30 && XM < 220 && YM > 750 && YM < 780){
                printf("debut_sauvegarde\n");
                fprintf(fichier, "%d 2 2\n", *accu);
                for (i = 0; i < *accu; i++){
                    pixel_vers_float_x((*sauvegarde)[i].x, &xx);
                    pixel_vers_float_y((*sauvegarde)[i].y, &yy);
                    if ((*sauvegarde)[i].classe==1 || (*sauvegarde)[i].classe==2){
                    fprintf(fichier, "%d %f %f\n", (*sauvegarde)[i].classe, xx, yy);
                    }
                }
            }
            if (XM > 30 && XM < 220 && YM > 530 && YM < 560 && *accu != 0 && *supprimer_pts==0){
                *supprimer_pts=1;
                supprimer_dernier_point((*accu)--, *sauvegarde);
                *TOLGA=supprimer(*TOLGA,dernier);

            }
        }
    }

    if (*x > 30 && *x < 220 && *y > 750 && *y < 780) /*MODE 1 & 2*/{
        fprintf(fichier, "%d 2 2\n", *accu);
        for (i = 0; i < *accu; i++){
            pixel_vers_float_x((*sauvegarde)[i].x, &xx);
            pixel_vers_float_y((*sauvegarde)[i].y, &yy);
            if ((*sauvegarde)[i].classe==1 || (*sauvegarde)[i].classe==2){
                fprintf(fichier, "%d %f %f\n", (*sauvegarde)[i].classe, xx, yy);
            }
        }
    }

free(nx_pts);
nx_pts=NULL;
free(clique);
clique=NULL;
free(partie_deux);
partie_deux=NULL;



}