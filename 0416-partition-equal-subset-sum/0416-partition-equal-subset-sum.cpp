class Solution {
public:
    bool solve(vector<int>&nums,vector<vector<int>>&dp,int sum1,int sum2,int i,int target){
        if(i>=nums.size()){
            if(sum1==target)return true;
            else{
            
            return false;
            }
        }
        if(sum1==target)return true;
        if(sum1>target){
            return false;
        }
        if(dp[i][sum1]!=-1){
            return false;
        }
        if(solve(nums,dp,sum1+nums[i],sum2,i+1,target)){ return true;}else{
            dp[i][sum1] =2;
        }
        
        if(solve(nums,dp,sum1,sum2,i+1,target)){return true;}else{
        dp[i][sum1] = 2;

        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
sum+=nums[i];
        }
        if(sum%2!=0)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum/2,-1));

        int sum1 =0,sum2=0;
        return solve(nums,dp,sum1,sum2,0,sum/2);
    }
};