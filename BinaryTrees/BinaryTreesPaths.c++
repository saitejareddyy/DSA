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

void solve(Node* root, vector<vector<int>> &ans, vector<int> &temp){

    if(root == nullptr) return;

    temp.push_back(root -> data);

    if(!root -> left && !root -> right){
        ans.push_back(temp);
    }

    solve(root -> left, ans, temp);
    solve(root -> right, ans, temp);

    temp.pop_back();
}

int main(){
    Node* root = new Node(0);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, ans, temp);
    for(vector<int> &nums: ans){
        for(int num: nums){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}