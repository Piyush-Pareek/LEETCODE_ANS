class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, j = k-1;
       for(int l = 0; j<=s.size()-1;l++){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i = i+k*2;
            j = j+k*2;
       }
        return s;

    }
};