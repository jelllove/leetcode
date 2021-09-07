class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int firstThree = nums[0]*nums[1]*nums[2];
        int lastThree = nums[size-1]*nums[size-2]*nums[size-3];
        int first2Last1 = nums[0]*nums[1]*nums[size-1];
        return max(firstThree,max(lastThree,first2Last1));
    }
};