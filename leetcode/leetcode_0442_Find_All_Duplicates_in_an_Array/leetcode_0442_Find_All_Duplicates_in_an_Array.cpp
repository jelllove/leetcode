class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= n)
            {
                if (nums[nums[i] - 1] > n)
                    ans.push_back(nums[i]);
                else
                    nums[nums[i] - 1] += n;
            }
            else
            {
                int val = nums[i] - n;
                if (nums[val - 1] > n)
                    ans.push_back(val);
                else
                    nums[val - 1] += n;
            }
        }
        
        return ans;
    }
};