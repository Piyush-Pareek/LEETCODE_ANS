class Solution {
public:
    // int count  =0;
    // int solve(vector<int>&nums, int target,int sum,int i,vector<vector<int>>&dp,int sumi){
    //     if(target == sum&&i==nums.size()){
    //         return 1;
    //     }
    //     if(i>=nums.size()){
    //         return 0;
    //     }
    //     int x=0;
    //    x = sum+sumi;
    //     if(dp[i][x]!=-1) return dp[i][x];
    //     int a = solve(nums,target,sum+nums[i],i+1,dp,sumi);
    //     int b = solve(nums,target,sum-nums[i],i+1,dp,sumi);
    //     return dp[i][x] =  a+b;
    // }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(abs(target)>sum) return 0;
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum+1,0));
        // return solve(nums,target,0,0,dp,sum);
        
        dp[nums.size()][target+sum] =1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=2*sum;j>=(0);j--){

                int a=0 ,b =0;
                if(j+nums[i]<=2*sum)
                a=  dp[i+1][j+nums[i]];
                if(j-nums[i]>=0)
                 b = dp[i+1][j-nums[i]];
                 dp[i][j] = a+b;
            }
        }
        return dp[0][0+sum];
    }
};