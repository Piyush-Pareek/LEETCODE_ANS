class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minel = *min_element(nums.begin(),nums.end());
        int maxel= *max_element(nums.begin(),nums.end());
        return gcd(minel,maxel);
    }
};