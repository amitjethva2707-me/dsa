class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()==1 || fruits.size()==2) return fruits.size();
          unordered_map<int, int> freq;
    int left = 0, ans = 0;

    for (int right = 0; right < fruits.size(); right++) {
        freq[fruits[right]]++;   // add fruit to window

        while (freq.size() > 2) {   // third fruit aavi gayi
            freq[fruits[left]]--;
            if (freq[fruits[left]] == 0)
                freq.erase(fruits[left]);
            left++;   // shrink window
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
    }
};