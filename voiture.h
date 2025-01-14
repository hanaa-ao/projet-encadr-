#ifndef VOITURE_H
#define  VOITURE_H
#define MAX_voiture 100


typedef struct {
char modele[25];
char marque[30];
float prix;
int disponible;
} Voiture;

typedef struct{
char nom [25];
char prenom [25];
char ID[15];
}Client;

typedef struct{
    char nom[25];
    char prenom [25];
    char code[15];
}resp;


void saisir (Client T,int N);
void Admininfo (resp A);
void afficherAppc(void);
void afficherAppa(void );
void ajoutervoiture(Voiture V[],int N);
void affichervoiture(Voiture V[],int N);
void modifiervoiture(Voiture V[], int N);
void supprimervoiture(Voiture V[], int N) ;
void recherchervoiture(Voiture V[],int N);
void triervoitures(Voiture V[], int N);
void enregistrercvs(Voiture V[], int N);

#endif
