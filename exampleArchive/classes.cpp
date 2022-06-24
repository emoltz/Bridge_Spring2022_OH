#include <iostream>
using namespace std;

class A;
class B;

class A{
private:
    int data;

public:
    A(int newData){
        data = newData;
    }
    int getData(){
        return data;
    }
    void joinData(int newData){
        data = data + newData;
    }
};

class B{
private:
    int data;
    A* a;
public:
    B(int newData){
        data = newData;
    }

    B(int newData, A* newA){
        a = newA;
        data = newData;
    }

    int getData(){
        return data;
    }

    int getAData(){
       return a->getData();
    }
};

int main(){
    A objectA(5);
    B objectB(10, &objectA);

    return 0;

}