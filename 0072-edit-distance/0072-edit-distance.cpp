class Solution {
public:
    int solve(string& s1, string& s2,int i,int j,vector<vector<int>>&dp){
     
            // FIX THIS:
if (i >= s1.size()) {
    return s2.size() - j; // Need to insert remaining s2 characters
}
if (j >= s2.size()) {
    return s1.size() - i; // Need to delete remaining s1 characters
}
if(dp[i][j]!=-1)return dp[i][j];
            int a;
            if(s1[i]==s2[j]){
               
                a = solve(s1,s2,i+1,j+1,dp); // do nothing 
             
            }else{
                int b= solve(s1,s2,i,j+1,dp); // insert
                int d= solve(s1,s2,i+1,j+1,dp);  // replace  
                int c = solve(s1,s2,i+1,j,dp);  // delet
                a = 1+min(b,min(c,d));  // take +1 step whete insert dleet or replace 
            }
            return dp[i][j] =  a;
    }
    int minDistance(string word1, string word2) {
        string temp = "";
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1,word2,0,0,dp);
    }
};