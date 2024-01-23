#pragma once

#include <Eigen/Dense>

using namespace std;

// This file contains classes of available objects


// The base object class that all other objects inherit from
// Rotational motion is not allowed
template<int dimension>
class BaseObject
{
    using Myvector = Eigen::RowVector<double, dimension>;

    public:
        const double m;    // mass
        Myvector pos;        // position
        Myvector v;          // velocity
        Myvector a;          // acceleration

        // Constructor
        BaseObject(double m = {1.0}, 
                   const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                   const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                   const Myvector &a = Eigen::RowVectorXd::Zero(dimension)) : m(m), pos(pos), v(v), a(a) {}
};


template<int dimension = 2>
class Particle: public BaseObject<dimension>
{
    using Myvector = Eigen::RowVector<double, dimension>;

    public:
        const double radius = 1.0;

        // Constructor
        Particle(double radius = {1.0}, 
                 double m = {1.0},
                 const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                 const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                 const Myvector &a = Eigen::RowVectorXd::Zero(dimension)) : radius(radius), BaseObject<dimension>{m, pos, v, a} {}
};

