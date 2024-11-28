#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Fonction permettant de générer un aléatoire entre 2 double*/
double frand_a_b(double a, double b){
    return ( rand()/(double)RAND_MAX ) * (b-a) + a ;
}


/*Fonction permettant de générer les données néccessaire au programme*/
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
        fprintf(fichier,"%d %f %f\n",classe,x,y);
    }
    fclose(fichier);
    return;
}

int main(int argc, char *argv[]){
    int nb, d, c;
    srand(time(NULL));
    if(argc<5){
        fprintf(stderr,"Il faut au moins 4 arguments\n");
        exit(EXIT_FAILURE);
    }
    nb=atoi(argv[2]);
    d=atoi(argv[3]);
    c=atoi(argv[4]);
    creation(argv[1],nb,d,c);
    exit(EXIT_SUCCESS);
}
