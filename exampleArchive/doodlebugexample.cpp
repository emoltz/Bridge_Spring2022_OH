#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

const int LIMIT = 20;
const int DOODLEBUGS = 5;
const int ANTS = 100;

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
const int DIRECTIONS = 4;

const int DOODLEBUG_ID = 1;
const int ANT_ID = 2;
class Organism;

class Area{
private:
    int totalDoodleBugs;
    int totalAnts;
    int timeStepCount;
public:
    Organism* garden[LIMIT][LIMIT];
    int randomNumberGenerator(int range, int optional = 0) {
        return (rand() % range) + optional;
    }

    Area() : totalDoodleBugs(DOODLEBUGS), totalAnts(ANTS), timeStepCount(0){
        this->populate();
    }
    Area(int doodleBugsCount, int antsCount) : totalDoodleBugs(doodleBugsCount), timeStepCount(0), totalAnts(antsCount) { this->populate();}

    virtual ~Area();
    void populate();
    void beginGame();
    void printWorld();
    int getTimeStepCount() const{return timeStepCount;}
};

class Organism{
    friend class World;
protected:
    Area* world;
    int position_x;
    int position_y;
    int breedingTime;
    int organismLifeTime;
public:

    Organism() : world(nullptr), position_x(0), position_y(0), breedingTime(0), organismLifeTime(0){}
    Organism(Area* currentGarden, int x, int y) : world(currentGarden), position_x(x), position_y(y), breedingTime(0), organismLifeTime(currentGarden->getTimeStepCount()){}

    virtual void move();
    virtual void breed() = 0;
    virtual bool starving() {return false;};
    virtual int getType() = 0;
    void getTheCell(int direction, int& temp_x, int& temp_y);
    bool onTheBoard(int x, int y);
    vector<int> getEmptyCells(int x, int y);
};

class Ant : public Organism{
public:
    Ant() : Organism(){}
    Ant(Area* theWorld, int x, int y) : Organism(theWorld, x, y) {}

    virtual int getType() {return ANT_ID;}
    virtual void breed();
    virtual void move();

};

class Doodlebug : public  Organism{

public:
    Doodlebug() : Organism(), timeTillStarve(0) {}
    Doodlebug(Area* theWorld, int x, int y) : Organism(theWorld, x, y), timeTillStarve(0) {}

    virtual int getType() {return DOODLEBUG_ID;}
    virtual void move();
    virtual void breed();
    virtual bool starving() {return timeTillStarve == 3;}

private:
    int timeTillStarve;
};

int main(){
    srand(time(0));
    int doodleBugs = 5;
    int ants = 100;

    Area board(doodleBugs, ants);
    board.beginGame();
}

void Area::beginGame(){
    cout << "Press enter to move forward" << endl;
    char c;
    cin.get(c);
    if (c != '\n'){
        exit(1);
    }

    while (c == '\n') {
        timeStepCount++;
        for (int x = 0; x < LIMIT; x++) {
            for (int y = 0; y < LIMIT; y++) {
                if (garden[x][y] == nullptr) {
                    continue;
                }
                if (garden[x][y]->getType() == 1) {
                    garden[x][y]->move();
                }
            }
        }

        for (int x = 0; x < LIMIT; x++) {
            for (int y = 0; y < LIMIT; y++) {
                if (garden[x][y] == nullptr) {
                    continue;
                }
                if (garden[x][y]->getType() == 2) {
                    garden[x][y]->move();
                }
            }
        }

        for (int x = 0; x < LIMIT; x++) {
            for (int y = 0; y < LIMIT; y++) {
                if (garden[x][y] == nullptr){
                    continue;
                }
                garden[x][y]->breed();
            }
        }
        //STARVE
        for (int x = 0; x < LIMIT; x++) {
            for (int y = 0; y < LIMIT; y++) {
                if (garden[x][y] == nullptr){
                    continue;
                }
                if (garden[x][y]->starving()){
//                    delete garden[x][y];
                    garden[x][y] = nullptr;
                }
            }
        }
        printWorld();

        cin.get(c);
        if (c != '\n'){
            exit(1);
        }
    }
}

void Area::printWorld() {
    cout << endl;
    for (auto & x : garden) {
        for (auto organism : x) {
            if (organism == nullptr)
                cout << '-' << " ";
            else if (organism->getType() == DOODLEBUG_ID)
                cout << 'X' << " ";
            else
                cout << 'o' << " ";
        }
        cout << endl;
    }
}

