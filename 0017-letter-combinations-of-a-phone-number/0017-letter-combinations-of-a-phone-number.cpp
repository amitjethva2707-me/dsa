class Solution {
public:
  vector<string> ans;
   void helper(string &digits,int idx,string &curr,vector<string> &mp){
    if(idx == digits.size()){
        ans.push_back(curr);
        return;
    }
    string letters = mp[digits[idx]-'0'];
    for(char ch:letters){
        curr.push_back(ch);
        helper(digits,idx+1,curr,mp);
        curr.pop_back();
    }
   }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return{};
        }
        vector<string> mp {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        string curr= "";
        helper(digits,0,curr,mp);
        return ans;
    }
};