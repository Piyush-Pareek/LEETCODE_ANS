class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k == s.size()) return "0";
        stack<char>stk;
        for(int i=0;i<s.size();i++){
          
                while(!stk.empty()&&k>0&&stk.top()-'0'>s[i]-'0'){
                     stk.pop();
                    k--;
                }
                stk.push((char)s[i]);
           
        }
       string ans ="";
       while(!stk.empty()){
        char x = stk.top();
        
        stk.pop();

        ans+=x;
       }
       reverse(ans.begin(),ans.end());

       ans =  ans.substr(0,ans.size()-k);
       while(ans.size()>1&&ans.front()=='0')ans.erase(0,1);
       return ans;
    }
};