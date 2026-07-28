class Solution {
public:
    string shortestPalindrome(string s) {
     string rev=s;
        reverse(rev.begin(),rev.end());
        for(int i=0;i<s.length();i++){
            // if(rev.substr(i)==s.substr(0,s.length()-i)){
            if(!memcmp(s.c_str()+0, rev.c_str()+i,s.length()-i)){
                return(rev.substr(0,i)+s);
            }
        }
        return rev+s;
    // above code has tc=O(n^2)   
    }
};