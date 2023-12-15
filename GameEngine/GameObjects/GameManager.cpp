#include "GameManager.h"

#include "../Components/SquareRender.h"
#include "../Components/TextRender.h"

void GameManager::Start()
{
    player1 = new Paddle(1);
    player1->name = "Player 1 paddle";
    player1->Start();
    player1->GetComponent<SquareRender>()->SetColor(0, 255, 0);

    player2 = new Paddle(2);
    player2->name = "Player 2 paddle";
    player2->Start();
    player2->GetComponent<SquareRender>()->SetColor(255, 0, 0);

    ball = new Ball();
    ball->Start();

    TextGameObject = new GameObject();
    TextGameObject->transform.position = Vector2(SCREEN_WIDTH/2 - 30,25);
    TextRenderComponent = new TextRender();
    TextGameObject->AddComponent(TextRenderComponent);
    UpdateScoreText();

    RestartGame();
}

void GameManager::ResetPositions()
{
    // moves paddles to their starting locations
    player1->transform.position = Vector2(50, SCREEN_HEIGHT / 2);
    player2->transform.position = Vector2(570,SCREEN_HEIGHT / 2);

    // move ball to starting location // middle of screen
    ball->transform = Transform(Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0), Vector3(0, 0, 0), Vector3(255, 0, 0));
}

void GameManager::Reset()
{
    ball->Reset();
    ResetPositions();
}

void GameManager::RestartGame() // pressed R
{
    ScorePlayer1 = 0;
    ScorePlayer2 = 0;
    UpdateScoreText();

    ball->Reset();
    ResetPositions();
}

void GameManager::Tick()
{
    GameObject::Tick();

    // check ball position
    if (ball->transform.position.x < 10)
    {
        // player 1 lose
        AddScore(2, 1); // add 1 point to player 2
        Reset();
    }
    else if (ball->transform.position.x > SCREEN_WIDTH-10)
    {
        // player 2 lose
        AddScore(1, 1); // add 1 point to player 1
        Reset();
    }


    // check if Esc or R pressed
    if (Input::IsButtonDown(START))
    {
        QUIT_REQUESTED = true;
    }
    if (Input::IsButtonDown(RESTART))
    {
        RestartGame();
    }
}

void GameManager::AddScore(int Player, int ScoreToAdd)
{
    if (Player == 1)
    {
        ScorePlayer1 += ScoreToAdd;
    }
    else if (Player == 2)
    {
        ScorePlayer2 += ScoreToAdd;
    }

    printf("score is now %i - %i\n", ScorePlayer1, ScorePlayer2);
    UpdateScoreText();
}

std::vector<int> GameManager::GetScores()
{
    return std::vector<int>{ScorePlayer1, ScorePlayer2};
}

void GameManager::UpdateScoreText()
{
    
    TextRenderComponent->SetText(std::to_string(ScorePlayer1) + " - " + std::to_string(ScorePlayer2));
}