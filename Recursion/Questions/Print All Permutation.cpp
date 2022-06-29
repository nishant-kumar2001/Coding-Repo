// problem link - https://leetcode.com/problems/permutations/

// TOC - O(n!*n)
// SC - O(1)

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void print(int ind, int n, vector<int> &nums){
        
        if(ind==n){
            ans.push_back(nums);
            return;
        }
       
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            print(ind+1,n,nums);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        print(0,nums.size(),nums);
        return ans;
    }
};
