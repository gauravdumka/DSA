class Solution {
public:
    string findValidPair(string s) {
       vector<int>hash(10,0);
       for(int i=0; i<s.length();i++){
            hash[s[i]-'0']++;
       }
       for(int i=0;i<s.length()-1;i++){
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            if(a != b && hash[a] == a && hash[b] == b) {
                return s.substr(i, 2);
            }
       }
       return "";
    }
};