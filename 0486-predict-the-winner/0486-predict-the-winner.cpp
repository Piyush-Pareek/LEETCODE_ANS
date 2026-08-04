class Solution {
public:
bool find2(vector<int>&nums,int i,int j,int chance,int score1,int score2){
     if(i>j){
        if(score1>=score2) return true;
        return false;
    }
    bool x = find(nums,i+1,j,chance,score1,score2+nums[i]);
    bool y = find(nums,i,j-1,chance,score1,score2+nums[j]);
    if(x&&y)return true;
    return false;
}
bool find(vector<int>&nums,int i,int j,int chance,int score1,int score2){
    if(i>j){
        if(score1>=score2) return true;
        return false;
    }
    bool x = find2(nums,i+1,j,chance,score1+nums[i],score2);
    bool y = find2(nums,i,j-1,chance,score1+nums[j],score2);
    if(x||y)return true;
    return false;
}

    bool predictTheWinner(vector<int>& nums) {
       
        
        return find(nums,0,nums.size()-1,0,0,0);
    }
};