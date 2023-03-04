#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int balance = 100;
    int bet;
    int result1, result2, result3;
    char playAgain = 'y';

    srand(time(NULL));

    
    FILE *fp;
    fp = fopen("Slot.txt", "w");

    printf("Welcome to the Slot Machine!\n");

    while (playAgain == 'y' && balance > 0) {
        printf("Your balance: %d\n", balance);
        printf("Enter your bet (0 to quit): ");
        scanf("%d", &bet);

        if (bet == 0) {
            break;
        }

        if (bet > balance) {
            printf("You don't have enough balance!\n");
            continue;
        }

        result1 = rand() % 10;
        result2 = rand() % 10;
        result3 = rand() % 10;

        printf("%d %d %d\n", result1, result2, result3);

        if (result1 == result2 && result2 == result3) {
            printf("You win! %d coins\n", bet * 10);
            balance += bet * 10;
        } else if (result1 == result2 || result2 == result3 || result1 == result3) {
            printf("You win! %d coins\n", bet * 3);
            balance += bet * 3;
        } else {
            printf("You lose!\n");
            balance -= bet;
        }

        
        fprintf(fp, "%d %d %d\n", result1, result2, result3);

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Thanks for playing! Your final balance is: %d\n", balance);

    
    fclose(fp);

    return 0;
}
