#include<array>


using namespace std;

// This file contains classes of available objects


// The base object class that all other objects inherit from
// Rotational motion is not allowed
template<int dimension = 2>
class BaseObject
{
    public:
        float m;    // mass
        array<float, dimension> pos;  // position
        array<float, dimension> v;    // velocity
        array<float, dimension> a;    // acceleration
        
        // Constructor
        BaseObject(float m = 1, 
                   array<float, dimension> pos = {0},
                   array<float, dimension> v = {0},
                   array<float, dimension> a = {0}) : m(m), pos(pos), v(v), a(a) {}
};

