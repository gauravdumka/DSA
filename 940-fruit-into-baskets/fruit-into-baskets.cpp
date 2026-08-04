class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>hash;int i=0; int maxlen =1;
        for(int j=0;j<fruits.size();j++){
            hash[fruits[j]]++;
            while(hash.size()>2){
                hash[fruits[i]]--;
                if(hash[fruits[i]] == 0){
                    hash.erase(fruits[i]);
                }
                i++;
            }
            
            maxlen=max(maxlen,j-i+1);
            
        }
        return maxlen;
    }
};