#pragma once
#include "Rectangle2D.h"
#include "Component.h"
#include <vector>
class Entity
{
	// TODO: Add:
// - A Rectangle2D bounding-box.
// - A collection of Components.
// - An implementation to make Entity copyable.
public:
	Rectangle2D *rectangle2D;
	std::vector<class Component*> components;
	Entity();
	Entity(Rectangle2D *rect2d, std::vector<class Component*> components);
	void AddComponent(class Component* component);
};

