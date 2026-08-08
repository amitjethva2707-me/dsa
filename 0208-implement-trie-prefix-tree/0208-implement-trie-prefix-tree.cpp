struct Node{
    Node* links[26];
    bool flag = false;
      Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }
    bool containkey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setend(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    //tc= 0(n)
    void insert(string word) {
        Node* node = root;
        for(int i =0;i<word.length();i++){
            if(!node->containkey(word[i])){ // if node is not exist;
                node->put(word[i],new Node());
            } // moves to refernce trie;
           node = node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) { // tc = O(n)
        Node* node = root;
        for(int i =0;i<word.length();i++){
            if(!node->containkey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isend();
    }
    
    bool startsWith(string prefix) { // O(n)
        Node* node = root;
        for(int i =0;i<prefix.length();i++){
            if(!node->containkey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */