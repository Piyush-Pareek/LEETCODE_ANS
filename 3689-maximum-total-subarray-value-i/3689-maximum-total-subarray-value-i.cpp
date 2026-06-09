class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto min_it = min_element(nums.begin(),nums.end());
        auto max_it = max_element(nums.begin(),nums.end());
        return (long long)k*(*(max_it)-*(min_it));
            }
};