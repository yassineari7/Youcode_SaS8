#include <stdio.h>
#include <string.h>

#define MAX_RESERVATIONS 100

struct Reservation {
    char firstName[50];  
    char lastName[50];   
    char phone[20];      
    int age;             
    char status[20];     
    int reference;       
    char date[15];  
};

struct Reservation reservations[MAX_RESERVATIONS];
int reservationCount = 0;  

int generate_reference() {
    return 5000 + reservationCount;  
}

void add_reservation() {
    if (reservationCount < MAX_RESERVATIONS) {  
        printf("Enter first name: ");
        scanf("%s", reservations[reservationCount].firstName);  
        printf("Enter last name: ");
        scanf("%s", reservations[reservationCount].lastName);  
        printf("Enter phone: ");
        scanf("%s", reservations[reservationCount].phone); 
        printf("Enter age: ");
        scanf("%d", &reservations[reservationCount].age); 
        printf("Enter status (validé, reporté, annulé, traité): ");
        scanf("%s", reservations[reservationCount].status);  
        printf("Enter date (DD/MM/YYYY): ");
        scanf("%s", reservations[reservationCount].date);  

        reservations[reservationCount].reference = generate_reference();
        printf("Reservation added successfully! Reference: %d\n", reservations[reservationCount].reference);

        reservationCount++;  
    } else {
        printf("Reservation list is full.\n");  
    }
}

void modify_reservation(int reference) {
    int found = 0;
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].reference == reference) {  
            printf("Modifying reservation for %s %s:\n", reservations[i].firstName, reservations[i].lastName);
            printf("Enter new first name: ");
            scanf("%s", reservations[i].firstName);  
            printf("Enter new last name: ");
            scanf("%s", reservations[i].lastName); 
            printf("Enter new phone: ");
            scanf("%s", reservations[i].phone); 
            printf("Enter new age: ");
            scanf("%d", &reservations[i].age);  
            printf("Enter new status (validé, reporté, annulé, traité): ");
            scanf("%s", reservations[i].status);  
            printf("Enter new date (DD/MM/YYYY): ");
            scanf("%s", reservations[i].date);  

            printf("Reservation modified successfully!\n");
            found = 1;  
            break;
        }
    }
    if (!found) {
        printf("Reservation with reference %d not found.\n", reference);  
    }
}
    
void delete_reservation(int reference) {
    int found = 0;
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].reference == reference) {  
            for (int j = i; j < reservationCount - 1; j++) {
                reservations[j] = reservations[j + 1];  
            }
            reservationCount--;  
            printf("Reservation deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Reservation with reference %d not found.\n", reference);  
    }
}

void display_reservation(int reference) {
    int found = 0;
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].reference == reference) {
            printf("Reservation details:\n");
            printf("First Name: %s\n", reservations[i].firstName);  
            printf("Last Name: %s\n", reservations[i].lastName);  
            printf("Phone: %s\n", reservations[i].phone);  
            printf("Age: %d\n", reservations[i].age);  
            printf("Status: %s\n", reservations[i].status);  
            printf("Date: %s\n", reservations[i].date);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Reservation with reference %d not found.\n", reference);  
    }
}

void sort_by_name() {
    struct Reservation temp;
    for (int i = 0; i < reservationCount - 1; i++) {
        for (int j = 0; j < reservationCount - i - 1; j++) {
            if (strcmp(reservations[j].lastName, reservations[j + 1].lastName) > 0) {
                temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
        }
    }
    printf("Reservations sorted by name successfully.\n");
}

void search_by_reference(int reference) {
    int found = 0;
    for (int i = 0; i < reservationCount; i++) {
        if (reservations[i].reference == reference) {
            display_reservation(reference);  
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Reservation with reference %d not found.\n", reference);  
    }
}

void search_by_name(char name[]) {
    int found = 0;
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(reservations[i].lastName, name) == 0) {
            display_reservation(reservations[i].reference);
            found = 1;
        }
    }
    if (!found) {
        printf("No reservation found for last name %s.\n", name);
    }
}

void display_statistics() {
    int ageSum = 0, ageGroups[3] = {0, 0, 0};  
    int statusCount[4] = {0, 0, 0, 0};  

    for (int i = 0; i < reservationCount; i++) {
        ageSum += reservations[i].age;  

       
        if (strcmp(reservations[i].status, "validé") == 0) {
            statusCount[0]++;
        } else if (strcmp(reservations[i].status, "annulé") == 0) {
            statusCount[1]++;
        } else if (strcmp(reservations[i].status, "reporté") == 0) {
            statusCount[2]++;
        } else if (strcmp(reservations[i].status, "traité") == 0) {
            statusCount[3]++;
        }

       
        if (reservations[i].age <= 18) {
            ageGroups[0]++;
        } else if (reservations[i].age <= 35) {
            ageGroups[1]++;
        } else {
            ageGroups[2]++;
        }
    }

    printf("Average age: %.2f\n", (float)ageSum / reservationCount);  
    printf("0-18: %d patients\n19-35: %d patients\n36+: %d patients\n",
           ageGroups[0], ageGroups[1], ageGroups[2]);  
    printf("Reservations by status:\n");
    printf("Validé: %d\nAnnulé: %d\nReporté: %d\nTraité: %d\n", statusCount[0], statusCount[1], statusCount[2], statusCount[3]);  
}

void display_menu() {
    printf("\nDental Appointment Reservation System\n");
    printf("1. Add Reservation\n");
    printf("2. Modify Reservation\n");
    printf("3. Delete Reservation\n");
    printf("4. Display Reservation Details\n");
    printf("5. Sort Reservations by Name\n");
    printf("6. Search Reservation by Reference\n");
    printf("7. Search Reservation by Name\n");
    printf("8. Display Statistics\n");
    printf("9. Exit\n");
}

int main() {
    int choice, reference;
    char name[50];

    
    for (int i = 0; i < 10; i++) {
        snprintf(reservations[i].firstName, 50, "First%d", i + 1);  
        snprintf(reservations[i].lastName, 50, "Last%d", i + 1);    
        snprintf(reservations[i].phone, 20, "061234567%d", i + 1);  
        reservations[i].age = 20 + i;
        snprintf(reservations[i].status, 20, (i % 2 == 0) ? "validé" : "annulé");  
        reservations[i].reference = generate_reference();  
        snprintf(reservations[i].date, 15, "0%d/10/2024", i + 1); 
        reservationCount++;  
    }

    do {
        display_menu();  
        printf("Choose an option: ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                add_reservation(); 
                break;
            case 2:
                printf("Enter reference to modify: ");
                scanf("%d", &reference);
                modify_reservation(reference); 
                break;
            case 3:
                printf("Enter reference to delete: ");
                scanf("%d", &reference);
                delete_reservation(reference);
                break;
            case 4:
                printf("Enter reference to view details: ");
                scanf("%d", &reference);
                display_reservation(reference);
                break;
            case 5:
                sort_by_name();
                break;
            case 6:
                printf("Enter reference to search: ");
                scanf("%d", &reference);
                search_by_reference(reference);
                break;
            case 7:
                printf("Enter last name to search: ");
                scanf("%s", name);
                search_by_name(name);
                break;
            case 8:
                display_statistics();
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 9);

    return 0;
}