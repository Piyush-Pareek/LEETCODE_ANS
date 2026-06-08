class Solution {
public:
    int count  =0;
    int solve(vector<int>&nums, int target,int sum,int i){
        if(target == sum&&i==nums.size()){
            return 1;
        }
        if(i>=nums.size()){
            return 0;
        }
        int a = solve(nums,target,sum+nums[i],i+1);
        int b = solve(nums,target,sum-nums[i],i+1);
        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};