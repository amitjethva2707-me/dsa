class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> freq;
        for (int x : hand) {
            freq[x]++;
        }
        for (auto& pair : freq) {
            pq.push(pair.first);
        }
        while(!pq.empty()){
            int start = pq.top();
            for(int i = start;i<start+groupSize;i++){
                if(freq[i] == 0){
                    return false;
                }
                freq[i]--;
            }
            while(!pq.empty() && freq[pq.top()] == 0){
                pq.pop();
            }
        }
        return true;
    }
};