#include <iostream>
using namespace std;
//Question 1:
/*
 * Given a file with the GPA (double) of all students and their names, determine the name of the student with the median GPA. The filename will be given to you by the user (be sure to check for validity), and is in two columns, where the first column holds the student’s GPA, and the second holds their name, a tab character is used to separate the two columns. Name can be any number of individual words separated by spaces. Please note, the data in the file is sorted by GPA.
A sample of the file is below:
2.5 John Jones 3.773 Ulysses S. Grant 4.0 Madonna

 This should print:
 `Ulysses S. Grant`
 */


//Question 2:

class Result{
public:
    int left;
    int right;
    Result(int newLeft = 0, int newRight = 0) : left(newLeft), right(newRight){}
};

template <class T>
class BSTNode{
private:
    T data;
    BSTNode* parent;
    BSTNode* left;
    BSTNode* right;
public:
    // more code here
    friend // your function here
};

/*
 * Your task is to design a function (recursive or iterative) which will determine the total quantity of left and right children in the binary search tree. Your function should return a Result object where left is the number of left pointers which are not pointing to nullptr and right is the number of right pointers which are not pointing to nullptr. Your function will take a pointer to the root node of the tree and, as indicated, is a friend of the BSTNode class.
 *
 *        50
 *          ->
 *          70
 *      65 <- -> 90
 *
 *      Has 1 left pointer (the link from 70 to 65) and 2 right pointers (50 to 70 and 70 to 90).
 */



int main(){


}