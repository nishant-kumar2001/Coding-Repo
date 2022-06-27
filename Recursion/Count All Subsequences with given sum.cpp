/*
FORMAT

int f(){
    
    base case{
        check sum if satisfied  then return 1
        else return 0
    }
    
    
    add no. in my sum
    1) call on left 
    
    
    subtract no. in my sum
    
    2) call on right
    
    
    return 1 + 2

}
*/

// Time Complexity - O(2^n)

#include <bits/stdc++.h>
using namespace std;


int print(int ind,int n,int arr[],int sum,int s){
    
    //base case
    if(ind==n){
        if(sum == s)    return 1;
        else    return 0;
    }
    
    // condition of taking the element
    sum+=arr[ind];
    int left = print(ind+1,n,arr,sum,s);
    
    sum-=arr[ind];
    // condition of not taking
    int right = print(ind+1,n,arr,sum,s);
        
    return left+right;
}


int main() {
	// your code goes here
	int n;  cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	    
	int s;  cin>>s;
	cout<<print(0,n,arr,0,s);
	return 0;
}
