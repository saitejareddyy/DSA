// Problem Statement:

// Given an array consisting only of 0s and 1s, segregate all 0s to the left side and all 1s to the right side of the array.
// You must do this in-place (without using extra space) and in O(n) time.

// Example:

// Input:
// arr = [0, 1, 1, 0, 1, 0, 0, 1]

// Output:
// arr = [0, 0, 0, 0, 1, 1, 1, 1]

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr){
    int n = arr.size();
    int l = 0;
    for(int r=0; r<n; r++){
        if(arr[r] == 0){
            swap(arr[l], arr[r]);
            l++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter arr size n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the array sequence";
    for(int i=0; i<n; i++) cin>>arr[i];
    solve(arr);
    for(int i=0; i<n; i++) cout<<arr[i];
}
