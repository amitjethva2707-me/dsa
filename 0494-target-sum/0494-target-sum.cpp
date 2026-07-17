class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = 0;
        for(int x : nums){
            totalsum  += x;

        }
        if(totalsum-target < 0 || (totalsum-target)%2!=0){
            return 0;
        }
        int tar = (totalsum-target)/2;
        int n = nums.size();
        vector<int> prev(tar+1,0) , curr(tar+1,0);
        if(nums[0] == 0){
            prev[0] =2;
        }  else{
            prev[0] =1;
        }
        if(nums[0] != 0 && nums[0]<= tar){
            prev[nums[0]] = 1;
        }
        for(int i = 1 ;i<n;i++){
            fill(curr.begin(),curr.end(),0);
            for(int s = 0;s<=tar;s++){
                int notpick = prev[s];
                int pick =0;
                if(nums[i]<=s){
                    pick = prev[s-nums[i]];
                }
                curr[s] = pick+notpick;
            }
            prev = curr;
        }

        return prev[tar];
    }
};