#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

int height(Node* root){

    if(root == nullptr) return 0;

    int L = height(root -> left);
    int R = height(root -> right);
    return 1 + max(L, R);

    // T.C = O(N);
    // S.C = O(N);
}

int main(){
    Node* root = new Node(0);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);
    cout<<height(root);
    return 0;
}