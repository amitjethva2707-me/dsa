class Node{
public:
    string url;
    Node* next;
    Node* prev;
    Node(string url){
        this->url = url;
        prev = NULL;
        next = NULL;
    }
};
class BrowserHistory {
public:
Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        curr->next = NULL;
        Node* node = new Node(url);
        curr->next = node;
        node->prev = curr;
        curr = node;
        
    }
    
    string back(int steps) {
        while(steps-- && curr->prev){
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps--  && curr->next){
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */