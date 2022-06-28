// Problem Link - https://leetcode.com/problems/combination-sum-ii/submissions/

class Solution {
public:
    vector<vector<int>> ans;
    
    void print(int ind,int n,vector<int> v,vector<int> &arr,int target){
        
        if(ind==n){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        
        if(arr[ind]<=target){
            v.push_back(arr[ind]);
            target-= arr[ind];
            print(ind+1,n,v,arr,target);
            v.pop_back();
            target+=arr[ind];
        }
        
        while(ind<n-1&&arr[ind]==arr[ind+1])    // Tricky part to reduce TOC
            ind++;
        
        print(ind+1,n,v,arr,target);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        print(0,n,v,candidates,target);

        
        return ans;
    }
};
