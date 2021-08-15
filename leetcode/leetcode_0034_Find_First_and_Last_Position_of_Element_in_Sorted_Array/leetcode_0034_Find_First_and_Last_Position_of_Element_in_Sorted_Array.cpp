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
        /*
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
        */
        
        //Method 3: using the STL functionality
        auto res = find(nums.begin(), nums.end(), target);
        if (res == nums.end())
        {
            return {-1, -1};
        }
        else
        {
            int firstPos = res - nums.begin();
            int lastPos = firstPos;
            while (lastPos < nums.size() && nums[lastPos] == target)
            {
                ++lastPos;
            }
            
            return {firstPos, lastPos != firstPos ? lastPos - 1 : lastPos};
        }
            
        
    }
};


//Using the binary search
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int leftIndex = -1;
        int rightIndex = -1;
        
        int l = 0;
        int r = nums.size() - 1;
        
        //Find the left index
        while (l <= r)
        {
            int m = ((r - l) >> 1) + l;
            if (nums[m] == target)
            {
                leftIndex = m;
                r = m - 1;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        if (leftIndex == -1)
        {
            return {-1, -1};
        }

        
        //Find the right index
        r = nums.size() - 1;
        while (l <= r)
        {
            int m = ((r - l) >> 1) + l;
            if (nums[m] == target)
            {
                rightIndex = m;
                l = m + 1;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return {leftIndex, rightIndex};
        
    }
};