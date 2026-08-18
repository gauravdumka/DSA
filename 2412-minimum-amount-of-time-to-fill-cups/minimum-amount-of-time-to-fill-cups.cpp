class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq;
        for(int i=0;i<amount.size();i++){
            pq.push(amount[i]);
        }
        int cnt=0;
        while(pq.top()!=0){
            int c1=pq.top();
            pq.pop();
            if(pq.top()!=0){
                int c2=pq.top();
                pq.pop();
                cnt++;
                pq.push(c1-1);
                pq.push(c2-1);
            }else{
                cnt++;
                pq.push(c1-1);
            }
        }
        return cnt;

    }
};