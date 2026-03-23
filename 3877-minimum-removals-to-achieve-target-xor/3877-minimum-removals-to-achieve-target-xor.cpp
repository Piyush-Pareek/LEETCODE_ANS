class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
     int n = 16384;
        vector<int>dp(n,-1);
        dp[0]  = 0;
        for(int num:nums){
            vector<int>new_dp = dp;
            for(int i=0;i<n;i++){
                if(dp[i]!=-1){
                    new_dp[i^num] = max(new_dp[i^num],dp[i]+1);
                    
                }
            }
            dp = new_dp;
        }
        if(dp[target] == -1) return -1;
        return nums.size()-dp[target];
    }
};