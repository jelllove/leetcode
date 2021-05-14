class Solution {
public:
    
    int sum(int &x, int &y)
    {
        int z = x ^ y;
        int ans = 0;
        
        while (z != 0)
        {
            ++ans;
            z &= (z-1);
        }
        return ans;
    }
    
    int totalHammingDistance(vector<int>& nums) {
        
        
        //Method 1: brute force, failure, because the time limited exceeded;
        /*
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                ans += sum(nums[i], nums[j]);
            }
        }
        return ans;
        */
        
        //Method 2: check every bits of each number.
        if (nums.size() == 0)
            return 0;
        
        int ans = 0;
        const int BIT_COUNT = sizeof(nums[0]) * 8;
        unsigned int p = 0x1;
        for (int i = 0; i < BIT_COUNT; ++i)
        {
            int count = 0;
            for (auto &n : nums)
            {
                if (n & p)
                    ++count;
            }
            
            ans += (count * (nums.size() - count));
            p <<= 1;
        }
        
        return ans;
        
    }
};