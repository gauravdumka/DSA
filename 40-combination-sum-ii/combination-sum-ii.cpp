class Solution {
public:
    void find_subsequence(int idx,int target,vector<int>&arr ,vector<int>&temp, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        // if(idx>=arr.size()){  //// this part is not necessary bcz loop handles this condition
        //     return;
        // }
        for(int i=idx;i<arr.size();i++){
            if((i>idx) && (arr[i]==arr[i-1]))continue;
            if(arr[i]>target)break;

            temp.push_back(arr[i]);
            find_subsequence(i+1,target-arr[i],arr,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        find_subsequence(0,target,candidates,temp,ans);
        return ans;
    }
};