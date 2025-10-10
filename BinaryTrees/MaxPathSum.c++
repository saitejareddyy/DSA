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

int solve(Node* root, int &ans){

    if(root == nullptr) return 0;

    int L = solve(root -> left, ans);
    if(L < 0) L = 0;
    int R = solve(root -> right, ans);
    if(R < 0) R = 0;

    ans = max(ans, root->data + L + R);

    return max(L, R) + root -> data;
}

int main(){
    Node* root = new Node(0);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);
    int ans = INT_MIN;
    solve(root, ans);
    cout<<"max path sum:: "<<ans;
}