class Solution {
public:

 int climb(int n,int pos,vector<int>&vec,vector<int>&dp ){

        if(pos >= n){
            return 0;
        }
        if(dp[pos]!=-1)return dp[pos];
    return dp[pos] = vec[pos]+min(climb(n,pos+1,vec,dp), climb(n,pos+2,vec,dp)) ;
    }
   
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
    vector<int>dp1(cost.size(),-1);
   return min(climb(cost.size(),0,cost,dp),climb(cost.size(),1,cost,dp1));
    }
};