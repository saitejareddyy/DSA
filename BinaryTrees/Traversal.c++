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

void InOrder(Node* root){
    if(root == nullptr) return;

    InOrder(root -> left);
    cout<<root -> data<< " ";
    InOrder(root -> right);

    // T.C = O(N);
    // S.C = O(N);
}

void preOrder(Node* root){
    if(root == nullptr) return ;

    cout<<root -> data<<" ";
    preOrder(root -> left);
    preOrder(root -> right);

    // T.C = O(N);
    // S.C = O(N);
}

void postOrder(Node* root){
    if(root == nullptr) return ;

    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> data <<" ";


    // T.C = O(N);
    // S.C = O(N);
}

void LevelOrder(Node* root){
    queue<Node*> q;
    vector<int> ans;
    q.push(root);

    while (!q.empty()){
        int size = q.size();
        while(size--){
            Node* node = q.front();
            q.pop();
            ans.push_back(node->data);
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
    }

    for(int x: ans) cout<<x<<" ";
    
}



int main(){
    Node* root = new Node(0);
    root -> left = new Node(1);
    root -> right = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);
    root -> right -> left = new Node(5);
    root -> right -> right = new Node(6);
    // preOrder(root);
    // InOrder(root);
    // postOrder(root);
    LevelOrder(root);
    return 0;
}