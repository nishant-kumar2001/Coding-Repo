/*
FORMAT

bool f(){
    
    base case{
        check sum if satisfied print ds then return true
        else return false
    }
    
    add the element in ds
    add no. in my sum
  1  check recursion call on added ds if it's true then return 
    
    
    remove the element in ds
    subtract no. in my sum
    
  2  check this call recursion on ds if true then return 
    
    
    if 1&2 not statisfied return false

}
*/

// Time Complexity - O(2^n)
// Space Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;


bool print(int ind,int n,vector<int> &ds,int arr[],int sum,int s){
    
    //base case
    if(ind==n){
        if(sum == s){
            for(auto it:ds)
                cout<<it<<" ";
            return true;
        }
        return false;
    }
    
    // condition of taking the element
    ds.push_back(arr[ind]);
    sum+=arr[ind];
    if(print(ind+1,n,ds,arr,sum,s)==true)
        return true;
    
    ds.pop_back();
    sum-=arr[ind];
    // condition of not taking
    if(print(ind+1,n,ds,arr,sum,s)==true)
        return true;
        
    return false;
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
