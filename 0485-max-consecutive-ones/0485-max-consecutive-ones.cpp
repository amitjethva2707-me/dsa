class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0) return 0;
        int count =0;
        int maxi = 0;
        for(int j =0;j<nums.size();j++){
            if(nums[j]== 1){
                count++;
            maxi = max(maxi,count);
            } else{
                count = 0;
            }
        }
        return maxi;
    }
};