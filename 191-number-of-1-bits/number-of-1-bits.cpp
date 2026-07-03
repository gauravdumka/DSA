class Solution {
public:
    int hammingWeight(int n) {
        int cnt;
        while(n!=0){
            if(n&1==1){
                cnt+=1;
            }
            n=(n>>1);
        }
        return cnt;
    }
};