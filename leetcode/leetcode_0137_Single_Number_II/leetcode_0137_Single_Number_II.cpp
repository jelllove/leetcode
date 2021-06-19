class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Method 1: sort and find
        /*
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (i < nums.size())
        {
            if (((i + 2) >= nums.size()) || (nums[i] != nums[i + 2]))
                return nums[i];
            else
                i += 3;
        }
        
        return 0;
        */
        
        //Method 2: using the hash
        //value + count
        unordered_map<int, int> um;
        
        for (auto &n : nums)
        {
            um[n]++;
        }
        
        for (auto &u : um)
        {
            if (u.second == 1)
                return u.first;
        }
        
        return 0;
    }
};