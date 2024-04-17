//
// Created by Pierce on 3/12/24.
//

#ifndef CS2420_PROJECT_GAMEMANAGER_H
#define CS2420_PROJECT_GAMEMANAGER_H

enum GameState { Start, InProgress, End, Shutdown };

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

public:
    // Called when the game starts to initialize variables
    GameState StartGame()
    {
        cout << " --- HANGMAN ---\n";
        
        // Reset variables
        currentHangmanIndex = 0;
        delete correctLetters;
        correctLetters = new list<char>();
        delete incorrectLetters;
        incorrectLetters = new list<char>();
        
        // TODO : Set word randomly from a list
        // Choose random word, set word
        word = "temporary";
        
        // Draw empty hangman (this method will cout the correct Hangman)
        PrintCurrentHangman(currentHangmanIndex);
        
        // cout << "_" for word.length
        hintWord = "";
        for (int i = 0; i < word.size(); ++i)
        {
            hintWord += "_";
        }
        cout << hintWord << endl;

        // Start next phase
        return GameState::InProgress;
    }

    GameState InProgress()
    {
        // Prompt user for a letter, set letter
        cout << "Guess a letter: \n";
        string letter;
        cin >> letter;
        
        // Check that letter was not already guessed
        if (!(correctLetters->search(letter[0]) == -1 && incorrectLetters->search(letter[0]) == -1))
        {
            cout << "You already guessed that letter!\n";
            return GameState::InProgress;
        }
        
        // Search each letter in word for letter
        bool isFound = false;
        for (int i = 0; i < word.size(); i++)
        {
            if (letter[0] == word[i]) // Letter IS found
            {
                isFound = true;
                correctLetters->insert(letter[0]);
                break;
            }
        }
        
        // if letter NOT found:
        if (!isFound)
        {
            // Add letter to list of incorrect letters
            incorrectLetters->insert(letter[0]);
            
            // Increment Hangman state
            currentHangmanIndex++; // Compare to maxHangmanIndex
        }
        else // else if letter is found:
        {
            // Add letter to list of correct letters
            correctLetters->insert(letter[0]);
        }
        
        // Check if you Win/Lose: (if letters == word or hangman state == maxHangmanIndex)
        if (correctLetters->searchAll(word) || currentHangmanIndex >= maxHangmanIndex)
        {
            // Start End Phase
            return GameState::End;
        }
        
        // Draw current Hangman State
        PrintCurrentHangman(currentHangmanIndex);
        
        // Draw "_" for each letter not in correct letters list
        for (int i = 0; i < word.size(); ++i)
        {
            if (correctLetters->search(word[i]) != -1)
            {
                hintWord[i] = word[i]; // Updates the hint with correct letters
            }
        }
        cout << hintWord << endl;

        // Restart In-Progress phase if NOT Win/Lose
        return GameState::InProgress;
    }

    GameState EndGame()
    {
        // Check if Win or Lose
        bool win = true;
        if (currentHangmanIndex >= maxHangmanIndex)
        {
            // Lose
            win = false;
        }
        
        // TODO : Show Win/Lose screen
        if (win)
        {
            // Show Win Screen
            cout << "You guessed the word: " << word << endl;
            cout << "Play again? (y/n)\n";
        }
        else
        {
            // Show Lose Screen
            cout << "You failed to guess the word: " << word << endl;
            cout << "Play again? (y/n)\n";
        }
        
        // Restart Logic:
        // Wait for user input
        string input;
        cin >> input;
        
        // if user inputs "y"
        if (input[0] == 'y' || input[0] == 'Y')
        {
            // Restart Game
            return GameState::Start;
        }
        // else
        // Game Over
        cout << " --- Game Over ---\n";
        return GameState::Shutdown;
    }
};

#endif //CS2420_PROJECT_GAMEMANAGER_H
