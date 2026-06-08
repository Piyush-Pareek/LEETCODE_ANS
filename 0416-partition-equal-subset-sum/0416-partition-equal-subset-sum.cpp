class Solution {
public:
bool solve(vector<int>& nums,vector<vector<int>>&dp,int i,int target){
    if(i>=nums.size())return false;
    if(target<0) return false;
    if(target == 0) return true;

    if(dp[i][target]!=-1) return dp[i][target];
    bool a = solve(nums,dp,i+1,target-nums[i]);
    bool b = solve(nums,dp,i+1,target);

    return dp[i][target] =  a||b;
}
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        int target =  total/2;
        vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,dp,0,target);
    }
};