class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int,int>mpp;
        // for(int i=0;i<nums.size();i++){
        //     if(mpp.find(nums[i])!=mpp.end()){
        //        if(abs(mpp[nums[i]]-i)<=k){
        //         return true;
        //        }
        //     }
        //     mpp[nums[i]]=i;
        // }
        // return false;


        //    SECOND METHOD

        unordered_set<int>st;
        if(k==0)return false;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()){
                return true;
            }
            st.insert(nums[i]);
            if(st.size()>k){
                st.erase(nums[i-k]);
            }
        }
        return false;
    }
};