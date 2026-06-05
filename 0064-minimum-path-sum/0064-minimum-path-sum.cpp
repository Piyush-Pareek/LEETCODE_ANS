class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        dp[grid.size()-1][grid[0].size()-1]=grid[grid.size()-1][grid[0].size()-1];
        for(int i=0;i<grid.size();i++) dp[i][grid[0].size()] =INT_MAX;
        for(int i=0;i<grid[0].size();i++) dp[grid.size()][i] = INT_MAX;
        for(int i=grid.size()-1;i>=0;i--){
            for(int j =grid[0].size()-1;j>=0;j--){
                if(i==grid.size()-1&&j==grid[0].size()-1){}else
                dp[i][j] = grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};