class Solution {
public:
    void findcombination(int idx, int target, vector<int>&arr, vector<vector<int>>&ds, vector<int>&ans){
        if(idx>=arr.size()){
            if(target==0){
                ds.push_back(ans);
            }
            return;
        }
        if(arr[idx]<=target){
            ans.push_back(arr[idx]);
            findcombination(idx, target-arr[idx],arr,ds,ans);
            ans.pop_back();
        }
        findcombination(idx+1, target, arr, ds, ans);
    }

public:

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ds; vector<int>ans;
        findcombination(0,target,candidates,ds,ans);
        return ds;

    }
};