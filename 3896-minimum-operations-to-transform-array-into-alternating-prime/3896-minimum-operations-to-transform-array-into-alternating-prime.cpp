class Solution {
public:
    bool isprime(int n ){
        if(n<=1) return false;
        if(n==2) return true;
        if(n%2==0) return false;

        for(int i=3;i*i<=(n);i+=2){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int count = 0;
         for(int i=0;i<nums.size();i++){
             if(i%2==0&&!isprime(nums[i])){
                 int x = nums[i];
                 while(!isprime(x++))count++;
             }
             else if(i%2!=0&&isprime(nums[i])) {
                 
                 if(nums[i] == 2) count+=2;
                 else 
                 count++;
         }   }
        
        return count;
    }
};