class Solution {
public:
    bool isBalanced(string num) {
        int i=0; int j=1; long long even=0; long long odd=0; int n=num.length();
        while(j<n){
            even+=num[i]-'0';
            odd+=num[j]-'0';
            i=i+2;
            j+=2;
        }
        if(n%2==1){
            even+=num[n-1]-'0';
        }
        return (even==odd?true:false);
    }
};