class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int end1 = maxEnd * nums[i];
            int end2 = minEnd * nums[i];
           
            maxEnd = max(max(end1, end2), nums[i]);
            minEnd = min(min(end1, end2), nums[i]);
            
            ans = max(ans, maxEnd);
        }
        return ans;
    }
};