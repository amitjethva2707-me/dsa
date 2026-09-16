class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0,currend=0,maxreach = 0;
        for(int i =0;i<nums.size()-1;i++){
            maxreach = max(maxreach,i+nums[i]);
            if(i==currend){
                jumps++;
                currend= maxreach;
            }
        }
        return jumps;
    }
};