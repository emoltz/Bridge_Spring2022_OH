#include <iostream>
using namespace std;

class Organism;
class Ant;
class Doodlebug;

class Area{
public:
    Organism* garden[100][100];
};

class Organism{
public:
    Area* world;
};

class Ant : public Organism{
public:
    Ant(Area* world, int x, int y);
};