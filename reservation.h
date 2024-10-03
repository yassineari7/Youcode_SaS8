#ifndef RESERVATION_H
#define RESERVATION_H

#define MAX_RESERVATIONS 100

// Structure for reservation
struct Reservation {
    char first_name[50];
    char last_name[50];
    char phone[15];
    int age;
    char status[15];
    int reference;
    char date[15];
};

// Function prototypes
void add_reservation(struct Reservation reservations[], int count);
void modify_reservation(struct Reservation reservations[], int count);
void display_reservations(struct Reservation reservations[], int count);
void search_reservation(struct Reservation reservations[], int count);
void sort_by_name(struct Reservation reservations[], int count);
void sort_by_status(struct Reservation reservations[], int count);
void show_statistics(struct Reservation reservations[], int count);
void insert_default_reservations(struct Reservation reservations[], int *count);

#endif // RESERVATION_H