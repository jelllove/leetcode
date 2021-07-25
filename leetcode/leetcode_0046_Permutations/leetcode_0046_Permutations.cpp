class Solution {
public:
    
    void helper(vector<vector<int>> &ans, vector<int>& nums, int idx)
    {
        
        if (idx == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        
        for (int i = idx; i <= (nums.size() - 1); ++i)
        {
            swap(nums[i], nums[idx]);
            helper(ans, nums, idx + 1);
            swap(nums[i], nums[idx]); 
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        //Method 1: using the backtrack method
        
        vector<vector<int>> ans;
        helper(ans, nums, 0);
        
        return ans;
        
        
    }
};