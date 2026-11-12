/*
 * Project: Console-based Number Guessing Game
 * Description: The computer generates a random number (1-100)
 *              and the user attempts to guess it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret, guess, attempts = 0;
    char choice;

    srand(time(NULL));  // seed the random number generator

    do {
        secret = rand() % 100 + 1;  // random number from 1 to 100
        attempts = 0;

        printf("\n=== Number Guessing Game ===\n");
        printf("I have picked a number between 1 and 100.\n");
        printf("Can you guess it?\n\n");

        do {
            printf("Enter your guess: ");
            if (scanf("%d", &guess) != 1) {
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n');  // clear input buffer
                continue;
            }

            attempts++;

            if (guess < secret) {
                printf("Too low! Try again.\n");
            } else if (guess > secret) {
                printf("Too high! Try again.\n");
            } else {
                printf("\nCorrect! You guessed the number %d in %d attempt(s).\n",
                       secret, attempts);
            }
        } while (guess != secret);

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for playing. Goodbye!\n");
    return 0;
}
