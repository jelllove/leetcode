
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin() , coins.end());
        
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , 0));
        
        //solving for first coin value 
        for(int i=coins[0]; i<=amount; i+=coins[0])
            dp[1][i] = 1;
        
        //1 one way to create amount 0
        for(int i=0; i<=n; i++) 
            dp[i][0] = 1;
        
        for(int i=2; i<=n; i++) {
            
            for(int k=1; k<=amount; k++) {
                dp[i][k] = dp[i-1][k];
                
                if(k >= coins[i-1])
                    dp[i][k] += dp[i][k-coins[i-1]];
            }
        }
        
        return dp[n][amount];
    }
};