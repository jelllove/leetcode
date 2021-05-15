class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> tmpList;
            
            //第一个是一定要放的
            //firt 1
            tmpList.push_back(1);
            
            for (int k = 1; k < i; ++k)
            {
                //除了头和尾是1之外，别的，就是上两个加起来，这个比较简单
                tmpList.push_back(res[i - 1][k - 1] + res[i - 1][k]);
            }
            
            //最后一个要看情况，只有第一行是要放的
            //last 1
            if (i >= 1)
            {
                tmpList.push_back(1);
            }
            
            res.push_back(tmpList);
        }
        
        return res;
    }
};