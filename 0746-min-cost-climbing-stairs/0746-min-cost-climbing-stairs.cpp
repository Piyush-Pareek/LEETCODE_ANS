class Solution {
public:

//  int climb(int n,int pos,vector<int>&vec,vector<int>&dp ){

//         if(pos >= n){
//             return 0;
//         }
//         if(dp[pos]!=-1)return dp[pos];
//     return dp[pos] = vec[pos]+min(climb(n,pos+1,vec,dp), climb(n,pos+2,vec,dp)) ;
    // }
   
    int minCostClimbingStairs(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int a=0,b=0;
        int x =0,y=0;
        for(int i = nums.size()-1;i>0;i--){
            int temp = nums[i]+min(x,y);
            y = x;
            x = temp;
        }
        a = x;
        x=0,y=0;
        for(int i =nums.size()-1;i>=0;i--){
            int temp = nums[i]+min(x,y);
            y=x;
            x=temp;
        }
        b=x;
        return min(a,b);
   
    }
};