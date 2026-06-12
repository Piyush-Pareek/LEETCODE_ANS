class Solution {
public:
    int solve(vector<string>& str,int m,int n,int i,int count,vector<vector<vector<int>>>&dp){
        if(i>=str.size()) return 0;
        if(m==0&&n==0)return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int x=0,y=0;
        for(auto k:str[i]){
            
                if(k=='0')x++;
                if(k=='1')y++;
            
        }
    int a =0;
        if(m-x>=0&&n-y>=0)
         a = 1+solve(str,m-x,n-y,i+1,count+1,dp);
        int b = solve(str,m,n,i+1,count,dp);
        return dp[i][m][n] = max(a,b);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,m,n,0,0,dp);
    }   
};