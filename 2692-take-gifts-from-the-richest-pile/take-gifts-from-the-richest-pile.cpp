class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int i=0;i<gifts.size();i++){
            pq.push(gifts[i]);
        }
        
        while(k){
            int el=pq.top();
            pq.pop();
            pq.push(floor(sqrt(el)));
            k--;
        }
        long long cnt=0;
        while(!pq.empty()) {
            cnt += pq.top();
            pq.pop();
        }
        return cnt;
    }
};