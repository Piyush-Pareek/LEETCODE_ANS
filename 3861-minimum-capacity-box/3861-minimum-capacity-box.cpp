class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=-1;
        for(int i =0;i<capacity.size();i++){
            if(ans == -1 ){
                if(capacity[i]>=itemSize) ans = i;
            }else{
                if(capacity[i]>=itemSize&&capacity[ans]>capacity[i]) ans = i;
            }
                
        }
        return ans;
    }
};