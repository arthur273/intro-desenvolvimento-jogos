#include "TileSet.h"
#include <stdexcept>
#include <cmath>

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) 
    : tileWidth(tileWidth), tileHeight(tileHeight){

    tileSet.Open("recursos/Tileset.png");
    // Verifica se o sprite foi carregado corretamente
    if (!tileSet.IsOpen()) {
        throw std::runtime_error("Erro ao carregar o tileset: " + file);
    }

    // Calcula o número total de tiles
    int spriteWidth = tileSet.GetWidth();
    int spriteHeight = tileSet.GetHeight();

    // Calcula o número de colunas e linhas no tileset
    int columns = spriteWidth / tileWidth;
    int rows = spriteHeight / tileHeight;

    // Define o número total de tiles
    tileCount = columns * rows;

    // Configura o sprite para usar frames correspondentes aos tiles
    tileSet.SetFrameCount(columns, rows); 
    // tileSet.SetFrameTime(0);  // Tiles não são animados
}

void TileSet::RenderTile(int index, float x, float y) {
    // Verifica se o índice é válido
    //SDL_Log("%d", tileCount);
    if (index >= tileCount) {
        throw std::out_of_range("Índice de tile inválido");
    }
    // Define o frame do sprite para o tile desejado
    tileSet.SetFrame(index);

    // Renderiza o tile na posição especificada
    tileSet.Render(x, y, tileWidth, tileHeight);
}

int TileSet::GetTileWidth() {
    return tileWidth;
}

int TileSet::GetTileHeight() {
    return tileHeight;
}