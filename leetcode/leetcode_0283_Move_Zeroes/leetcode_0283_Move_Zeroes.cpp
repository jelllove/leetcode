class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Method 1: bulle sort
        /*
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] == 0)
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }*/
        //Method 2: just using one time
        
        int n = 0; //当前非0的个数
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                swap(nums[n], nums[i]);
                ++n;
            }
        }
    }
};