class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        vector<long long>sum;
        vector<long long>mul;
        long long max_element = -1;
        long long temp =0;
        for(int i=0;i<nums.size();i++){
            sum.push_back(temp);
             if(temp>max_element) max_element = temp;
            temp+=nums[i];
            
           
        }
        long long tem = 1;
        mul.push_back(1);
        for(int i = nums.size()-1;i>0;i--){
            if (nums[i] > max_element / mul.back()) {
                break; 
            }
            mul.push_back(((long long)nums[i])*mul.back());
            
          
        }
        reverse(mul.begin(),mul.end());
        temp = -1;
        int n = nums.size();
        if(mul.size()!=nums.size()) n = mul.size();
        int j = nums.size()-n;
        for(int i =0;i<n;i++){
            
            if(sum[i+j] == mul[i]) return i+j;
        }
        return temp;
    }
};