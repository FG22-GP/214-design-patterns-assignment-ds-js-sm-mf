﻿#pragma once
#include "Ball.h"
#include "../GameObject.h"
#include "Paddle.h"
#include "../Input.h"
#include "../Random.h"
#include "../Components/TextRender.h"

class GameManager : public GameObject
{
public:
    static GameManager& GetInstance()
    {
        static GameManager Instance;
        return Instance;
    }

    void Start() override;
    void ResetPositions();
    void Reset();
    void RestartGame();
    void Tick() override;
    void AddScore(int Player, int ScoreToAdd);
    std::vector<int> GetScores();
    void UpdateScoreText();

    Ball* ball;
    Paddle* player1;
    Paddle* player2;

    GameObject* TextGameObject;
    TextRender* TextRenderComponent;

    int ScorePlayer1 = 0;
    int ScorePlayer2 = 0;

private:
    GameManager()
    {
    }

    GameManager(GameManager const&) = delete;
    void operator=(GameManager const&) = delete;
};
