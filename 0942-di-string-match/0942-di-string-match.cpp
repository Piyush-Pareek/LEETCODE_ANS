class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
      int high=n;
      int low=0;
      vector<int >ans;
      for(int i=0;i<s.size();i++){
        if(s[i]=='I'){
       ans.push_back(low);
       low++;
        }
        else{
            ans.push_back(high);
            high--;
        }
      } 
      ans.push_back(low);
      return ans; 
    }
};