class Solution {
public:
    double myPow(double x, int n) {
        // double ans =1;
        // long long m=n;
        // if(m<0) m=-1*m;
        // while(m!=0){
        //     if(m%2==1){
        //         ans=ans*x;
        //         m=m-1;
        //     }else{
        //         x=x*x;
        //         m=m/2;
        //     }
            
        // }
        // if(n<0)return 1/ans;
        // return ans;
        double result=1;
        long long m=n;
        if(m<0)m=-1*m;
        if(m==0)return 1;
        if(m%2==1){
            result=result*x;
        }
        result=result*myPow(x*x,m/2);
        if(n<0){
            return 1/result;
        }
        return result;
    }
};