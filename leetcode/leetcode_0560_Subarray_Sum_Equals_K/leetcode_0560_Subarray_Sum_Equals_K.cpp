class Solution {
public:
    int subarraySum(vector<int>& nums, int K) {
        unordered_map<int,int> um;
        int sum{0},c{0};
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==K)  c++;
            auto it= um.find(sum-K);
            if(it!=um.end())   c+=it->second;
            um[sum]++;
        }
        return c;
    }
};