#include <iostream>
using namespace std;

void example1(){
    int var = 8;
    int *pointer = &var;

    cout << *pointer << endl;
    cout << var;

    cout << "_______" <<endl;

    *pointer = 10;
    cout << var;
}

void example2(){
    int *array = nullptr;
    //ask the user how much space they need for their array
    int size = 15;
    array = new int[size];

    for (int i = 0; i < size; i++){
        array[i] = i + 1;
    }

    for (int i = 0; i < size; i++){
        cout << array[i] << " ";
    }

    delete[] array;
}

void whatWillItPrint(){
    //what will print?
    int var = 10;
    int *pointer = &var;
    *pointer = 20;
    var = 15;

    cout << *pointer;
}

int main(){

    int var = 10;
    int *pointer = &var;
    *pointer = 20;

    int **pointer2 = &pointer;
    **pointer2 = 30;

    cout << var;


    return 0;
}