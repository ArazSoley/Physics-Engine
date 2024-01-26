#pragma once

#include "Objects.h"
#include <vector>
#include "Eigen/Dense"
#include "Globals.h"

using namespace std;
using Myvector = Eigen::RowVector<double, dimension>;


// A world where all objects live
class World
{
    vector<Particle> objects;  // A vecotr where all objects are stored
    const Myvector gravity;    // gravity
    const int width, height;   // width/height of the screen
    int fps = 30;                     // FPS. Initialized in Start
    double timestep = 1.0 / 30.0;     // Physical timestep. Initialized in Start

    //Stepping function
    void Step();

    public:

        // Constructor
        World(int width,
              int height,
              const Myvector &gravity = Myvector(0, 9.8)) : width(width), height(height), gravity(gravity) {}
              
        // Adds a single particle to the world
        void AddParticle(double radius = {1.0}, 
                         double m = {1.0},
                         const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &a = Eigen::RowVectorXd::Zero(dimension));

        // Activates the engine for "duration" seconds
        void Start(int duration = 30, int framePerSecond = 30, double timeStep = 1.0 / 30.0);
};
