
class Solution {
public:
    unordered_map<string, int> mpp;

    vector<vector<string>> ans;

    string b;

    int sz;

private:
    void dfs(string word, vector<string>& seq) {

        if (word == b) {

            reverse(seq.begin(), seq.end());

            ans.push_back(seq);

            reverse(seq.begin(), seq.end());

            return;
        }

        int steps = mpp[word];

        for (int i = 0; i < sz; i++) {

            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++) {

                word[i] = ch;

                if (mpp.find(word) != mpp.end() &&
                    mpp[word] + 1 == steps) {

                    seq.push_back(word);

                    dfs(word, seq);

                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        // Reset for every test case
        mpp.clear();
        ans.clear();

        b = beginWord;
        sz = beginWord.size();

        unordered_set<string> st(
            wordList.begin(),
            wordList.end()
        );

        if (st.find(endWord) == st.end()) {
            return ans;
        }

        queue<string> q;

        q.push(beginWord);

        mpp[beginWord] = 0;

        st.erase(beginWord);

        // BFS: Find shortest distance of every word
        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int steps = mpp[word];

            for (int i = 0; i < sz; i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    word[i] = ch;

                    if (st.find(word) != st.end()) {

                        q.push(word);

                        mpp[word] = steps + 1;

                        st.erase(word);
                    }
                }

                word[i] = original;
            }
        }

        // If endWord is unreachable
        if (mpp.find(endWord) == mpp.end()) {
            return ans;
        }

        // DFS: Generate all shortest paths
        vector<string> seq;

        seq.push_back(endWord);

        dfs(endWord, seq);

        return ans;
    }
};
