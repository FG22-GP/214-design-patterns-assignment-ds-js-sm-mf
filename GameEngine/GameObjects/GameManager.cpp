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

    ball = new Ball();
    ball->Start();

    RestartGame();
}

void GameManager::ResetPositions()
{
    // moves paddles to their starting locations
    player1->transform.position = Vector2(30, SCREEN_HEIGHT / 2);
    player2->transform.position = Vector2(590,SCREEN_HEIGHT / 2);

    // move ball to starting location // middle of screen
    ball->transform =Transform(Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0), Vector3(0, 0, 0), Vector3(255, 0, 0)) ;

}

void GameManager::Reset()
{
    // make ball go towards losing player (loser serves)
    if(Player1Lost)
    {
        ball->Direction = Vector2(-1,0);
    }
    else
    {
        ball->Direction = Vector2(1,0);
    }
    
    ResetPositions();
}

void GameManager::RestartGame()
{
    ScorePlayer1 = 0;
    ScorePlayer2 = 0;

    // randomize ball starting direction
    if(Random::RandomBool())
    {
        ball->Direction = Vector2(1,0);
    }
    else
    {
        ball->Direction = Vector2(-1,0);
    }
    
    ResetPositions();
}

void GameManager::Tick()
{
    GameObject::Tick();

    // check ball position
    //printf("ball x: %f\n", ball->transform.position.x);
    if (ball->transform.position.x < 20)
    {
        // player 1 lose
        AddScore(2, 1); // add 1 point to player 2
        Player1Lost = true;
        Reset();
    }
    else if (ball->transform.position.x > 620)
    {
        // player 2 lose
        Player1Lost = false;
        AddScore(1, 1); // add 1 point to player 1
        Reset();
    }


    // check if Esc or R pressed
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

    printf("score is now %i - %i\n", ScorePlayer1, ScorePlayer2);
}

std::vector<int> GameManager::GetScores()
{
    return std::vector<int> {ScorePlayer1,ScorePlayer2};
}
