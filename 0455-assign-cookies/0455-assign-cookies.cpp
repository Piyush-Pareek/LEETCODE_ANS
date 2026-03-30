class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // if(s.size()==0) return 0;
        sort(g.begin(),g.end(),greater<int>());
        sort(s.begin(),s.end(),greater<int>());
        int count = 0,j=0;
        for(int i=0;i<g.size();i++){
            if(j<s.size()&&g[i]<=s[j]) {count++;j++;}
        }
        return count;
    }
};