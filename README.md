# Pong 

It's Pong.

Made by:

- **David Silverlind** - the "engine"
- **Jens Sundqvist** - research
- **Sergei Maltcev** - physics, gameplay
- **Max Fagerström** - graphics library

![Screenshot](https://djsimg.org/Piyz7KpNNci3IMdnjoMt.png)
![Screenshot](https://djsimg.org/8rV5nD2Q3QK3WO5d2wVj.png)

[Video](https://www.youtube.com/watch?v=5w5r4cPl-b0)

# Controls

W/S - Player 1 move up/down
Up/Down - Player 2 move up/down
R - Restart
ESC - Quit

# Approach

In essence, we set out to re-create aspects of Unity and Unreal Engine that we are used to working with. 

So we made our own classes and libraries for:

- GameObject
- Transform
- Vector2 and Vector3
- Physics
- Rendering
- Text
- Input
- ...and probably something else we're forgetting...

Having those set up, we were able to create a simple game like Pong with relative ease. The syntax for the code ended up being somewhat of a hybrid between Unity's C# and Unreal's C++. 

# How Does It Work

The core `game.cpp` is very short at only 53 lines. All it does is tick each GameObject in the "scene" every frame. In turn, every GameObject ticks all of its components. It's beautiful in its simplicity.

![Code](https://djsimg.org/Ky3iyrCMUTZm1SIO72eC.png)

Our "scene" is set up in the *GameManager*. It spawns the paddles and the ball. It also keeps track of where the ball is, awards points, and resets positions when needed.

# Design Patterns Used

## Component Pattern

We were heavily influenced by Unity's component driven system, so practically everything is a component. It's a bit unecessary for a simple game like Pong perhaps, but it made it really easy to extend and add new functionality. 

For example, when we set up the paddles we first created a Rectangle Render Component. Then when we needed to add collision to them, we just added a Collision Component to them.

## Singleton Pattern

Our GameManager is a singleton. It's a reference holder and state manager in our game. 

Our game didn't really need it to be a singleton, but we made it one because initially we thought we would need to access it from other places (like for updating the UI, or making the ball tell the game it went outside).

## Facade Pattern

Max made an awesome graphics library that trivialized it for the rest of us to render things to the scene. We didn't have to think about over complicated SDL syntax. Especially in combination with our component system it made things really easy to draw things to the screen.

We also created a very similar library for Input handling, so we can just write lines like `Input::GetButtonDown` instead of checking for SDL Events etc. 


## GameLoop/Update Pattern

As we are all used to Unity we re-created its MonoBehaviour class in our GameObject class. It made it very easy for us to create a game, extend functionality, and it let us have a main loop that is very short and sweet.


