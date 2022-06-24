#include <iostream>
using namespace std;

class Node{
public: 
    int data;
    Node* next;
    Node(){
        data = 0;
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
    
    ~LinkedList(){
        Node* temp = head;
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }

    void addNode(int n){ //O(1)
        //create a new node
        //link it in the right place

        Node *temp = new Node;
        temp->data = n;
        temp->next = nullptr;

        //case 1: there is no list!
        if (head == nullptr){
            head = temp;
            tail = temp; // if there's only 1 node, then it is both the head AND the tail
        }
        else{ //case 2: there is a list already
            tail->next = temp;
            tail = tail->next; //nullptr
        }
    }

    void addNode_noTail(int n){ //O(n)
        Node* temp = new Node;
        temp->data = n;
        temp->next = nullptr;

        if (head == nullptr){
            head = temp;
        }
        else{
            //we need to iterate through the linked list until we get to the end!
            Node* itr = head;
            while(itr->next != nullptr){
                itr = itr->next;
            }
            itr->next = temp;
        }
    }

    void remove(int x){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->data == x){
                //CHALLENGE! How to remove the node? Hint: use the pointers!
            }

            temp = temp->next;
        }

    }

    bool search(int x){
        Node* temp = head;
        while(temp != nullptr){
            if (temp->data == x){
                return true;
            }
            else{
                temp = temp->next;
            }
        }
        return false;
    }

    void display(){
        Node* temp = head;
        int i = 1;
        while (temp != nullptr){
            cout << i << ": "<<  temp->data << endl;
            temp = temp->next;
            i++;
        }
    }
};


int main(){
    LinkedList l;
    l.addNode(5);
    l.addNode(10);
    l.addNode(110);
    l.display();
    
    return 0;
}