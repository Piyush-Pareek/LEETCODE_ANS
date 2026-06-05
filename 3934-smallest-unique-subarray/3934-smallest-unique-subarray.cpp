class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        
        int start = 1;
        int end = nums.size();
        int base = 100003;
        int mod = 1000000007;
        int min_len=INT_MAX;
        while(start<=end){
           unordered_map<long long,int>m;
            int len = start + (end-start)/2;
            long long curr_hash=0;
            long long power =1;
            for(int i=1;i<len;i++){
                power = (power*base)%mod;
            }
            for(int i=0;i<len;i++){
                curr_hash = (curr_hash*base+nums[i])%mod;
            }
            m[curr_hash]++;
            int k=0;
            for(int i=len;i<nums.size();i++,k++){
                curr_hash = (curr_hash-nums[k]*power)%mod;
                curr_hash = (curr_hash+mod)%mod;
                curr_hash = (curr_hash*base+nums[i])%mod;
                m[curr_hash]++;
            }
            int flag = 0;
            for(auto x:m){
                if(x.second == 1){
                    min_len = len;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                start = len+1;
            }else end = len-1;
        }
        return min_len;
    }
};