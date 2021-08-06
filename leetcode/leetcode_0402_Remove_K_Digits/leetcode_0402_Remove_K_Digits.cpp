class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(k >= num.size()) 
            return "0";
        
        string s;
        
        for(auto c : num)
        {
            while(s.size() && s.back() > c && k)
            {
                s.pop_back();
                k--;
            }
            
            if(s.size() || c != '0') 
                s.push_back(c);
        }
        
        while(s.size() && k--)
            s.pop_back();
        
        return s.empty() ? "0" : s;
        
    }
};