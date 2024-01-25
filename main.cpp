#include<iostream>
#include "World.h"
#include "Globals.h"

using namespace std;
using Myvector = Eigen::RowVector<double, dimension>;


int main()
{

    World myWorld;
    myWorld.AddParticle(1.0, 1.0, Myvector(23, 34.5));


    return 0;
}