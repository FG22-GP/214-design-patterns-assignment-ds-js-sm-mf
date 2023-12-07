#include "TestComponent.h"



void TestComponent::Tick(double DeltaTime)
		{
			printf("My gameobjects name: %s, deltatime is: %f\n", gameObject->name.c_str(), DeltaTime);
			//printf("Tick from test component!\n");
		}
