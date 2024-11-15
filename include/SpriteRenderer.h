#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include <string>

class SpriteRenderer : public Component {
private:
    Sprite sprite;

public:
    // Constructors and destructor
    explicit SpriteRenderer(GameObject& associated);
    SpriteRenderer(GameObject& associated, std::string file, int frameCountW = 1, int frameCountH = 1);
    virtual ~SpriteRenderer() override;

    // Inherited pure virtual methods
    void Update(float dt) override;
    void Render() override;
    bool Is(const std::string& type) const override;

    // Additional public methods
    void Open(std::string file);
    void SetFrameCount(int frameCountW, int frameCountH);
    void SetFrame(int frame);
};

#endif // SPRITE_RENDERER_H