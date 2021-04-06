class Solution {
public:
    int maxArea(vector<int>& height) {
        //Method 1: brute force
        //两个for 循环
        //但是数据多了，就会超时
        /*
        int maxWater = INT_MIN;
        for (int i = 0; i < height.size() - 1; ++i)
        {
            for (int j = i + 1; j < height.size(); ++j)
            {
                int area = min(height[j], height[i]) * (j - i);
                maxWater = max(maxWater, area);
            }
        }
        
        return maxWater;
        */
        
        //Method 2: using two pointer
        //利用两指针左右移动
        int left = 0;
        int right = height.size() - 1;
        
        int maxWater = INT_MIN;
        int area = 0;
        while (left < right)
        {
            area = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, area);
            
            if (height[left] < height[right])
                ++left;
            else
                --right;
            
        }
        
        return maxWater;
        
    }
};