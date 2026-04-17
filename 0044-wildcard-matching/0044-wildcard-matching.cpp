class Solution {
public:
    // Added DP Table: memo[a][b][star]. 
    // -1 = uncalculated, 0 = false, 1 = true
    bool check(string& s, string& p, int a, int b, int star, vector<vector<vector<int>>>& memo) {
        
        // FIX 1: Trailing Stars
        // If 'a' finishes first, we must check if the rest of 'p' is just stars.
        if (a == s.length() && b == p.length()) return true;
        if (a == s.length()) {
            for (int i = b; i < p.length(); i++) {
                if (p[i] != '*') return false;
            }
            return true;
        }
        if (b == p.length()) return false;

        // FIX 3: DP Check - If we already calculated this exact state, return it!
        if (memo[a][b][star] != -1) return memo[a][b][star] == 1;

        // We save the original 'a' and 'b' so we can save to our memo table at the end, 
        // since your while loop modifies 'a' and 'b' directly.
        int orig_a = a;
        int orig_b = b;
        bool ans = false;

        // Your exact Case 2: Star or Non-Star
        if (star == 0) {
            if (check(s, p, a + 1, b, 0, memo)) ans = true;
            else if (check(s, p, a, b + 1, 1, memo)) ans = true;
        } else {
            // Your exact While Loop logic
            while (a < s.length() && b < p.length()) {
                if (p[b] == '?') {
                    a++; b++;
                }
                else if (p[b] == '*') {
                    // FIX 2: Infinite Loop fixed!
                    // We hit a star, so we transition to "star mode" (0) and STOP the loop.
                    ans = check(s, p, a, b, 0, memo);
                    
                    // We must save and return immediately so the loop doesn't get stuck!
                    memo[orig_a][orig_b][star] = ans ? 1 : 0;
                    return ans;
                }
                else {
                    if (s[a++] != p[b++]) {
                        memo[orig_a][orig_b][star] = 0;
                        return false;
                    }
                }
            }
            
            // FIX 1 (Again): If the while loop finishes, check trailing stars one last time
            if (a == s.length() && b == p.length()) ans = true;
            else if (a == s.length()) {
                ans = true;
                for (int i = b; i < p.length(); i++) {
                    if (p[i] != '*') ans = false;
                }
            }
        }

        // FIX 3: Save our final answer to the DP table before returning
        memo[orig_a][orig_b][star] = ans ? 1 : 0;
        return ans;
    }

    bool isMatch(string s, string p) {
        // Initialize our 3D Memoization Table with -1
        // Size: [length of s + 1] x [length of p + 1] x [2 states for star mode]
        vector<vector<vector<int>>> memo(s.length() + 1, vector<vector<int>>(p.length() + 1, vector<int>(2, -1)));
        
        // Fixed the syntax error here. 
        // We start in star mode (0) if the first char is a '*', otherwise non-star mode (1)
        int start_mode = (p.length() > 0 && p[0] == '*') ? 0 : 1;
        
        return check(s, p, 0, 0, start_mode, memo);
    }
};