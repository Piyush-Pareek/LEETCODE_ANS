class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min_val = INT_MAX;
        int sum = 0;
        for(int i=0;i<nums.size();i++){

            if(nums[i]<0&&k>0)   { nums[i] = abs(nums[i]); k--;}
            if(min_val>nums[i]) min_val = nums[i];
            sum+=nums[i];
        }
       if(k ==0||k%2==0) return sum;
        return sum -2*(min_val);

    }
};