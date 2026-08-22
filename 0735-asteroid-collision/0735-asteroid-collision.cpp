class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && abs(asteroids[s.top()]) < abs(asteroids[i]) &&
                   asteroids[s.top()] > 0 && asteroids[i] < 0) {
                s.pop();
            }
            if (!s.empty() && abs(asteroids[i]) == abs(asteroids[s.top()]) &&
                asteroids[i] < 0 && asteroids[s.top()] > 0) {
                s.pop();
            } else if (!s.empty() &&
                       abs(asteroids[i]) < abs(asteroids[s.top()]) &&
                       asteroids[i] < 0 && asteroids[s.top()] > 0) {
                continue;
            } else {
                s.push(i);
            }
        }
        while (!s.empty()) {
            ans.push_back(asteroids[s.top()]);
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};