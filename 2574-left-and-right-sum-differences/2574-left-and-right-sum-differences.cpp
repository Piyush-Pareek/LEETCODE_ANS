class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>prefix;
        vector<int>suffix;
        int num =0; 

        for(int i=0;i<nums.size();i++){
            prefix.push_back(num);
            num+=nums[i];
        }
        num=0;
        for(int i = nums.size()-1;i>=0;i--){
            suffix.push_back(num);
            num+=nums[i];
        }
        reverse(suffix.begin(),suffix.end());
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(prefix[i]-suffix[i]));
        }
        return ans;
    }
};