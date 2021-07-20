class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int n = columnTitle.size();
        
        for (auto &c : columnTitle)
        {
            //It is better to add a adjustment about whether the sum will exceed the INT_MAX
            sum *= 26;
            
            //It is better to add a adjustment about whether the sum will exceed the INT_MAX
            sum += (c - 'A' + 1);
        }
        
        return sum;
    }
};