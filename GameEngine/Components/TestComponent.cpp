#include "TestComponent.h"



void TestComponent::Tick()
		{
			printf("My gameobjects name: %s\n", gameObject->name.c_str());
			//printf("Tick from test component!\n");
		}
