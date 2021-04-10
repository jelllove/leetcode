class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //如果大小都不一样，肯定不是同构字符
        if (s.size() != t.size())
            return false;
        
        //如果两个都没有字符，那也算是同构
        if (s.size() == 0)
            return true;
        
        //准备两个hash table， 记录自己的字符与另一个字符串中的字符进行映射
        unordered_map<char, char> mpS;
        unordered_map<char, char> mpT;
        
        for (int i = 0; i < s.size(); ++i)
        {
            //如果S的hash table中没有出现过
            if (mpS.count(s[i]) <= 0)
            {
                //那对的T的字符在T的hash table中，也不应该出现过
                if (mpT.count(t[i]) > 0)
                    return false;
                
                //相互映射
                mpS[s[i]] = t[i];
                mpT[t[i]] = s[i];
            }
            else
            {
                //相互比较一下，看看对不对
                if (mpS[s[i]] != t[i] || mpT[t[i]] != s[i])
                    return false;
            }
        }
        
        //最后都比较完了
        return true;
    }
};