#pragma once

#include <Eigen/Dense>
#include "../Globals.h"

using namespace std;
using Myvector = Eigen::RowVector<double, dimension>;


// This file contains classes of available objects


// The base object class that all other objects inherit from
// Rotational motion is not allowed
class BaseObject
{
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


class Particle: public BaseObject
{
    public:
        const double radius = 1.0;

        // Constructor
        Particle(double radius = {1.0}, 
                 double m = {1.0},
                 const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                 const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                 const Myvector &a = Eigen::RowVectorXd::Zero(dimension)) : radius(radius), BaseObject{m, pos, v, a} {}
};

