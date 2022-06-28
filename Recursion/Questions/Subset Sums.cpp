// Problem Link - https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution{

vector<int> ans;
    
    void print(int ind,int sum, int n, vector<int> &arr){
        
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        
        sum+= arr[ind];
        print(ind+1,sum,n,arr);
        
        sum-= arr[ind];
        
        print(ind+1,sum,n,arr);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        print(0,0,N,arr);
        return ans;
        
    }
};
