class Solution {
public:
    int trap(vector<int>& height) {
        //Using two pointer
        int left = 0;
        int right = height.size() - 1;
        
        int allArea = 0;
        
        //利用两指针
        while (left < right)
        {
            //先判断左右指针的高低
            if (height[left] < height[right])
            {
                //指针都是从低的移动到高的位置去的
                //如果移动的过程中，遇上了比自己还要低的，那就记下这个水坑的大小，加起来
                //然后在遇一个比自己高的时候停下来，指针移到新的位置上上去
                int i = left + 1;
                while (i <= right && height[i] < height[left])
                {
                    allArea += (height[left] - height[i]);
                    ++i;
                }
                left = i;
            }
            else
            {
                int i = right - 1;
                while (i >= left && height[i] < height[right])
                {
                    allArea += (height[right] - height[i]);
                    --i;
                }
                right = i;
            }
        }
        
        return allArea;
    }
};