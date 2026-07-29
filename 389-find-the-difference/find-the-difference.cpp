class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>hash(26);
        for(char s:s){
            hash[s-'a']++;
        }
        for(char t:t){
            hash[t-'a']--;
        }
        char cnt;
        for(int i=0;i<26;i++){
          if(hash[i]<0){
            cnt= i+'a';
          }  
        }
        return cnt;
    }
};