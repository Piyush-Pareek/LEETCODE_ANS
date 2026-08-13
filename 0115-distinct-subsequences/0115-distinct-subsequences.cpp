class Solution {
public:
    int solve(string& s,string& t,int i,int j,vector<vector<int>>&dp){
        if(j == t.length()){
            return 1;
        }
        if(i>=s.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0,b=0;
        if(s[i] == t[j])
        a = solve(s,t,i+1,j+1,dp);

        b = solve(s,t,i+1,j,dp);
        return dp[i][j] = a+b;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.length()+1,vector<int>(t.length()+1,-1));
       return  solve(s,t,0,0,dp);
    }
};