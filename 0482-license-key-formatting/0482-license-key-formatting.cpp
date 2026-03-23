class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int dash=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='-') dash++;
            else
                if(s[i]>='a')
            temp+=s[i]-32;
            else 
                temp+=s[i];
        }
        if(temp.size()==0) return "";
        int x = s.size()-dash;
        x = x%k;
        if(x == 0) x=k;
        int i =0;
        string ans="";
        while(x--)ans+=temp[i++];
       
        int count = 0;
        
        for( ;i<temp.size();i++){
            if(count%k==0) {ans+="-"; count =0;}
            count++;
            ans+=temp[i];
        }
        return ans;
    }
};