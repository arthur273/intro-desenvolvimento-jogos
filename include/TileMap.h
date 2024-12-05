#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <memory>
#include <string>
#include "Component.h"
#include "TileSet.h"
#include "GameObject.h"
#include <sstream>

class TileMap : public Component {
public:
    // Construtor que recebe o GameObject associado, arquivo de mapa e TileSet
    TileMap(GameObject& associated, std::string file, TileSet* tileSet);

    // Carrega o mapa a partir de um arquivo
    void Load(std::string file);

    // Troca o TileSet em uso
    void SetTileSet(TileSet* tileSet);

    // Método accessor para acessar tiles
    int& At(int x, int y, int z = 0);

    // Renderiza todas as camadas do mapa
    void Render() override;

    // Renderiza uma camada específica do mapa
    void RenderLayer(int layer);

    // Métodos para obter as dimensões do mapa
    int GetWidth();
    int GetHeight();
    int GetDepth();

    // Overrides necessários 
    void Update(float dt) override;
    bool Is(const std::string& type) const override;

private:
    // Matriz de tiles representada como um vetor unidimensional
    std::vector<int> tileMatrix;

    // Ponteiro único para o TileSet em uso
    std::unique_ptr<TileSet> tileSet;

    // Dimensões do mapa
    int mapWidth;
    int mapHeight;
    int mapDepth;
};

#endif // TILEMAP_H