class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int cur = 0;//当前应该走到的问题
        int mx = 0;//最远能走多远
        int ans = 0;//一共走了几次
        for (int i = 0; i < n - 1; i++) 
        {
            if (mx < v[i] + i)//如果当前的位置已经超过了最远能走的位置了，那就修改最远的问题
                mx = v[i] + i;
            if (i == cur)  //如果i走到了上一个最远的那个点，就直接更新cur的值
            {
                cur = mx; //更新当前的最应该走到哪里
                ans++; //多走了一步，加1
            }
                
        }
        return ans;
    }
};