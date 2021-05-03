class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
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
    }
};