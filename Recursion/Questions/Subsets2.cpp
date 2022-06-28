// Problem Link - https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void print(int ind,int n, vector<int> v, vector<int> &nums){
        
        if(ind==n){
            ans.push_back(v);
            return;
        }
        
        
        
        v.push_back(nums[ind]);
        print(ind+1,n,v,nums);
        
        v.pop_back();
        
        while(ind<n-1 && nums[ind]==nums[ind+1])
            ind++;
        
        print(ind+1,n,v,nums);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int> v;
        print(0,n,v,nums);
        return ans;
    }
};
