class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minel = *min_element(nums.begin(),nums.end());
        int maxel= *max_element(nums.begin(),nums.end());
        while(minel!=0){
            int temp = maxel%minel;
            maxel = minel;
            minel = temp;
        }
        return maxel;
    }
};