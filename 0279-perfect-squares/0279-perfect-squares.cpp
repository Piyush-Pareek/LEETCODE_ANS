class Solution {
public:
int solve(int n,int i,vector<vector<int>>&dp){
    long long sq = i*i;
    if(n-sq<0)return 1e9;
    if(n-sq == 0) return 1;
    if(dp[i][n]!=-1)return dp[i][n];
    
    int c = solve(n,i+1,dp);
    int a =1+ solve(n-sq,i+1,dp)%1000000009;
    int b= 1+solve(n-sq,i,dp)%1000000009;
    return dp[i][n] = min(a,min(b,c))%1000000009;
}
    int numSquares(int n) { 
            vector<vector<int>>dp(100+1,vector<int>(n+1,-1));
            return solve(n,1,dp);
    }
};