#include<iostream>
#include "World.h"
#include "Globals.h"

using namespace std;
using Myvector = Eigen::RowVector<double, dimension>;


int main()
{

    World myWorld(1280, 720);

    for (int x = 100, y = 200, i = 5; i > 0; i--)
        for (int j = 4; j > 0; j--)

            myWorld.AddParticle(20, 50, Myvector(100 + i * (2 * 20 + 10), 200 + j * (2 * 20 + 10)), Myvector(0, 100));

    myWorld.Start(10, 60);

    return 0;
}