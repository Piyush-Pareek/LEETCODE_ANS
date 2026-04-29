class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>temp;
        for(auto x:grid){
            temp.insert(temp.end(),x.begin(),x.end());
        }
        int y  = temp.size()/2;
        nth_element(temp.begin(),temp.begin()+y,temp.end());
        int n = temp[y]; 
        int score = 0;
    for(int i =0;i<temp.size();i++){
        if(abs(temp[i]-n)%x == 0){
            score+=(abs(temp[i]-n)/x);
        }else{
            return -1;
        }
    }
    return score;
    }
};