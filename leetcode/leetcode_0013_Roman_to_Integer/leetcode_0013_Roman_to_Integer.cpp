
vector<pair<string, int>> SymbolTable ={
    {"CD", 400},
    {"CM", 900},
    {"XL", 40},
    {"XC", 90},
    {"IV", 4},
    {"IX", 9},
    {"I", 1},
    {"V", 5},
    {"X", 10},
    {"L", 50},
    {"C", 100},
    {"D", 500},
    {"M", 1000}
};

class Solution {
public:
    int romanToInt(string s) {
        
        //Method 1: 最容易理解的方式，但是速度上不太行
        /*
        int ans = 0;
        
        int i = 0;
        while (i < s.size())
        {
            for (auto &b : SymbolTable)
            {
                if (b.first.size() <= (s.size() - i) &&
                   b.first == s.substr(i, b.first.size()))
                {
                    ans += b.second;
                    i += b.first.size();
                    break;
                }
            }
        }
        
        return ans;
        */
        
        //Method 2: using the map, 同时有一个它有一个规律，就是 I,IV, IX是一组，而X, XL, XC同一组,C，CD, CM是一组
        //所以他们在出现的时候只要判断一个比另一个小的话，那直接减一下就行了
        unordered_map<char, int> um;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        
        
        int ans = 0;
        int i = 0;
        while (i < s.size())
        {
            if ((i + 1) < s.size() && (um[s[i]] < um[s[i + 1]]))
            {
                ans += (um[s[i + 1]] - um[s[i]]);
                i += 2;
            }
            else
            {
                ans += um[s[i]];
                ++i;
            }
        }
        
        return ans;
        
    }
};