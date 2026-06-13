class Solution {
public:
    int solve(string& text1,string& text2,int i,int j,vector<vector<int>>&dp){
        if(i>=text1.size()||j>=text2.size()) return 0;
        int a =0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j]){
            a = 1+solve(text1,text2,i+1,j+1,dp);
        }else{
            int b = solve(text1,text2,i+1,j,dp);
            int c = solve(text1,text2,i,j+1,dp);
            a = max(b,c);
        }

        return dp[i][j] =  a;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // return solve(text1,text2,0,0,dp);
        int max_size = 0;
        for(int i = text1.size()-1;i>=0;i--){
            for(int j = text2.size()-1;j>=0;j--){
                int a =0;
                if(text1[i]==text2[j]){
                    a = 1+dp[i+1][j+1];
                }else{
                    int b = dp[i+1][j];
                    int c = dp[i][j+1];
                    a = max(b,c);
                }
                dp[i][j]=a;
                if(a>max_size)max_size = a;
            }
        }
        return max_size;
    }
};