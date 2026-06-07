class Solution {
public:
struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        
        // Combine the two hashes (using a simple bitwise shift and XOR to minimize collisions)
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};
    bool solve(vector<int>&stones,int k,unordered_map<pair<int,int>,int,PairHash>&dp,int i,int prev,int temp){
        if(i>=stones.size()||k<=0||k>temp) return false;
        cout<<k<<endl;
        if(dp.find({i,k-1})!=dp.end())return dp[{i,k-1}];
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
        bool a =solve(stones,k,dp,found+1,prev,temp);
        bool b = solve(stones,k+1,dp,found+1,prev,temp);
        bool c = solve(stones,k-1,dp,found+1,prev,temp);
        if(!(a||b||c)){
            dp[{i,k-1}] = 0;
        }
        else  dp[{i,k-1}] = 1;
        // cout<<"i "<<i<<" v-"<<dp[i][k]<<" k "<<k<<endl;
         return dp[{i,k-1}];
    }
    bool canCross(vector<int>& stones) {

        int min_val = stones[0],max_val = stones[0];
        for(int i =1;i<stones.size();i++){
            min_val = min(stones[i],min_val);
            max_val = max(stones[i],max_val);
        }
        int  k = max_val-min_val;
        // vector<vector<int>>dp(stones.size(),vector<int>(k,-1));
        unordered_map<pair<int,int>,int,PairHash>dp;
        // m[0][k] = 0;
        return solve(stones,1,dp,1,stones[0],k);
    }
};