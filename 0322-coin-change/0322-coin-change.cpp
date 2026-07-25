class Solution {
public:
    int  solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        if(amount == 0){
            return 0;
        }
        if(i>=coins.size()||amount<0) return 1e9;
        // if(count>dp[i][amount]&&dp[i][amount]!=-1) return INT_MAX;
        int min_count ;
        if(dp[i][amount]!=-1) return dp[i][amount];   
        int b=  solve(coins,amount-coins[i],i,dp);  
        if(b!=1e9)b++;
        int a = solve(coins,amount,i+1,dp);
        min_count = min(b,a);
        return dp[i][amount]=  min_count;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int ans =  solve(coins,amount,0,dp);
       if(ans == 1e9)ans = -1;
        return ans;
    }
};