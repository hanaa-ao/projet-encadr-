#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "voiture.h"




int main(void){


    int N=1;
    int choix ;
    Client T;
    Voiture V[100];
    resp A;
    int k;
    char person [20],cv[30];
 
    
    printf("Bienvenue dans notre service de location de voitures !:\n");
    printf("vous etes client ou admin :\n");
    scanf("%s",person);
    
    
    if (strcmp (person ,"admin")==0){
        
        Admininfo (A);
        
        printf("vous pouvez entrer le code de verefication:\n");
        scanf("%s",cv);
        
        if (strcmp(cv,"12ad88")==0){
            printf("bienvenu :\n");
            
             afficherAppa();
            
            do{
                printf("entrer votre choix :");
                scanf("%d",&choix);
                
                switch (choix) {
                    case 1:
                        ajoutervoiture(V,N);
                        printf("voulez vous retourner au menu pricipal : (1: Oui, 0:non )");
                        scanf("%d",&k);
                        do{
                            break;
                        }while((k==1));
                    case 2:
                        
                        affichervoiture(V,N);
                        break;
                    case 3:
                        modifiervoiture(V,N);
                        break;
                    case 4:
                        supprimervoiture(V,N);
                        break;
                    case 5:
                        enregistrercvs(V,N) ;
                        break;
                    case 0:
                        printf("\n vous avez quitte ; Au revoir !\n");
                        break;
                    default:
                        printf("\nChoix invalide. Veuillez réessayer.\n");
                }
            }while((choix != 0));
        } }
    
    else{
        saisir (T,N);
        printf("voici le menu :\n");
        
        afficherAppc();
        
        do{
            
      
            printf("entrer votre choix :");
            scanf("%d",&choix);
            
       switch (choix) {
                    
                    case 1:
                        affichervoiture(V, N);
                        break;
                    case 2:
                        recherchervoiture(V, N);
                        break;
                    case 3:
                        triervoitures(V, N);
                        break;
                   
                    case 0:
                        printf("\n vous avez quitte ; Au revoir !\n");
                        break;
                    default:
                        printf("\nChoix invalide. Veuillez réessayer.\n");
                }
        }while((choix != 0));
        
       
        return 0;
            }
        
    }
        
        
        
    

    
    
    


