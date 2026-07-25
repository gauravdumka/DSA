class StockSpanner {
public:
    vector<int>prices; stack<int>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        prices.push_back(price); int span;
        while(!st.empty() && prices[st.top()]<=price){
            st.pop();
        }
        if (st.empty()){
             span = prices.size();
        }else{
             span = (prices.size() - 1) - st.top();
        }
        st.push(prices.size()-1);
        return span;
    }     
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */