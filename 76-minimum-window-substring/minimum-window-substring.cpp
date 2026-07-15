class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        int l=0;int r=0;int min_len=INT_MAX; int cnt=0;int Sindex=-1;
        int hash[256]={0};
        for(int i=0; i<t.length();i++){
            hash[t[i]]++;
        }
        while(r<s.length()){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt==n){
                ////// shrink the window for min substring
                if(((r-l)+1)<min_len){
                    min_len=(r-l)+1;
                    Sindex=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return(Sindex==-1?"":s.substr(Sindex,min_len));
    }
};