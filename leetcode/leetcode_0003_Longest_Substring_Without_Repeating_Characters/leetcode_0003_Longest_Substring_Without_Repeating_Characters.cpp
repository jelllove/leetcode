//Method 1: using the bitset
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        int leftPos = 0;
        int rightPos = 0;
        
        bitset<256> myBit;
        
        while (leftPos < s.size())
        {
            //  a, b, c, a, b, c
            //  一开始都还是顺利的，就是找到第二个A的时候，因为之前已经有过了，所以要从left开始找，一直把bitset中的那个 s[rightPos]，消除，消除后再重新置上s[leftPos]
            if (myBit.test(s[rightPos]))
            {
                myBit.reset(s[leftPos]);
                leftPos++;
            }
            else
            {
                myBit.set(s[rightPos]);
                rightPos++;
            }
            
            if (len < (rightPos - leftPos))
            {
                len = rightPos - leftPos;
            }
            
            
            if ((leftPos + len) >= s.size() ||
               rightPos >= s.size()
               )
            {
                break;
            }
        }
        
        return len;
    }
};






//Method 2: using the hash table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int amount = 256;
        int hashTable[amount] = {0};
        
        int i = 0, j = 0;
        
        int maxCount = 0;
        
        while (i < s.size())
        {
            
            if (hashTable[s[j]] != 0)
            {
                hashTable[s[i]] = 0;
                ++i;
            }
            else
            {
                hashTable[s[j]] = 1;
                ++j;
            }
            
            maxCount = max(maxCount, j - i);
            
            if (i + maxCount >= s.size() ||
               j >= s.size())
            {
                break;
            }
            
        }
        
        return maxCount;
    }
};