#ifndef VEC2_H
#define VEC2_H

#include <cmath>

class Vec2 {
public:
    // Construtores
    Vec2();
    Vec2(float x, float y);

    // Funções de operações geométricas
    float Magnitude() const;                // Magnitude (tamanho) do vetor
    Vec2 Normalize() const;                 // Normaliza o vetor
    float Distance(const Vec2& other) const; // Distância entre dois vetores
    float Slope() const;                    // Inclinação do vetor em relação ao eixo X
    Vec2 Rotate(float angle) const;         // Rotação do vetor por um determinado ângulo

    // Operadores
    Vec2 operator+(const Vec2& other) const; // Soma de vetores
    Vec2 operator-(const Vec2& other) const; // Subtração de vetores
    Vec2 operator*(float scalar) const;      // Multiplicação do vetor por um escalar

    // Acessores
    float GetX() const;
    float GetY() const;
    void Set(float x, float y);

private:
    float x, y;  // Coordenadas do vetor
};

#endif // VEC2_H
