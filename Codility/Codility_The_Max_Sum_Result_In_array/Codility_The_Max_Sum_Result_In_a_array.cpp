#include "public.h"



int sum(vector<int> &nums)
{
    if (nums.size() == 0)
        return INT_MIN;

    if (nums.size() <= 1)
        return nums[0];

    vector<int> dp(nums.size(), 0);

    int maxVal = INT_MIN;

    dp[0] = nums[0];
    dp[1] = max(nums[1], nums[0]);

    for (int i = 2; i < nums.size(); ++i)
    {
        dp[i] = max(nums[i], max(dp[i - 1], dp[i - 2] + nums[i]));
        maxVal = max(maxVal, dp[i]);
    }

    return maxVal;

    // {}
    // {8}
    // {-5}
    // {int_max - 1}
    // {int_min + 1}
    // 1, 2, 3, 4, 5
    // 5, 4, 3, 2, 1
    // 1, -2, 3, -5, 6
    // -2, 4, -5, 6, -7
    // -4, -8, -9, -1, -5
}

int main(int argc, char *argv[])
{
    vector<int> test1 = {-4, -8, -9, -1, -5};
    assert((-1 == sum(test1)));

    vector<int> test2 = {-2, 4, -5, 6, -7};
    assert((10 == sum(test2)));

    vector<int> test3 = {1, -2, 3, -5, 6};
    assert((10 == sum(test3)));

    vector<int> test4 = {3, -4, 4, 10};
    assert((13 == sum(test4)));

    vector<int> test5 = {9, -4, -8, -2};
    assert((9 == sum(test5)));

    vector<int> test6 = { -4, -8, 9, -2, -7};
    assert((9 == sum(test6)));
    
    vector<int> test7 = { -4, -8, -2, -7, 9};
    assert((9 == sum(test7)));

    return EXIT_SUCCESS;
}
