class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
          int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= m; i++) {
            prev[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        return n-prev[m];
    }
};