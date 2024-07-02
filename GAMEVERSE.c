#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define WIDTH 30
#define HEIGHT 20
#define ENEMY_COUNT 8
#define BULLET_SPEED 1
#define ENEMY_SPEED 0.5
#define ROCK_SPEED 1
#define ROCK_COUNT 3

int playerX, playerY;
int enemyX[ENEMY_COUNT], enemyY[ENEMY_COUNT];
int bulletX, bulletY;
int rockX[ROCK_COUNT], rockY[ROCK_COUNT];
int score;
int lives;

void printChoice(int choice)
{
        switch (choice)
        {
        case 1:
                printf("Rock");
                break;
        case 2:
                printf("Paper");
                break;
        case 3:
                printf("Scissors");
                break;
        }
}

void initializeGame()
{
        playerX = WIDTH / 2;
        playerY = HEIGHT - 1;
        bulletX = -1;
        bulletY = -1;
        score = 0;
        lives = 3;

        srand(time(NULL));
        for (int i = 0; i < ENEMY_COUNT; i++)
        {
                enemyX[i] = rand() % WIDTH;
                enemyY[i] = rand() % 3;
        }

        for (int i = 0; i < ROCK_COUNT; i++)
        {
                rockX[i] = rand() % WIDTH;
                rockY[i] = rand() % HEIGHT;
        }
}

void drawGame()
{
        system("cls");
        for (int y = 0; y < HEIGHT; y++)
        {
                for (int x = 0; x < WIDTH; x++)
                {
                        if (x == playerX && y == playerY)
                        {
                                printf("P");
                        }
                        else if (x == bulletX && y == bulletY)
                        {
                                printf("|");
                        }
                        else
                        {
                                int isEntity = 0;
                                for (int i = 0; i < ENEMY_COUNT; i++)
                                {
                                        if (enemyX[i] == x && enemyY[i] == y)
                                        {
                                                printf("E");
                                                isEntity = 1;
                                                break;
                                        }
                                }
                                for (int i = 0; i < ROCK_COUNT; i++)
                                {
                                        if (rockX[i] == x && rockY[i] == y)
                                        {
                                                printf("O");
                                                isEntity = 1;
                                                break;
                                        }
                                }
                                if (!isEntity)
                                {
                                        printf(" ");
                                }
                        }
                }
                printf("\n");
        }
        printf("Score: %d Lives: %d\n", score, lives);
}

void updateGame()
{
        // Move bullet
        if (bulletY >= 0)
        {
                bulletY -= BULLET_SPEED;
        }
        // Move enemies
        for (int i = 0; i < ENEMY_COUNT; i++)
        {
                enemyY[i] += ENEMY_SPEED;
                if (enemyY[i] >= HEIGHT)
                {
                        enemyX[i] = rand() % WIDTH;
                        enemyY[i] = 0;
                        lives--; // Lose a life if an enemy reaches the bottom
                }
        }
        // Move rocks
        for (int i = 0; i < ROCK_COUNT; i++)
        {
                rockY[i] += ROCK_SPEED;
                if (rockY[i] >= HEIGHT)
                {
                        rockX[i] = rand() % WIDTH;
                        rockY[i] = 0;
                }
                if (rockX[i] == playerX && rockY[i] == playerY)
                {
                        lives--; // Lose a life if a rock hits the player
                        rockX[i] = rand() % WIDTH;
                        rockY[i] = 0;
                }
        }
        // Check for bullet collisions with enemies
        if (bulletY >= 0)
        {
                for (int i = 0; i < ENEMY_COUNT; i++)
                {
                        if (bulletX == enemyX[i] && bulletY == enemyY[i])
                        {
                                score++;
                                bulletX = -1;
                                bulletY = -1;
                                enemyX[i] = rand() % WIDTH;
                                enemyY[i] = 0;
                        }
                }
        }
}
int random()
{
        return rand() % 20 + 5;
}
int rollDice()
{
        return rand() % 6 + 1;
}

void displayResult(int usernumber, int randnum)
{
        printf("\nPress Enter to continue...\n");
        getchar(); // Wait for user to press enter before continuing
}

void clearConsole()
{
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
}

