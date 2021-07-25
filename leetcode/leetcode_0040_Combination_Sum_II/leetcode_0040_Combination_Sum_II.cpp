//Method 1: using the recursion
class Solution {

    
public:
    
    void helper(vector<int>& nums, int idx, vector<int> &subSet, int target, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(subSet);
            return;
        }
        
        if (idx >= nums.size() || target < 0)
            return;
        
        
        for (int i = idx; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            
            subSet.push_back(nums[i]);
            helper(nums, i + 1, subSet, target - nums[i], ans);
            subSet.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        if (candidates.size() == 0 || (candidates.size() == 1 && candidates[0] > target))
        {
            return vector<vector<int>>{};
        }
        
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> ans;
        vector<int> subSet;
        
        helper(candidates, 0, subSet, target, ans);
        
        return ans;
        
    }
};
