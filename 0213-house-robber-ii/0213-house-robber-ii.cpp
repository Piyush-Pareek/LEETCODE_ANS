class Solution {
public:
    // int robhouse(vector<vector<int>>&dp,vector<int>&nums,int x,int i){
    //     if(i>=nums.size()) return 0;
    //     if(i == nums.size()-1&&x==0)return 0;
    //     if(dp[x][i] !=-1&&i!=nums.size()) return dp[x][i];
    //     if(i==0){ x =0;}
    //     int b = nums[i]+robhouse(dp,nums,x,i+2);
    //     if(i==0){ x =1;}
    //     int a = robhouse(dp,nums,x,i+1);
    //     return dp[x][i]= max(a,b);
    // }
  int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
    
        int a=0,b=0;
        int x=0,y=0;
        
        for(int i=nums.size()-1;i>0;i--){
            int temp = max(x,nums[i]+y);
            y = x;
            x = temp;
        }
        a = x;
        x=0;y=0;
        for(int i = nums.size()-2;i>=0;i--){
             int temp = max(x,nums[i]+y);
            y = x;
            x = temp;
        }
        b = x;
        return max(a,b);
    }
};