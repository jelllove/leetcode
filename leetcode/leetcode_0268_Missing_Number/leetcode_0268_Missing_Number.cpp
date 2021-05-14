class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total = int(double(nums.size() + 1) * (double(nums.size()) / 2.0));
        
        int sum = 0;
        for (int &n : nums)
        {
            sum += n;
        }
        
        return total - sum;
    }
};