class Solution {
public:
    int minDistance(string text1, string text2) {
          int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= m; i++) {
            prev[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        int delete1 = n-prev[m];
        int delete2 = m-prev[m];
        return delete1+ delete2;
    }
};