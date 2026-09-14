class Solution {
public:
    bool checkValidString(string s) {

        int open = 0;
        int star = 0;

        // Left to right
        for (char ch : s) {

            if (ch == '(') {
                open++;
            }
            else if (ch == '*') {
                star++;
            }
            else {
                if (open > 0)
                    open--;
                else if (star > 0)
                    star--;
                else
                    return false;
            }
        }

        // Remaining '(' must be matched by '*' AFTER them
        open = 0;
        star = 0;

        // Right to left
        for (int i = s.size() - 1; i >= 0; i--) {

            if (s[i] == ')') {
                open++;
            }
            else if (s[i] == '*') {
                star++;
            }
            else {
                if (open > 0)
                    open--;
                else if (star > 0)
                    star--;
                else
                    return false;
            }
        }

        return true;
    }
};