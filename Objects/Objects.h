#pragma once

#include <Eigen/Dense>
#include "Globals.h"
#include "Color.h"

using namespace std;
using Myvector = Eigen::RowVector<float, dimension>;


// This file contains classes of available objects


// The base object class that all other objects inherit from
// Rotational motion is not allowed
class BaseObject
{
    public:
        float mass;
        Myvector position;
        Myvector velocity;
        Myvector acceleration;
        Color color;

        // Constructor
        BaseObject(float m = {1.0}, 
                   const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                   const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                   const Myvector &a = Eigen::RowVectorXd::Zero(dimension),
                   const Color &color = {255, 0, 0}) : mass(m), position(pos), velocity(v), acceleration(a), color(color) {}
};


class Particle: public BaseObject
{
    public:
        float radius = 1.0;

        // Constructor
        Particle(float radius = {1.0}, 
                 float m = {1.0},
                 const Myvector &pos = Eigen::RowVectorXd::Zero(dimension),
                 const Myvector &v = Eigen::RowVectorXd::Zero(dimension),
                 const Myvector &a = Eigen::RowVectorXd::Zero(dimension),
                 const Color &color = {255, 0, 0}) : radius(radius), BaseObject{m, pos, v, a, color} {}
};

