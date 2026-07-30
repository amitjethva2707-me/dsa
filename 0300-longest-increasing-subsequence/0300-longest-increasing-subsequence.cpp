class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1,0);
        vector<int> curr(n+1,0);
        for(int i =n-1;i>=0;i--){
            for(int p = i-1;p>=-1;p--){
                int len = next[p+1];
                if(p==-1 || nums[i]>nums[p]){
                    len = max(len,1+next[i+1]);
                }
                curr[p+1] = len;
            }
            next = curr;
        }
        return next[-1+1];
    }
};