#include "Component.h"
#include "GameObject.h"  // Make sure GameObject is declared before using it

// Constructor that associates the Component with a GameObject
Component::Component(GameObject& associated)
    : associated(associated) {}

// Virtual destructor to allow proper cleanup of derived classes
Component::~Component() {
    // You can add cleanup code if needed for derived classes, but typically,
    // memory for components is managed by the GameObject (or parent class).
}

// Example of Update function: override this in derived classes
void Component::Update(float dt) {
    // Base implementation does nothing, derived classes will override
}

// Example of Render function: override this in derived classes
void Component::Render() {
    // Base implementation does nothing, derived classes will override
}

