class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>=intervals[i+1][0]){
                intervals[i+1][0] = min(intervals[i][0],intervals[i+1][0]);
                intervals[i+1][1] = max(intervals[i][1],intervals[i+1][1]);
                intervals[i][0] =-1;
                intervals[i][1] =-1;
            }
        }
        vector<vector<int>>ans;
        for(int i =0;i<intervals.size();i++){
            if(intervals[i][0]!=-1)ans.push_back(intervals[i]);
        }
        return ans;
    }
};