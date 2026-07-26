class Solution {
public:
    bool isMatch(string s, string p) {

        int n = p.size();
        int m = s.size();

        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        // Base Case
        prev[0] = true;

        // Empty pattern vs non-empty string
        for (int j = 1; j <= m; j++) {
            prev[j] = false;
        }

        for (int i = 1; i <= n; i++) {

            // Check if p[0...i-1] consists only of '*'
            bool allStars = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }

            cur[0] = allStars;

            for (int j = 1; j <= m; j++) {

                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    cur[j] = prev[j - 1];
                }
                else if (p[i - 1] == '*') {
                    cur[j] = prev[j] || cur[j - 1];
                }
                else {
                    cur[j] = false;
                }
            }

            prev = cur;
        }

        return prev[m];
    }
};