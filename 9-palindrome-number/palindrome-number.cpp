class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        int rem=0;
        long long rev=0;
        while(x!=0){
            if(x<0)return false;
            rem=x%10;
            rev=(rev*10)+rem;
            x=x/10;
        }
        return(rev==temp);
    }
};