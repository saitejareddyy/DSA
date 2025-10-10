#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;           
    Node* right;

    Node(int data){
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};

bool Indentical(Node* root1, Node* root2){
    if(root1 == nullptr && root2 == nullptr)return true;
    if(root1 == nullptr || root2 == nullptr) return false;

    if(root1->data == root2->data && Indentical(root1 -> left, root2 -> left) && Indentical(root1 -> right, root2->right)){
        return true;
    }

    return false;
}

//

int main(){
    Node* root = new Node(0);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);

    Node* root1 = new Node(0);
    root1 -> left = new Node(1);
    root1 -> right = new Node(2);
    root1 -> left -> left = new Node(3);
    root1 -> left -> right = new Node(4);
    root1 -> right -> left = new Node(5);
    root1 -> right -> right = new Node(6);
    cout<<Indentical(root, root1);
    return 0;
}

