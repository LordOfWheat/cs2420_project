//
// Created by Pierce on 3/12/24.
//

#ifndef CS2420_PROJECT_GAMEMANAGER_H
#define CS2420_PROJECT_GAMEMANAGER_H

enum GameState { Start, InProgress, End };

class gamemanager
{
private:
    string word;
    // Not needed?
    //GameState gameState = GameState::Start;

public:
    GameState StartGame()
    {
        // Choose random word, set word
        // cout << "_" for word.length
        // Draw empty hangman (cout << hangman)

        // Start next phase
        return GameState::InProgress;
    }

    GameState InProgress()
    {
        // Prompt user for a letter, set letter
        // Search each letter in word for letter
        // if letter NOT found:
            // Add letter to list of incorrect letters
            // Increment Hangman state
        // else if letter is found:
            // Add letter to list of correct letters
        // Check if you Win/Lose:
        // (if letters == word or hangman state == max)
            // Start End Phase
        // Draw "_" for each letter not in correct letters list
        // Draw current Hnagman State

        // Restart In-Progress phase if NOT Win/Lose
        return GameState::InProgress;
    }

    GameState EndGame()
    {
        // Show Win/Lose screen
        // Wait for user input

        // Restart Game
        return GameState::Start;
    }
};

#endif //CS2420_PROJECT_GAMEMANAGER_H
