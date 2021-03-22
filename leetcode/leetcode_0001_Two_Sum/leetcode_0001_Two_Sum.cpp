class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //a hash table map the value and index;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            //Find out the difference
            int dif = target - nums[i];
            if (mp.count(dif) >= 1)
                return vector<int>{mp[dif], i};
            else
                mp[nums[i]] = i;
        }
        
        return vector<int>{};
        
    }
};