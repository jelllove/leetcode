
//把所有的字符串排一下序，但是比大小的时候要组合的比一下，不能直接比较大小
//因为比如“9” < "91"，所以如果直接比大小的话，那就会变成  "91", "9"
//最后组织起来，变成了 919，但事实上组合成  991，应该是最大的
struct Cmp
{
public:
    bool operator ()(const string &a, const string &b)
    {
        //堆的比较规则与sort的正好是相反的
        return ((a + b) < (b + a));
    }
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        //Method 1: using the vector, and sort with the string
        /*
        string ans = "";
        if (nums.size() == 0)
            return "0"
        
        vector<string> tmpList;
        for (auto &item : nums)
        {
            tmpList.push_back(to_string(item));
        }
        
        //把所有的字符串排一下序，但是比大小的时候要组合的比一下，不能直接比较大小
        //因为比如“9” < "91"，所以如果直接比大小的话，那就会变成  "91", "9"
        //最后组织起来，变成了 919，但事实上组合成  991，应该是最大的
        std::sort(tmpList.begin(), tmpList.end(), [](const string &a, const string &b){return (a + b) > (b + a);});
        
        for (auto &s : tmpList)
        {
            ans += s;
        }
        
        //有可能最后返回的是 “00000”，这样的话，只要返回"0“就可以了
        if (ans == "" || ans[0] == '0')
            return "0";
        else
            return ans;
        */
        
        //Method 2: using the heap to finish the sort during the insert
        string ans = "";
        if (nums.size() == 0)
            return "0";
        
        priority_queue<string, vector<string>, Cmp> pq;
        for (auto &item : nums)
        {
            pq.push(to_string(item));
        }
        

        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        
        //有可能最后返回的是 “00000”，这样的话，只要返回"0“就可以了
        if (ans == "" || ans[0] == '0')
            return "0";
        else
            return ans;
        
    }
};