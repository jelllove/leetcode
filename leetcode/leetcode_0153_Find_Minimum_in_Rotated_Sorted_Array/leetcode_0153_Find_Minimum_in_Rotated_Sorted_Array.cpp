class Solution {
public:
    int findMin(vector<int>& nums) {
        //Method 1: Traverse the vector
        /*
        int ans = INT_MAX;
        
        for (auto &i : nums)
            ans = min(ans, i);
        
        return ans;
        
        */
        
        //Method 2: sort the vector, and get the first one;
        /*
        sort(nums.begin(), nums.end(), less<int>());
        return nums[0];
        */
        
        
        //Method 3: binary search
        if (nums.size() == 1)
            return nums[0];
        
        if (nums[0] < nums[nums.size() - 1])
            return nums[0];
        
        int l = 0, r = nums.size() - 1;
        
        while (l < r)
        {
            //如果已经在最小右大了，那直接返回最小的那个
            if (nums[l] < nums[r])
                return nums[l];
            
            //得到中间值
            int m = (r - l) / 2 + l;
            
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        return nums[l];
    }
};