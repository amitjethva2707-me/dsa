class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // 1. Changed to unsigned int to bypass signed integer overflow crashes
        vector<unsigned int> prev(amount + 1, 0), curr(amount + 1, 0);

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                prev[j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                unsigned int nottake = prev[j];
                unsigned int take = 0;

                if (coins[i] <= j)
                    take = curr[j - coins[i]];

                curr[j] = take + nottake;
            }
            prev = curr;
        }

        // 2. Returns naturally as int
        return prev[amount];
    }
};
