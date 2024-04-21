//
// Created by Pierce on 3/12/24.
//

#ifndef CS2420_PROJECT_GAMEMANAGER_H
#define CS2420_PROJECT_GAMEMANAGER_H

enum GameState { Intro, Start, InProgress, End, Shutdown };

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

string words[] = { "feast", "outside", "experience", "hangman", "storage", "elephant",
                     "commemorate", "flourish", "indigo", "examination", "underground",
                     "candy", "sugar", "money", "denominator", "indifferent", "superficial",
                     "hippopotamus", "adrenaline", "vintage" };

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
    // Startup Screen
    GameState Intro()
    {
        while (true) {
            cout << " --- HANGMAN ---\n";

            PrintCurrentHangman(maxHangmanIndex);

            cout << "Are you ready to start? (y/n)\n";

            string response;
            cin >> response;

            if (response == "y" || response == "start" || response == "s")
                return GameState::Start;
            else if (response == "n" || response == "quit" || response == "q")
                return GameState::Shutdown;
        }
    }

    // Called when the game starts to initialize variables
    GameState StartGame()
    {
        
        // Set random seed
        srand(time(NULL));
        
        // Reset variables
        currentHangmanIndex = 0;
        delete correctLetters;
        correctLetters = new list<char>();
        delete incorrectLetters;
        incorrectLetters = new list<char>();
        
        // Set word randomly from the list
        int size = sizeof(words)/sizeof(words[0]);
        int randomIndex = rand() % size;
        word = words[randomIndex];
        
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
        // Show list of wrong letters
        if (!incorrectLetters->is_empty())
        {
            cout << "Previously guessed: " << *incorrectLetters << endl;
        }
        
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
        PrintCurrentHangman(currentHangmanIndex);
        
        // Check if Win or Lose
        bool win = true;
        if (currentHangmanIndex >= maxHangmanIndex)
        {
            // Lose
            win = false;
        }
        
        // Show Win/Lose screen
        if (win)
        {
            // Show Win Screen
            cout << "You guessed the word: " << word << endl;
        }
        else
        {
            // Show Lose Screen
            cout << "You failed to guess the word: " << word << endl;
        }
        
        // Restart Logic:
        cout << "Play again? (y/n)\n";
        // Wait for user input
        // if user inputs "y"
        string input;
        cin >> input;
    
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
