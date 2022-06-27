/*
FORMAT

f(){
    
    base case{
        check sum if satisfied then print ds
    }
    
    add the element in ds
    add no. in my sum
    call recursion on added ds
    
    remove the element in ds
    subtract no. in my sum
    
    call recursion on ds

}
*/

// Time Complexity - O(2^n)
// Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;


void print(int ind,int n,vector<int> &ds,int arr[],int sum,int s){
    
    //base case
    if(ind==n){
        if(sum == s){
            for(auto it:ds)
                cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    
    // condition of taking the element
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    print(ind+1,n,ds,arr,sum,s);
    
    ds.pop_back();
    sum-=arr[ind];
    // condition of not taking
    print(ind+1,n,ds,arr,sum,s);
}


int main() {
	// your code goes here
	int n;  cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	vector<int> ds;
	int s;  cin>>s;
	print(0,n,ds,arr,0,s);
	return 0;
}
