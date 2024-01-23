#pragma once

#include "Objects/Objects.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;

// A world where all objects live
template<int dimension = 2>
class World
{
    using Myvector = Eigen::RowVector<double, dimension>;

    
    double gravity = 9.8;

    public:
        vector<Particle<dimension>> objects;
        void AddParticle(double radius = {1.0}, 
                         double m = {1.0},
                         const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                         const Myvector &a = Eigen::RowVectorXd::Zero(dimension));

};
