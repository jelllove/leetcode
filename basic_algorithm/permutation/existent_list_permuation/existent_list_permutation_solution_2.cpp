
class Solution {
public:
    void get_next_permuation(vector<int> &nums)
    {
        int i = nums.size() - 2;

        while (i >= 0 && nums[i] > nums[i + 1])
            --i;
        
        if (i >= 0)
        {
            int j = nums.size() - 1;
            while (i >= 0 && j >= i && nums[j] < nums[i])
                --j;
            swap(nums[i], nums[j]);
        }
            
        reverse(nums.begin() + i + 1, nums.end());
    }

    vector<vector<int>> myPermuation(vector<int>& nums)
    {
        vector<vector<int>> ans;

        ans.push_back(nums);
        while (true)
        {
            get_next_permuation(nums);
            if (nums != ans[0])
                ans.push_back(nums);
            else
                break;
        }
        return ans;
    }
};

int main(int argc, char *argv[])
{


	vector<int> data = {1, 2, 3};

    vector<vector<int>> res = Solution().myPermuation(data);

    return EXIT_SUCCESS;
}