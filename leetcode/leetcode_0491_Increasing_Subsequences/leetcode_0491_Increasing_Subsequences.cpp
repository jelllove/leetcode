class Solution {
    
private:
    vector<vector<int>> ans;
public:
    
    void helper(int idx, vector<int>& nums, vector<int> &sub_set)
    {
        if (idx >= nums.size())
            return;
        
        unordered_set<int> us;//Record the duplicated num
        
        for (int i = idx; i < nums.size(); ++i)
        {
            if ((sub_set.size() == 0 || nums[i] >= sub_set.back()) && us.count(nums[i]) == 0)
            {
                sub_set.push_back(nums[i]);
                us.insert(nums[i]);
                
                if (sub_set.size() > 1)
                    ans.push_back(sub_set);
                
                helper(i + 1, nums, sub_set);
                
                sub_set.pop_back();
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.size() < 2)
            return {};
        
        //Method 1: using the bit for traverse all possible combination.
        /*
        vector<int> tmp;
        set< vector<int> > dup;
        
        int possible = pow(2, nums.size()) - 1;
        
        for (int i = 3; i <= possible; ++i)
        {
            bitset<15> bt(i);
            
            vector<int> tmp;
            int n = nums.size();
            
            for (int k = 0; k < nums.size(); ++k)
            {
                if (bt.test(k))
                {
                    if (tmp.size() == 0 || nums[k] >= tmp.back())
                        tmp.push_back(nums[k]);
                    
                    if (tmp.size() >= 2 && dup.count(tmp) == 0)
                    {
                        dup.insert(tmp);
                        ans.push_back(tmp);
                    }
                }
            }
        }
        
        return ans;
        */
        
        //Method 2: using the dfs recursion
        vector<int> sub_set;
        helper(0, nums, sub_set);
        return ans;
    }
};