class Solution {
public:
    int minimumPushes(string word) {
        int result=0;
        unordered_map<int,int>mp;
        int assignkey=2;
        for(char &ch:word){
            if(assignkey>9){
                assignkey=2;
            }
            mp[assignkey]++;
            result+=mp[assignkey];
            assignkey++;
        }
        return result;
    }
};