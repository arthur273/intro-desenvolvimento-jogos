#ifndef TILESET_H
#define TILESET_H

#include <string>
#include "Sprite.h"  


class TileSet {
public:
    // Construtor que recebe dimensões dos tiles e caminho do arquivo
    TileSet(int tileWidth, int tileHeight, std::string file);

    // Renderiza um tile específico na posição x, y
    void RenderTile(int index, float x, float y);

    // Getters para as dimensões dos tiles
    int GetTileWidth();
    int GetTileHeight();

private:
    // Sprite que contém todos os tiles
    Sprite tileSet;

    // Dimensões de cada tile
    int tileWidth;
    int tileHeight;

    // Número total de tiles no conjunto
    int tileCount;
};

#endif // TILESET_H