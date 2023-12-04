#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <math.h>
#include <sstream>
#include <vector>
#include <ctime>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

// FORWARD DECLARATIONS
class Component;



// CLASSES

class Vector3
{
	public:
		float x,y,z;

		Vector3() : x(0), y(0), z(0) {}
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

		Vector3 operator+(const Vector3& other) const {
			return Vector3(x+other.x, y+other.y, z+other.z);
		}

		Vector3 operator+=(const Vector3& other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		Vector3 operator*(float factor)
		{
			return Vector3(x*factor, y*factor, z*factor);
		}

		Vector3 operator*=(float factor)
		{
			x *= factor;
			y *= factor;
			z *= factor;
			return *this;
		}

		Vector3 operator-(const Vector3& other) const {
			return Vector3(x-other.x, y-other.y, z-other.z);
		}

		Vector3 operator-=(const Vector3& other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		// TODO a bunch of operators still missing + stuff like DotProduct, Cross, Distance etc...
		//
		// look into not returning copies

};

class Transform
{
	public:
		Vector3 position;

		void Move(float dX, float dY, float dZ)
		{
			position.x += dX;
			position.y += dY;
			position.z += dZ;
		}

		void SetPosition(float X, float Y, float Z)
		{
			position.x = X;
			position.y = Y;
			position.z = Z;
		}

	// TODO add rotation and scale
};

class GameObject
{
	public:
		std::string name;
		Transform transform;
		std::vector<Component*> components;
		bool active = true;
		bool visible = true;

		GameObject(std::string inname = "GameObject"){
			name = inname;
		}

};



class Component
{
	public:
		GameObject *gameObject;
		virtual void Tick() = 0;
};

class RenderCircleComponent : public Component
{
	public:
		SDL_Renderer* renderer;
		int r, g, b;
		int radius;
		void Tick() {
			SDL_SetRenderDrawColor(renderer, r, g, b, 255);

			for (int y = -radius; y <= radius; y++)
			{
				for (int x = -radius; x <= radius; x++)
				{
					if ( (x * x) + (y * y) <= radius * radius) // if distance <= radius = we draw a pixel
					{
						SDL_RenderDrawPoint(renderer, gameObject->transform.position.x + x, gameObject->transform.position.y + y);
					}
				}
			}
		}

		RenderCircleComponent(SDL_Renderer* render, int red, int green, int blue, int rad)
		{
			r = red;
			g = green;
			b = blue;
			radius = rad;
			renderer = render;
		}
};

class TestComponent : public Component
{
	public:

		void Tick()
		{
			printf("My gameobjects name: %s\n", gameObject->name.c_str());
			//printf("Tick from test component!\n");
		}
};

// GLOBALS
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
bool gQuit = false;
std::vector<GameObject*> GameObjects;

bool init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not init. SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL gigachad", 
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			printf("failed to create window. SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{

			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(!gRenderer)
			{
				printf("Failed to create renderer. %s", SDL_GetError());
				return false;
			}

		}
	}
	return true;

}

void close()
{
	// closes the sdl program
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL; // TODO test if these NULL's are necessary
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}


void InputCheck()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0){
		if(event.type == SDL_QUIT) // this seems to trigger when you hit the X in windows etc.
		{
			gQuit = true;
		}
		else if (event.type ==  SDL_MOUSEBUTTONDOWN)
		{
			switch(event.button.button)
			{
				case SDL_BUTTON_LEFT:
					SDL_Log("left click");
					break;
				case SDL_BUTTON_RIGHT:
					SDL_Log("Right click");
					break;
				case SDL_BUTTON_MIDDLE:
					SDL_Log("Middle click");
					break;
			}
		}
		else if (event.type == SDL_KEYDOWN)
		{
			//SDL_Log("%s pressed", SDL_GetKeyName(event.key.keysym.sym));
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					gQuit=true;
					break;
				case SDLK_f:
					SDL_Log("F pressed");
					break;

			}
		}
	}
}


int rng(int lower, int upper)
{
	int range = upper - lower + 1;
	int num = std::rand() % range + lower;
	return num;
}


int main(int argc, char* args[]) {
	if(init() == false)
	{
		// something failed to initialize, we die
		return 1;
	}


	// create a bunch of game objects
	for(int i = 0; i < 100; i++)
	{
		GameObject* go = new GameObject("random object");
		int r = rng(0,500);
		int r2 = rng(0,500);
		int rcolor = rng(0,255);
		int rsize = rng(5,20);
		go->transform.position = Vector3(r,r2,0);

		RenderCircleComponent* rcc = new RenderCircleComponent(gRenderer, rcolor, 128,128, rsize);
		rcc->gameObject = go;
		go->components.push_back(rcc);
/*
		TestComponent* tc = new TestComponent(); 
		tc->gameObject = go; // so we dont need to do this everytime
		go->components.push_back(tc);*/

		GameObjects.push_back(go);
	}

	// create a GameObject
	GameObject* A = new GameObject("GameObject A");
	A->transform.position = Vector3(100,100,0);

	// add some components to it
	RenderCircleComponent* rcc = new RenderCircleComponent(gRenderer, 0,255,0,10);
	rcc->gameObject = A;
	A->components.push_back(rcc);

	TestComponent* tc = new TestComponent(); // TODO should try to push our gameobject in the constructor
	tc->gameObject = A; // so we dont need to do this everytime
	A->components.push_back(tc);

	GameObjects.push_back(A); // add it to the global GameObjects array (vector actually)

	// another GameObject...
	GameObject* B = new GameObject("B");
	B->transform.position = Vector3(0,0,0);
	RenderCircleComponent* rcc2 = new RenderCircleComponent(gRenderer, 255,0,0, 15);
	rcc2->gameObject = B;
	B->components.push_back(rcc2);

	TestComponent* tc2 = new TestComponent();
	tc2->gameObject = B;
	B->components.push_back(tc2);

	GameObjects.push_back(B);

	while(!gQuit)
	{
		SDL_RenderClear(gRenderer);

		// main loop
		
		for(auto & go : GameObjects) // Iterate over all GameObjects
		{
			// Iterate over all components on the GameObject and run their Tick()
			for(auto & component : go->components)
			{
				component->Tick();
			}

			go->transform.position += Vector3(2,1,0);
			go->transform.position *= 1.01;

			// clamp to screen
			if(go->transform.position.x > SCREEN_WIDTH){
				go->transform.position.x = 0;
			}
			if(go->transform.position.y > SCREEN_HEIGHT)
			{
				go->transform.position.y = 0;
			}
		}

		// restore draw color to black so the background remains black
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

		// and finally present the frame
		SDL_RenderPresent(gRenderer);

		InputCheck();

	}

	close();
	return 0;
}
