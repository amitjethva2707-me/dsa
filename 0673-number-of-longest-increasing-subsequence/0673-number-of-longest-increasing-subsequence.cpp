class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi =1;
         vector<int> dp(n,1);
         vector<int> cnt(n,1);
        for(int i =0;i<n;i++){
            for(int p =0;p<i;p++){
                if(nums[p]<nums[i] && dp[i]<dp[p]+1){
                  dp[i] = dp[p]+1;
                  cnt[i] = cnt[p];
                } else if(nums[i]>nums[p] && dp[p]+1==dp[i]){
                    cnt[i]+=cnt[p];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int ans =0;
        for(int i =0;i<n;i++){
            if(maxi == dp[i]){
               ans+=cnt[i];
            }
        }
        return ans;
    }
};