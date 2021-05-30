class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        
        //Method 1: brute force 
        int s = -1;
        int e = -1;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
            {
                if (s == -1)
                {
                    s = i;
                    e = i;
                }
                else
                    e = i;
            }
            else
            {
                if (s != -1)
                    break;
            }
        }
        
        return vector<int>{s, e};
    }
};