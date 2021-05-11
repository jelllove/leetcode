// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1)
            return 1;
        //就是一个二分查找法
        int l = 1;
        int r = n;
        
        while (l <= r)
        {
            int m = (r - l) / 2 + l;
            if (isBadVersion(m))
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return l;
    }
};