Area::~Area(){
    for (int x = 0; x < LIMIT; x++) {
        for (int y = 0; y < LIMIT; y++) {
            if (garden[x][y] != nullptr)
                delete garden[x][y];
        }
    }
}
void Organism::move() {
    organismLifeTime++;
    breedingTime++;
    int new_x = position_x;
    int new_y = position_y;
    int direction = world->randomNumberGenerator(4, 1);
    getTheCell(direction, new_x, new_y);

    if (onTheBoard(new_x, new_y)){
        if (world->garden[new_x][new_y] != nullptr){
            return;
        }
        else{
            world->garden[new_x][new_y] = this;
            world->garden[position_x][position_y] = nullptr;
            position_x = new_x;
            position_y = new_y;
        }
    }
}

void Organism::getTheCell(int direction, int &temp_x, int &temp_y) {
    switch (direction) {
        case UP:
            temp_x--;
            break;
        case DOWN:
            temp_x++;
            break;
        case LEFT:
            temp_y--;
            break;
        case RIGHT:
            temp_y++;
            break;
        default:
            cout <<"Random number generation error -> Wrong direction\n";
            exit(1);
    }
}
bool Organism::onTheBoard(int x, int y) {
    return ((x >= 0) && (x < LIMIT) && (y >= 0) && (y < LIMIT));
}

vector<int> Organism::getEmptyCells(int x, int y) {
    vector<int> adjEmptyCells;

    for (int direction = 1; direction <= DIRECTIONS; direction++) {
        int temp_x = x;
        int temp_y = y;
        getTheCell(direction, temp_x, temp_y);

        if ((onTheBoard(temp_x, temp_y)) && (world->garden[temp_x][temp_y] == nullptr))
            adjEmptyCells.push_back(direction);
    }
    return adjEmptyCells;
}
void Ant::move() {
    if (this->organismLifeTime == world->getTimeStepCount())
        return;
    else
        Organism::move();
}

void Ant::breed() {
    if (this->breedingTime >= 8) {
        int x = position_x;
        int y = position_y;
        vector<int> adjEmptyCells = getEmptyCells(x, y);

        if (!(adjEmptyCells.empty())) {
            int randomIndex = world->randomNumberGenerator(adjEmptyCells.size());
            int direction = adjEmptyCells[randomIndex];
            getTheCell(direction, x, y);
            world->garden[x][y] = new Ant(world, x, y);
            breedingTime = 0;
        }
    }
}

void Doodlebug::move() {
    if (this->organismLifeTime == world->getTimeStepCount())
        return;

    vector<int> nearbyAnts;

    for (int direction = 1; direction <= DIRECTIONS; direction++) {
        int x = position_x;
        int y = position_y;

        getTheCell(direction, x, y);

        if ((onTheBoard(x, y)) && (world->garden[x][y] != nullptr)
            && (world->garden[x][y]->getType() == ANT_ID))
            nearbyAnts.push_back(direction);
    }

    int x = position_x;
    int y = position_y;

    //If there are ants, choose random one and eat it
    if (!(nearbyAnts.empty())){
        int randomIndex = world->randomNumberGenerator(nearbyAnts.size());
        int direction = nearbyAnts[randomIndex];
        getTheCell(direction, x, y);

        delete world->garden[x][y];
        world->garden[x][y] = this;
        world->garden[position_x][position_y] = nullptr;
        position_x = x;
        position_y = y;
        timeTillStarve = 0;
        organismLifeTime++;
        breedingTime++;
    }
    else {
        Organism::move();
        timeTillStarve++;
    }
}

void Doodlebug::breed() {
    if (breedingTime >= 8) {
        int x = position_x;
        int y = position_y;
        vector<int> adjEmptyCells = getEmptyCells(x, y);

        if (!(adjEmptyCells.empty())) {
            int randomIndex = world->randomNumberGenerator(adjEmptyCells.size());
            int direction = adjEmptyCells[randomIndex];
            getTheCell(direction, x, y);
            world->garden[x][y] = new Doodlebug(world, x, y);
            breedingTime = 0;
        }
    }
}
void Area::populate() {
    for (int x = 0; x < LIMIT; x++) {
        for (int y = 0; y < LIMIT; y++) {
            garden[x][y] = nullptr;
        }
    }
    srand(time(0));
    int x, y;
    int currentDoodlebugs = 0;
    int currentAnts = 0;

    while (currentDoodlebugs < totalDoodleBugs){
        x = randomNumberGenerator(LIMIT);
        y = randomNumberGenerator(LIMIT);
        if (garden[x][y] == nullptr){
            garden[x][y] = new Doodlebug(this, x, y);
            currentDoodlebugs++;
        }

    }

    while (currentAnts < totalAnts){
        x = randomNumberGenerator(LIMIT);
        y = randomNumberGenerator(LIMIT);
        if (garden[x][y] == nullptr){
            garden[x][y] = new Ant(this, x, y);
            currentAnts++;
        }
    }
    printWorld();
}