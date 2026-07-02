class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(goal^start){   // while(start||goal)
            if((goal & 1)!= (start & 1)){
                start=start^1;
                cnt++;
            }
            goal=goal>>1;
            start=start>>1;
        }
        return cnt;
    }
};