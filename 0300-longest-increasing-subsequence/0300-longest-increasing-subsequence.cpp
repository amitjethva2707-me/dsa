class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi =1;
        vector<int> dp(n,1);
        for(int i =0;i<n;i++){
            for(int p =0;p<i;p++){
                if(nums[p]<nums[i]){
                    dp[i] = max(dp[i],1+dp[p]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};