#include <iostream>
using namespace std;

int main(){
    bool end = true;
    int i = 1;
    while(end){
        cout << i << endl;
        i++;
        if (i == 15){
            end = false;
        }
        if (end == false){
            cout << "Hello!";
        }
    }

    return 0;
}
