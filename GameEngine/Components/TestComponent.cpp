#include "TestComponent.h"



void TestComponent::Tick()
		{
			printf("My gameobjects name: %s, deltatime is: %f\n", gameObject->name.c_str(), DELTATIME);
			//printf("Tick from test component!\n");
		}
