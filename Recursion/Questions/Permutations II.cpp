// Problem Link -: https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,int> mp;
    
    void helper(int f,int l,vector<int> &nums){
        
        if(f==l){
            if(!mp.count(nums))
                ans.push_back(nums);
            mp[nums]++;
            return;
        }
       
       
        for(int i=f;i<l;i++){
            swap(nums[i],nums[f]);
            helper(f+1,l,nums);
            swap(nums[i],nums[f]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        helper(0,nums.size(),nums);
        
        return ans;
        
    }
};
