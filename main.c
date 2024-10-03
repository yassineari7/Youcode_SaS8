#include <stdio.h>
#include "reservation.h"

int main() {
    struct Reservation reservations[MAX_RESERVATIONS];
    int count = 0;

    insert_default_reservations(reservations, &count); // Insert default reservations

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Reservation\n");
        printf("2. Modify Reservation\n");
        printf("3. Display Reservations\n");
        printf("4. Search Reservation\n");
        printf("5. Sort Reservations by Name\n");
        printf("6. Sort Reservations by Status\n");
        printf("7. Show Statistics\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_reservation(reservations, count);
                count++; // Increase count after adding
                break;
            case 2:
                modify_reservation(reservations, count);
                break;
            case 3:
                display_reservations(reservations, count);
                break;
            case 4:
                search_reservation(reservations, count);
                break;
            case 5:
                sort_by_name(reservations, count);
                printf("Reservations sorted by name.\n");
                break;
            case 6:
                sort_by_status(reservations, count);
                printf("Reservations sorted by status.\n");
                break;
            case 7:
                show_statistics(reservations, count);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}