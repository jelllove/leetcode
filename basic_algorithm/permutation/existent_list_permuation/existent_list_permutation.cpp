
class Solution {
public:
    void helper(vector<int>& nums, int from, int end, vector<vector<int>> &ans)
    {
        if (from == end)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = from; i <= end; ++i)
        {
            swap(nums[i], nums[from]);
            helper(nums, from + 1, end, ans);
            swap(nums[i], nums[from]);
        }
    }

    vector<vector<int>> myPermuation(vector<int>& nums)
    {
        vector<vector<int>> ans;
        helper(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};

int main(int argc, char *argv[])
{


	vector<int> data = {1, 2, 3};

    vector<vector<int>> res = Solution().myPermuation(data);

    return EXIT_SUCCESS;
}