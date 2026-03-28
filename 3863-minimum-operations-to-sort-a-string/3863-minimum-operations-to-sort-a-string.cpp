class Solution {
public:
    int minOperations(string s) {
        string temp = s;
        sort(temp.begin(),temp.end());
        if(temp == s) return 0;
        if(s.size()<=2) return -1;
        string si = s;
        sort(si.begin(),si.end()-1);
        if(temp == si) return 1;
        si = s;
        sort(si.begin()+1,si.end());
         if(temp == si) return 1;
        if(s[0] == temp.back()&&s[s.size()-1] == temp[0]&&temp.back()!=temp[temp.size()-2]&&temp[0]!=temp[1]) return 3;
        return 2;
    }
};