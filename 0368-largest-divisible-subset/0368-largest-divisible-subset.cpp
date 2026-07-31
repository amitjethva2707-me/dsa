class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1) ,hash(n);
        int maxi =1;
        int lastindex = 0;
        for(int i =0;i<n;i++){
            hash[i] = i;
            for(int p =0;p<i;p++){
                if(nums[i]%nums[p] == 0 && 1+dp[p]>dp[i]){
                    dp[i] = 1+dp[p];
                    hash[i] = p;
                }
            }
        
        if(dp[i]>maxi){
            maxi = dp[i];
            lastindex = i;
        }
        }
        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;

    }
};