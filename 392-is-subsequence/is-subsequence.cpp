class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0; int j=0; int cnt=0;
       while(i<s.length() && j<t.length()){
            while(j<t.length() && s[i]!=t[j]){
                j++;
            }
            if(s[i]==t[j]){
                cnt++;
            }
            i++;
            j++;
       }
        return (cnt==s.length()?true:false);
    }
};