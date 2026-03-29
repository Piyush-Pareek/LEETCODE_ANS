class Solution {
public:
    bool check(vector<int>&nums,int k,int j){
        int count = 0;
        for(int i=j;i<j+k-1;i++){
            if(nums[i]>nums[i+1]) count++;
        }
        if(nums[k+j-1] >nums[j]) count++;
        if(count>1)return false;
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int sum = 0;
        for(int i=1;i<=nums.size();i++){
            int maxPrev = -1;
            bool hayana = true;
            
            
            if(nums.size()%i!=0) continue;
            for(int j =0;j<i;j++){
                if(maxPrev<nums[j]) maxPrev = nums[j];
            }
            for(int j =0;j<nums.size();j+=i)
            {
                int max_curr = -1;
                 for(int k =j;k<j+i;k++){
                    if(maxPrev>nums[k]&&j!=0) {
                        hayana = false;
                        break;
                    }
                     if(max_curr<nums[k]) max_curr = nums[k];
                }
                bool isPossible = check(nums,i,j);
                if(!isPossible){
                    hayana = false;
                    break;
                }
                maxPrev = max_curr;
                if(!hayana) break;
            }
            if(hayana)
                sum+=i;
            
        }
        return sum;
    }
};