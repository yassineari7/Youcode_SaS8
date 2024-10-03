Dental Appointment Reservation Management System
Introduction
This application allows users to manage dental appointment reservations, providing features such as adding, modifying, and deleting reservations, tracking their status, and generating statistics.

Features
The application includes a main menu with the following functionalities:

Add Reservation:

Allows users to add a new reservation by providing the following information:
First Name
Last Name
Phone Number
Age
Status (validated, postponed, canceled, processed)
Unique Reference Number (automatically generated)
Reservation Date
Modify or Delete Reservation:

Enables users to modify or delete an existing reservation based on the unique reference number.
Display Reservation Details:

Users can view complete information about a reservation, including the date and status.
Sorting Reservations:

Sort reservations by:
Name
Status (validated, postponed, canceled, processed)
Date (optional)
Search Reservations:

Search for a reservation by:
Unique Reference Number
Name
Date (optional)
Statistics:

Calculate the average age of patients who have made reservations.
Display the number of patients by age group (e.g., 0-18 years, 19-35 years, 36+ years).
Generate statistics to know the total number of reservations by status (validated, canceled, etc.).
Notes:
The project includes 10 default reservations that are automatically inserted when the program is executed.
Required Functionalities
Variables: Used to store reservation information.
Conditions: Employed to search, modify, and delete reservations.
Loops: Used to iterate through and display the list of reservations.
Arrays: To store multiple reservations.
Strings: To manipulate names, phone numbers, etc.
Structures: To group information related to a reservation.
Project Structure
less
Copier le code
.
├── main.c                // Main application file
├── reservation.c         // Implementation of reservation functionalities
├── reservation.h         // Header file defining reservation structure and function prototypes
└── README.md             // Project documentation
How to Compile and Run
To compile the application, use the following command:

bash
Copier le code
gcc main.c reservation.c -o reservation_system
Then, run the application with:

bash
Copier le code
./reservation_system
Conclusion
This application serves as an efficient tool for managing dental appointments, enhancing organization and accessibility for both patients and dental practitioners. It emphasizes usability and functionality, ensuring a smooth experience for managing reservations.
