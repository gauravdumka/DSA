class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0; int j=0; unordered_map<char,int>mpp; int result=0;
        while(j<s.size()){
            mpp[s[j]]++;
            while(mpp[s[j]]>2){
                mpp[s[i]]--;
                i++;
            }
            result=max(result,j-i+1);
            j++;
        }
        return result;
    }
};