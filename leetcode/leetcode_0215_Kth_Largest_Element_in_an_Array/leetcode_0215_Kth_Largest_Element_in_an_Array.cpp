class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        
        for (auto &item : nums)
        {
            pq.push(item);
        }
        
        for (int i = 0; i < k - 1; ++i)
        {
            pq.pop();
        }
        
        return pq.top();
    }
};