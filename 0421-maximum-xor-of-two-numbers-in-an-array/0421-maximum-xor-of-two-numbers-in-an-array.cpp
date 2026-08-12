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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int x : nums){
            trie.insert(x);
        }
        int maxi = 0;
        for(int x : nums){
            maxi= max(maxi,trie.getmax(x));
        }
        return maxi;
    }
};