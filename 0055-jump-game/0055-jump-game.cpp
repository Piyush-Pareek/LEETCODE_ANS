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
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};