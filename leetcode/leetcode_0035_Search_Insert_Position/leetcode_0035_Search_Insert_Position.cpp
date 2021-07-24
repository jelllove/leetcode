class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        //Method 1: using the binary search
        /*
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return l;
        */
        
        //Method 2: using the STL search
        
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};