class Solution {
public:
    int reverseBits(int n) {
        int i =0;
        int ans=0;
        while(i<32){
            if((n&1)==1){
                ans=ans<<1;
                ans=ans|1;
            }else{
                ans=ans<<1;
            }
            n=n>>1;
            i++;
        }
        return ans;
    }
};