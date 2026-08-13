struct Node{
    Node* links[2];
    bool containkey(int bit){ // "Does this character already have a node connected to it?"
        return (links[bit] != NULL);
    }
    void put(int bit,Node* node){ // It creates/connects a link for a character.
        links[bit]=node;
    }
    Node* get(int bit){ //It returns the node connected to that character.
        return links[bit];
    }
    
};
class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    //tc= 0(n)
    void insert(int num) {
        Node* node = root;
        for(int i =31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->containkey(bit)){ // if node is not exist;
                node->put(bit,new Node());
            } // moves to refernce trie;
           node = node->get(bit);
        }
    }
    int getmax(int x){
        Node* node = root;
        int maxnum =0;
        for(int i =31;i>=0;i--){
            int bit = (x>>i)&1;
            if(node->containkey(1-bit)){
                maxnum = maxnum|(1<<i);
                node = node->get(1-bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxnum;
    }

};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> oq;
        int q =  queries.size();
        for(int i =0;i<q;i++){//O(q)
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        // qlogq
        sort(oq.begin(),oq.end());
        vector<int> ans(q,0);
        int ind = 0;
        int n = nums.size();
        Trie trie;
        //0(q*32+n*32)
        for(int i =0;i<q;i++){
            int ai= oq[i].first;
            int xi = oq[i].second.first;
            int qind = oq[i].second.second;
            while(ind<n && nums[ind]<=ai){
                  trie.insert(nums[ind]);
                  ind++;
            }
            if(ind == 0){
                ans[qind] = -1;
            }else{
                ans[qind] = trie.getmax(xi);
            }

        }
        return ans;

    }
};