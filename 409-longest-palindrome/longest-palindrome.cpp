class Solution {
public:
    int longestPalindrome(string s) {
        int ans=0;
        int upper[26]={0};
        int lower[26]={0};
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z'){
                lower[s[i]-'a']++;
            }
            else{
                upper[s[i]-'A']++;
            }
        }
        for(int i=0; i<26;i++){
            if(lower[i]%2==0){
                ans=ans+lower[i];
            }
            if(lower[i]%2!=0){
                ans=ans+(lower[i]-1);
            }
            if(upper[i]%2==0){
                ans=ans+upper[i];
            }
            if(upper[i]%2!=0){
                ans=ans+(upper[i]-1);
            }
        }
        int n=s.size();
        if(n==ans){
            return ans;
        }
        else{
            return ans+1;
        }
    }
};