int main()
{
        int choice;
        char playAgain;

        do
        {
                int inp;

                printf("  GGGG      A       M      M   EEEEE V       V EEEEE  RRRRR    SSSSSS  EEEEE\n");
                printf(" G         A A      M M  M M   E      V     V  E      R    R  S        E    \n");
                printf(" G  GGG   AAAAA     M   M  M   EEEE    V   V   EEEE   RRRRR    SSSSS   EEEE \n");
                printf(" G   GG  A     A    M      M   E        V V    E      R   R         S  E    \n");
                printf("  GGGG  A       A   M      M   EEEEEE    V     EEEEEE R    R  SSSSSS   EEEEE\n");

                printf("\n                                 (CHOOSE YOUR GAME) \n");
                printf("\n                                   1. Mind Reader\n");
                printf("\n                                   2. Dice Roll\n");
                printf("\n                                   3. Shooter\n");
                printf("\n                                   4. ROCK - PAPER - SCISSOR\n");

                scanf("%d", &inp);

#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif
                switch (inp)
                {
                case 1:
                {
                        printf(" M      M    IIIIII   N    N  DDDDD  \n");
                        printf(" M M  M M      II     NN   N  D    D \n");
                        printf(" M   M  M      II     N N  N  D    D\n");
                        printf(" M      M      II     N  N N  D    D\n");
                        printf(" M      M    IIIIII   N   NN  DDDDD \n");

                        srand(time(NULL));

                        int yes;
                        char choice;
                        int give = random();
                        do
                        {

                                if (give % 2 == 0)
                                {
                                        give = give;
                                }
                                else
                                {
                                        give = give + 1;
                                }

                                printf("\n\n >>>>>>  I CAN READ YOUR MIND  <<<<<<\n\n Don't Believe me? Start Then...........\n\n");
                                printf("    Think Of Any Number in your Mind.\n\n");
                                printf("(!!NOTE!! Remember The Number)\n\n");
                                printf("If You Have Thought Of The Number, Press 1 \n\n");

                                scanf("%d", &yes);
#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                                if (yes == 1)
                                {
                                        printf("\nMultiply The Number by 2...And Remember The value.\n");
                                }

                                printf("\nIf you're ready to move forward, press 2 for >>GO<<\n\n");
                                scanf("%d", &yes);

#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                                if (yes == 2)
                                {
                                        printf("\nTHE MIND READER GAVE YOU THE NUMBER : %d\n\n", give);
                                }

                                printf("Add the number with the value you have\n\n");
                                printf("If you're Done. PRESS  >3<\n\n");

                                scanf("%d", &yes);
#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif
                                if (yes == 3)
                                {
                                        printf("Divide The Value in Half And Feed Your Pet Dog One Half...\n\n");
                                        printf("And NOW Remember The Other Half.\n\n");
                                }
                                printf("\nAre you done with your Calculating ? If >>YES<< press 4 \n\n");
                                scanf("%d", &yes);

#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                                if (yes == 4)
                                {
                                        printf("\n(((((>> NOW Minus the Number you thought in Starting <<))))))\n\n");
                                }
                                int left = give / 2;
                                printf("Are you done with your Calculating ? If YES.... Press 5 \n\n");
                                scanf("%d", &yes);

#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                                if (yes == 5)
                                {
                                        printf("Now I Know , What Number is Left in your Mind... Press 1\n\n");
                                }
                                scanf("%d", &yes);

#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                                if (yes == 1)
                                {
                                        printf("             Ha Ha Ha Ha ...You're Only Left with %d\n\n", left);
                                }
                                printf("Do you Want to Play Again ?? (y/n)\n");
                                scanf(" %c", &choice);

                        } while (choice == 'y' || choice == 'Y');
                        break;
                }

                case 2:
                {
                        do
                        {
                                printf(" DDDDD   IIIII   CCCC   EEEEE \n");
                                printf(" D    D    I    C       E     \n");
                                printf(" D     D   I    C       E     \n");
                                printf(" D     D   I    C       EEEE  \n");
                                printf(" D    D    I    C       E     \n");
                                printf(" DDDDD   IIIII   CCCC   EEEEE \n");

                                char playerName[50];
                                printf("\nEnter your name: ");
                                scanf("%s", playerName);

                                int totalPoints = 0;

                                for (int i = 1; i <= 5; ++i)
                                {
                                        int usernumber;
                                        printf("Round %d: Guess a number between 1-6: ", i);
                                        scanf("%d", &usernumber);

                                        clearConsole();

                                        int randnum = rollDice();
                                        printf("You rolled a %d\n", randnum);

                                        printf("Your guess was %d\n", usernumber);

                                        if (usernumber == randnum)
                                        {
                                                printf("Your guess is correct! You earn 1 point.\n");
                                                totalPoints++;
                                        }
                                        else
                                        {
                                                printf("Wrong guess! Try again.\n");
                                        }

                                        displayResult(usernumber, randnum);
                                        getchar();
                                        clearConsole();
                                }

                                printf("\nGame Over!\n");
                                printf("Player: %s\n", playerName);
                                printf("Total Points: %d\n", totalPoints);

                                printf("Do you want to play again? (y/n): ");
                                scanf(" %c", &playAgain);

                                // Clear the console screen
#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                        } while (playAgain == 'y' || playAgain == 'Y');

                        break;
                }
                case 3:
                {

                        do
                        {

                                printf(" SSSSS  H   H  OOOOO  OOOOO  TTTTT  EEEEE  RRRR \n");
                                printf(" S      H   H  O   O  O   O    T    E      R   R \n");
                                printf(" SSSSS  HHHHH  O   O  O   O    T    EEEE   RRRR  \n");
                                printf("     S  H   H  O   O  O   O    T    E      R  R  \n");
                                printf(" SSSSS  H   H  OOOOO  OOOOO    T    EEEEE  R   R \n");

                                printf("\n\n");
                                char input;
                                int s;
                                printf("TRY TO KILL 8 ENEMIES TO WIN \n\n Press > 1 < TO START THE GAME\n\n (IF YOU WANT TO LEAVE IN THE MIDDLE OF THE GAME PRESS 'Q' BUTTON)\n");
                                scanf("%d", &s);

                                if (s == 1)
                                {

                                        initializeGame();

                                        while (1)
                                        {
                                                if (_kbhit())
                                                {
                                                        input = _getch();
                                                        if (input == 'a' && playerX > 0)
                                                        {
                                                                playerX--;
                                                        }
                                                        else if (input == 'd' && playerX < WIDTH - 1)
                                                        {
                                                                playerX++;
                                                        }
                                                        else if (input == ' ')
                                                        {
                                                                if (bulletY < 0)
                                                                {
                                                                        bulletX = playerX;
                                                                        bulletY = playerY - 1;
                                                                }
                                                        }
                                                        else if (input == 'q')
                                                        {
                                                                break;
                                                        }
                                                }

                                                updateGame();
                                                drawGame();

                                                // Game over condition
                                                if (lives <= 0)
                                                {
                                                        printf("Game Over! YOU'RE LOST !\n");
                                                        break;
                                                }

                                                // Win condition
                                                if (score >= ENEMY_COUNT)
                                                {
                                                        printf("You Win!\n");
                                                        break;
                                                }
                                        }
                                }

                                printf("Do you want to play again? (y/n): ");
                                scanf(" %c", &playAgain);

#ifdef _WIN32
                                system("cls");
#else
                                system("clear");
#endif

                        } while (playAgain == 'y' || playAgain == 'Y');

                        break;
                }
                case 4:
                {
                        printf(" ROCK    PAPER  SCISSOR \n\n");
                        printf("  ^       ^        ^   \n\n");
                        printf(" RRRR    PPPP   SSSSS \n");
                        printf(" R   R   P   P  S     \n");
                        printf(" RRRR    PPPP   SSSSS \n");
                        printf(" R  R    P          S\n");
                        printf(" R   R   P      SSSSS \n");

                        printf("\n\n");
                        int playerChoice, computerChoice;
                        char playAgain;

                        srand(time(0));

                        do
                        {
                                computerChoice = rand() % 3 + 1;

                                printf("Choose your move:\n");
                                printf("1. Rock\n");
                                printf("2. Paper\n");
                                printf("3. Scissors\n");
                                printf("Enter your choice (1-3): ");
                                scanf("%d", &playerChoice);

                                printf("You chose: ");
                                printChoice(playerChoice);
                                printf("\n\n");

                                printf("Computer chose: ");
                                printChoice(computerChoice);
                                printf("\n\n");

                                if (playerChoice == computerChoice)
                                {
                                        printf("It's a draw!\n\n");
                                }
                                else if ((playerChoice == 1 && computerChoice == 3) ||
                                         (playerChoice == 2 && computerChoice == 1) ||
                                         (playerChoice == 3 && computerChoice == 2))
                                {
                                        printf("You win!\n\n");
                                }
                                else
                                {
                                        printf("You lose!\n\n");
                                }

                                printf("Do you want to play again? Press (y/n): ");
                                scanf(" %c", &playAgain);
#ifdef _WIN32 == ==
                                system("cls");
#else
                                system("clear");
#endif
                        } while (playAgain == 'y' || playAgain == 'Y');

                        printf("Thank you for playing! Goodbye.\n");

                        break;
                }
                }
                printf("Do you want to return to the main menu? (y/n): ");
                scanf(" %c", &playAgain);

                // Clear the console screen
#ifdef _WIN32
                system("cls");
#else
                system("clear");
#endif

        } while (playAgain == 'y' || playAgain == 'Y');

        return 0;
}
