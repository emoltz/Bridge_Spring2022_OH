#include <iostream>
using namespace std;


void multiplyByFive(int &x){
    x = x * 5;
}

int multiplyByFive_withReturn(int x){
    int n = x * 5;
    return n;
}


int multiplyByFive_withReturn(int x, bool &awesomeness){
    int n = x * 5;

    if (awesomeness == false){
        awesomeness = true;
    }
    else{
        awesomeness = false;
    }

    return n;
}


int main(){
    
    int i = 10;
    bool Ethan = true;

    int result = multiplyByFive_withReturn(i, Ethan);
    cout << result << endl;
    cout << "in this example, i is still " << i << endl;

    cout << "Ethan is awesome? ";
    if (Ethan == true){
        cout << "Yes!";
    }
    else{
        cout << "No :(";
    }


    return 0;
}