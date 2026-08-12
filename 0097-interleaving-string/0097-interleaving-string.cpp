class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, string comp, vector<int>& num1,vector<vector<int>>&dp) {
        if (comp == s3) return true;
        if (i < s1.size() && j < s2.size() && s1[i] != s3[k] && s2[j] != s3[k]) {
            return false;
        }
        if (i >= s1.size() && j < s2.size() && s2[j] != s3[k]) return false;
        if (j >= s2.size() && i < s1.size() && s1[i] != s3[k]) return false;
        if(dp[i][j]!=-1)return dp[i][j];
        if (j < s2.size() && s2[j] == s3[k]) {
            num1.push_back(-(j + 1));
            if (solve(s1, s2, s3, i, j + 1, k + 1, comp + s2[j], num1,dp)) return true;
            num1.pop_back();
        }
        if (i < s1.size() && s1[i] == s3[k]) {
            num1.push_back(i + 1);
            if (solve(s1, s2, s3, i + 1, j, k + 1, comp + s1[i], num1,dp)) return true;
            num1.pop_back();
        }
        dp[i][j] = 0;
        return false;
    } 

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<int> num1;
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        if (!solve(s1, s2, s3, 0, 0, 0, "", num1,dp)) return false;
        
        if (num1.empty()) return true;

        // Count blocks (transitions between positive and negative values)
        int count1 = 0; // number of blocks from s1 (positive)
        int count2 = 0; // number of blocks from s2 (negative)

        // Determine the type of the first block
        bool prev_is_s1 = (num1[0] > 0);
        if (prev_is_s1) count1++;
        else count2++;

        // Count transitions
        for (size_t idx = 1; idx < num1.size(); ++idx) {
            bool curr_is_s1 = (num1[idx] > 0);
            if (curr_is_s1 != prev_is_s1) {
                if (curr_is_s1) count1++;
                else count2++;
                prev_is_s1 = curr_is_s1;
            }
        }

        // Check the basic |n - m| <= 1 constraint on blocks
        if (abs(count1 - count2) <= 1) {
            return true;
        }

        // Optional: if blocks condition fails, check if splitting multi-char chunks can work
        // (i.e. maximum possible blocks if every single character is its own block)
        // count1 actual elements sum up to total characters used from s1/s2, 
        // but here we can check standard boundaries.
        return false;
    }
};
