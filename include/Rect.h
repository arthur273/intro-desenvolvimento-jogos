// State.h
#ifndef RECT_H
#define RECT_H

#include <string>

class Rect {

public:
    // Construtores
    Rect();
    Rect(float x, float y, float w, float h);

    
// Funções de operações geométricas
    float Magnitude() const;                            // Magnitude da posição (distância da origem)
    Rect Normalize() const;                             // Normaliza o vetor
    float Distance(const Rect& other) const;            // Distância entre dois retângulos
    float Slope() const;                                // Inclinação do vetor (posição) em relação ao eixo X
    Rect Rotate(float angle) const;                     // Rotação do vetor

    // Operadores
    Rect operator+(const Rect& other) const;            // Soma de dois retângulos (componentes)
    Rect operator-(const Rect& other) const;            // Subtração de dois retângulos (componentes)
    Rect operator*(float scalar) const;                 // Multiplicação do vetor por escalar

    // Acessores
    float GetX() const;
    float GetY() const;
    float GetWidth() const;
    float GetHeight() const;
    void SetPosition(float x, float y);
    void SetDimensions(float w, float h);

private:
    float x, y;  // Posição (canto superior esquerdo)
    float w, h;  // Dimensões (largura e altura)
};

#endif // RECT_H
