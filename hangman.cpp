//
// Created by christinaroesner on 3/11/2024.
//

#include "list.h"
#include "GameManager.h"

using namespace std;

int main()
{
    ///// --- Main Game Loop --- ////
    GameManager gameManager;
    
    GameState gameState = GameState::Intro;

    gameState = gameManager.Intro();
    do // Game Loop, runs the game until finished
    {
        if (gameState == GameState::Start)
            gameState = gameManager.StartGame();
        else if (gameState == GameState::InProgress)
            gameState = gameManager.InProgress();
        else if (gameState == GameState::End)
            gameState = gameManager.EndGame();
    } while (gameState != GameState::Shutdown);
}