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
        vector<unsigned int>dp(target+1,0);
        // return solve(nums,target,dp);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            unsigned int total = 0;
            for(int j:nums){
                if(i-j>=0)
                total+=dp[i-j];
            }
            dp[i] = total;
        }
        return dp[target];
    }
};