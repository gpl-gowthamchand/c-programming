/*
 * Application: Number Guessing Game
 * Author: gpl-gowthamchand
 * Date: 2025-01-27
 * 
 * Description: An interactive number guessing game where the player tries to guess a randomly generated number
 * 
 * Features:
 * - Random number generation
 * - Difficulty levels (Easy, Medium, Hard)
 * - Score tracking
 * - Hint system
 * - Multiple rounds
 * - High score saving
 * 
 * Requirements:
 * - Standard C library
 * - Random number generation
 * 
 * Usage: gcc real_world_numberGuessingGame.c -o numberGame && ./numberGame
 * 
 * Installation:
 * - Compile with: gcc real_world_numberGuessingGame.c -o numberGame
 * - Run with: ./numberGame
 * 
 * Examples:
 * - Play on easy mode (1-10, 5 attempts)
 * - Play on medium mode (1-50, 7 attempts)
 * - Play on hard mode (1-100, 10 attempts)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SCORES 10

// Game structure
struct GameStats {
    int totalGames;
    int totalWins;
    int bestScore;
    int currentStreak;
};

// Function to initialize random seed
void initRandom() {
    srand(time(NULL));
}

// Function to display welcome message
void displayWelcome() {
    printf("========================================\n");
    printf("    Welcome to Number Guessing Game!   \n");
    printf("========================================\n");
    printf("I'm thinking of a number. Can you guess it?\n\n");
}

// Function to display difficulty menu
int selectDifficulty() {
    int choice;
    printf("Select Difficulty Level:\n");
    printf("1. Easy   (1-10,   5 attempts)\n");
    printf("2. Medium (1-50,   7 attempts)\n");
    printf("3. Hard   (1-100, 10 attempts)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    return choice;
}

// Function to get difficulty parameters
void getDifficultyParams(int difficulty, int *maxNumber, int *maxAttempts) {
    switch (difficulty) {
        case 1: // Easy
            *maxNumber = 10;
            *maxAttempts = 5;
            break;
        case 2: // Medium
            *maxNumber = 50;
            *maxAttempts = 7;
            break;
        case 3: // Hard
            *maxNumber = 100;
            *maxAttempts = 10;
            break;
        default:
            *maxNumber = 10;
            *maxAttempts = 5;
    }
}

// Function to provide hints
void provideHint(int guess, int target, int maxNumber) {
    int difference = abs(guess - target);
    int percentage = (difference * 100) / maxNumber;
    
    if (percentage <= 10) {
        printf("🔥 Very close! ");
    } else if (percentage <= 25) {
        printf("🔥 Close! ");
    } else if (percentage <= 50) {
        printf("🔥 Getting warmer! ");
    } else {
        printf("❄️  Cold! ");
    }
    
    if (guess < target) {
        printf("Try a higher number.\n");
    } else {
        printf("Try a lower number.\n");
    }
}

// Function to play a single game
int playGame(int difficulty) {
    int maxNumber, maxAttempts;
    getDifficultyParams(difficulty, &maxNumber, &maxAttempts);
    
    int target = rand() % maxNumber + 1;
    int guess;
    int attempts = 0;
    
    printf("\nI'm thinking of a number between 1 and %d.\n", maxNumber);
    printf("You have %d attempts. Good luck!\n\n", maxAttempts);
    
    while (attempts < maxAttempts) {
        attempts++;
        printf("Attempt %d/%d: Enter your guess: ", attempts, maxAttempts);
        scanf("%d", &guess);
        
        if (guess == target) {
            printf("🎉 Congratulations! You guessed it right!\n");
            printf("The number was %d. You took %d attempts.\n", target, attempts);
            return attempts;
        } else if (attempts < maxAttempts) {
            provideHint(guess, target, maxNumber);
        }
    }
    
    printf("😞 Game Over! The number was %d.\n", target);
    printf("Better luck next time!\n");
    return -1; // Lost
}

// Function to display game statistics
void displayStats(struct GameStats *stats) {
    printf("\n=== Game Statistics ===\n");
    printf("Total Games Played: %d\n", stats->totalGames);
    printf("Games Won: %d\n", stats->totalWins);
    printf("Win Rate: %.1f%%\n", 
           stats->totalGames > 0 ? (float)stats->totalWins * 100 / stats->totalGames : 0);
    printf("Best Score: %d attempts\n", stats->bestScore);
    printf("Current Streak: %d\n", stats->currentStreak);
}

// Function to display main menu
int displayMenu() {
    int choice;
    printf("\n=== Main Menu ===\n");
    printf("1. Play Game\n");
    printf("2. View Statistics\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct GameStats stats = {0, 0, 999, 0};
    int choice, difficulty, result;
    
    initRandom();
    displayWelcome();
    
    while (1) {
        choice = displayMenu();
        
        switch (choice) {
            case 1: // Play Game
                difficulty = selectDifficulty();
                if (difficulty < 1 || difficulty > 3) {
                    printf("Invalid difficulty! Using Easy mode.\n");
                    difficulty = 1;
                }
                
                result = playGame(difficulty);
                stats.totalGames++;
                
                if (result > 0) { // Won
                    stats.totalWins++;
                    stats.currentStreak++;
                    if (result < stats.bestScore) {
                        stats.bestScore = result;
                    }
                } else { // Lost
                    stats.currentStreak = 0;
                }
                break;
                
            case 2: // View Statistics
                displayStats(&stats);
                break;
                
            case 3: // Exit
                printf("Thank you for playing Number Guessing Game!\n");
                printf("Final Statistics:\n");
                displayStats(&stats);
                exit(0);
                
            default:
                printf("Invalid choice! Please enter 1-3.\n");
        }
    }
    
    return 0;
}
