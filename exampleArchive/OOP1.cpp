#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    int data;
    int weight;

    Node(int newData){
        data = newData;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;
    Node* tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    Node* front(){

    }

    void add_node(int n){
        Node *temp = new Node(n);

        if(head == nullptr){
            head = temp;
        }
        else{
            //already a list
            tail->next = temp;
            tail = tail->next;
        }


    }
    void display(){

    }
    void sortbyData(){

    }

    void sortbyHeight(){

    }
};


int main(){
    LinkedList l;
    l.add_node(5);


}