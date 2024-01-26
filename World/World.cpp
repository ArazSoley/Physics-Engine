#include"World.h"
#include <Eigen/Dense>
#include "Globals.h"

using namespace std;
using Myvector = Eigen::RowVector<double, dimension>;


void World::AddParticle(double radius, double m, const Myvector &pos, const Myvector &v, const Myvector &a)
{
    objects.push_back(Particle(radius, m, pos, v, a));
}


void World::Step(void)
{
    // acceleation is constant for now
    for (auto &vec: objects)
    {
        vec.pos += vec.v * timestep;
        vec.v += vec.a * timestep;
    }
}
