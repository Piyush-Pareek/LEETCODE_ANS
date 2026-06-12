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
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i =strs.size()-1;i>=0;i--){
             int x=0,y=0;
        for(auto k:strs[i]){
            
                if(k=='0')x++;
                if(k=='1')y++;
            
        }
            for(int j =0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    int a =0;
                    if(j+x<=m&&k+y<=n)
                     a = 1+dp[i+1][j+x][k+y];
                    int b = dp[i+1][j][k];
                    dp[i][j][k] = max(a,b);
                   
                }
            }
        }
        return dp[0][0][0];
        // return solve(strs,m,n,0,0,dp);
    }   
};