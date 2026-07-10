class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int>hash(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int goodpairs=0;
        for(int i=0;i<hash.size();i++){
            if(hash[i]>1){
                goodpairs+=((hash[i]*(hash[i]-1))/2);
            }
        }
        return goodpairs;
    }
};