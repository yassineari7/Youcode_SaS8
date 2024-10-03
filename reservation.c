#include <stdio.h>
#include <string.h>
#include "reservation.h"

// Function to add a reservation
void add_reservation(struct Reservation reservations[], int count) {
    if (count >= MAX_RESERVATIONS) {
        printf("Cannot add more reservations.\n");
        return;
    }

    struct Reservation new_reservation;

    // Getting details from the user
    printf("Enter first name: ");
    scanf("%s", new_reservation.first_name);
    printf("Enter last name: ");
    scanf("%s", new_reservation.last_name);
    printf("Enter phone number: ");
    scanf("%s", new_reservation.phone);
    printf("Enter age: ");
    scanf("%d", &new_reservation.age);
    printf("Enter status (validated, postponed, canceled, processed): ");
    scanf("%s", new_reservation.status);
    
    // Generate unique reference
    new_reservation.reference = 4000 + count + 1; 
    printf("Enter reservation date (YYYY-MM-DD): ");
    scanf("%s", new_reservation.date);

    // Add the new reservation
    reservations[count] = new_reservation;

    printf("Reservation added successfully! Reference: %d\n", new_reservation.reference);
}

// Function to modify an existing reservation
void modify_reservation(struct Reservation reservations[], int count) {
    int reference;
    printf("Enter reference number to modify: ");
    scanf("%d", &reference);
    
    for (int i = 0; i < count; i++) {
        if (reservations[i].reference == reference) {
            // Modify reservation details
            printf("Enter new first name: ");
            scanf("%s", reservations[i].first_name);
            printf("Enter new last name: ");
            scanf("%s", reservations[i].last_name);
            printf("Enter new phone number: ");
            scanf("%s", reservations[i].phone);
            printf("Enter new age: ");
            scanf("%d", &reservations[i].age);
            printf("Enter new status: ");
            scanf("%s", reservations[i].status);
            printf("Enter new reservation date: ");
            scanf("%s", reservations[i].date);
            printf("Reservation modified successfully!\n");
            return;
        }
    }
    printf("Reservation not found!\n");
}

// Function to display all reservations
void display_reservations(struct Reservation reservations[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Reference: %d, Name: %s %s, Phone: %s, Age: %d, Status: %s, Date: %s\n",
            reservations[i].reference, reservations[i].first_name,
            reservations[i].last_name, reservations[i].phone,
            reservations[i].age, reservations[i].status,
            reservations[i].date);
    }
}

// Function to search for a reservation
void search_reservation(struct Reservation reservations[], int count) {
    int reference;
    printf("Enter reference number to search: ");
    scanf("%d", &reference);
    
    for (int i = 0; i < count; i++) {
        if (reservations[i].reference == reference) {
            printf("Reference: %d, Name: %s %s, Phone: %s, Age: %d, Status: %s, Date: %s\n",
                reservations[i].reference, reservations[i].first_name,
                reservations[i].last_name, reservations[i].phone,
                reservations[i].age, reservations[i].status,
                reservations[i].date);
            return;
        }
    }
    printf("Reservation not found!\n");
}

// Function to sort reservations by name
void sort_by_name(struct Reservation reservations[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(reservations[j].first_name, reservations[j + 1].first_name) > 0) {
                struct Reservation temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
        }
    }
}

// Function to sort reservations by status
void sort_by_status(struct Reservation reservations[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(reservations[j].status, reservations[j + 1].status) > 0) {
                struct Reservation temp = reservations[j];
                reservations[j] = reservations[j + 1];
                reservations[j + 1] = temp;
            }
        }
    }
}

// Function to show statistics
void show_statistics(struct Reservation reservations[], int count) {
    int age_sum = 0;
    int count_0_18 = 0;
    int count_19_35 = 0;
    int count_36_plus = 0;
    int status_count[4] = {0, 0, 0, 0}; // validated, postponed, canceled, processed

    for (int i = 0; i < count; i++) {
        age_sum += reservations[i].age;

        if (reservations[i].age <= 18) count_0_18++;
        else if (reservations[i].age <= 35) count_19_35++;
        else count_36_plus++;

        if (strcmp(reservations[i].status, "validated") == 0) status_count[0]++;
        else if (strcmp(reservations[i].status, "postponed") == 0) status_count[1]++;
        else if (strcmp(reservations[i].status, "canceled") == 0) status_count[2]++;
        else if (strcmp(reservations[i].status, "processed") == 0) status_count[3]++;
    }

    printf("Average age of patients: %.2f\n", (double)age_sum / count);
    printf("Number of patients aged 0-18: %d\n", count_0_18);
    printf("Number of patients aged 19-35: %d\n", count_19_35);
    printf("Number of patients aged 36+: %d\n", count_36_plus);
    printf("Total reservations by status:\n");
    printf("Validated: %d\n", status_count[0]);
    printf("Postponed: %d\n", status_count[1]);
    printf("Canceled: %d\n", status_count[2]);
    printf("Processed: %d\n", status_count[3]);
}

// Function to insert default reservations
void insert_default_reservations(struct Reservation reservations[], int *count) {
    struct Reservation default_reservations[10] = {
        {"Ali", "Elhami", "0612345678", 25, "validated", 4001, "2024-10-01"},
        {"Sara", "Bakkali", "0612345679", 30, "postponed", 4002, "2024-10-02"},
        {"Hassan", "Haddad", "0612345680", 20, "canceled", 4003, "2024-10-03"},
        {"Laila", "Amar", "0612345681", 28, "processed", 4004, "2024-10-04"},
        {"Rachid", "Mouhssine", "0612345682", 40, "validated", 4005, "2024-10-05"},
        {"Fatima", "Zahra", "0612345683", 50, "postponed", 4006, "2024-10-06"},
        {"Ibrahim", "Ouarzazi", "0612345684", 29, "canceled", 4007, "2024-10-07"},
        {"Nadia", "Benjelloun", "0612345685", 35, "processed", 4008, "2024-10-08"},
        {"Youssef", "Ouhbi", "0612345686", 41, "validated", 4009, "2024-10-09"},
        {"Samira", "Azzouzi", "0612345687", 28, "postponed", 4010, "2024-10-10"}
    };

    for (int i = 0; i < 10; i++) {
        reservations[*count] = default_reservations[i];
        (*count)++;
    }
}