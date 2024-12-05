#include "TileMap.h"
#include <fstream>
#include <stdexcept>

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) 
    : Component(associated) {
    // Converte o ponteiro para um unique_ptr
    this->tileSet.reset(tileSet);
    
    // Carrega o mapa
    Load(file);
}

void TileMap::Load(std::string file) {
    SDL_Log("Tentando carregar mapa de: %s", "recursos/map.txt");
    std::ifstream mapFile(file);
    if (!mapFile.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo de mapa: " + file);
    }

    std::string line;
    
    // Lê a primeira linha que contém as dimensões
    std::getline(mapFile, line);
    std::stringstream dimensionsStream(line);
    
    std::string value;
    std::vector<int> dimensions;
    
    // Parse das dimensões
    while (std::getline(dimensionsStream, value, ',')) {

        value.erase(0, value.find_first_not_of(" \t\n\r"));
        value.erase(value.find_last_not_of(" \t\n\r") + 1);

        if (value.empty()) {
            //SDL_Log("Aviso: Valor vazio encontrado, ignorando.");
            break;
        }

        //SDL_Log("Lendo valor: %s", value.c_str()); // Log do valor extraído

        dimensions.push_back(std::stoi(value));
    }
    //SDL_Log("erro aqui");
    // Verifica se temos 3 dimensões
    if (dimensions.size() != 3) {
        throw std::runtime_error("Formato de dimensões inválido");
    }

    // Define as dimensões do mapa
    mapWidth = dimensions[0];
    mapHeight = dimensions[1];
    mapDepth = dimensions[2];

    // Redimensiona a matriz de tiles
    tileMatrix.clear();
    tileMatrix.resize(mapWidth * mapHeight * mapDepth);

    // Lê os tiles
    unsigned long tileIndex = 0; // unsigned long é mais ou menos = size_t
    while (std::getline(mapFile, line) && tileIndex < tileMatrix.size()) {
        std::stringstream tileStream(line);

        while (std::getline(tileStream, value, ',')) {

            value.erase(0, value.find_first_not_of(" \t\n\r"));
            value.erase(value.find_last_not_of(" \t\n\r") + 1);

            if (value.empty()) {
                //SDL_Log("Aviso: Valor vazio encontrado, ignorando.");
                break;
            }

            //SDL_Log("Lendo valor: %s", value.c_str()); // Log do valor extraído


            if (!value.empty() && tileIndex < tileMatrix.size()) {
                tileMatrix[tileIndex++] = std::stoi(value);
            }
        }
    }

    mapFile.close();
}

void TileMap::SetTileSet(TileSet* tileSet) {
    // Converte o ponteiro para um unique_ptr
    this->tileSet.reset(tileSet);
}

int& TileMap::At(int x, int y, int z) {
    // Verifica se as coordenadas estão dentro dos limites
    if (x < 0 || x >= mapWidth || y < 0 || y >= mapHeight || z < 0 || z >= mapDepth) {
        throw std::out_of_range("Coordenadas de tile inválidas");
    }

    // Calcula o índice no vetor unidimensional
    return tileMatrix[z * (mapWidth * mapHeight) + y * mapWidth + x];
}

void TileMap::Render() {
    // Renderiza todas as camadas
    SDL_Log("Tile Map Render called");
    for (int layer = 0; layer < mapDepth; ++layer) {
        RenderLayer(layer);
    }
}

void TileMap::RenderLayer(int layer) {
    SDL_Log("Rendering Map Layer");
    // Verifica se a camada é válida
    if (layer < 0 || layer >= mapDepth) {
        throw std::out_of_range("Camada de mapa inválida");
    }

    // Obtém as dimensões do tile
    int tileWidth = tileSet->GetTileWidth();
    int tileHeight = tileSet->GetTileHeight();

    // Obtém a posição do GameObject
    float x = associated.box.GetX();
    float y = associated.box.GetY();

    // Renderiza os tiles da camada
    for (int j = 0; j < mapHeight; ++j) {
        for (int i = 0; i < mapWidth; ++i) {
            int tileIndex = At(i, j, layer);
            
            // Renderiza apenas tiles não vazios
            if (tileIndex != -1) {
                tileSet->RenderTile(
                    tileIndex, 
                    x + i * tileWidth, 
                    y + j * tileHeight
                );
            }
        }
    }
}

int TileMap::GetWidth() {
    return mapWidth;
}

int TileMap::GetHeight() {
    return mapHeight;
}

int TileMap::GetDepth() {
    return mapDepth;
}

// necessários para compilador não reclamar sobre a herança de component
bool TileMap::Is(const std::string& type) const{
    return type == "TileMap";
}


void TileMap::Update(float dt) {

}