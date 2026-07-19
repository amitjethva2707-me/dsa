class Solution {
public:
    int maxDepth(string s) {
        int maxi =0;
        int depth =0;
        for(char x : s){
            if(x == '('){
                depth++;
                maxi = max(maxi,depth);
            } else if(x == ')'){
                depth--;
            }
        }
        return maxi;
    }
};