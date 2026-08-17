class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }
        while(k){
            int el=pq.top();
            pq.pop();
            pq.push(el-(floor(el/2)));
            k--;
        }
        int stones=0;
        while(!pq.empty()){
            stones+=pq.top();
            pq.pop();
        }
        return stones;
    }
};