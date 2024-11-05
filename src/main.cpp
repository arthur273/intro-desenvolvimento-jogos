#include "Game.h"

int main(int argc, char* argv[]) {
    Game& game = Game::GetInstance("JOGO", 800, 600);
    game.Run();
    return 0;
}