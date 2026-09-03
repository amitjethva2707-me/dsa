class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m>n) return "";
        int freq[256] = {0};
        for(char c: t){
            freq[c]++;
        }
        int left = 0, right = 0, count = 0;
        int minlen = INT_MAX;
        int start = 0;
        while(right<n){
            if(freq[s[right]]>0) count++;
            freq[s[right]]--;
            right ++;
            while(count == m){
                if(right-left<minlen){
                    minlen = right-left;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0) count--;
                left++;
            }
        }
        if(minlen == INT_MAX) return "";
        return s.substr(start,minlen);
    }
};