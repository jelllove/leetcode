/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                ans[i] = ans[i] * nums[j]; 
            }
        }

        return ans;
    }
};
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        
        int zero = 0;
        int product = 1;
        for(auto x : nums){
            if(x == 0){
                zero = zero + 1;
            }else{
                product = product * x;
            }
        }
        
        for(auto x : nums){
            if(x == 0){
                if(zero != 1){
                    ans.push_back(0);
                }else{
                    ans.push_back(product);
                }
            }else{
                if(zero == 0){
                    ans.push_back(product/x);
                }else{
                     ans.push_back(0);
                }
            }
        }
        
        return ans;
    }
};