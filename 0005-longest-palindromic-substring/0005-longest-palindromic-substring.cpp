class Solution {
public:
   int expand(string &s,int left,int right){
    while(left >= 0 && right < s.size() && s[left] == s[right]){
        right++;
        left--;
    }
    return right - left-1;
   }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0;i<s.size();i++){
            int len1 = expand(s,i,i);
            int len2 = expand(s,i,i+1);
            int len  = max(len1,len2);
            if(len> end - start+1){
                 start = i - (len-1)/2;
                 end = i+len/2;
            }
        }
        return s.substr(start,end-start+1);
    }
};