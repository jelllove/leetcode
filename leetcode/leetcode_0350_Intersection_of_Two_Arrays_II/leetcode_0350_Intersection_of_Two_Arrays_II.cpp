class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //Method 1: using the hash table
        /*
        unordered_map<int, int> um;
        
        vector<int> res;
        
        //先把nums1中的所有数据都统计一遍
        for (auto &n1 : nums1)
        {
            um[n1]++;
        }
        
        //然后在遍历nums2的时候，如果遇上了一样的，那就让原来的统计减1
        for (auto &n2: nums2)
        {
            if (um.count(n2) > 0 && um[n2] >= 1)
            {
                um[n2]--;
                res.push_back(n2);
            }
        }
        
        return res;
        */
        
        
        //Method 2: using sort + two pointer
        //先排序
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        //利用两个指针
        int p1 = 0;
        int p2 = 0;
        vector<int> res;
        
        while (p1 < nums1.size() && p2 < nums2.size())
        {
            //当两个数字一样的时候，就记录一下，否则的话，移动其中那个数字小的指针
            if (nums1[p1] == nums2[p2])
            {
                res.push_back(nums1[p1]);
                ++p1;
                ++p2;
            }
            else if (nums1[p1] > nums2[p2])
            {
                ++p2;
            }
            else
            {
                ++p1;
            }
        }
        
        return res;
    }
};