class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k+1, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> cur(2*k+1, 0);
            for (int trasaction = 0; trasaction < 2*k; trasaction++) {
                if (trasaction % 2 == 0) {
                    cur[trasaction] =
                        max(-prices[i] + after[trasaction + 1],
                            after[trasaction]);
                } else {
                    cur[trasaction] =
                        max(prices[i] + after[trasaction + 1],
                            after[trasaction]);
                }
            }
            after = cur;
        }
        return after[0];
    }
};
    