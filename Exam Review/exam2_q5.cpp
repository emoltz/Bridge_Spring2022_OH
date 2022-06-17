#include <iostream>
using namespace std;

bool isSorted(int s[], int length){
    //base case
    if (length == 0 || length == 1){
        return true;
    }
    else{
        if (s[0] >= s[1]){
            bool temp = isSorted(s + 1, length -1);
            if (temp){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}

int main(){
    int arr[5] = {60, 50, 30, 20, 10};
    if (isSorted(arr, 5)){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}