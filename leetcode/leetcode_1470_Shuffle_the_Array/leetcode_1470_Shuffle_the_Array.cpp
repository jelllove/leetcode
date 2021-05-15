class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> res(n * 2, 0);
        //按顺序插入数据
        int m = 0;
        for (int i = 0, j = n; i < n && j < 2*n; ++i, ++j)
        {
            res[m++] = nums[i];
            res[m++] = nums[j];
        }
        
        return res;
    }
};