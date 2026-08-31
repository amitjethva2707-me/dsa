class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }

    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int left = 0;
        int sum = 0;
        int cnt = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum > k) {
                sum -= nums[left];
                left++;
            }

            cnt += right - left + 1;
        }

        return cnt;
    }
};