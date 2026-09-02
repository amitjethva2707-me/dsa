class Solution {
public:
int f(vector<int> &nums,int k){
    unordered_map<int,int> freq;
    int i =0;
    int ans = 0;
    int dist = 0;
    for(int j = 0;j<nums.size();j++){
        if(freq[nums[j]] == 0){
             dist++;
        }
        freq[nums[j]]++;
        while(dist>k){
            freq[nums[i]]--;
            if(freq[nums[i]]==0){
                dist--;
            }
            i++;
        }
        ans += j-i+1;
    }
    return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};