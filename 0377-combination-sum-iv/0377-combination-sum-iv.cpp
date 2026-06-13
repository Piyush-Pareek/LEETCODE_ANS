class Solution {
public:
int solve(vector<int>&nums,int target,vector<int>&dp){
    if(target<0)return 0;
    if(target==0){return 1;}
    if(dp[target]!=-1)return dp[target];
    int toatal = 0;
    for(int j:nums){
        toatal+=solve(nums,target-j,dp);
    }
    
    return dp[target] =toatal;
}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(nums,target,dp);
    }
};