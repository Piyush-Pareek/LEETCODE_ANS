class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[nums.size()-1]=0;
        for(int i = nums.size()-2;i>=0;i--){
            int min_jump = INT_MAX;
            for(int j = i+1;j<=nums.size()-1&&j<=i+nums[i];j++){
                if(dp[j]==-1)continue;
                min_jump = min(min_jump,dp[ j]);
            }
        //   cout<<i<<endl;
            if(nums[i]==0||min_jump == INT_MAX)dp[i]=INT_MAX;
            else
            dp[i] = min_jump+1;
            cout<<dp[i]<<endl;
        }
        return dp[0];
    }
};