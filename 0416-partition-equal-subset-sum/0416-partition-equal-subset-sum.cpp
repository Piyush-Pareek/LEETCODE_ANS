class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        int target =  total/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
    for(int i=0;i<=nums.size();i++){
        dp[i][0] = 1;
    }
    for(int i=nums.size()-1;i>=0;i--){
        for(int j = 0;j<=total/2;j++){
            target = j;
            bool a=0;
            if(target-nums[i]>=0)
             a = dp[i+1][target-nums[i]];
            bool b = dp[i+1][target];
            dp[i][j] = a||b;
        }
    }
    return dp[0][total/2];

    }
};