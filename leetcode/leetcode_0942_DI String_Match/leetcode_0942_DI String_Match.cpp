class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        
        if (S.size() == 0)
            return ans;
        
        //因为根据题目意思，是一个模式的匹配
        //所以给是IID，那你只给出数字 0 1 2是不对的
        //因为0 1 2，也可以看成是  III
        //所以一定要多给一个数，比如  0 1 3 2 ，也就是
        //在匹配的字符串上加上一个 IIDI，这样来代表最后一个是D，是下降的
        //所以其实是让你弄一个这样的串出来： IID IID IID IID.....
        S += S[0];
        
        //利用双指针，一个指着头的数字
        //另一个指着头，另一个指向尾
        int i = 0;
        int d = S.size() - 1;
        
        
        
        int index = 0;
        while (index < S.size())
        {
            if (S[index] == 'I')
                ans.push_back(i++);
            else
                ans.push_back(d--);
            
            ++index;
        }
        
        return ans;
    }
};