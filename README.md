# Physics-Engine

### Creating a World
You can create your world in the "main.cpp" file.
A world can be created by instantiating a `World` object:
```
World myWorld(width, height, gravity);
```
where `width` and `height` specify the size of the world, and `gravity` is an object of `Myvector` type, which is defined in "main.cpp". Default value of `gravity` is defined in "Globals.h" file and can be modified as desired.

Particles can be added to a world using `AddParticle` method of the world object.
The arguments corresppond to radius, mass, position, velocity, acceleration, and color of the p article respectively. Position, velocity, and acceleration should be provided to the function as `MyVector` type. 

*Note: You can also use `randonNumMax` and `randonNumInRange` functions provided in "main.cpp" to create random particles.

After creating the world and adding the particles, you can start the world (or, the simulation) by using `Start` method of your `World` object. `Start` method takes fps as its argument, and the default value is 60.

### Compiling And Running The Program
You can compile and run the program by using `make build` and `make run` commands in the terminal respectively.