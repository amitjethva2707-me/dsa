class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int len = 0,maxas = INT_MIN,maxi = INT_MIN,sum;
            for(int j = i;j<min(i+k,n);j++){
                len++;
                maxi = max(maxi,arr[j]);
                sum = (len*maxi)+dp[j+1];
                maxas = max(maxas,sum); 
            }
            dp[i] = maxas;
        }
        return dp[0];
    }
};