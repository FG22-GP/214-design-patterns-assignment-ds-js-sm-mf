#include "TestGameObject.h"

void TestGameObject::Start()
{
    GameObject::Start();

    printf("Start from Test Game Object\n");
}

void TestGameObject::Tick()
{
    GameObject::Tick();

    printf("Tick from TestGameObject\n");
}
