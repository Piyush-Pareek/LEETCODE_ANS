class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int maxsum = 0;
        int sum =0;
        int normal_sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]*i);
            normal_sum+=nums[i];
        }
        maxsum = sum;
        int n = nums.size()-1;
        for(int i=nums.size()-1;i>=1;i--){
            sum = sum-nums[i]*n+normal_sum-nums[i];
            
           maxsum = max(sum,maxsum);
        }
        return maxsum;
    }
};