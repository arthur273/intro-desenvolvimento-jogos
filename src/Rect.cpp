#include "Rect.h"

#include <cmath> 
#define M_PI 3.14159265358979323846


// Construtores
Rect::Rect() : x(0), y(0), w(0), h(0) {}

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

// Função para calcular a magnitude (distância da origem)
float Rect::Magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Função para normalizar o vetor
Rect Rect::Normalize() const {
    float mag = Magnitude();
    return (mag != 0) ? Rect(x / mag, y / mag, w, h) : Rect(0, 0, w, h);
}

// Função para calcular a distância entre dois retângulos
float Rect::Distance(const Rect& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Função para calcular a inclinação em relação ao eixo X
float Rect::Slope() const {
    return std::atan2(y, x); // atan2 lida com todos os quadrantes
}

// Função para rotação do retângulo em torno da origem
Rect Rect::Rotate(float angle) const {
    float rad = angle * (M_PI / 180.0f);  // Convertendo ângulo para radianos
    float newX = x * std::cos(rad) - y * std::sin(rad);
    float newY = x * std::sin(rad) + y * std::cos(rad);
    return Rect(newX, newY, w, h);
}

// Operadores
Rect Rect::operator+(const Rect& other) const {
    return Rect(x + other.x, y + other.y, w, h);
}

Rect Rect::operator-(const Rect& other) const {
    return Rect(x - other.x, y - other.y, w, h);
}

Rect Rect::operator*(float scalar) const {
    return Rect(x * scalar, y * scalar, w, h);
}

// Acessores
float Rect::GetX() const {
    return x;
}

float Rect::GetY() const {
    return y;
}

float Rect::GetWidth() const {
    return w;
}

float Rect::GetHeight() const {
    return h;
}

void Rect::SetPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

void Rect::SetDimensions(float w, float h) {
    this->w = w;
    this->h = h;
}
