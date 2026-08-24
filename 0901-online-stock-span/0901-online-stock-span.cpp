class StockSpanner {
public:
     stack<pair<int,int>> st;
     int index;
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        int span;
        if(st.empty()){
            span = index +1;
        } else {
            span = index-st.top().second;
        }
        st.push({price,index});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */