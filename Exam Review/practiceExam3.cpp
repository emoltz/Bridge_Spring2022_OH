#include <iostream>
#include <vector>
using namespace std;

//Q5
class Base{
public:
    Base(){}
    virtual void f(){
        cout << "BASE ";
    }
};

class Derived: public Base{
public:
    Derived(): Base(){}

    virtual void f(){
        cout << "Derived ";
    }
};
void q5(){
    vector<Base> base_objs;
    Base obj1 = Derived();
    Derived obj2 = Derived();
    Base obj3 = Base();

    base_objs.push_back(obj1);
    base_objs.push_back(obj2);
    base_objs.push_back(obj3);

    for (Base base_obj : base_objs){
        base_obj.f();
    }
    obj1.f();
    obj2.f();
    obj3.f();
    //BASE BASE BASE BASE Derived BASE
}

//q6
class Person{
public:
    virtual void move() = 0;
};

//Q8
class A{
private:
    int x;
    int y;
public:
    A(): x(0), y(0){
        cout << "Default constructor" << endl;
    }

    A(int x, int y): x(x), y(y){
        cout << "Constructor with two values" << endl;
    }

    //deep copy
    A(const A& other){
        cout << "Copy constructor" << endl;
        x = other.x;
        y = other.y;
    }

};

void q8(){
    A a(1, 2);
    A b = a;
    //CHALLENGE: try changing values for a and b and then print the result. Then do the same without the copy constructor.
}


//Q9
class Sorting{
    virtual vector<int> sort(vector<int>& v) = 0;
    virtual string worst_case_runtime() = 0;
};

//Q10
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
};

ListNode* reverse_linked_list(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next;

    while(curr->next != nullptr){
        //Draw a picture!
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool is_target_in_list(ListNode* head, int target){
    ListNode* itr = head;
    while(itr != nullptr){
        if(itr->val == target){
            return true;
        }
        //ERROR IN SOLUTIONS FILE!!
        itr = itr->next;
    }
    return false;
}

int find_max(ListNode* head){
    int max = head->val;
    ListNode* itr = head;


    while(itr != nullptr){
        if (itr->val > max){
            max = itr->val;
        }
        itr = itr->next;
    }
//    Same as above ^^
//    for(auto itr2 = head; itr != nullptr; itr= itr->next){
//        //Same thing
//    }
    return max;
}

//Q13
//MinStack -> retrieve min element in constant time??
//One solution -- two stacks!
//Another solution: keep track of the minimum and keep it on top
// Space VS time!! Need more time? Add space. Need more space? Add time.


//Q14
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){};
};

bool isSameTree(TreeNode* p, TreeNode* q){
    if( p == nullptr || q == nullptr){
        return (p == q);
    }
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    if(left == nullptr || right == nullptr){
        return left == right;
    }
    if (left->val != right->val){
        return false;
    }
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode* root){
    return root == nullptr || isSymmetricHelp(root->left, root->right);
}

/*
 * iterative dfs solution:
PYTHON CODE BELOW _____
class Solution:
    def isSymmetric(self, root)
        stk1, stk2 = [root], [root]

        while stk1 and stk2:
            node1, node2 = stk1.pop(), stk2.pop()

            if not node1 and not node2:
                continue

            if (node1 and not node2) or (not node1 and node2) or (node1.val != node2.val):
                return False

            stk1.append(node1.right)
            stk1.append(node1.left)
            stk2.append(node2.left)
            stk2.append(node2.right)

        return True
 */


int main(){
    q8();
    return 0;
}