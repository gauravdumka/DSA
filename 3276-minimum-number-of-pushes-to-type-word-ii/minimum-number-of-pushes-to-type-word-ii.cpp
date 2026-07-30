class Solution {
public:
    int minimumPushes(string word) {
        vector<int>hash(26); int result=0;
        for(char &ch:word){
            hash[ch-'a']++;
        }
        sort(hash.begin(),hash.end(),greater<int>());
        for(int i=0;i<26;i++){
            result+=((i/8)+1)*hash[i];
        }
        return result;
    }
};