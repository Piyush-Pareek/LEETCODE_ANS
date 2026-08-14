class Solution {
public:
    bool solve(vector<int>&nums , int curr, vector<int>&dp){
        if(curr == nums.size()-1|| curr+nums[curr]>=nums.size()-1)return true;
        if(nums[curr] == 0)return false;
        if(dp[curr]!=-1)return false;
        for(int i = curr+1;i<=curr+nums[curr];i++){
            if(solve(nums,i,dp))return true;
        }
        return dp[curr] =  false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1);
        dp[nums.size()] = 1;
        dp[nums.size()-1] = 1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j = i+1;j<=i+nums[i];j++){
                if(dp[j] == 1){
                    dp[i] = 1;
                    break;
                }

            }

        }
        return dp[0];
    }
};