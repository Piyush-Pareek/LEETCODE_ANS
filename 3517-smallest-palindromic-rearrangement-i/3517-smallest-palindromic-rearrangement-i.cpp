class Solution {
public:
    string smallestPalindrome(string s) {
        string front = "";
        string back =  "";
        string middle ="";
        vector<int>freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            int x = freq[i]/2;
            if(freq[i]%2!=0){
                middle+=(i+'a');
            }
            while(x){
                front+=(i+'a');
                back+=(i+'a');
                x--;
            }
        }
        reverse(back.begin(),back.end());
        string ans = front+middle+back;
        return ans;
    }
};