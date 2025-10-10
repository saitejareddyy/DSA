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


vector<vector<int>> solve(Node* root){

    queue<Node*> q;
    q.push(root);

    bool order = true;
    vector<vector<int>> ans;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);
        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(order){
                temp[i] = node -> data;
            } else{
                temp[size - i - 1] = node -> data;
            }

            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        order = !order;
        ans.push_back(temp);
    }

    return ans;
}

int main(){
    Node* root = new Node(0);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);
    vector<vector<int>> ans = solve(root);
    for(vector<int> &nums: ans){
        for(int num: nums){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
