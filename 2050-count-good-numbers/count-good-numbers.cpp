class Solution {
public:
    const int MOD=1e9+7;
    int mypow(int x, long long n){
        long long result=1;
        long long half=1;
        if(n==0)return 1;
        if(n%2==1){
            result=(result*x)%MOD;
            n=n-1;
        }
        // half=mypow(x,n/2);
        // result=result*(half*half)%MOD;
        // below method is also correct
        result=result*mypow(1LL*x*x%MOD,n/2)% MOD;
        return result%MOD;
    }
    int countGoodNumbers(long long n) {
        return (long long)mypow(5,(n+1)/2)*mypow(4,n/2)%MOD;

    }
};