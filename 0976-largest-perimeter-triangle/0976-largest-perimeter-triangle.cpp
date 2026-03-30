class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max_peri = 0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]+nums[i+1]>nums[i+2]) {
                if(max_peri< nums[i]+nums[i+1]+nums[i+2])max_peri=nums[i+0]+nums[i+1]+nums[i+2];
            }
        }
        return max_peri;
    }
};