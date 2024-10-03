#include <stdio.h>
#include <string.h>

struct Reservation {
    char nom[50];
    char prenom[50];
    char telephone[15];
    int age;
    char statut[10];
    int reference;
    char date_reservation[20];
 };


 struct Reservation reservations[100];
int compteur = 0;

int generer_reference() {
    return compteur + 4001;
}

// Fonction bach nzid réservation jdida
void ajouter_reservation() {
    struct Reservation nouvelleReservation;

    printf("Nom: ");
    scanf("%s", nouvelleReservation.nom);

    
    printf("Prénom: ");
    scanf("%s", nouvelleReservation.prenom);

    
    printf("Téléphone: ");
    scanf("%s", nouvelleReservation.telephone);

    
    printf("Âge: ");
    scanf("%d", &nouvelleReservation.age);

    
    printf("Statut (validé, reporté, annulé, traité): ");
    scanf("%s", nouvelleReservation.statut);

    
    printf("Date de réservation (jj/mm/aaaa): ");
    scanf("%s", nouvelleReservation.date_reservation);

    
    nouvelleReservation.reference = generer_reference();


    reservations[compteur] = nouvelleReservation;
    compteur++;

    printf("Réservation tzadit b'success ! Référence: %d\n", nouvelleReservation.reference);
}
int chercher_reservation(int reference) {
    for (int i = 0; i < compteur; i++) {
        if (reservations[i].reference == reference) {
            return i;
                 }
    }
    return -1;  
}

void modifier_reservation() {
    int reference;
    printf("Entrez la référence de la réservation à modifier: ");
    scanf("%d", &reference);

    int index = chercher_reservation(reference);
    if (index != -1) {
        printf("Nouvel âge: ");
        scanf("%d", &reservations[index].age);
        
        printf("Nouveau statut (validé, reporté, annulé, traité): ");
        scanf("%s", reservations[index].statut);
        
        printf("Nouvelle date de réservation (jj/mm/aaaa): ");
        scanf("%s", reservations[index].date_reservation);

        printf("Réservation modifiée avec succès !\n");
    } else {
        printf("Réservation non trouvée !\n");
    }
}
// Fonction bach nsuprimi réservation
void supprimer_reservation() {
    int reference;
    printf("Entrez la référence de la réservation à supprimer: ");
    scanf("%d", &reference);

    int index = chercher_reservation(reference);
    if (index != -1) {
        for (int i = index; i < compteur - 1; i++) {
            reservations[i] = reservations[i + 1];  // Décalage des éléments
        }
        compteur--;
        printf("Réservation supprimée avec succès !\n");
    } else {
        printf("Réservation non trouvée !\n");
    }
}

// Fonction bach n'affichi les détails dyal réservation
void afficher_reservation() {
    int reference;
    printf("Entrez la référence de la réservation à afficher: ");
    scanf("%d", &reference);

    int index = chercher_reservation(reference);
    if (index != -1) {
        printf("\n--- Détails de la Réservation ---\n");
        printf("Nom: %s\n", reservations[index].nom);
        printf("Prénom: %s\n", reservations[index].prenom);
        printf("Téléphone: %s\n", reservations[index].telephone);
        printf("Âge: %d\n", reservations[index].age);
        printf("Statut: %s\n", reservations[index].statut);
        printf("Référence: %d\n", reservations[index].reference);
        printf("Date de réservation: %s\n", reservations[index].date_reservation);
        printf("-------------------------------\n");
    } else {
        printf("Réservation non trouvée !\n");
    }
}