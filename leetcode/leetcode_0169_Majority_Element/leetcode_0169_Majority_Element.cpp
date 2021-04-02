class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Method 1: using the hash table
        /*
        int maxCount = 0;
        int maxValue = INT_MIN;
        //Value + Count
        unordered_map<int, int> um;
        for (auto &n : nums)
        {
            um[n]++;
            if (um[n] >= maxCount)
            {
                maxValue = n;
                maxCount = um[n];
            }
        }
        
        return maxValue;
        */
        
        
        //Method 2: sort and lock the middle position
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
        
        
        //Method 3: using result and count
        int ret = nums[0];
        int count = 1;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (ret == nums[i])
            {
                ++count;
            }
            else
            {
                --count;
                if (count <= 0)
                {
                    ret = nums[i];
                    count = 1;
                }
            }
        }
        
        return ret;
        
        
    }
};