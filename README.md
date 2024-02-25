# Physics-Engine

## Creating a World
You create your world in the "main.cpp" file.
A world can be created by creating a `World` object:
```
World myWorld(width, height);
```
where `width` and `height` specify the size of the world.

Particles can be added to a world using `AddParticle` method of the world object.
The arguments corresppond to radius, mass, position, velocity, acceleration, and color of the p article respectively. Position, velocity, and acceleration should be provided to the function as `Myvector` type, which is defined in "main.cpp".

You can also use `randonNumMax` and `randonNumInRange` functions provided in "main.cpp" to create random particles.

After creating