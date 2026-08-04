class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // int mini=INT_MAX; int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     mini=min(mini,nums[i]);
        //     maxi=max(maxi,nums[i]);

        // }
        // vector<int>arr(maxi+1,0);
        // for(int i=0;i<nums.size();i++){
        //     arr[nums[i]]++;
        // }
        // vector<int>ans;
        // for(int i=mini;i<=maxi;i++){
        //     if(arr[i]==0){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;
        sort(nums.begin(),nums.end());
        vector<int>result;
        for(int i=1;i<nums.size();i++){
            for(int j=nums[i-1]+1;j<nums[i];j++){
                result.push_back(j);
            }
        }
        return result;

    }
};