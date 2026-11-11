class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0,pairs = 0;
        for(char  ch : s){
            if(ch == '('){
                open++;
            } else if(open>0){
                open--;
                pairs++;
            }
        }
        return s.length() - 2*pairs;
    }
};