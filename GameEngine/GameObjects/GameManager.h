#pragma once
#include "Ball.h"
#include "../GameObject.h"
#include "Paddle.h"
#include "../Input.h"
#include "../Random.h"

class GameManager : public GameObject
{
public:
   void Start() override;
   void ResetPositions();
   void Reset();
   void RestartGame();
   void Tick() override;
   void AddScore(int Player, int ScoreToAdd);
   std::vector<int> GetScores();

   Ball* ball;
   Paddle* player1;
   Paddle* player2;

   int ScorePlayer1 = 0;
   int ScorePlayer2 = 0;

   bool Player1Lost = false;
    
};
