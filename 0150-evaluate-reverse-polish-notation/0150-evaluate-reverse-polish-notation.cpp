class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {

            // Number
            if (tokens[i] != "+" &&
                tokens[i] != "-" &&
                tokens[i] != "*" &&
                tokens[i] != "/") {

                s.push(stoi(tokens[i]));
            }

            // Operator
            else {

                int first = s.top();
                s.pop();

                int second = s.top();
                s.pop();

                if (tokens[i] == "+") {
                    s.push(second + first);
                }

                else if (tokens[i] == "-") {
                    s.push(second - first);
                }

                else if (tokens[i] == "*") {
                    s.push(second * first);
                }

                else if (tokens[i] == "/") {
                    s.push(second / first);
                }
            }
        }

        return s.top();
    }
};