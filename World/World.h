#pragma once

#include "Objects.h"
#include <vector>
#include "Eigen/Dense"
#include "Globals.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "Color.h"

using namespace std;
using Myvector = Eigen::RowVector<float, dimension>;


// A world where all objects live
class World
{
    vector<Particle> objects;  // A vecotr where all objects are stored
    const Myvector gravity;    // gravity
    const int width, height;   // width/height of the screen
    int fps = 30;                     // FPS. Initialized in Start
    float timestep = 1.0 / 30.0;     // Physical timestep. Initialized in Start

    // Stepping function
    void Step();

    // Draws the bounding box and objects on given window
    void DrawOnWindow(sf::RenderTexture &texture) const;

    // Detects and resolves collisions
    void CollisionDetector();

    void SweepAndPrune();

    // Checks for collision between two particles and solves it
    void ParticleParticleCollisionCheck(Particle &first, Particle &second);

    // Performs a mergesort according to x position on "objects" (not in-place)
    vector<Particle> MergeSort(int first, int last) const;

    // Performs an in-place insertion sort according to x position on "objects"
    void InsertionSort();

    public:

        // Constructor
        World(int width,
              int height,
              const Myvector &gravity = defaultGravity) : width(width), height(height), gravity(gravity) {}
              
        // Adds a single particle to the world
        void AddParticle(float radius = {1.0}, 
                         float mass = {1.0},
                         const Myvector &position = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &velocity = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &acceleration = defaultGravity,
                         const Color &color = {255, 0, 0});

        // Activates the engine for "duration" seconds
        void Start(int framePerSecond = 30);
};
