// class StockSpanner {
// public:
//     vector<int>prices; stack<int>st;
//     StockSpanner() {
//         vector<int>prices; stack<int>st;
//     }
    
//     int next(int price) {
//         prices.push_back(price); int span;
//         while(!st.empty() && prices[st.top()]<=price){
//             st.pop();
//         }
//         if (st.empty()){
//              span = prices.size();
//         }else{
//              span = (prices.size() - 1) - st.top();
//         }
//         st.push(prices.size()-1);
//         return span;
//     }     
// };
class StockSpanner{
public:
    stack<pair<int,int>>st; int idx=-1;
    StockSpanner(){
        idx=-1;
    }
    int next(int price){
        int ans=0;
        idx++;
        while(!st.empty() && (st.top().first<=price)){
            st.pop();
        }
        ans= idx-(st.empty()?-1:st.top().second);
        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */