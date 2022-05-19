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

void doublePointers(){
    int var = 10;
    int *pointer = &var;
    *pointer = 20;

    int **pointer2 = &pointer;
    **pointer2 = 30;
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
   int *arr = new int[6];
   for (int i = 0; i < 6; i++){
       arr[i] = i;
   }

   int **pointer = &arr;

   cout << **pointer;
   cout << **pointer;

   //print
//    for (int i = 0; i < 6; i++){
//        cout << arr[i] << " ";
//    }


    return 0;

}