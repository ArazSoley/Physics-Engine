#include"World.h"
#include <Eigen/Dense>
#include "Globals.h"

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
