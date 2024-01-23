#include<iostream>
#include "World.h"

using namespace std;
using Myvector = Eigen::RowVector<double, 2>;
int main()
{

    World<2> myWorld;
    myWorld.AddParticle(1.0, 1.0, Myvector(12.9, 23.5));

    cout << myWorld.objects[0].pos[1] << endl;

    return 0;
}