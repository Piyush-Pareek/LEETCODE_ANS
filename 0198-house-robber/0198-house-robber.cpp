class Solution {
public:
    // int rec(vector<int>&nums , vector<int>&memo,int i,int sum){
    //     if(i>=nums.size()){
    //         return 0;
    //     }
    //     if(memo[i]!=-1){
    //         return memo[i];
    //     }
    //     sum+=nums[i];
    //     int a  = nums[i]+rec(nums,memo,i+2,sum);
    //     int b = rec(nums,memo,i+1,sum-nums[i]);
    //     memo[i] = max(a,b);
    //     return max(a,b);
    // }

    int rob(vector<int>& nums) {
        vector<int>memo(nums.size()+2,-1);
    memo[nums.size()] = 0;
    memo[nums.size()+1]=0;
    for(int i=nums.size()-1;i>=0;i--){
        memo[i] = max(memo[i+1],nums[i]+memo[i+2]);
    }
     return memo[0];   
    }
};