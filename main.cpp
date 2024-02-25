#include<iostream>
#include "World.h"
#include "Globals.h"
#include <cstdlib>
#include "Color.h"

using namespace std;
using Myvector = Eigen::RowVector<float, dimension>;

int randonNumMax(int max)
{
    return rand() % max;
}

int randonNumInRange(int min, int max)
{
    return (rand() % (max - min)) + min;
}

int main()
{
    int maxNum = 200;

    World myWorld(1920, 1080);


    for (int x = 100, y = 200, i = 20; i > 0; i--)
        for (int j = 15; j > 0; j--)
            myWorld.AddParticle(randonNumInRange(10, 25), randonNumInRange(20, 250), Myvector(100 + i * (2 * 20 + 10), 200 + j * (2 * 20 + 10)),
                                Myvector(randonNumMax(maxNum), randonNumMax(maxNum)), defaultGravity, Color{randonNumMax(256), randonNumMax(256), randonNumMax(256)});
 
    /* myWorld.AddParticle(20, 1, Myvector(300, 0), Myvector(0, 0));
    myWorld.AddParticle(20, 1000000, Myvector(400, 0), Myvector(-30, 0)); */

    myWorld.Start(300);

    return 0;
}