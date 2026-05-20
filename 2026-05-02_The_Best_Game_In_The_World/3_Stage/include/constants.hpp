#pragma once

#include <cstdint>

static const float COIN_DROP_SPEED = 5.0f;
static const float ENEMY_HEIGHT = 2.0f;
static const float ENEMY_SPEED = 1.0f;
static const float ENEMY_WIDTH = 2.0f;
static const float FRAME_DELAY_MS = 50.0f;
static const float GRAVITY = 0.5f;
static const float JUMP_POWER = -8.0f;
static const float MARIO_HEIGHT = 2.0f;
static const float MARIO_START_X = 10.0f;
static const float MARIO_START_Y = 15.0f;
static const float MARIO_WIDTH = 1.0f;

static const int32_t INITIAL_CAPACITY = 16;
static const int32_t MAP_HEIGHT = 25;
static const int32_t MAP_WIDTH = 80;
static const int32_t MAX_LEVELS = 3;
static const int32_t RESTART_DELAY_MS = 1500;
static const int32_t SCORE_AREA_WIDTH = 45;
static const int32_t SCORE_FOR_COIN = 100;
static const int32_t SCORE_FOR_KILL = 50;
static const int32_t SCORE_X_OFFSET = 5;

static const char COLOR_DEFAULT[] = "color 0F";
static const char COLOR_LOSE[] = "color 4F";
static const char COLOR_WIN[] = "color 2F";
static const char TYPE_BOX = '?';
static const char TYPE_BRICK = '#';
static const char TYPE_COIN = '$';
static const char TYPE_ENEMY = '^';
static const char TYPE_EXIT = '+';
static const char TYPE_LINES = '-';
static const char TYPE_MARIO = '@';