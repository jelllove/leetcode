class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int next = 0;
        
        while (next < nums.size())
        {
            if (nums[next] != val)
            {
                nums[cur] = nums[next];
                ++cur;
            }
            
            ++next;
        }
        return cur;
    }
};