//
// Created by Pierce on 3/12/24.
//

#ifndef CS2420_PROJECT_GAMEMANAGER_H
#define CS2420_PROJECT_GAMEMANAGER_H

enum GameState { Start, InProgress, End };

string hangmans[7] =
{
    "   +---+\n"
    "   |   |\n"
    "       |\n"
    "       |\n"
    "       |\n"
    "       |\n"
    "  ===========",
    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "       |\n"
    "       |\n"
    "       |\n"
    "  ===========",
    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "   |   |\n"
    "       |\n"
    "       |\n"
    "  ===========",
    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "   |\\  |\n"
    "       |\n"
    "       |\n"
    "  ===========",
    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|\\  |\n"
    "       |\n"
    "       |\n"
    "  ===========",
    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|\\  |\n"
    "    \\  |\n"
    "       |\n"
    "  ===========",
    "   +---+\n"
    "   |   |\n"
    "   O   |\n"
    "  /|\\  |\n"
    "  / \\  |\n"
    "       |\n"
    "  ==========="
};

class GameManager
{
private:
    //GameState gameState = GameState::Start; // Not needed?
    string word; // stores the word to find until End
    string hintWord; // "_______"
    int currentHangmanIndex = 0;
    const int maxHangmanIndex = 6;
    
    list<char> *correctLetters = new list<char>();
    list<char> *incorrectLetters = new list<char>();
    
    void PrintCurrentHangman(int hangmanIndex = 0)
    {
        cout << hangmans[hangmanIndex] << endl;
    }
    
    void UpdateHintWord()
    {
        // TODO
    }

public:
    GameState StartGame()
    {
        // TODO
        // Reset currentHangmanIndex
        currentHangmanIndex = 0;
        
        // Choose random word, set word
        word = "temporary";
        
        // Draw empty hangman (cout << hangman)
        PrintCurrentHangman(currentHangmanIndex);
        
        // cout << "_" for word.length
        hintWord = "";
        for (int i = 0; i < word.size(); ++i)
        {
            hintWord += "_ ";
        }
        cout << hintWord << endl;

        // Start next phase
        return GameState::InProgress;
    }

    GameState InProgress()
    {
        // TODO
        // Prompt user for a letter, set letter
        string letter;
        cin >> letter;
        
        // Search each letter in word for letter
        // if letter NOT found:
            // Add letter to list of incorrect letters
            // Increment Hangman state
        // else if letter is found:
            // Add letter to list of correct letters
        // Check if you Win/Lose:
        // (if letters == word or hangman state == maxHangmanIndex)
            // Start End Phase
            return GameState::End;
        // Draw "_" for each letter not in correct letters list
        // Draw current Hangman State

        // Restart In-Progress phase if NOT Win/Lose
        return GameState::InProgress;
    }

    GameState EndGame()
    {
        // TODO
        // Show Win/Lose screen
        // Wait for user input

        // Restart Game
        return GameState::Start;
    }
};

#endif //CS2420_PROJECT_GAMEMANAGER_H
