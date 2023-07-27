#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Prime number checker, checks if a integer given by a user is considered prime, and then gives all the prime factors of the number.
// A number is prime only if it is divisible by 1 and itself.
bool is_valid_integer(const int number) {
    return (number > 1);
}

int isPrime(int num) {
    if (num <= 1)
        return 0; // Not prime if the number is less than or equal to 1

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0; // Not prime if it's divisible by any number from 2 to sqrt(num)
    }

    return 1; // Prime if no divisors found other than 1 and itself
}

// Main function begin
int main(void) {

    printf("\n* * * * WELCOME TO PRIME NUMBER BREAKDOWN * * * *\n");

    int userInt;

    while (1) {
        printf("Enter an integer: ");

        if (scanf("%d", &userInt) != 1) {
            // Invalid input (not an integer)
            printf("Invalid input! Please enter a valid integer.\n");

            // Clear the input buffer to avoid an infinite loop
            while (getchar() != '\n')
                continue;

            continue;
        } 

        // Check if the input is valid
        if (!is_valid_integer(userInt)) {
            printf("Invalid input! Please enter an integer greater than 1.\n");
            continue;
        } else {
            break;
        }

    }

    // Begin checking process
    int* primeArray = NULL;
    int size = 0;
    
    for (int i = 2; i <= (userInt / 2) + 1; i++) {
        if (userInt % i == 0 && isPrime(i)) {
            // Increase the size of the array to accommodate the new element
            size++;
            primeArray = (int*)realloc(primeArray, size * sizeof(int));

            // Check if memory allocation was successful
            if (primeArray == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            // Add the new element to the end of the array
            primeArray[size - 1] = i;
        } else {
            continue;
        }
    }

    // Show results
    if (size == 0) {
        printf("%d is a prime number.", userInt);
    } else {
        printf("%d is not a prime number.", userInt);
        printf("\nThe prime factors of %d are: ", userInt);
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                printf("%d", primeArray[i]);
            } else {
                printf("%d, ", primeArray[i]);
            }
        }
    }

    // Free the allocated memory
    free(primeArray);

    // Prompt user for another integer
    while (1) {
        char againResponse = ' ';
        printf("\nAnother new prime breakdown? (Y/N): ");
        scanf(" %c", &againResponse);

        if (againResponse == 'Y' || againResponse == 'y') {
            main();
        } else if (againResponse == 'N' || againResponse == 'n') {
            exit(0);
        } else {
            printf("Invalid response. Please enter 'Y' or 'N'.\n");
        }
    }

    return 0;
}
