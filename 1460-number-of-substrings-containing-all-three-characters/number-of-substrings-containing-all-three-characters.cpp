class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int r=0; int l=0; int cnt=0; map<char,int>mpp;
        while(r<s.length()){
            mpp[s[r]]++;
            while(mpp.size()==3){
                cnt+=(n-r);
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return cnt;
    }
};