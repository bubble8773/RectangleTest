// RectangleTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include "Entity.h"
#include "Component.h"
#include "HealthComponent.h"
#include "AttackComponent.h"
#include "MovementComponent.h"
using namespace std;

//class Entity;
//class Component;
//class HealthComponent;
//class AttackComponent;
//class MovementComponent;
int main(int argc, const char* argv[])
{
    string fileName = "";
   
   /* if (argc < 2)
    {
        std::cerr << "Specify a file to run this program.\n";
        return 1;
    }*/
    std::cout << "Enter the filename: ";
    std::cin >> fileName;
    argv[1] = fileName.c_str();
    std::cout << "Running program against file: " << argv[1] << "\n";
    std::ifstream file(argv[1], std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file.\n";
        return 2;
    }
    unsigned int numberOfEntities = 0;
    if (!(file >> numberOfEntities))
    {
        std::cerr << "Failed to get number of Entities from file.\n";
        return 3;
    }
    // TODO: Add a collection of Entities.
    vector<Entity*> entites;
    int countIntersection = 0;
    for (unsigned int i = 0; i < numberOfEntities; ++i)

    {
        float x = 0;
        float y = 0;
        float width = 0;
        float height = 0;
        Entity* newEntity = new Entity();
        HealthComponent *healthComponent = new HealthComponent();
        AttackComponent *attackComponent = new AttackComponent();
        MovementComponent* movementComponent = new MovementComponent();

        if (!(file >> x >> y >> width >> height))
        {
            std::cerr << "Error getting bounds on line " << i + 1 << ".\n";
            return 4;
        }
        
        
        // Not every Entity has Components.
        std::string componentTypes;
        const auto currentPos = file.tellg();
        file >> componentTypes;
        if (!componentTypes.empty() && !std::isalpha(componentTypes.back()))
        {
            file.seekg(currentPos);
            componentTypes.clear();
        }
        for (const char type : componentTypes)
        {
            switch (type)
            {
            case 'H':
                // TODO: This Entity has a HealthComponent.
                newEntity->AddComponent(healthComponent);
                //To test this case
               // cout << "Added health"<<endl;
                break;
            case 'A':
                // TODO: This Entity has an AttackComponent.
                newEntity->AddComponent(attackComponent);
                //cout << "Added attack" << endl;                
                break;
            case 'M':
                // TODO: This Entity has a MovementComponent.
                newEntity->AddComponent(movementComponent);
                //cout << "Added movement" << endl;
                break;
            
            default:
                std::cerr << "Unknown Component type: " << type << "\n";
                break;
            }
        }
        // TODO: Use the above information to create an Entity with
       // a Rectangle2D bounding box and given Components.

        newEntity->rectangle2D = new Rectangle2D(x, y, width, height);
        entites.push_back(newEntity);
    }
    file.close();
    const auto start = std::chrono::high_resolution_clock::now();
   
    //  Algorithm to detect number of Entity intersections.    
    for( int i = 0; i <= entites.size()-1; i++)
    {
        //To test number of components in each entity
        //cout<<entites[i]->components.size()<<endl;

        if (i != entites.size() - 1 && i+1 != entites.size() - 1) {
            if (entites[i]->rectangle2D->TestIntersection(entites[i + 1]->rectangle2D)) {
                //cout << "Interscetion has occured" << endl;
                countIntersection++;
            }
           /* else {
                cout << "Interscetion has not occured" << endl;
            }*/
        }
        //else  if (i == entites.size() - 1)
        //{
        //    if (entites[i]->rectangle2D->TestIntersection(entites[i - 1]->rectangle2D)) {
        //        //cout << "Interscetion has occured" << endl;
        //        countIntersection++;
        //    }
        //}
    }
    cout << countIntersection << endl;
    const auto end = std::chrono::high_resolution_clock::now();
    const auto runMS =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Algorithm executed in " << runMS.count() << "ms.\n";
    return 0;
}

