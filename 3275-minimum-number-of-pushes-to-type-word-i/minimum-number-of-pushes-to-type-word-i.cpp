class Solution {
public:
    int minimumPushes(string word) {
        // int result=0;
        // unordered_map<int,int>mp;
        // int assignkey=2;
        // for(char &ch:word){
        //     if(assignkey>9){
        //         assignkey=2;
        //     }
        //     mp[assignkey]++;
        //     result+=mp[assignkey];
        //     assignkey++;
        // }
        // return result;

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