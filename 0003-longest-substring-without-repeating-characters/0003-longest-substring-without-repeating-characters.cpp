class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int left = 0;
        int maxlen = 0;
        for(int right = 0;right<s.size();right++){
            if(last[s[right]] >= left){
                left = last[s[right]]+1;
            }
            last[s[right]] = right;
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};