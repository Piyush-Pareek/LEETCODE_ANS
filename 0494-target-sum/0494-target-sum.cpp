class Solution {
public:
    int count  =0;
    int solve(vector<int>&nums, int target,int sum,int i,vector<vector<int>>&dp,int sumi){
        if(target == sum&&i==nums.size()){
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        int x=0;
        if(sum>=0) x = sum;
        else{
            x = abs(sum)+sumi+1;
        }
        if(dp[i][x]!=-1) return dp[i][x];
        int a = solve(nums,target,sum+nums[i],i+1,dp,sumi);
        int b = solve(nums,target,sum-nums[i],i+1,dp,sumi);
        return dp[i][x] =  a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(2*sum+2,-1));
        return solve(nums,target,0,0,dp,sum);
    }
};