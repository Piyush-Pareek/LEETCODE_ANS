class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int>ans(s.length()+1);
        int count = s.length();
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1&&s[i]=='D'){ans[i]=count--;ans[i+1] = count--;}
            else if(s[i]== 'D'){
                ans[i] = count--;
            } 
        }
        count = 0;
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1&&s[i]=='I'){ans[i]=count++;ans[i+1] = count++;}
             else if(s[i]== 'I'){
                ans[i] = count++;
            } 
        }
        return ans;
    }
};