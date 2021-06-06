class Solution {
public:
    vector<int> grayCode(int n) {
        int amount = 1<<n;
        
        vector<int> ans;
        for (int i = 0; i < amount; ++i)
        {
            ans.push_back(i ^ (i>>1));
        }
        
        return ans;
    
    }
};