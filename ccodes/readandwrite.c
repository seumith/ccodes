#include <stdio.h>  // Include the standard I/O library for file operations and printing
#include <stdlib.h> // Include the standard library for functions like EXIT_FAILURE

// Define a structure to hold student details
struct dets {
    char name[50]; // Array to store the student's name
    char id[50];   // Array to store the student's ID
};

int main() {
    FILE *stud, *rud; // Pointers to FILE structures for handling file operations

    // Open the file "ranesh.txt" in read mode
    rud = fopen("ranesh.txt", "r");

    // Check if the file was successfully opened
    if (rud == NULL) {
        perror("Unable to open file named ranesh.txt"); // Print an error message if the file cannot be opened
        return EXIT_FAILURE; // Exit the program with a failure status
    }

    // Array to store the data read from "ranesh.txt"
    char rudDta[100];

    // Read a line from "ranesh.txt" into rudDta
    if (fgets(rudDta, sizeof(rudDta), rud) == NULL) {
        perror("Cannot read file named ranesh.txt"); // Print an error message if reading fails
        return EXIT_FAILURE; // Exit the program with a failure status
    }

    // Initialize a struct dets with specific values
    struct dets st1 = {"MANVESH", "6699FCK"};

    // Create the filename for the new file using the student's name and ID
    char studentFile[100];
    sprintf(studentFile, "%s%s.txt", st1.name, st1.id); // Format the filename as "MANVESH6699FCK.txt"

    // Open the newly created file in write mode
    stud = fopen(studentFile, "w");

    // Check if the file was successfully opened
    if (stud == NULL) {
        perror("Cannot open the file"); // Print an error message if the file cannot be opened
        return EXIT_FAILURE; // Exit the program with a failure status
    }

    // Write a greeting message to the new file
    fprintf(stud, "Hello nice to meet you %s\n", st1.name);
    // Write the contents read from "ranesh.txt" to the new file
    fprintf(stud, "%s", rudDta);

    // Close both files
    fclose(rud);
    fclose(stud);

    // Print a message indicating that the task is complete
    printf("Task completed");

    return 0; // Exit the program successfully
}
