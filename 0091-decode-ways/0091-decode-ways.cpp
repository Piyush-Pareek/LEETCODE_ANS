class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1);
        dp[s.length()] = 1;
        if (s[s.length() - 1] != '0')
            dp[s.length() - 1] = 1;
        else
            dp[s.length() - 1] = 0;
        if (s[0] == '0')
            return 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i + 1] == '0' && (s[i] > '2' || s[i] == '0'))
                return 0;
        }

        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] > '2') {
                dp[i] = dp[i + 1];
            } else if (s[i] == '0') {
                dp[i] = 0;
            } else {
                if ((s[i] == '1' || s[i] == '2') &&
                    (s[i] == '1' || s[i + 1] < '7')) {
                    dp[i] = dp[i + 1] + dp[i + 2];
                } else {
                    dp[i] = dp[i + 1];
                }
            }
        }
        return dp[0];
    }
};