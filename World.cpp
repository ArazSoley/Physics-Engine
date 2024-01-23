#include"World.h"
#include <Eigen/Dense>
#include "Objects/Objects.h"

using namespace std;

template<int dimension>
void World<dimension>::AddParticle(double radius, double m, const Myvector &pos, const Myvector &v, const Myvector &a)
{
    objects.push_back(Particle<dimension>(radius, m, pos, v, a));
}