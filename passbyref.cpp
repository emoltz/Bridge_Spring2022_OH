#include <iostream>
using namespace std;

void transformInto10(int x){
    // made a copy of x
    x = 10;
    //changed x to 10
    //deleted x
}

void transformInto10_PBR(int &x){
    x = 10;
}

void passByReferenceDriver(){
    int y = 1;
    transformInto10_PBR(y);
    cout << y;
}

void pointers(){
    int var = 8;
    int *pointer = &var; //putting the ADDRESS of var into this pointer

    cout << *pointer;
}

void dynamicArrays(){

    int *array = nullptr;
    cout << "Enter a size:";
    int size;
    cin >> size;

    array = new int[size];

    for(int i = 0; i < size; i++){
        array[i] = i + 1;
    }

    for (int i = 0; i < size; i++){
        cout << array[i] << endl;
    }

    delete[] array;

}

int main(){
    // dynamicArrays();

    int array[5] = {1, 2, 3, 4, 5};
    cout << array;

    return 0;

}