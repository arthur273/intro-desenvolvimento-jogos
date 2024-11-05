// Game.h
#ifndef GAME_H
#define GAME_H

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include <string>
#include "State.h"

#include <stack>  // For managing a stack of states
#include <memory> // For smart pointers

using namespace std;

class Game {
public:
    static Game& GetInstance(const string& title = "Jogo", int width = 1200, int height = 900);
    void Run();
    
    // Stack management functions
    void PushState(State* state);

    void PopState();
    State& GetCurrentState();

    SDL_Renderer* GetRenderer();
    SDL_Window* GetWindow();

    ~Game();

private:
    Game(const string& title, int width, int height);  // Construtor privado
    void INIT_SDL();
    void SHUTDOWN_SDL();  


    stack<State*> stateStack; // Stack to manage multiple states

    SDL_Window* window;         
    SDL_Renderer* renderer;
    State* state;    
    static Game* instance;      



    // Member variables
    int width; // Add width as a member variable
    int height; // Add height as a member variable
};

#endif // GAME_H
