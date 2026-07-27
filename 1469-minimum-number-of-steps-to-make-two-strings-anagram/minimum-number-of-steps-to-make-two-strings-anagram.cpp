class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>hash(26);
        for(char s:s){
            hash[s-'a']++;
        }
        for(char t:t){
            hash[t-'a']--;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(hash[i] > 0) {
                ans += hash[i];
            }
        }
        return ans;
    }
};