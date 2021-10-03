class Solution {
public:
    void dfs(const vector<int> &nums, int l, int r, vector<double> &res) 
    {
        if (l + 1 == r) {
            res.push_back(nums[l]);
            return;
        }

        vector<double> left, right;
        for (int bound = l + 1; bound <= l + (r - l) / 2; bound++) {
            dfs(nums, l, bound, left);
            dfs(nums, bound, r, right);
            for (auto a : left) {
                for (auto b : right) {
                    res.push_back((double)a + (double)b);
                    res.push_back(abs((double)a - (double)b));
                    res.push_back((double)a * (double)b);
                    res.push_back((double)a / (double)b);
                }
            }
            left.clear();
            right.clear();
        }
    }

    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        vector<int> begin = cards;

        do  {
            vector<double> res;
            dfs(cards, 0, cards.size(), res);
            for (int i = 0; i < res.size(); i++) {
                if (abs(res[i] - 24.0) < 1e-5) {
                    return true;
                }
            }
            next_permutation(cards.begin(), cards.end());
        } while (begin != cards);
       
        return false;
    }
};