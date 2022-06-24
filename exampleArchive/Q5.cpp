#include <iostream>
#include <vector>
#include <string>
using namespace std;
//functions:
int* getPosNums(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int *outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

//constants:
//const int ARRAY_SIZE = 6;
const int ARRAY_SIZE = 10;

int main() {
//    int arr[ARRAY_SIZE] = {3, -1, -3, 0, 6, 4};
    int arr[ARRAY_SIZE] = {5, -2, -1, 0, 1, 2, 3, -4, 5, 6};
    int newArraySize;
    int *posArrAddress = nullptr;

    //first function
    cout << endl << "First Function:" << endl;
    cout << getPosNums(arr, ARRAY_SIZE, newArraySize);
    cout << " size: " << newArraySize << endl;

    //second function
    cout << endl << "Second Function:" << endl;
    cout << getPosNums2(arr, ARRAY_SIZE, &newArraySize);
    cout << " size " << newArraySize << endl;

    //third function
    cout << endl << "Third Function:" << endl;
    getPosNums3(arr, ARRAY_SIZE, posArrAddress, newArraySize);
    cout << "Address: " << posArrAddress << " size: " << newArraySize << endl;

    //fourth function
    cout << endl << "Fourth Function:" << endl;
    getPosNums4(arr, ARRAY_SIZE, &posArrAddress, &newArraySize);
    cout << "Address: " << posArrAddress << " size: " << newArraySize << endl;

    return 0;
}

int* getPosNums(int* arr, int arrSize, int& outPosArrSize){
    int* newArray = new int [arrSize];
    int newArrayIndex = 0;
    //create new array
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0){
            newArray[newArrayIndex] = arr[i];
            newArrayIndex++;
        }

    }
    //update the outPosArrSize parameter
    outPosArrSize = newArrayIndex;

    //returns base address of array
    return arr;
}
int* getPosNums2(int* arr, int arrSize, int *outPosArrSizePtr){
    int* newArray = new int [arrSize];
    int newArrayIndex = 0;

    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0){
            newArray[newArrayIndex] = arr[i];
            newArrayIndex++;
        }
    }
    *outPosArrSizePtr = newArrayIndex;
    return arr;
}
void getPosNums3 (int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    int* newArray = new int[arrSize];
    int newArrayIndex = 0;

    //create new array
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0){
            newArray[newArrayIndex] = arr[i];
            newArrayIndex++;
        }
    }
    //update outPosArr with base address of new array
    outPosArr = newArray;
    outPosArrSize = newArrayIndex;
}
void getPosNums4 (int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    int* newArray = new int[arrSize];
    int newArrayIndex = 0;

    //create new array
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0){
            newArray[newArrayIndex] = arr[i];
            newArrayIndex++;
        }
    }
    //use outPosArrPtr to update base address of the array (containing the positive numbers)
    outPosArrPtr = &newArray;
    //user outPosArrSizePtr to update array's logical size
    *outPosArrSizePtr = newArrayIndex;
}