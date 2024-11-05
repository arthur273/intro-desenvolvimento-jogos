#include "Game.h"

int main(int argc, char* argv[]) {
    Game& game = Game::GetInstance("JOGO", 1200, 900);
    game.Run();
    return 0;
}