class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
            return vector<int>{-1, -1};
        
        //Method 1: brute force 
        /*
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
        */
        
        //Method 2: binary search
        int l = 0;
        int r = nums.size() - 1;
        
        int s = -1;
        int e = -1;
        
        while (l < r)
        {
            int m = ((r - l)/2) + l;
            if (nums[m] == target)
            {
                s = m;
                e = m;
                
                while ((s - 1) >= 0 && nums[s - 1] == target)
                    --s;
                
                while ((e + 1) < nums.size() && nums[e + 1] == target)
                    ++e;
                
                break;
            }
            else if (nums[m] > target)
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        
        if (s == -1 && nums[l] == target)
        {
            s = l;
            e = l;
        }
        
        return vector<int>{s, e};
    }
};