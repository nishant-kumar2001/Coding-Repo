/*
FORMAT

f(){
    
    base case
    
    add the element in ds
    call recursion on added ds
    
    remove the element in ds
    
    call recursion on ds

}
*/
// Time Complexity - O(2^n)
// Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;


void print(int ind,int n,vector<int> &ds,int arr[]){
    
    //base case
    if(ind==n){
        for(auto it:ds)
            cout<<it<<" ";
        cout<<endl;
        return;
    }
    
    // condition of taking the element
    ds.push_back(arr[ind]);
    print(ind+1,n,ds,arr);
    
    ds.pop_back();
    
    // condition of not taking
    print(ind+1,n,ds,arr);
}


int main() {
	// your code goes here
	int n;  cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	vector<int> ds;
	print(0,n,ds,arr);
	return 0;
}
