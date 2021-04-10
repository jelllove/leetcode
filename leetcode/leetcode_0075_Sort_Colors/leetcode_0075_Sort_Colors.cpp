class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0; //左边指向0的index
        int r = nums.size() - 1;//右边指向2的index
        int m = 0;//中间指向1的index
        
        //最后相当于这样：
        //           l           m  r
        //  0  0  0  0  1  1  1  1  2  2  2
        
        while (m <= r)
        {
            if (nums[m] == 0)
            {
                swap(nums[m], nums[l]);
                ++l;
                ++m;
            }
            else if (nums[m] == 1)
            {
                ++m;
            }
            else
            {
                swap(nums[r], nums[m]);
                --r;
            }
        }
    }
};