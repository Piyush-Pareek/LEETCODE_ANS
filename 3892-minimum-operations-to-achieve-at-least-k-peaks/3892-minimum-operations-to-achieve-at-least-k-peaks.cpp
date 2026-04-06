class Solution {
public:
    int choose(vector<vector<int>>&memo,vector<int>&cost,int i,int j,int k){
        
        if(i>j&&k!=0) return 1e9;
        if(k<=0 ) return 0 ;
        if(memo[i][k]!=-1){
            return memo[i][k];
        }
        // take 
        int a = choose(memo,cost,i+2,j,k-1)+cost[i];
        // leave
        int b = choose(memo,cost,i+1,j,k);
    return memo[i][k] = min(a,b);
    }
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if(k*2>n) return -1;
        vector<vector<int>>memo(n,vector<int>(k+1,-1));
        vector<int>cost(n);
        for(int i=0;i<n;i++){
            if(i == 0){
                 cost[i] = max(nums[n-1],nums[i+1])-nums[i]+1;
            }else if(i == n-1){
                 cost[i] = max(nums[i-1],nums[0])-nums[i]+1;
            }else{
                cost[i] = max(nums[i-1],nums[i+1])-nums[i]+1;
            }
            if(cost[i]<0) cost[i] = 0;
        }// circular array so 1 to n-1 then 2 to n-2 +0 
        int a =  choose(memo,cost,1,n-1,k);
       memo.assign(n,vector<int>(k,-1));
        int b =  choose(memo,cost,2,n-2,k-1)+cost[0];
        return min(a,b);
        
    }
};