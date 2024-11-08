#include "Vec2.h"
#include <cmath> 


#define M_PI 3.14159265358979323846



// Construtores
Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

// Função para calcular a magnitude (tamanho) do vetor
float Vec2::Magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Função para normalizar o vetor (vetor unitário)
Vec2 Vec2::Normalize() const {
    float mag = Magnitude();
    return (mag != 0) ? Vec2(x / mag, y / mag) : Vec2(0, 0);
}

// Função para calcular a distância entre dois vetores
float Vec2::Distance(const Vec2& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Função para calcular a inclinação do vetor em relação ao eixo X
float Vec2::Slope() const {
    return std::atan2(y, x); // atan2 lida com todos os quadrantes
}

// Função para rotação do vetor por um determinado ângulo
Vec2 Vec2::Rotate(float angle) const {
    float rad = angle * (M_PI / 180.0f);  // Convertendo ângulo para radianos
    float newX = x * std::cos(rad) - y * std::sin(rad);
    float newY = x * std::sin(rad) + y * std::cos(rad);
    return Vec2(newX, newY);
}

// Operadores
Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

// Acessores
float Vec2::GetX() const {
    return x;
}

float Vec2::GetY() const {
    return y;
}

void Vec2::Set(float x, float y) {
    this->x = x;
    this->y = y;
}
