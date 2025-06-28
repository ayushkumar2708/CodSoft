#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation
    const int maxAttempts = 5;
    int score = 0;
    string playAgain;

    do {
        int randomNumber = rand() % 100 + 1;
        int attempts = 0;
        bool hasGuessedCorrectly = false;

        cout << "Number Guessing Game Session!" << endl;
        cout << "---------------------------------" << endl;
        cout << "YOU CAN TRY TO GUESS THE NUMBER BETWEEN 1 TO 100:" << endl;
        cout << "---------------------------------------------------" << endl;

        while (attempts < maxAttempts) {
            int userGuess;
            cout << "Enter your guess number: ";
            cin >> userGuess;
            attempts++;

            if (userGuess == randomNumber) {
                cout << "Congratulations! You've guessed the correct number!" << endl;
                score++;
                hasGuessedCorrectly = true;
                break;
            } else if (userGuess < randomNumber) {
                cout << "Your guess is too low." << endl;
            } else {
                cout << "Your guess is too high." << endl;
            }

            cout << "Attempts remaining: " << (maxAttempts - attempts) << endl;
        }

        if (!hasGuessedCorrectly) {
            cout << "Sorry, you don't have more attempts. The correct number was: " << randomNumber << endl;
        }

        cout << "If you want to play again then enter yes otherwise no: (yes/no): ";
        cin >> playAgain;

    } while (playAgain == "yes" || playAgain == "Yes");

    cout << "Game over! Your final score is: " << score << endl;

    return 0;
}