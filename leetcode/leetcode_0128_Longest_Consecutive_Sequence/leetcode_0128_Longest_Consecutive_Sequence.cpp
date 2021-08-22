class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){return 0;}
        sort(nums.begin(),nums.end());
       
        int cnt=1;int ans=INT_MIN;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]){continue;}
            
             if(nums[i-1]==nums[i]-1){
                cnt++;
                
             } 
            else{
                
                ans=max(ans,cnt);
               
                cnt=1;
            }
             
            
        }
        ans=max(ans,cnt);
        return ans;
    }
};