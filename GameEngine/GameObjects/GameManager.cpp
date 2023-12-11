#include "GameManager.h"

#include "../Components/SquareRender.h"

void GameManager::Start()
{
    player1 = new Paddle(1);
    player1->name = "Player 1 paddle";
    player1->Start();
    player1->GetComponent<SquareRender>()->SetColor(0,255,0);
    
    player2 = new Paddle(2);
    player2->name = "Player 2 paddle";
    player2->Start();
    player2->GetComponent<SquareRender>()->SetColor(255,0,0);

    SetupGame();
}

void GameManager::SetupGame()
{
    // moves paddles to their starting locations
    player1->transform.position = Vector2(100, 250);
    player2->transform.position = Vector2(500,250);
}

void GameManager::RestartGame()
{
    ScorePlayer1 = 0;
    ScorePlayer2 = 0;
    SetupGame();
}

void GameManager::Tick()
{
    GameObject::Tick();

    if(Input::IsButtonDown(START))
    {
        QUIT_REQUESTED=true;
    }
    if(Input::IsButtonDown(RESTART))
    {
        RestartGame();
    }
}

void GameManager::AddScore(int Player, int ScoreToAdd)
{
    if(Player==1)
    {
        ScorePlayer1 += ScoreToAdd;
    }
    else if (Player==2)
    {
        ScorePlayer2 += ScoreToAdd;
    }
}

std::vector<int> GameManager::GetScores()
{
    return std::vector<int> {ScorePlayer1,ScorePlayer2};
}
