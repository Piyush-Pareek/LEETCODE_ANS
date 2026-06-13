class Solution {
public:
    int solve(string& s,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size()||j<0)return 0;
        int a = 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]){
            a = 1+solve(s,i+1,j-1,dp);
        }else{
            int b = solve(s,i+1,j,dp);
            int c = solve(s,i,j-1,dp);
            a = max(b,c);
        }

        return dp[i][j] =  a;
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,0,s.size()-1,dp);
    }
};