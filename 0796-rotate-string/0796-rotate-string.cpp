class Solution {
public:
    void leftshift(string& s,int i){
        string temp = s.substr(i,s.length()-i);
        string x = s.substr(0,i);
        s = temp+x;
         }
    bool rotateString(string s, string goal) {
        string temp=s;
        for(int i =0;i<s.size();i++){
            leftshift(temp,1);
            if(temp == goal) return true;
        }
        return false;
    }
};