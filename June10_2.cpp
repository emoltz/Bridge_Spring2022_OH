#include <iostream>
#include <string>
using namespace std;

class Line{
private:
    double length;
    int* arr;
public:
    
    Line(){
        cout << "Object created!" << endl;
        arr = new int[5];

    }
    ~Line(){
        cout << "Object deleted!" << endl;
        //put whatever you'd like to delete in here.
    }
    void setLength( double len){
        length = len;
    }
    double getLength(){
        return length;
    }
};

int main(){
    
    Line l;
    l.setLength(6);
    cout << "Length: " << l.getLength() << endl;
    
    return 0;
}