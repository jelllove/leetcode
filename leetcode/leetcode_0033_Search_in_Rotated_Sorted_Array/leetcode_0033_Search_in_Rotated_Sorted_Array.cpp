#include "public.h"


class Solution {
public:

    int binaryFind(vector<int>& nums, int l, int r, int target)
    {
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (nums[l] == target)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }


    int search(vector<int>& nums, int target)
    {
        int startIndex = -1;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                startIndex = i + 1;
            }
        }

        if (startIndex == -1)
        {
            return binaryFind(nums, 0, nums.size() - 1, target);
        }
        else
        {
            int ret = binaryFind(nums, 0, startIndex - 1, target);
            if (ret != -1)
            {
                return ret;
            }

            return binaryFind(nums, startIndex, nums.size() - 1, target);
        }
    }
};

//Solution 2, the best, binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
            return -1;
        
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r)
        {
            int m = ((r - l) >> 1) + l;
            
            if (nums[m] == target)
                return m;
            else if (nums[m] > nums[l])
            {
                if (nums[l] <= target and target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if (nums[m] < nums[r])
            {
                if (nums[m] < target and target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            else
            {
                if (nums[l] == nums[m])
                    ++l;
                if (nums[r] == nums[m])
                    --r;
            }
        }
        
        return -1;
    }
};