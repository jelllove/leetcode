class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1 || k == 0)
            return;
        //用K取余的目的是为了把多余的旋转去除掉
        int m = k % nums.size();
        //如果取余是0，相当于没有移，那就不用动了
        if (m == 0)
            return;
        
        
        //Method 1: using a temp vector
        //如果使用一个个进行pop和push的话，会超时
        /*
        vector<int> tmpVec;
        tmpVec.insert(tmpVec.begin(), nums.begin() + (nums.size() - m), nums.end());
        nums.erase(nums.begin() + (nums.size() - m), nums.end());
        nums.insert(nums.begin(), tmpVec.begin(), tmpVec.end());
        */
        
        //Method 2: Using the reverse
        /*
        //如果测试用例是:  1,2,3,4,5,6,7
        //                3
        //那第一次reverse之后，就是  7, 6, 5, 4, 3, 2, 1
        std::reverse(nums.begin(), nums.end());
        
        //第二次Reverse之后，是5, 6, 7, 4, 3, 2, 1
        std::reverse(nums.begin(), nums.begin() + m);
        
        //第三次Reverse之后，是：5， 6， 7， 1， 2，3，4
        std::reverse(nums.begin() + m, nums.end());
        */
        
        
        //Method 3: STL本身提供了一Rotate的函数
        std::rotate(nums.begin(), nums.begin() + (nums.size() - m), nums.end());
        
    }
};