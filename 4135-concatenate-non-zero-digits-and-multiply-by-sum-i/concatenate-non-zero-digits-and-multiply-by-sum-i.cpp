class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long temp=0;
        while(n){
            if((n%10)!=0){
                sum=sum+(n%10);
                temp=temp*10;
                temp=temp+(n%10);
            }
            n=n/10;
        };
        long long x=0;
        while(temp){
            x=x*10;
            x=x+(temp%10);
            temp=temp/10;
        }
        return(x*sum);
    }
};