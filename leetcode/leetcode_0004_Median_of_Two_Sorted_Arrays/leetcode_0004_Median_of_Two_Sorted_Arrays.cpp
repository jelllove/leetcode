class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Method 1: vector + vector, sort
        /*
        vector<int> ans = nums1;
        ans.insert(ans.end(), nums2.begin(), nums2.end());
        std::sort(ans.begin(), ans.end());
        
        if (ans.size() == 0)
            return 0.0;
        
        if ((ans.size() & 0x01) == 0x01)
        {
            return (double)ans[ans.size() / 2];
        }
        else
        {
            return (double)(ans[ans.size() / 2] + ans[ans.size() / 2 - 1]) / 2.0;
        }
        */
        
        //Method 2: Another vector to insert the value
        /*
        int total = nums1.size() + nums2.size();
        
        vector<int> ans(total, 0);
        
        int i1 = 0;
        int i2 = 0;
        int index = 0;
        
        while (i1 < nums1.size() || i2 < nums2.size())
        {
            if (i1 >= nums1.size())
            {
                ans[index++] = nums2[i2++];
            }
            else if (i2 >= nums2.size())
            {
                ans[index++] = nums1[i1++];
            }
            else
            {
                if (nums1[i1] >= nums2[i2])
                {
                    ans[index++] = nums2[i2++];
                }
                else
                {
                    ans[index++] = nums1[i1++];
                }
            }
        }
        
        if ((ans.size() & 0x01) == 0x01)
        {
            return (double)ans[ans.size() / 2];
        }
        else
        {
            return (double)(ans[ans.size() / 2] + ans[ans.size() / 2 - 1]) / 2.0;
        }
        */
    
        //Method 3: using two pointer
        /*
        int total = nums1.size() + nums2.size();  //总的个数
        int MedianIndex = 0;//中间的那个值的位置
        int count = 1;
        if ((total & 0x01) == 0x01)
        {
            //如果是奇数，那中间的位置直接除2可得，然后个数也只要一个就可以了
            MedianIndex = total / 2;
            count = 1;
        }
        else
        {
            //如果是偶数，那要取中间的两个值
            MedianIndex = total / 2 - 1;
            count = 2;
        }
        
        //两个指针
        int i1 = 0;
        int i2 = 0;
        //最后要返回的值
        double val = 0.0;
        int got = 0;//已经取得的值
        
        //因为要在两个VECTOR中来回的改对应的指针,所以在比较了两个VECTOR的大小后，使用指针更方便一点
        vector<int> *pList = nullptr; 
        int *pListIndex = nullptr;
        
        while (i1 < nums1.size() || i2 < nums2.size())
        {
            
            if (i1 >= nums1.size())
            {
                pList = &nums2;
                pListIndex = &i2;
            }
            else if (i2 >= nums2.size())
            {
                pList = &nums1;
                pListIndex = &i1;
            }
            else
            {
                if (nums1[i1] >= nums2[i2])
                {
                    pList = &nums2;
                    pListIndex = &i2;
                }
                else
                {
                    pList = &nums1;
                    pListIndex = &i1;
                }
            }
            
            if (
                ((i1 + i2) == MedianIndex) || ((i1 + i2) == MedianIndex + 1 && count == 2)
                )
            {
                val +=  (*pList)[*pListIndex];
                ++got;
            }
            ++(*pListIndex);
            
            if (got == count)
                break;
        }
        
        return val / double(count);
        */
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int medianCount = 1;
        int medianIndex = (n1 + n2) /  2;
        if (!((n1 + n2) & 0x1))
        {
            medianCount = 2;
            --medianIndex;
        }
        
        int idx1 = 0;
        int idx2 = 0;
        int index = 0;
        int sum = 0;
        
        while (idx1 < n1 || idx2 < n2)
        {
            int tmp = 0;
            
            if (idx1 == n1)
                tmp = nums2[idx2++];
            else if (idx2 == n2)
                tmp = nums1[idx1++];
            else if (nums1[idx1] < nums2[idx2])
                tmp = nums1[idx1++];
            else
                tmp = nums2[idx2++];
            
            if (index >= medianIndex)
            {
                if (index <= medianIndex + medianCount - 1)
                    sum += tmp;
                else
                    break;
            }
            ++index;
        }
        
        return (double)sum / double(medianCount);
            
        
        
        
    }
};