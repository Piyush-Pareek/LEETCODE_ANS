class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>> num(n);
        int k = 0;
        int j = 0, bet_col = n - 2;
        int chance = 0;
        while (k < s.size()) {
            int i;
            if (!chance) {
                for (i = 0; i < n&&k<s.length(); i++) {
                    num[i].push_back(s[k++]);
                    if(i == n-1) j++;
                }
                chance = 1;
            } else {
                int x =1;
                while(x<=bet_col&&k<s.length()){
                for (i = 0; i < n; i++) {
                    if(i==n-1-x)
                    num[i].push_back(s[k++]);
                    else num[i].push_back(' ');
                }
                x++;
                }
                chance = 0;
            }
        }
        string ans ="";
        for(int i=0;i<n;i++){
            for(int j=0;j<num[i].size();j++){
                if(num[i][j]!=' ')
                ans+=num[i][j];
            }
        }
        return ans;
    }
};