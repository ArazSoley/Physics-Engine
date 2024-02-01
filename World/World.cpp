#include "World.h"
#include <Eigen/Dense>
#include "Globals.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Color.h"

using namespace std;
using Myvector = Eigen::RowVector<float, dimension>;


void World::AddParticle(float radius, float mass, const Myvector &position,
                        const Myvector &velocity, const Myvector &acceleration, const Color &color)
{
    objects.push_back(Particle(radius, mass, position, velocity, acceleration, color));
}

void World::Step()
{
    for(auto &object : objects)
    {
        //acceleration is constant for this version of engine
        object.velocity += object.acceleration * timestep;
        object.position += object.velocity * timestep;
        //subsequent collision detector  
    }
}

void World::Start(int framePerSecond)
{
    // Initializing timestep & fps
    timestep = 1.0 / framePerSecond;
    fps = framePerSecond;
    

    // The main window
    sf::RenderWindow window(sf::VideoMode(width + 50, height + 50), "2D Physics Engine");
    window.setFramerateLimit(fps);

    // A single frame
    sf::RenderTexture texture;
    texture.create(width + 50, height + 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();


        // Move the objects
        Step();
        // Detect and resolve collisions
        CollisionDetector();

        texture.clear();
        texture.setSmooth(true);
        // Draw objects on the frame
        DrawOnWindow(texture);

        window.clear();
        window.draw(sf::Sprite(texture.getTexture()));
        window.display();
        
    }
}

void World::DrawOnWindow(sf::RenderTexture &texture) const
{
    // The bounding box
    sf::RectangleShape box(sf::Vector2f(width, height));
    box.setPosition((texture.getSize().x - width) / 2.0, (texture.getSize().y - height) / 2.0);
    box.setOutlineColor(sf::Color::Blue);
    box.setOutlineThickness(1);
    texture.draw(box);

    // Draw every object of "objects" on texture
    for (auto &object: objects)
    {
        sf::CircleShape particle(object.radius);
        particle.setPosition(object.position[0] + 25, object.position[1] + 25);
        particle.setFillColor(sf::Color(object.color.red, object.color.green, object.color.blue));
        texture.draw(particle);
    }
}

void World::CollisionDetector()
{
    // First, check border collisions
    for (int i = 0, size = objects.size(); i < size; i++)
    {
        // Upper and lower
        if ((objects[i].position[1] <= 0 && objects[i].velocity[1] < 0) || 
            ((objects[i].position[1] + 2 * objects[i].radius) >= height && objects[i].velocity[1] > 0))
            objects[i].velocity[1] = -objects[i].velocity[1];
        // Left and right
        if ((objects[i].position[0] <= 0 && objects[i].velocity[0] < 0) || 
            ((objects[i].position[0] + 2 * objects[i].radius) >= width && objects[i].velocity[0] > 0))
            objects[i].velocity[0] = -objects[i].velocity[0];
    }

    SweepAndPrune();
}

void World::SweepAndPrune()
{
    //InsertionSort();
    objects = MergeSort(0, objects.size()-1);
    
    for (int i = 0, size = objects.size(); i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
        {
            if (objects[j].position[0] <= (objects[i].position[0] + objects[i].radius * 2))
                {ParticleParticleCollisionCheck(objects[i], objects[j]);}
            else
                break;
        }
}

void World::ParticleParticleCollisionCheck(Particle &first, Particle &second)
{
    Myvector diffOfCenters((first.position + Myvector(first.radius, first.radius)) - (second.position + Myvector(second.radius, second.radius)));
    Myvector diffOfVelocities(first.velocity - second.velocity);

    if ((diffOfCenters.squaredNorm() <= ((first.radius + second.radius) * (first.radius + second.radius))) &&
        (diffOfCenters.dot(diffOfVelocities) < 0))
    {
        first.velocity = first.velocity - (2 * second.mass / (first.mass + second.mass)) * (diffOfVelocities.dot(diffOfCenters) / diffOfCenters.squaredNorm()) * diffOfCenters;
        second.velocity = second.velocity + (2 * first.mass / (first.mass + second.mass)) * ((-1 * diffOfVelocities).dot(-1 * diffOfCenters) / diffOfCenters.squaredNorm()) * diffOfCenters;
    }
}

void World::InsertionSort()
{
    for (int i = 1, size = objects.size(); i < size; i++)
    {
        Particle temp(objects[i]);
        int j = i - 1;
        for (; (j > -1) && (objects[j].position[0] > temp.position[0]); j--)
            {objects[j + 1] = objects[j];}

        objects[j + 1] = temp;
    }
}

/*
vector<Particle> World::MergeSort(int first, int last) const
{
    if (first > last)
        return vector<Particle>();
    if (first == last)
        return vector<Particle> {objects[first]};

    vector<Particle> leftVec = MergeSort(first, (first + last) / 2);
    vector<Particle> rightVec = MergeSort((first + last) / 2 + 1, last);

    vector<Particle> res;
    int leftIdx = 0, rightIdx = 0, leftSize = leftVec.size(), rightSize = rightVec.size();

    for (; leftIdx < leftSize && rightIdx < rightSize;)
    {
        if (leftVec[leftIdx].position[0] < rightVec[rightIdx].position[0])
        {
            res.push_back(leftVec[leftIdx]);
            leftIdx++;
        }
        else
        {
            res.push_back(rightVec[rightIdx]);
            rightIdx++;
        }
    }
    for (; leftIdx < leftSize; leftIdx++)
        res.push_back(leftVec[leftIdx]);
    for (; rightIdx < rightSize; rightIdx++)
        res.push_back(rightVec[rightIdx]);

    counter+=res.size();
    return res;
} */
/*
void World::Start(int duration, int framePerSecond)
{
    // Initializing timestep & fps
    timestep = 1.0 / framePerSecond;
    fps = framePerSecond;
    

    // A list for storing all the frames
    list<sf::Texture> frames;
    int totalFrameCount = duration * fps;


    for (int frameNum = 0; frameNum < totalFrameCount; frameNum++)
    {
        // A single frame
        sf::RenderTexture texture;
        texture.create(width + 50, height + 50);

        // Move the objects
        Step();
        // Detect and resolve collisions
        CollisionDetector();
        // Draw objects on the frame
        DrawOnWindow(texture);  

        //texture.getTexture().copyToImage().saveToFile("C:\\Users\\Araz\\Documents\\C++ Projects\\Physics-Engine\\vid\\" + to_string(frameNum) + ".png");

        frames.push_back(texture.getTexture());
    }

    // The main window
    sf::RenderWindow window(sf::VideoMode(width + 50, height + 50), "2D Physics Engine");
    window.setFramerateLimit(fps);

    // Show the rendered frames
    for (const auto &texture : frames)
    {
        // Display the frame on the window
        sf::Sprite sprite(texture);

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
      
        window.clear();
        window.draw(sprite);
        window.display();
    }
} */
