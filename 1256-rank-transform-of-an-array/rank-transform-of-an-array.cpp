class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<long long,int>hash;
        for(int i=0;i<arr.size();i++){
            hash[arr[i]]=0;
        }
        //// maps are already sorted . Do sorting while using unsorted map
        int rank=1;
        for(auto &it:hash){
            it.second=rank++;
        }
        vector<int>ans(arr.size()); int i=0;
        for(int i=0;i<arr.size();i++){
            ans[i]=hash[arr[i]];
        }
        return ans;

    }
};