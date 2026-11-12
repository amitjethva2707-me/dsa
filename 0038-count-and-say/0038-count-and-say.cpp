class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int k = 2;k<=n;k++){
            string ans = "";
            int count = 1;
            for(int i =0;i<s.size();i++){
                if(i+1<s.size() && s[i] == s[i+1]){
                    count++;
                } else {
                   ans += to_string(count);
                   ans += s[i];
                   count = 1;
                }
            }
           s = ans;
        }
        return s;
    }
};