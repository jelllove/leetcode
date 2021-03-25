class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //Method 1: using the unordered_map
        /*
        if (s1.size() > s2.size())
            return false;
        
        unordered_map<char, int> mpS1;
        
        for (auto &item : s1)
        {
            mpS1[item]++;
        }
        
        int count = 0;
        int n = s1.size();
        unordered_map<char, int> mpS2;
        for (int i = 0; i < s2.size(); ++i)
        {
            mpS2[s2[i]]++;
            ++count;
            
            if (count >= n)
            {
                if (mpS2 == mpS1)
                {
                    return true;
                }
                else
                {
                    int pos = (i - n + 1);
                    mpS2[s2[pos]]--;
                    if (mpS2[s2[pos]] == 0)
                        mpS2.erase(s2[pos]);
                    --count;
                    
                }
            }
            
        }
        
        return false;
        */
        
        
        //Method 2: using template array
        if (s1.size() > s2.size())
            return false;
        
        //因为题目中只写了s1和s2中只会有26个小字字母
        //所以只要使用两个数组就可以了
        int hashS1[26] = {0};
        int hashS2[26] = {0};
        
        //先建立一个s1的hash表
        for (auto &item : s1)
        {
            hashS1[item - 'a']++;
        }
        
        //定义left和right两个指针，用来进行移动
        int l = 0;
        int r = 0;
        int n = s1.size();
        
        //一直到S2的最后一个
        while (r < s2.size())
        {
            //把s2这个字符串上的数据做成hash表
            hashS2[s2[r] - 'a']++;
            if ((r - l + 1) == n)
            {
                //如果这个表的长度已经和s1一样了，就做一次比较，
                if (memcmp(hashS2, hashS1, sizeof(hashS1)) == 0)
                    return true;
                else
                    hashS2[s2[l] - 'a']--; //比较失败的话，那就把之前left位置的那个hash值减1
                    
                //左右同时向后移
                ++r;
                ++l;
            }
            else
            {
                //因为s2的表的长度还没有和s1一样，所以先只移到right指针
                ++r;
            }
        }
        
        return false;
        
    }
};