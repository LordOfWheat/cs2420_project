//
// Created by christinaroesner on 3/11/2024.
//

#include "list.h"
#include "GameManager.h"
using namespace std;

int main() {
     /*
      * start screen
      * 20 words stored in list (use the random function to pick random word)
      * after random word is selected, store the letters in word separately in list (ex. [ c, a, t])
      * make an empty list that will be for correct letters (semi-empty, fill it with underscores for printing)
      * make an empty list that will be for incorrect letters
      * print correct letters
      * wait for user input
      * search for inputted letter in the letter-in-word list
      *     if not found, insert in incorrect letters, update hangman state (?) and print
      *     if found, replace in correct letters; print correct letters (with the underscores) and same hangman frame
      * repeat until either correct letters list has no underscores or hangman state is at max
      * if no underscores, win screen
      * if hangman state is max, lose screen
      * when finished, clear lists
      */

    // for testing the functions, you may delete if you want
     auto ListTest = new list<int>();
     auto ListTest2 = new list<int>();
     auto ListTest3 = new list<int>();

     for (int i = 1; i < 11; i++) {
         ListTest->insert(i);
         ListTest2->insert(i);
     }

     for (int i = 20; i < 30; i++) {
         ListTest3->insert(i);
     }


//     cout << "Before replace: " << endl;
//     cout << *ListTest << endl << endl;
//
//     ListTest->replace(5, 11); // change index to any int to test that replace works
//
//     cout << "After replace: " << endl;
//     cout << *ListTest << endl << endl;

//     cout << *ListTest << endl;
//     cout << ListTest->search(3) << endl << endl;
//
//     ListTest->insert(3);
//
//     cout << *ListTest << endl;
//     cout << ListTest->search(3, 2) << endl;
//     cout << *ListTest << endl << endl;

        cout << ListTest->searchAll(ListTest2) << endl;
        cout << ListTest->searchAll(ListTest3) << endl;
     
     
     // Game Manager Testing
//     GameManager gameManager;
//
//     gameManager.StartGame();
}