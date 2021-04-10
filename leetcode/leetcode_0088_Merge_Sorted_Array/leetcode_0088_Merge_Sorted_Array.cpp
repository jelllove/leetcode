class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //如果nums2是空，那就直接返回，因为不用做什么
        if (n == 0)
            return;
        
        if (m == 0)
        {
            copy(nums2.begin(), nums2.end(), nums1.begin());
            return;
        }
        
        int i = m -1;
        int j = n -1;
        
        int tail = (m + n - 1);
        
        //使用J来作判断，原因是因为如果J已经结束的话，那就不用再作操作了
        //比如遇上了nums1中有10000个数字，而nums2中只有1个数字的话
        //那这样的话，就可以节省很多的时间
        while (j >= 0)
        {
            //如果nums1已经用完了，或者是nums2大于nums1，那就使用nums2
            if (i < 0 || nums2[j] > nums1[i])
            {
                nums1[tail--] = nums2[j--];
            }
            else
            {
                nums1[tail--] = nums1[i--];
            }
        }
    }
};