class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //Method 1: sort and find, but low efficiency.
        
        sort(nums.begin(), nums.end());
        
        int minValue = 0;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0 && minValue != nums[i])
            {
                if ((nums[i] - minValue) == 1)
                {
                    minValue = nums[i];
                }
                else
                {
                    return minValue + 1;
                }
            }
        }
        
        return minValue == 0 ? 1 : minValue + 1;
        
    }
};