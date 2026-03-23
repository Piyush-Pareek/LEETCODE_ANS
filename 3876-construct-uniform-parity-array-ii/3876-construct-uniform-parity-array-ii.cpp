class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
    
        // even - odd odd 
        // odd - even - odd 
        // smallest even > small odd - ,odd
        // small odd > small even - nothing 
        int smaleven = INT_MAX;
        int smalodd = INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                if(smaleven>nums1[i]) smaleven = nums1[i];
            }
            else  if(nums1[i]%2!=0){
                if(smalodd>nums1[i]) smalodd = nums1[i];
            }
        }
        if(smalodd == INT_MAX||smaleven==INT_MAX) return true;
        if(smalodd>smaleven) return false;
        return true;
    }
};