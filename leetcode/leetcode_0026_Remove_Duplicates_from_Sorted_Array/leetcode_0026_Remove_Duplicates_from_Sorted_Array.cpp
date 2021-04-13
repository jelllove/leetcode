class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        
        int cur = 0;
        int next = 1;
        
        while (next < nums.size())
        {
            if (nums[cur] != nums[next])
            {
                ++cur;
                swap(nums[cur], nums[next]);
            }
            ++next;
        }
        
        return cur + 1;
    }
};