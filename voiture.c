#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "voiture.h"

// fonction pour le client

void saisir (Client T,int N){

printf("saisir les informations du client  :\n");
printf("saisir le nom:");
scanf("%s",T.nom);
printf("saisir le prenom : ");
scanf("%s",T.prenom);
printf("saisir le ID : ");
scanf("%s", T.ID);

    printf("vous pouvez utiliser l'application :\n");
    
}

void Admininfo (resp A){
   
    printf("entrer votre nom et prenom :");
    scanf("%s %s",A.nom,A.prenom);
    printf("entrer le ID:");
    scanf("%s",A.code);
    
}

//fonction afficher menu admin

void afficherAppa(void ) {
    printf("\n=== Menu Gestion de Location de Voitures ===\n");
    printf("1. Ajouter les voitures\n");
    printf("2. Afficher voiture\n");
    printf("3. modifier voiture\n");
    printf("4. supprimer voiture \n");
    printf("5. stocker dans le fichier \n");
    printf("0. Quitter\n");
}




//fonction pour afficher menu client 

void afficherAppc(void ) {
    printf("\n=== Menu Gestion de Location de Voitures ===\n");
    printf("1. Afficher les voitures\n");
    printf("2. Rechercher une voiture\n");
    printf("3. Trier les voitures\n");
    printf("0. Quitter\n");
}


// fonction pour ajouter les voitures

void ajoutervoiture(Voiture V[],int N){
   
    printf("entrer le nombre des voiture :");
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        printf("entrer les information du %d voiture:\n",i+1);
        printf("entrer la marque:");
        scanf("%s",V[i].marque);
        printf("entrer le modele:");
        scanf("%s",V[i].modele);
        printf("entrer le prix par jour:");
        scanf("%f",&V[i].prix);
        printf("Disponibilité (1 pour disponible, 0 pour non disponible) : ");
        scanf("%d",&V[i].disponible);
    }
}


// fonction d'affichage des voitures

void affichervoiture(Voiture V[],int N){
    
   
    printf("\nListe des voitures :\n");
    printf(" Marque | Modèle | Prix/Jour | Disponibilité\n");
    printf("-------------------------------------------------------------------------------\n");
    for (int i= 0 ; i < N; i++){
            printf(" %s | %s | %.2f | %s \n",
                   V[i].marque,
                   V[i].modele,
                   V[i].prix,
                   V[i].disponible ? "Disponible" : "Non disponible");
    } }


    // modifier voiture


void modifiervoiture(Voiture V[], int N) {
    char mod [50];
    
    printf("Entrez la marque ou le modèle à modifier : ");
    scanf("%s", mod);

    for (int i = 0; i < N; i++) {
        if (strcmp(V[i].marque, mod) == 0 || strcmp(V[i].modele,mod) == 0) {
            printf("\nAnciennes informations : %s %s %.2f %d\n", V[i].marque, V[i].modele, V[i].prix, V[i].disponible);
            printf("Nouveau prix : ");
            scanf("%f", &V[i].prix);
            printf("Nouvelle disponibilité (1: disponible, 0: non disponible) : ");
            scanf("%d", &V[i].disponible);
            printf("Modification réussie.\n");
        }
    }

}

// supprimer voiture

void supprimervoiture(Voiture V[], int N) {
    char mod[50];
    
    printf("Entrez la marque ou le modèle à supprimer : ");
    scanf("%s", mod);

    for (int i = 0; i < N; i++) {
        if (strcmp(V[i].marque, mod) == 0 || strcmp(V[i].modele,mod) == 0) {
            
            for (int j = i ; j < N - 1; j++) {
                V[j] = V[j + 1];    }
          
            printf("Voiture supprimée.\n");
           
        }
    }
    
}
    

// fonction de recherche du voiture

void recherchervoiture(Voiture V[],int N){
    char M[100];
    
    printf("recherche par marque :\n");
    printf("entrer le nom de la marque:");
    scanf("%s",M);
    
    for(int i=0;i<N ;i++){
        if (strcmp(V[i].marque, M) == 0) {
                   printf("%s | %s | %.2f | %s\n",
                         V[i].marque,
                        V[i].modele,
                       V[i].prix,
                      V[i].disponible ? "Disponible" : "Non disponible");
               }
           }
       }


// fonction de tri de voiture
    
void triervoitures(Voiture V[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N- i - 1; j++) {
            if (V[j].prix > V[j + 1].prix) {
                Voiture temp = V[j];
              V[j] = V[j + 1];
              V[j + 1] = temp;
            }
        }
    }

    printf("\nVoitures triées par prix de location par jour.\n");
    for (int i = 0; i < N; i++) {
        printf(" %s | %s | %.2f | %s \n",
               V[i].marque,
               V[i].modele,
               V[i].prix,
              V[i].disponible ? "Disponible" : "Non disponible");
    }
}

// enregistrer cvs

void enregistrercvs(Voiture V[],int N) {
    FILE *f = fopen("cvs.txt", "w");
    if (f==NULL) {
        printf("\nErreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(f,"Marque, Modèle, Prix, Disponibilité \n");
    
    for (int i = 0; i < N; i++) {
        fprintf(f, "%s, %s, %.2f, %d\n",
               V[i].marque,
               V[i].modele,
               V[i].prix,
               V[i].disponible);
    }

    fclose(f);
}









    
    



