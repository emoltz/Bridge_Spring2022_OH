#include <iostream>
using namespace std;

class Organism;
class Ant;
class Doodlebug;

class Area{
public:
    Organism* garden[20][20];
};

class Organism{
public:
    Area* world;
    //virtual function: what functions MUST you have for the Ants and the Doodlebugs?
};

class Ant : public Organism{
public:
    Ant(Area* world, int x, int y);
};

