#include <iostream>
using namespace std;


void doubleTriangle(int n){
    char asterisk = '*';
    char space = ' ';
    int spaceLimt = 2 * n - 2;
    int numOfLines = n * 2 - 1;
    int asteriskLimit = 1;


    for(int lineNumber = 1; lineNumber <= numOfLines; lineNumber++){ //responsible for each ROW!
        for (int j = 1; j <= asteriskLimit; j++){ //left stars
            cout << asterisk;
        }

        //spaces
        for (int j = 1; j <= spaceLimt; j++){
            cout << space;
        }

        //right stars
        for (int j = 1; j <= asteriskLimit; j++){
            cout << asterisk;
        }
        
        cout << endl;

        if(lineNumber < n){
            asteriskLimit++;
            spaceLimt -= 2;
        }
        else{
            asteriskLimit--;
            spaceLimt += 2;
        }
        
    }

}

int main(){

    doubleTriangle(5);

    return 0;
}
