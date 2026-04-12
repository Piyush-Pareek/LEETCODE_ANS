class Solution {
public:
static bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    if(a.second ==0&&b.second == 0){
        return a.first>b.first;
    }else{
        if(a.second == 0){
            return true;
        }else if(b.second == 0)return false;
    }
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        string s="";
        vector<pair<int,int>>num;
        for(int i=0;i<nums1.size();i++){
            num.push_back({nums1[i],nums0[i]});
        }
       
        sort(num.begin(),num.end(),cmp);
        for(int i=0;i<num.size();i++){
            string temp="";
            auto x = num[i];
            while(x.first--){
                s+='1';
            }
            while(x.second--){
                s+='0';
            }
        }
        
      long long  result =0;
      int mod = 1000000007;
      for (char c : s) {
    result = (result * 2 + (c - '0')) % mod;
}
        return (int)result;
    }
};