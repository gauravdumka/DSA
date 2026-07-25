class Solution {
public:
    int maxProduct(int n) {
        int maxi=0; int smaxi=0;
        while(n){
            int rem=n%10;
            n=n/10;
            if (rem > maxi) {
                smaxi = maxi;
                maxi = rem;
            }
            else if (rem > smaxi) {
                smaxi = rem;
            }
        }
        return maxi*smaxi;
    }
};