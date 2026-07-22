class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>out;
        long long x=1;
        for(int i=0;i<nums.size();i++){
            x*=nums[i];
            out.push_back(x);
        }
        x = 1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i == 0){
                out[i]=x;
            }else
            out[i]= out[i-1]*x;
            x*=nums[i];
        }
    return out;
    }
};