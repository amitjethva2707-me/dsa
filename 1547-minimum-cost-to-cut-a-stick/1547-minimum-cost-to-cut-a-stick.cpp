class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int n1 = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(n1+2,vector<int>(n1+2,0));
        for(int i= n1;i>=1;i--){
            for(int j = 1;j<=n1;j++){
                if(i>j) continue;
                int mini = INT_MAX;
                for(int ind = i;ind<=j;ind++){
                  int cost = cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                  mini = min(mini,cost);
                }
                dp[i][j]= mini;
            }
        }
        return dp[1][n1];
    }
};