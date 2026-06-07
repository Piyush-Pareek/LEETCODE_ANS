class Solution {
public:
    bool solve(vector<int>&stones,int k,vector<vector<int>>&dp,int i,int prev){
        if(i>=stones.size()||k<0) return false;
        if(dp[i][k]!=-1)return dp[i][k];
        int l = i,r=stones.size()-1;
        int found =-1;
        int target = prev+k;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(stones[mid] == target){
                found = mid;
                r = mid-1;
            }
            else if(stones[mid]>target){
                r =mid-1;
            }else l = mid+1;
        }
        if(found == -1)return false;
        if(found == stones.size()-1) return true;
        prev = stones[found];
        bool a =solve(stones,k,dp,found+1,prev);
        bool b = solve(stones,k+1,dp,found+1,prev);
        bool c = solve(stones,k-1,dp,found+1,prev);
        if(!(a||b||c)){
            dp[i][k] = 0;
        }
        else  dp[i][k] = true;
        // cout<<"i "<<i<<" v-"<<dp[i][k]<<" k "<<k<<endl;
         return dp[i][k];
    }
    bool canCross(vector<int>& stones) {

      
        int  k = stones.size();
        vector<vector<int>>dp(stones.size(),vector<int>(k+1,-1));
        return solve(stones,1,dp,1,stones[0]);
    }
};