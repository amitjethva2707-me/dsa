class Solution {
public:
   bool f(int i,vector<string>& wordDict,string &s,vector<int> &dp){
    if(i == s.size()){
        return true;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    for(string word : wordDict){
        if(i+word.length()<=s.length() && 
            s.substr(i,word.length())==word){
                if(f(i+word.length(),wordDict,s,dp)){
                    return dp[i] = true;
                }
            }
    }
    return dp[i]= false;
   }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        return f(0,wordDict,s,dp);
    }
};