class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        string x="";
        int len = nums.size();
        while(len){
            x+=((len%2)+'0');
            len/=2;
        }
        int ans = pow(2,x.size());
    if(nums.size() <= 2){
        return nums.size();
    }
        return ans;
    }
};