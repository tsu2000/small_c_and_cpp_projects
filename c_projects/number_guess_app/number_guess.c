#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    const int MIN = 1;
    const int MAX = 100;
    int guess; 
    int guesses = 0;
    int answer;

    // Use current time as seed
    srand(time(0));

    answer = (rand() % MAX) + MIN;

    char output[100];
    sprintf(output, "Guess a number between %d and %d\n", MIN, MAX);
    printf("%s", output);

    do {
        scanf("%d", &guess);
        if (guess < answer) {
            printf("Guess is too low!\n");
        } else if (guess > answer) {
            printf("Guess is too high!\n");
        }
        guesses++;
    } while (guess != answer);

    printf("* * * Result * * *\n");
    printf("The answer was %d.\n", answer);
    char buffer[100];
    sprintf(buffer, "You took %d guesses to reach the correct answer.\n", guesses);
    printf("%s", buffer);

    return 0;
}
