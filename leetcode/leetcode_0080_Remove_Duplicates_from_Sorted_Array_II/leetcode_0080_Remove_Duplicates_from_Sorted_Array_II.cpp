class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if (nums.size() <= 2)
            return nums.size();
        
        //除了使用count，也可以使用c0, c1两个指针
        int count = 1;
        int cur = 0;
        int next = 1;
        
        while (next < nums.size())
        {
            if (nums[cur] == nums[next])
            {
                if (count == 1)
                {
                    ++cur;
                    ++count;
                    swap(nums[cur], nums[next]);
                }
            }
            else
            {
                ++cur;
                count = 1;
                swap(nums[cur], nums[next]);
            }
            ++next;
        }
        
        return cur + 1;
    }
};