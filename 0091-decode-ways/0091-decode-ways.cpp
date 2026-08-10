class Solution {
public:

int solve(string s,int i,vector<int>&dp){
    if(s[i]=='0')return 0;
    if(i == s.size()||i == s.size()-1){
        return 1;
    }
    if(dp[i]!=-1)return dp[i];
    int a=0,b=0;
     a = solve(s,i+1,dp);
    if((s[i]=='1'||s[i]=='2')&&(s[i]=='1'||s[i+1]<'7'))
    b = solve(s,i+2,dp);
    return dp[i] = a+b;
}
    int numDecodings(string s) {
        vector<int>dp( s.length(),-1);
        if(s[0]=='0')return 0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i+1]=='0'&&(s[i]>'2'||s[i]=='0')) return 0;
        }
        return solve(s,0,dp);
    }
};                                                                               