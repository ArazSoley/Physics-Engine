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
    vector<Particle> objects;                   // A vecotr where all objects are stored
    const Myvector gravity;  //gravity
    const double timestep;
    const int width, height;

    public:

        // Constructor
        World(int width,
              int height,
              const Myvector &gravity = Myvector(0, 9.8),
              double timestep = 0.05) : width(width), height(height), gravity(gravity), timestep(timestep) {}
              
        // Adds a single particle to the world
        void AddParticle(double radius = {1.0}, 
                         double m = {1.0},
                         const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &a = Eigen::RowVectorXd::Zero(dimension));
};
