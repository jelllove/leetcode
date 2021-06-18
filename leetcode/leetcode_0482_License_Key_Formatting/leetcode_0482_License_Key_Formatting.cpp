class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        //这里做一次反转，是为了防止使用两次遍历
        reverse(s.begin(), s.end());
        string ans = "";
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '-')
            {
                if ((count % k == 0) && (count != 0))
                {
                    ans += "-";
                }
                ans += toupper(s[i]);
                count++;
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};