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

int diameter(Node* root, int &maxi){

    if(root == nullptr){
        return 0;
    }

    int L = diameter(root -> left, maxi);
    int R = diameter(root -> right, maxi);

    maxi = max(maxi, L + R);
    return 1 + max(L , R);

    // T.C = O(N);
    // S.C = O(N);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);
    root->left->left->left = new Node(1);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(9);
    root->right->right->right = new Node(25);
    root->right->right->right->right = new Node(30);

    int maxi = 0;
    diameter(root, maxi);
    cout<<"Diameter of a binary tree: "<<maxi;
    return 0;
}

//