class Solution {
public:
    int solve(vector<int>&stones, int i,vector<vector<int>>&dp,int n,int sum,int sumi){
        if(i==n){
           return sum;
        }

        if(i>stones.size())return INT_MAX;
        int x = sum;
        if(dp[i][x]!=-1)return dp[i][x];
                int d = solve(stones,i+1,dp,n,sum+stones[i],sumi);
                
                int y = solve(stones,i+1,dp,n,abs(sum-stones[i]),sumi);
                
        return dp[i][x] = min(d,y);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum =0;
        for(int i= 0;i<stones.size();i++)sum+=stones[i];
        vector<vector<int>>dp(stones.size(),vector<int>(sum*2+1,-1));
        return solve(stones,0,dp,stones.size(),0,sum);
    }
};