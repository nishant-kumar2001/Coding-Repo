// Problem Link - https://leetcode.com/problems/combination-sum/

// Method 1

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> &candidates,int total,int i,int target,vector<int> &v){
        
        if(total==target){
            ans.push_back(v);
            return;
        }
        
        if(i>=candidates.size() || total>target)
            return;
        
        v.push_back(candidates[i]);
        helper(candidates,total+candidates[i],i,target,v);
        v.pop_back();
        helper(candidates,total,i+1,target,v);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        helper(candidates,0,0,target,v);
        return ans;
    }
};

// Method 2

class Solution {
public:
    vector<vector<int>> ans;
    bool check(int ind,int n,vector<int> v,vector<int> &arr,int total){
        
        
        if(total<=0)
            return total==0?1:0;
        
        if(ind==n)  return 0;
        
        v.push_back(arr[ind]);
        total-= arr[ind];
        if(check(ind,n,v,arr,total))
             ans.push_back(v);
        
        v.pop_back();
        total+= arr[ind];
        
        if(check(ind+1,n,v,arr,total))
             ans.push_back(v);
        
        return 0;
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        
        
        vector<int> v;
        check(0,n,v,candidates,target);
        
        return ans;
    }
};
