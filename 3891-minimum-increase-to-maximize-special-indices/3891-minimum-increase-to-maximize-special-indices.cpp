class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        auto get_cost = [&](int i){
        int  max_el = max(nums[i-1],nums[i+1]);
            return max(0,max_el-nums[i]+1);
        };
        long long min_cost = 0;
        if(n%2!=0){
            for(int i=1;i<nums.size()-1;i+=2){
                min_cost+=get_cost(i);
            }
        }
        else{
            long long curr_cost = 0;
            for(int i=2;i<nums.size()-1;i+=2){
                curr_cost+=get_cost(i);
            }
            min_cost = curr_cost;
            for(int i=1;i<nums.size()-1;i+=2){
               curr_cost+=get_cost(i);
               curr_cost-=get_cost(i+1);
               min_cost = min(curr_cost,min_cost);
            }
        }
        return min_cost;
    }
};
