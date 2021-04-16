class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //Method 1: 使用hash(map)
        // value + count
        /*
        unordered_map<int, int> um;
        
        for (auto &n : nums)
        {
            um[n]++;
        }
        
        for (auto &e : um)
        {
            if (e.second == 1)
                return e.first;
        }
        
        return 0;
        */
        
        //Method 2: 对数组排序，然后找出不是成对出现的就行了
        /*
        std::sort(nums.begin(), nums.end());
        
        //这里的i一定是2个2个的加上去的
        for (int i = 0; i < nums.size() - 1; i += 2)
        {
            if (nums[i] != nums[i + 1])
                return nums[i];
        }
        
        return nums.back();
        */
        
        
    
        //Method 3: using the bit calucation
        //因为有以下几个位操作的原理
        // X ^ 0 = X
        // X ^ X = 0
        // 所以把所有的数加起来的话，最后因为两两抵消，只剩下那个唯一的
        int ans = 0;
        
        for (auto &n : nums)
        {
            ans ^= n;
        }
        
        return ans;
    }
};