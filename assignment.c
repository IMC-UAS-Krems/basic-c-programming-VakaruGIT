#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    // WRITE YOUR CODE HERE
    // Check if number of arguments is different from 2 // argc is the number of arguments
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc - 1);
        return 1;
    }
    // Arguments need to be integers greater than 0 // atoi() is used to convert string to integer
    if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers");
        return 1;
    }

    // Convert arugments to integers
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *)); // **matrix is a pointer to a pointer
    for (int i = 0; i < rows; i++) { 
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (maxrand - minrand + 1) + minrand;
        }
    }

    // Open file for writing
    FILE *file = fopen("matrix.txt", "w");
    if (!file) { // if file does not exist
        printf("Failed opening the file");
        return 1;
    }

    // Write matrix to file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == cols - 1) {
                fprintf(file, "%d", matrix[i][j]); // fprintf() writes formatted output to file
            }
            else{
                fprintf(file, "%d ", matrix[i][j]); 
            }

        }
    if (i != rows - 1){ // add the newline only if it is not the last row
        fprintf(file, "\n");
    }
    }
    fclose(file);

    // Free memory (good practice because we allocated memory)
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
    // i tried the code with the arguments 5 5
}
