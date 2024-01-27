#include "World.h"
#include <Eigen/Dense>
#include "Globals.h"
#include <SFML/Graphics.hpp>
#include <list>

using namespace std;
using Myvector = Eigen::RowVector<double, dimension>;


void World::AddParticle(double radius, double m, const Myvector &pos, const Myvector &v, const Myvector &a)
{
    objects.push_back(Particle(radius, m, pos, v, a));
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

        Step();
        DrawOnWindow(texture);


        frames.push_back(texture.getTexture());
    }

    // The main window
    sf::RenderWindow window(sf::VideoMode(width + 50, height + 50), "2D Physics Engine");
    // timestep
    const sf::Time frameTime = sf::seconds(timestep);

    for (const auto &texture : frames)
    {
        // Display the frame on the window
        sf::Sprite sprite(texture);

        window.clear();
        window.draw(sprite);
        window.display();


        // Introduce a delay to achieve the desired frame rate
        sf::sleep(frameTime);
    }
}

void World::DrawOnWindow(sf::RenderTexture &texture) const
{
    // The bounding box
    sf::RectangleShape box(sf::Vector2f(width, height));
    box.setPosition((texture.getSize().x - width) / 2.0, (texture.getSize().y - height) / 2.0);
    box.setOutlineColor(sf::Color::Blue);
    texture.draw(box);

    // Draw every object of "objects" on texture
    for (auto &object: objects)
    {
        sf::CircleShape particle(object.radius);
        particle.setPosition(object.position[0], object.position[1]);
        particle.setFillColor(sf::Color::Red);
        texture.draw(particle);
    }
}