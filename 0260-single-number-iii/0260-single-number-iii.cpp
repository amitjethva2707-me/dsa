class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int num : nums) {
            x ^= num;
        }

        // Use unsigned int to safely isolate the rightmost set bit
        unsigned int bit = (unsigned int)x & -(unsigned int)x;

        int a = 0, b = 0;
        for (int num : nums) {
            if (num & bit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }

        return {a, b};
    }
};