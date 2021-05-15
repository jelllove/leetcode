class Solution {
public:
    string intToRoman(int num) {
        //首先把这个罗马数字的表弄出来
        vector<pair<int, string>> vec = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        //然后从最大的那个开始数，如果当前的值比它大，那就取那个字符，同时把数字减掉
        //一直到最后，只剩下0
        int i = 0;
        string ans = "";
        while (i < vec.size() && num > 0)
        {
            if (num >= vec[i].first)
            {
                ans += vec[i].second;
                num -= vec[i].first;
            }
            else
            {
                ++i;
            }
        }
        
        return ans;
    }
};