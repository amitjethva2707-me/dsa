class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int depth =0;
        for(char x : s){
            if(x == '('){
                if(depth>0){
                    ans +=x;
                }
                depth++;
            } else {
                depth--;
                if(depth>0){
                    ans+=x;
                }
            }
        }
        return ans;
    }
};