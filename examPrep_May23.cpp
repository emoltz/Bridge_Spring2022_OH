#include <iostream>
#include <vector>
using namespace std;

//find occurences of a number in an array
// it has to be recursive!

const int size = 5;

int findOccurences(int *array, int size, int x){
    //base case -> if the array is nothing, then return 0
    if (size == 0){
        return 0;
    }
    else{
        // pass array minus 1 element into the function name as a recursive call
        if(array[0] == x){
            return 1 + findOccurences(array + 1, size - 1, x);
        }
        else{
            return findOccurences(array + 1, size - 1, x);
        }
    }
}

//another way to do it
int findOccurences(int *array, int size, int start, int end, int x);

int main(){
    int array[size] = {1, 2, 2, 3, 5};
    int *iterator = array;

    cout << findOccurences(iterator, size, 2);

    cout << "Addresses: " << endl;
    cout << array;
    cout << endl;
    cout << &array[0];

    return 0;
}