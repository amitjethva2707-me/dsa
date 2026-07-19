class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);
        for(int i =0;i<=amount;i++){
            if(i%coins[0] == 0){
                prev[i] = i/coins[0];
            } else {
                prev[i] = INT_MAX;
            }
        }
        for(int i =1;i<n;i++){
            for(int j =0;j<=amount;j++){
                int nottake = prev[j];
                int take = INT_MAX;
                if(coins[i]<=j && curr[j-coins[i]] !=INT_MAX){
                    take = 1+curr[j-coins[i]];
                }
                curr[j] = min(take,nottake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans>=INT_MAX) return -1;
        return ans;
    }
};