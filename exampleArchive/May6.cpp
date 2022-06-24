#include <iostream>
#include <vector>
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

void doublePointer(){
    int var = 10;
    int *pointer = &var;
    *pointer = 20;

    int **pointer2 = &pointer;
    **pointer2 = 30;

    cout << var;
}

void vectors(){
    //remember what it is doing on the backend! this is not a magic datatype
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(10);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

int main(){

    vectors();


    return 0;
}