class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        int startVal = nums[0];
        int tailVal = nums[0];
        
        vector<string> ans;
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (tailVal + 1 == nums[i])
                tailVal = nums[i];
            else
            {
                if (tailVal == startVal)
                    ans.push_back(to_string(tailVal));
                else
                    ans.push_back(to_string(startVal) + "->" + to_string(tailVal));
                startVal = tailVal = nums[i];
            }
        }
        
        if (tailVal == startVal)
            ans.push_back(to_string(tailVal));
        else
            ans.push_back(to_string(startVal) + "->" + to_string(tailVal));
        
        return ans;
    }
};