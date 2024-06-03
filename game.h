#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <string>
#include <vector>

class ObstacleHandler;
class EntityManager;
class Entity;

class Game {
	int initGame();
	void closeGame();

	static int tick;

	SDL_Window* window;

public:
	Game();
	~Game();

	void render();
	void update();
	void mainLoop();
	void handleEvents();

	int getTick() const;

	static const int SCREEN_WIDTH = 1200;
	static const int SCREEN_HEIGHT = 480;

	static bool initError;
	static bool running;
	
	static std::string errorMessage;

	static SDL_Renderer* renderer;
	static SDL_Event event;

	static Entity& player;
	static EntityManager entityManager;
	static ObstacleHandler obstacleHandler;
};