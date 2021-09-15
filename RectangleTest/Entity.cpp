//#include <graphics.h>
#include <conio.h>
#include "Entity.h"

Entity::Entity()
{
	rectangle2D = new Rectangle2D();

}

void Entity::AddComponent(class Component* component)
{
	this->components.push_back(component);
}

Entity::Entity(Rectangle2D *rect2d, std::vector<class Component*> components)
{
	this->rectangle2D = rect2d;
	this->components = components;
}
